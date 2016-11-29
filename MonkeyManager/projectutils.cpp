#include "projectutils.h"

ProjectUtils* ProjectUtils::p_instance = NULL;

/**
 * @brief Empty class constructor
 */
ProjectUtils::ProjectUtils(){}

/**
 * @brief Empty class destructor
 */
ProjectUtils::~ProjectUtils(){}

/**
 * @brief Returns an instance of ProjectUtils singleton
 * @return Instance of ProjectUtils
 */
ProjectUtils* ProjectUtils::instance(){
    if (!p_instance)   // Only allow one instance of class to be generated.
        p_instance = new ProjectUtils;
    return p_instance;
}


/**
 * @brief Adds a project to the projects vector
 * @param project  Project object
 */
void ProjectUtils::add_project(Project project){
    m_projects.push_back(project);
}

/**
 * @brief Removes a project from m_projects vector
 * @param name  Name of project
 */
void ProjectUtils::remove_project(string name){
    bool found = false;
    for (m_projects_iterator = m_projects.begin();
            m_projects_iterator != m_projects.end();
            m_projects_iterator++){
        if ((*m_projects_iterator).get_name() == name){
            found = true;
            m_projects.erase(m_projects_iterator);
            break;
        }
    }
    if (!found) {
        throw ERR_PROJECT_NOT_FOUND;
    }
}

/**
 * @brief Finds a project by name
 * @param name  Name of project
 * @return the iterator at the position where the project was found
 */
vector<Project>::iterator ProjectUtils::find_project_by_name(string name){
    bool found = false;
    for (m_projects_iterator = m_projects.begin();
            m_projects_iterator != m_projects.end();
            m_projects_iterator++){
        if ((*m_projects_iterator).get_name() == name){
            found = true;
            break;
        }
    }
    if (!found) {
        throw ERR_PROJECT_NOT_FOUND;
    }
    return m_projects_iterator;
}

/**
 * @brief Sets a project for access across classes.
 * @param name  Name of project
 */
void ProjectUtils::set_open_project(string name){
    m_open_project = *find_project_by_name(name);
}

/**
 * @brief Gets the currently open project
 * @return Currently open project
 */
Project& ProjectUtils::get_open_project(){
    return m_open_project;
}

/**
 * @brief Sets the projects vector
 * @param projects  A vector of projects
 */
void ProjectUtils::set_projects(vector<Project> projects){
    m_projects = projects;
}

/**
 * @brief Gets the projects vector
 * @return gets projects vector
 */
vector<Project>& ProjectUtils::get_projects(){
    return m_projects;
}

/**
 * @brief Sets a task for access across classes.
 * @param task  A reference to a task
 */
void ProjectUtils::open_task(Task& task){
    m_opened_task = task;
}

/**
 * @brief Gets the currently open task
 * @return A reference to the currently open task
 */
Task& ProjectUtils::get_open_task(){
    return m_opened_task;
}

/**
 * @brief Gets the index of the current project
 * @return Index of the current project
 */
int& ProjectUtils::get_current_project_index(){
    return m_current_project_index;
}

/**
 * @brief Saves index of the current project
 * @param index  Index of the current project
 */
void ProjectUtils::set_current_project_index(int index){
    m_current_project_index = index;
}

