#ifndef Json_utils_H
#define Json_utils_H
#pragma once

#include <QDate>
#include "project.h"
#include "task.h"
#include "projectutils.h"

#include "json.hpp"
void remove_json_project(string projectName);
void create_json_project(Project newproject);
void save_all_projects(vector <Project> projects);
void remove_json_task(Project project, Task taskRemove);
void add_json_task(Project project, Task new_task);
Project load_json_project(string projectName);
vector <Project> load_all_projects();
bool project_exists(string name);
//Project Change
void rename_project(string old_name, string new_name);
void change_project_description(string project_name, string new_description);

//Task Change
void change_task_name(Project& project, int task_number, string new_name);
void change_task_due_date(Project& project, int task_number, QDate new_date);
void change_task_description(Project& project, int task_number, string new_description);
void change_task_status(Project& project, int task_number, string new_status);

#endif
