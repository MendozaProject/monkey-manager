#include json_utils.h

using namespace std;

using json = nlohmann::json;
/**
 * @brief remove_json_project, deletes json project from computer
 * @param projectName, string of project name that you want to remove
 */
void remove_json_project(string projectName)
{
	string filename = projectName + ".json";
    remove(filename.c_str());
}
/**
 * @brief create_json_project, Creates a json project
 * @param newproject, the project that you want to create a json for
 */
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
/**
 * @brief save_all_projects, saves all of the current projects in singleton
 * @param projects, send singleton of projects
 */
void save_all_projects(vector <Project> projects)
{

    for(int i=0;i<projects.size();i++)
    {
        create_json_project(projects[i]);
    }
}
/**
 * @brief load_json_project, loads the json project
 * @param projectName, send string of project name
 * @return, retunrs project of given string name
 */
Project load_json_project(string projectName)
{
    Project project_to_load;
	json j1;

    ifstream jsonfile(projectName);
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

return project_to_load;
}
/**
 * @brief load_all_projects, loads all json projects on computer
 * @return, returns vector of projects
 */
vector <Project> load_all_projects()
{
vector <Project> all_projects;
Project loaded_project;
QDirIterator jsonfile(QDir::currentPath(), QStringList() << "*.json", QDir::Files, QDirIterator::NoIteratorFlags);
while (jsonfile.hasNext())
{
    jsonfile.next();
    loaded_project=load_json_project(jsonfile.fileName().toStdString());
    all_projects.push_back(loaded_project);
}

return all_projects;

}
/**
 * @brief project_exists, checks if project exists
 * @param name, string of the project name that you want to check
 * @return, returns true if project exists, false if not
 */
bool project_exists(string name)
{
    string filename= name + ".json";
  ifstream jsonfile(filename);
  if(jsonfile)
      return true;
  else
      return false;


}
/**
 * @brief rename_project, renames the json project
 * @param old_name, string of old json project name
 * @param new_name, string of new json project name
 */
void rename_project(string old_name, string new_name)
{
	string oldfilename = old_name + ".json";
	string newfilename = new_name + ".json";
    json j1;

    ifstream jsonfile(oldfilename);
    jsonfile >> j1;
    jsonfile.close();

    j1["Project"]["Name"]=new_name;

    ofstream jsonfile1;
    jsonfile1.open(oldfilename);
    jsonfile1 << j1;
    jsonfile1.close();
    rename(oldfilename.c_str(), newfilename.c_str());
}
