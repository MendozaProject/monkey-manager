import json
import os
from Project import Project
from ProjectUtils import ProjectUtils


# ######################################################################
# Last updated by Mike on October 9

RESERVED_WORDS = ["exit", "help", "list", "new", "delete", "edit", "open"]

def manager():
    print "________________________________________________________________"
    print "  MONKEY MANAGER (For commands list, type 'help')"
    ProjectUtils.load_projects() #loads existing projects
    while True:

        command = raw_input('\nMain--> ')
        command = command.strip()
        if command == 'exit' or command == 'x':
            break
        elif command == 'help' or command == 'h':
            help_list()
        elif command == 'new' or command == 'n':
            new_project()
        elif command == 'list' or command == 'l':
            list_projects()
        elif command == 'delete' or command == 'd':
            delete_project()
        elif command == 'edit' or command == 'e':
            edit_project()
        elif not ProjectUtils.find_project_by_name(command) == -1:
            index = ProjectUtils.find_project_by_name(command)
            view_project(index)
        elif command == 'clear':
            print "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"
            print "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"
            print "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"
        else:
            print "\nCommand or Project not recognized"
            
            
def help_list():
    print "________________________________________________________________"
    print "  MAIN COMMANDS\n"
    
    print "  <project name>       View Project Details"
    print "  'x' or 'exit'        Exit the program"
    print "  'l' or 'list'        Lists out all your projects"
    #print "  'o' or 'open'        Open a project"
    print "  'e' or 'edit'        Edit a project"
    print "  'd' or 'delete'      Delete a project"
    print "  'n' or 'new '        Create a new project"
    print "  'clear'              Clear the screen"
    

def new_project():
    print "________________________________________________________________"
    print "  NEW PROJECT (Type 'cancel' to cancel)\n"
    
    name = ""
    description = ""
    
    while True:
        name = raw_input ("Project Name:  ")
        name = name.strip()
        if name == 'cancel':
            return
        if not ProjectUtils.find_project_by_name(name) == -1:
            print "\nProject named '" + name + "' is already taken\n"
        elif len(name) < 2:
            print "\nProject name must at least 2 character\n"
        elif not is_reserved_word(name):
            print "\nProject name cannot be a reserved word\n"
        else:
            break

    while description == "":
        description = raw_input ("\nDescription:   ")
        description = description.strip()
        if name == 'cancel':
            return

    ProjectUtils.add_project(Project(name, description))
    
    print "\n  Success! Your new project '" + name + "' has been created!"
    

def list_projects():
    if not ProjectUtils.projects:
        print "\nError: Project List is empty"
        return

    print "________________________________________________________________"
    print "  PROJECTS LIST\n"
    
    i = 0
    for project in ProjectUtils.projects:
        i += 1
        print str(i) + ". " + project.name


def delete_project():
    if not ProjectUtils.projects:
        print "\nError: Project List is empty"
        return

    print "________________________________________________________________"
    print "  DELETE PROJECT (Type 'cancel' to cancel)\n"
    while True:
        name = raw_input("Project Name:  ")
        name = name.strip()
        
        if name == 'cancel':
            return
    
        index = ProjectUtils.find_project_by_name(name)

        if index == -1:
            print "Project named '" + name + "' not found"
        else:
            ProjectUtils.remove_project(index)
            print "Project '" + name + "' was deleted"
            break


def view_project(index):
    print "________________________________________________________________"
    print "  " + ProjectUtils.projects[index].name
    print "\n  Date Created:  " + str(ProjectUtils.projects[index].created_date)
    print "\n  Description:   " + str(ProjectUtils.projects[index].description)


def edit_project():
    if not ProjectUtils.projects:
        print "\nError: Project List is empty"
        return

    print "________________________________________________________________"
    print "  Edit PROJECT (Type 'cancel' to cancel)\n"

    while True:
        name = raw_input("Project Name:     ")
        name = name.strip()
        if name == 'cancel':
            return

        index = ProjectUtils.find_project_by_name(name)

        if index == -1:
            print "\nProject named '" + name + "' not found\n"
        else:
            break
            
    while True:
        new_name = raw_input("\nNew Project Name: ")
        new_name = new_name.strip()
        if new_name == 'cancel':
            return
        if not ProjectUtils.find_project_by_name(new_name) == -1:
            print "\nProject named '" + new_name + "' is already taken"
        elif len(new_name) < 2:
            print "\nProject name must be at least 2 characters"
        elif not is_reserved_word(new_name):
            print "\nProject name cannot be a reserved word"
        else:
            break

    while True:
        new_description = raw_input("\nNew Description:  ")
        new_description = new_description.strip()
        if new_description == 'cancel':
            return
        else:
            break

    #Renames and updates existing project .json file
    with open(name + '.json', 'r') as f:
        projectfiledata=json.load(f)
        projectfiledata["Description"]=new_description
    with open(name + '.json', 'w') as f:
        json.dump(projectfiledata, f)
        f.close()
    os.rename(name + '.json', new_name + '.json')
    ProjectUtils.projects[index].name = new_name
    ProjectUtils.projects[index].description = new_description

    print "\n  Success! '" + name + "' ---> '" + new_name + "'"


def is_reserved_word(name):
    for word in RESERVED_WORDS:
        if word == name:
            return False
    return True

if __name__ == '__main__': manager()


