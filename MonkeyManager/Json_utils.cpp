/*
Need edit functions

*/


#include "date.h"
#include "project.h"
#include "task.h"
#include "projectutils.h"

#include "json.hpp"

#include <string>
#include <iostream>
#include <stdio.h>
#include <vector>
#include <fstream>

using namespace std;

using json = nlohmann::json;



void remove_json_project(string projectName)
{
	string filename = projectName + ".json";
    remove(filename.c_str());
}
void create_json_project(Project newproject) //need function in Project or Task for Task number
{
	int number_task = 0;
	string name_task = "task";
	string project_name = newproject.get_name();
	
	vector<Task> project_tasks = newproject.get_tasks();
	int task_size = project_tasks.size();

	Date project_date = newproject.get_created_date();
	int day = project_date.DAY;
	int month = project_date.MONTH;
	int year = project_date.YEAR;
	int hour = project_date.HOUR;
	int minute = project_date.MINUTE;
	int second = project_date.SECOND;

	json j1 = {
		{"Project",{
			{"Name", newproject.get_name() },
			{"Description", newproject.get_description() },
			{"Task Number", 0},
			{ "Created Date",{
				{ "Day",day },
				{ "Month",month },
				{ "Year",year },
				{ "Hour", hour },
				{ "Minute", minute },
				{ "Second", second }
		}},
		}},
		{"Tasks", {
		} }
	  };

	for (int i = 0; i < task_size; i++)//use m_task_number for number_task once function is made
	{
		number_task += 1;
		name_task += to_string(number_task);
		Date task_due = project_tasks[i].get_due_date();
		Date task_date = project_tasks[i].get_created_date();
		int day = task_due.DAY;
		int month = task_due.MONTH;
		int year = task_due.YEAR;
		int hour = task_due.HOUR;
		int minute = task_due.MINUTE;
		int second = task_due.SECOND;
		int day2 = task_date.DAY;
		int month2 = task_date.MONTH;
		int year2 = task_date.YEAR;
		int hour2 = task_date.HOUR;
		int minute2 = task_date.MINUTE;
		int second2 = task_date.SECOND;

	    
		j1["Tasks"][name_task] = {
		{ "Name", project_tasks[i].get_name() },
		{ "Due Date",{
			{"Day",day},
			{"Month",month},
			{"Year",year},
			{"Hour", hour},
			{"Minute", minute},
			{"Second", second}
			}},
		{ "Created Date",{
			{ "Day", day2},
			{ "Month", month2},
			{ "Year", year2},
			{ "Hour", hour2},
			{ "Minute", minute2},
			{ "Second", second2}
		}},
		{ "Description", project_tasks[i].get_description() },
		{ "ID", project_tasks[i].get_id_number() },
		{ "Status", project_tasks[i].get_status() }
		};
		name_task = "task";
	}
	string filename = project_name + ".json";
	ofstream jsonfile;
	jsonfile.open(filename);
	jsonfile << j1;
	jsonfile.close();

	
}
void remove_json_task(Project project, Task taskRemove)//need to chnage once m_task_number function is made
{
	string taskName = taskRemove.get_name();
	string task_name = "task";
	int task_number = 1;
	json j1;
	string task_name1;
	string project_name = project.get_name();
	ifstream jsonfile(project_name + ".json");
	jsonfile >> j1;
	jsonfile.close();
	int json_size = j1["Tasks"].size();
	
		for (int i = 0; i < json_size ; i++)
	{
		
		task_name += to_string(task_number);
		task_name1 = j1["Tasks"][task_name]["Name"];
		
		if (task_name1 == taskName)
		{
			
			j1["Tasks"].erase(task_name);
			break;
		}
		task_name = "task";
		task_number += 1;
	}

	string filename = project_name + ".json";
	ofstream jsonfile1;
	jsonfile1.open(filename);
	jsonfile1 << j1;
	jsonfile1.close();


}
void add_json_task(Project project, Task new_task)
{
	string project_name = project.get_name();
	
	json j1;
	
	ifstream jsonfile(project_name + ".json");
	jsonfile >> j1;
	jsonfile.close();

   int task_number = 1 + j1["Tasks"].size();
   string task_name = "task" + to_string(task_number);

   Date task_due = new_task.get_due_date();
   Date task_date = new_task.get_created_date();
   int day = task_due.DAY;
   int month = task_due.MONTH;
   int year = task_due.YEAR;
   int hour = task_due.HOUR;
   int minute = task_due.MINUTE;
   int second = task_due.SECOND;
   int day2 = task_date.DAY;
   int month2 = task_date.MONTH;
   int year2 = task_date.YEAR;
   int hour2 = task_date.HOUR;
   int minute2 = task_date.MINUTE;
   int second2 = task_date.SECOND;


   j1["Tasks"][task_name] = {
	   { "Name", new_task.get_name() },
	   { "Due Date",{
		   { "Day",day },
		   { "Month",month },
		   { "Year",year },
		   { "Hour", hour },
		   { "Minute", minute },
		   { "Second", second }
	   } },
	   { "Created Date",{
		   { "Day", day2 },
		   { "Month", month2 },
		   { "Year", year2 },
		   { "Hour", hour2 },
		   { "Minute", minute2 },
		   { "Second", second2 }
	   } },
	   { "Description", new_task.get_description() },
	   { "ID", new_task.get_id_number() },
	   { "Status", new_task .get_status()}
   };

   string filename = project_name + ".json";
   ofstream jsonfile1;
   jsonfile1.open(filename);
   jsonfile1 << j1;
   jsonfile1.close();

}
void load_json_project(Project& project_to_load,string projectName)//send empty project and name of project to load
{
	json j1;

	ifstream jsonfile(projectName + ".json");
	jsonfile >> j1;
	jsonfile.close();

	Date project_date;
	int task_number = j1["Project"]["Task Number"];
	int day = j1["Project"]["Created Date"]["Day"];
	int month = j1["Project"]["Created Date"]["Month"];;
	int year = j1["Project"]["Created Date"]["Year"];
	int hour = j1["Project"]["Created Date"]["Hour"];
	int minute = j1["Project"]["Created Date"]["Minute"];
	int second = j1["Project"]["Created Date"]["Second"];
	project_date.DAY= day;
	project_date.MONTH = month;
	project_date.YEAR = year;
	project_date.HOUR = hour;
	project_date.MINUTE = minute;
	project_date.SECOND = second;


	int day1 = 0;
	int month1 = 0;
	int year1 = 0;
	int hour1 = 0;
	int minute1 = 0;
	int second1 = 0;

	vector <Task> project_tasks;
	Date task_created_date;
	Date task_due_date;
	Task new_task;
	//int task_number = 0;
	string task_name = "task";
	int size_tasks = j1["Tasks"].size();
	for (int i = 0; i < size_tasks; i++)
	{
		
			task_number += 1;
			task_name += to_string(task_number);
			new_task.set_name(j1["Tasks"][task_name]["Name"]);

			day1 =j1["Tasks"][task_name]["Due Date"]["Day"];
			month1= j1["Tasks"][task_name]["Due Date"]["Month"];
			year1= j1["Tasks"][task_name]["Due Date"]["Year"];
			hour1= j1["Tasks"][task_name]["Due Date"]["Hour"];
			minute1= j1["Tasks"][task_name]["Due Date"]["Minute"];
			second1= j1["Tasks"][task_name]["Due Date"]["Second"];
			task_due_date.DAY=day1;
			task_due_date.MONTH=month1;
			task_due_date.YEAR=year1;
			task_due_date.HOUR=hour1;
			task_due_date.MINUTE=minute1;
			task_due_date.SECOND=second1;
			new_task.set_due_date(task_due_date);

			day1 = j1["Tasks"][task_name]["Created Date"]["Day"];
			month1 = j1["Tasks"][task_name]["Created Date"]["Month"];
			year1 = j1["Tasks"][task_name]["Created Date"]["Year"];
			hour1 = j1["Tasks"][task_name]["Created Date"]["Hour"];
			minute1 = j1["Tasks"][task_name]["Created Date"]["Minute"];
			second1 = j1["Tasks"][task_name]["Created Date"]["Second"];
			task_created_date.DAY = day1;
			task_created_date.MONTH = month1;
			task_created_date.YEAR = year1;
			task_created_date.HOUR = hour1;
			task_created_date.MINUTE = minute1;
			task_created_date.SECOND = second1;
			new_task.set_created_date(task_created_date);
			

			new_task.set_description(j1["Tasks"][task_name]["Description"]);
			//new_task.set_id(j1["Tasks"][task_name]["ID"]);
			new_task.set_status(j1["Tasks"][task_name]["Status"]);

			project_tasks.push_back(new_task);
			task_name = "task";
		

	}



	project_to_load.set_name(j1["Project"]["Name"]);
	project_to_load.set_description(j1["Project"]["Description"]);
	project_to_load.set_created_date(project_date);
	project_to_load.set_tasks(project_tasks);


}
