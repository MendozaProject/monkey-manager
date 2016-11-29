#ifndef PROJECTUTILS_H
#define PROJECTUTILS_H
#pragma once

#include <stddef.h>

#include "project.h"

using namespace std;

class ProjectUtils {
private:
    vector<Project> m_projects;
    vector<Project>::iterator m_projects_iterator;
    Project m_open_project;
    static ProjectUtils* p_instance;
    Task m_opened_task;
    int m_current_project_index;

    /**
     * @brief Empty class constructor
     */
    ProjectUtils();
    /**
     * @brief Empty class destructor
     */
    ~ProjectUtils();

public:

    /**
     * @brief Creates one and only one instance of the ProjectUtils
     */
    static ProjectUtils *instance();

    /**
     * @brief Adds a project to the projects vector
     */
    void add_project(Project project);

    /**
     * @brief Removes a project from m_projects vector
     */
    void remove_project(string name);

    /**
     * @brief Finds a project by name
     */
    vector<Project>::iterator find_project_by_name(string name);

    /**
     * @brief Sets a project for access across classes.
     */
    void set_open_project(string name);

    /**
     * @brief Gets the currently open project
     */
    Project& get_open_project();

    /**
     * @brief Sets the projects vector
     */
    void set_projects(vector<Project> projects);

    /**
     * @brief Gets the projects vector
     */
    vector<Project>& get_projects();

    /**
     * @brief Sets a task for access across classes.
     */
    void open_task(Task& task);

    /**
     * @brief Gets the currently open task
     */
    Task& get_open_task();

    /**
     * @brief Gets the index of the current project
     */
    int& get_current_project_index();

    /**
     * @brief Saves index of the current project
     */
    void set_current_project_index(int index);
};

#endif // PROJECTUTILS_H
