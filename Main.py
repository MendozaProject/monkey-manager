import sys
from Project import Project

def main():
    
    print "________________________________________________________________"
    print "  MONKEY MANAGER (For commands list, type 'help')\n"

    while (True):
        command = raw_input('\nMain--> ')
        if command == 'exit' or command == 'x':
            break;
        elif command == 'help' or command ==  'h':
            help_list()
        elif command == 'new' or command == 'n':
            new_project()
        elif command == 'list' or command == 'l':
            list_projects()
        elif command == 'delete' or command == 'd':
            delete_project()
        elif ProjectManager.find_project_by_name(command) != -1:
            index = ProjectManager.find_project_by_name(command)
            view_project(index)
        elif command == 'clear':
            print "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"
        else:
            print "Command not recognized"
            
            
def help_list():
    print "________________________________________________________________"
    print "  MAIN COMMANDS\n"
    
    print "  <project name>       View Project Details"
    print "  'x' or 'exit'        Exit the program"
    print "  'l' or 'list'        Lists out all your projects"
    #print "'o' or 'open'        Open a project"
    print "  'd' or 'delete'      Delete a project"
    print "  'n' or 'new '        Create a new project"
    print "  'clear'              Clear the screen"
    
    
    
def new_project():
    print "________________________________________________________________"
    print "  NEW PROJECT (Type 'cancel' to cancel)\n"
    
    name = ""
    description  = ""
    
    while True:
        name = raw_input ("Project Name:  ")
        if name == 'cancel':
            return
        if ProjectManager.find_project_by_name(name) == -1 and not name == "": 
            break
        else:
            print("Name cannot be blank or already taken")

    while description == "":
        description = raw_input ("\nDescription:   ")
        if name == 'cancel':
            return
        
    ProjectManager.add_project(Project(name, description))
    
    print "\n  Success, your new project '" + name + "' has been created!"
    

def list_projects():
    print "________________________________________________________________"
    print "  PROJECTS LIST\n"
    
    i = 0
    for project in ProjectManager.projects:
        i = i + 1
        print str(i) + ". " + project.name

def delete_project():
    print "________________________________________________________________"
    print "  DELETE PROJECT (Type 'cancel' to cancel')\n"
    while True:
        name = raw_input("Project Name:  ")
        
        if name == 'cancel':
            return
    
        index = ProjectManager.find_project_by_name(name)

        if index == -1:
            print "Project named '" + name + "' not found"
        else:
            ProjectManager.remove_project(index)
            print "Project '" + name + "' was deleted"
            break

def view_project(index):
    print "________________________________________________________________"
    print "  " + ProjectManager.projects[index].name
    print "\n  Date Created:  " + str(ProjectManager.projects[index].created_date)
    print "\n  Description:   " + ProjectManager.projects[index].description
    


# This class is a singleton that manages the projects list
# Make sure to use its methods when manipulating the projects list
#       ProjectManager.<method call>
class ProjectManager(type):

    projects = []
    
    # Makes sure there is only one instance of Project Manager (Singleton)
    _instances = {}
    def __call__(cls, *args, **kwargs):
        if cls not in cls._instances:
            cls._instances[cls] = super(ProjectManager, cls).__call__(*args, **kwargs)
        return cls._instances[cls]
        
    @classmethod
    def find_project_by_name(self, name):
        i = 0
        for project in self.projects:
            if project.name == name:
                return i
        return -1
        
    @classmethod
    def add_project(self, new_project):    
        self.projects.append(new_project)
        
    @classmethod
    def remove_project(self, index):
        del self.projects[index]
        
# Metaclass, Do not touch!
class MyClass(object):
    __metaclass__ = ProjectManager


if __name__ == '__main__': main()


