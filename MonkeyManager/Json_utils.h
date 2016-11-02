#ifndef Json_utils_H
#define Json_utils_H
#pragma once
#include "date.h"
#include "project.h"
#include "task.h"
#include "projectutils.h"

#include "json.hpp"
void remove_json_project(string projectName);//works
void create_json_project(Project newproject);//works with at least 2 tasks
void remove_json_task(Project project, Task taskRemove);//works but need to change with m_task_number function
void add_json_task(Project project, Task new_task);//works
void load_json_project(Project& project_to_load, string projectName);//works

#endif