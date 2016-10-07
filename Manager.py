from Project import Project
from ProjectUtils import ProjectUtils

# ######################################################################
# Last updated by Angelo on October 6


def manager():
    print "________________________________________________________________"
    print "  MONKEY MANAGER (For commands list, type 'help')"

    while True:
        command = raw_input('\nMain--> ')
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
        elif ProjectUtils.find_project_by_name(command) != -1:
            index = ProjectUtils.find_project_by_name(command)
            view_project(index)
        elif command == 'clear':
            print "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"
            print "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"
            print "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"
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
        if name == 'cancel':
            return
        if ProjectUtils.find_project_by_name(name) == -1 and not name == "":
            break
        else:
            print("Name cannot be blank or already taken")

    while description == "":
        description = raw_input ("\nDescription:   ")
        if name == 'cancel':
            return
        
    ProjectUtils.add_project(Project(name, description))
    
    print "\n  Success, your new project '" + name + "' has been created!"
    

def list_projects():
    print "________________________________________________________________"
    print "  PROJECTS LIST\n"
    
    i = 0
    for project in ProjectUtils.projects:
        i += 1
        print str(i) + ". " + project.name


def delete_project():
    print "________________________________________________________________"
    print "  DELETE PROJECT (Type 'cancel' to cancel)\n"
    while True:
        name = raw_input("Project Name:  ")
        
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
    print "\n  Description:   " + ProjectUtils.projects[index].description


def edit_project():
    print "________________________________________________________________"
    print "  Edit PROJECT (Type 'cancel' to cancel)\n"

    while True:
        name = raw_input("Project Name:  ")

        if name == 'cancel':
            return

        index = ProjectUtils.find_project_by_name(name)

        if index == -1:
            print "Project named '" + name + "' not found"
        else:
            # Loops

            name = raw_input("New Project Name:  ")
            if name == 'cancel':
                break
            else:
                ProjectUtils.projects[index].name = name

            description = raw_input("New Description")




if __name__ == '__main__': manager()


