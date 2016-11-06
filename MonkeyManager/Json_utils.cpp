#include <QDate>
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
void create_json_project(Project newproject)
{
    int number_task = newproject.get_current_ticket();
	string name_task = "task";
	string project_name = newproject.get_name();
	
	vector<Task> project_tasks = newproject.get_tasks();
	int task_size = project_tasks.size();

    QDate project_date = newproject.get_created_date();
    int day = project_date.day();
    int month = project_date.month();
    int year = project_date.year();

	json j1 = {
		{"Project",{
			{"Name", newproject.get_name() },
            {"Description", newproject.get_description() },
            {"Task Number", number_task},
			{ "Created Date",{
				{ "Day",day },
				{ "Month",month },
                { "Year",year }
		}},
		}},
		{"Tasks", {
             {"Task List",{}}
		} }
	  };

    for (int i = 0; i < task_size; i++)
	{
        number_task = project_tasks[i].get_task_number();
		name_task += to_string(number_task);
        QDate task_due = project_tasks[i].get_due_date();
        QDate task_date = project_tasks[i].get_created_date();
        int day = task_due.day();
        int month = task_due.month();
        int year = task_due.year();
        int day2 = task_date.day();
        int month2 = task_date.month();
        int year2 = task_date.year();


        j1["Tasks"]["Task List"][j1["Tasks"]["Task List"].size()]=name_task;
		j1["Tasks"][name_task] = {
		{ "Name", project_tasks[i].get_name() },
		{ "Due Date",{
			{"Day",day},
			{"Month",month},
            {"Year",year}
        }},
		{ "Created Date",{
			{ "Day", day2},
			{ "Month", month2},
            { "Year", year2}
        }},
		{ "Description", project_tasks[i].get_description() },
		{ "ID", project_tasks[i].get_id_number() },
        { "Status", project_tasks[i].get_status() },
        { "Task Number", project_tasks[i].get_task_number()}
        };
		name_task = "task";
	}
	string filename = project_name + ".json";
	ofstream jsonfile;
	jsonfile.open(filename);
	jsonfile << j1;
	jsonfile.close();

	
}
void remove_json_task(Project project, Task taskRemove)
{
	string taskName = taskRemove.get_name();
	string task_name = "task";
    int task_number = taskRemove.get_task_number();
	json j1;
	string task_name1;
	string project_name = project.get_name();
	ifstream jsonfile(project_name + ".json");
	jsonfile >> j1;
	jsonfile.close();

	
    task_name += to_string(task_number);
    j1["Tasks"].erase(task_name);

    for (int i=0; i < j1["Tasks"]["Task List"].size(); i++)//find task number in list
        {
            if (j1["Tasks"]["Task List"][i] == task_name)
            {j1["Tasks"]["Task List"].erase(i);
                break;
            }
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

   int task_number = new_task.get_task_number();
   string task_name = "task" + to_string(task_number);

   QDate task_due = new_task.get_due_date();
   QDate task_date = new_task.get_created_date();
   int day = task_due.day();
   int month = task_due.month();
   int year = task_due.year();
   int day2 = task_date.day();
   int month2 = task_date.month();
   int year2 = task_date.year();


   j1["Tasks"]["Task List"][j1["Tasks"]["Task List"].size()]=task_name;
   j1["Tasks"][task_name] = {
	   { "Name", new_task.get_name() },
	   { "Due Date",{
		   { "Day",day },
		   { "Month",month },
           { "Year",year }
       } },
	   { "Created Date",{
		   { "Day", day2 },
		   { "Month", month2 },
           { "Year", year2 }
       } },
	   { "Description", new_task.get_description() },
	   { "ID", new_task.get_id_number() },
       { "Status", new_task .get_status()},
       {"Task Number", new_task.get_task_number()}
   };

   string filename = project_name + ".json";
   ofstream jsonfile1;
   jsonfile1.open(filename);
   jsonfile1 << j1;
   jsonfile1.close();

}
void load_json_project(Project& project_to_load,string projectName)//need better way to get task names
{
	json j1;

	ifstream jsonfile(projectName + ".json");
	jsonfile >> j1;
	jsonfile.close();


	int task_number = j1["Project"]["Task Number"];
	int day = j1["Project"]["Created Date"]["Day"];
	int month = j1["Project"]["Created Date"]["Month"];;
	int year = j1["Project"]["Created Date"]["Year"];
    QDate project_date(year,month,day);



	int day1 = 0;
	int month1 = 0;
	int year1 = 0;


	vector <Task> project_tasks;
    QDate task_created_date;
    QDate task_due_date;
	Task new_task;


    int size_tasks = j1["Tasks"]["Task List"].size();
    string task_name=" ";
    for (int i = 0; i < size_tasks; i++)//loads all of the tasks
	{


            task_name=j1["Tasks"]["Task List"][i];//gets next task name
            new_task.set_name(j1["Tasks"][task_name]["Name"]);

			day1 =j1["Tasks"][task_name]["Due Date"]["Day"];
			month1= j1["Tasks"][task_name]["Due Date"]["Month"];
			year1= j1["Tasks"][task_name]["Due Date"]["Year"];

            task_due_date.setDate(year1,month1,day1);

            new_task.set_due_date(task_due_date);

			day1 = j1["Tasks"][task_name]["Created Date"]["Day"];
			month1 = j1["Tasks"][task_name]["Created Date"]["Month"];
			year1 = j1["Tasks"][task_name]["Created Date"]["Year"];

            task_created_date.setDate(year1,month1,day1);

			new_task.set_created_date(task_created_date);
			

			new_task.set_description(j1["Tasks"][task_name]["Description"]);
            new_task.set_id_number(j1["Tasks"][task_name]["ID"]);
			new_task.set_status(j1["Tasks"][task_name]["Status"]);
            new_task.set_task_number(j1["Tasks"][task_name]["Task Number"]);

			project_tasks.push_back(new_task);
			task_name = "task";
		

	}



	project_to_load.set_name(j1["Project"]["Name"]);
	project_to_load.set_description(j1["Project"]["Description"]);
	project_to_load.set_created_date(project_date);
	project_to_load.set_tasks(project_tasks);
    project_to_load.set_current_ticket(j1["Project"]["Task Number"]);


}
void rename_project(string old_name, string new_name)
{
	string oldfilename = old_name + ".json";
	string newfilename = new_name + ".json";
    rename(oldfilename.c_str(), newfilename.c_str());
}
void change_project_description(string project_name, string new_description)
{
	json j1;
	string filename = project_name + ".json";
	ifstream jsonfile(filename);
	jsonfile >> j1;
	jsonfile.close();
	j1["Project"]["Description"] = new_description;
	
	ofstream jsonfile1;
	jsonfile1.open(filename);
	jsonfile1 << j1;
	jsonfile1.close();


}

//Task Change
void change_task_name(Project& project, int task_number, string new_name)
{
	json j1;
	string filename = project.get_name() + ".json";
	ifstream jsonfile(filename);
	jsonfile >> j1;
	jsonfile.close();

	string task_name = "task" + to_string(task_number);
	j1["Tasks"][task_name]["Name"] = new_name;

	ofstream jsonfile1;
	jsonfile1.open(filename);
	jsonfile1 << j1;
	jsonfile1.close();
}
void change_task_due_date(Project& project, int task_number, QDate new_date)
{
	json j1;
	string filename = project.get_name() + ".json";
	ifstream jsonfile(filename);
	jsonfile >> j1;
	jsonfile.close();

	string task_name = "task" + to_string(task_number);

    int day = new_date.day();
    int month = new_date.month();
    int year = new_date.year();

	j1["Tasks"][task_name]["Due Date"]["Day"]= day;
	j1["Tasks"][task_name]["Due Date"]["Month"]= month;
	j1["Tasks"][task_name]["Due Date"]["Year"]= year;

	ofstream jsonfile1;
	jsonfile1.open(filename);
	jsonfile1 << j1;
	jsonfile1.close();
}
void change_task_description(Project& project, int task_number, string new_description)
{
	json j1;
	string filename = project.get_name() + ".json";
	ifstream jsonfile(filename);
	jsonfile >> j1;
	jsonfile.close();

	string task_name = "task" + to_string(task_number);

	j1["Tasks"][task_name]["Description"] = new_description;

	ofstream jsonfile1;
	jsonfile1.open(filename);
	jsonfile1 << j1;
	jsonfile1.close();


}
void change_task_status(Project& project, int task_number, string new_status)
{
	json j1;
	string filename = project.get_name() + ".json";
	ifstream jsonfile(filename);
	jsonfile >> j1;
	jsonfile.close();

	string task_name = "task" + to_string(task_number);

	j1["Tasks"][task_name]["Status"] = new_status;




}
