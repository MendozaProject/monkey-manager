#ifndef Json_utils_H
#define Json_utils_H
#pragma once
#include <QDate>
#include <QDebug>
#include <QFileInfo>
#include <QDirIterator>
#include "project.h"
#include "task.h"
#include "projectutils.h"
#include "json.hpp"
#include <string>
#include <iostream>
#include <stdio.h>
#include <vector>
#include <fstream>
/**
 * @brief rename_project, renames the json project
*/
void remove_json_project(string projectName);
/**
 * @brief create_json_project, creates a json project
 */
void create_json_project(Project newproject);
/**
 * @brief save_all_projects, saves all the current projects in singleton
 */
void save_all_projects(vector <Project> projects);
/**
 * @brief load_json_project, loads the json file, and returns the project
 */
Project load_json_project(string projectName);
/**
 * @brief load_all_projects, loads all json files
 */
vector <Project> load_all_projects();
/**
 * @brief project_exists, checks if json file exists
 */
bool project_exists(string name);
//Project Change
/**
 * @brief rename_project, renames the json file
 */
void rename_project(string old_name, string new_name);
#endif
