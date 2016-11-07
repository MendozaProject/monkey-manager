#ifndef PROJECTUTILS_H
#define PROJECTUTILS_H
#pragma once

#include "project.h"

class ProjectUtils {
private:
    vector<Project> s_projects;
    vector<Project>::iterator s_projects_iterator;
    Project s_open_project;
    static ProjectUtils* m_pInstance;
    Task s_opened_task;

    ProjectUtils();
    ~ProjectUtils();

public:
    static ProjectUtils *Instance();

    void add_project(Project project);
    void remove_project(string name);

    Project find_project_by_name(string name);

    void open_project(string name);
    Project get_open_project();

    void set_projects(vector<Project> projects);
    vector<Project>& get_projects();

    void open_task(Task& task);
    void close_task();

    Task get_open_task();

    string trim_string(string s);
};

#endif // PROJECTUTILS_H
