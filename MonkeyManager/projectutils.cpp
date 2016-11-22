#include "projectutils.h"
#include <stddef.h>
using namespace std;

ProjectUtils* ProjectUtils::m_pInstance = NULL;

ProjectUtils::ProjectUtils(){}
ProjectUtils::~ProjectUtils(){}

void ProjectUtils::add_project(Project project){
    s_projects.push_back(project);
}

ProjectUtils* ProjectUtils::Instance(){
    if (!m_pInstance)   // Only allow one instance of class to be generated.
        m_pInstance = new ProjectUtils;
    return m_pInstance;
}

void ProjectUtils::remove_project(string name){
    bool found = false;
    for (s_projects_iterator = s_projects.begin();
            s_projects_iterator != s_projects.end();
            s_projects_iterator++){
        if ((*s_projects_iterator).get_name() == name){
            found = true;
            s_projects.erase(s_projects_iterator);
            break;
        }
    }
    if (!found) {
        throw ERR_PROJECT_NOT_FOUND;
    }
}

vector<Project>::iterator ProjectUtils::find_project_by_name(string name){
    bool found = false;
    //Project* proj;
    for (s_projects_iterator = s_projects.begin();
            s_projects_iterator != s_projects.end();
            s_projects_iterator++){
        if ((*s_projects_iterator).get_name() == name){
            found = true;
            //proj = *s_projects_iterator;
            break;
        }
    }
    if (!found) {
        throw ERR_PROJECT_NOT_FOUND;
    }
    return s_projects_iterator;
}

//void ProjectUtils::open_project(Project project) {
//    s_open_project = project;
//}

void ProjectUtils::open_project(string name){
    s_open_project = *find_project_by_name(name);
}

Project& ProjectUtils::get_open_project(){
    return s_open_project;
}

void ProjectUtils::set_projects(vector<Project> projects){
    s_projects = projects;
}

vector<Project>& ProjectUtils::get_projects(){
    return s_projects;
}


void ProjectUtils::open_task(Task& task){
    s_opened_task = task;
}

void ProjectUtils::close_task(){
    s_opened_task = NULL;
}

Task& ProjectUtils::get_open_task(){
    return s_opened_task;
}

string ProjectUtils::trim_string(string s){
    int i = 0;

    while(s.at(i) == ' ')
        i++;
    size_t j = s.length() - 1;
    while(s.at(j) == ' ')
        j--;

    return s.substr(i, j - i + 1);
}

int& ProjectUtils::get_current_project_index(){
    return current_project_index;
}

void ProjectUtils::set_current_project_index(int index){
    current_project_index = index;
}
