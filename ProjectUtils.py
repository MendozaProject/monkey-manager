####################################################################
# This class is a singleton that manages the projects list
# Make sure to use its methods when manipulating the projects list
#       ProjectManager.<method call>
#
# Last updated by Angelo on October 6
from Project import Project


class ProjectUtils(type):
    projects = []
    opened_project = Project()

    RESERVED_WORDS = ["exit", "help", "list", "new", "delete", "edit", "open", "back"]

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

    @classmethod
    def remove_project(self, index):
        del self.projects[index]

    @classmethod
    def is_reserved_word(self, name):
        for word in self.RESERVED_WORDS:
            if word == name:
                return False
        return True

# Metaclass, Do not touch!
class MyClass(object):
    __metaclass__ = ProjectUtils
