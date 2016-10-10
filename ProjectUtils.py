####################################################################
# This class is a singleton that manages the projects list
# Make sure to use its methods when manipulating the projects list
#       ProjectManager.<method call>
#
# Last updated by Mike on October 9
import json
import os
from Project import Project

# Last updated by Angelo on October 6
from Project import Project


class ProjectUtils(type):
    projects = []
    opened_project = Project()

    # Makes sure there is only one instance of Project Manager (Singleton)
    _instances = {}

    def __call__(cls, *args, **kwargs):
        if cls not in cls._instances:
            cls._instances[cls] = super(ProjectUtils, cls).__call__(*args, **kwargs)
        return cls._instances[cls]

    @classmethod
    def find_project_by_name(self, name):
        i = 0
        found = False
        for project in self.projects:
            if project.name == name:
                found = True
                break
            i += 1
        
        if found: return i
        else: return -1

    @classmethod
    def add_project(self, new_project):
        self.projects.append(new_project)
        #creates .json file for new project
        new_project.name + '.json'
        with open(new_project.name + '.json', 'w') as f:
            newdescription={"Created_Date" : new_project.created_date,"Description" : new_project.description}
            json.dump(newdescription, f)
            f.close()

    @classmethod
    def load_projects(self):
        #loads existing projects into projects[]
        for file in os.listdir(os.curdir):
            if file.endswith(".json"):
                with open(file, 'r') as f:
                    projectfiledata = json.load(f)
                    current_description = projectfiledata["Description"]
                    current_date = projectfiledata["Created_Date"]
                    loaded_project = Project()
                    loaded_project.name=file.replace(".json","")
                    loaded_project.description = current_description
                    loaded_project.created_date = current_date
                    self.projects.append(loaded_project)
                    f.close()


    @classmethod
    def remove_project(self, index):
        os.remove(self.projects[index].name + '.json')
        del self.projects[index]



# Metaclass, Do not touch!
class MyClass(object):
    __metaclass__ = ProjectUtils
