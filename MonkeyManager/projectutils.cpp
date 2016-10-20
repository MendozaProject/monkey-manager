#include "projectutils.h"

ProjectUtils::ProjectUtils(){}
ProjectUtils::~ProjectUtils(){}

void ProjectUtils::add_project(Project project){
    s_projects.push_back(project);
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

Project ProjectUtils::find_project_by_name(string name){
    bool found = false;
    Project proj;
    for (s_projects_iterator = s_projects.begin();
            s_projects_iterator != s_projects.end();
            s_projects_iterator++){
        if ((*s_projects_iterator).get_name() == name){
            found = true;
            proj = *s_projects_iterator;
            break;
        }
    }
    if (!found) {
        throw ERR_PROJECT_NOT_FOUND;
    }
    return proj;
}

void ProjectUtils::open_project(string name){
    s_open_project = find_project_by_name(name);
}

Project ProjectUtils::get_open_project(){
    return s_open_project;
}
