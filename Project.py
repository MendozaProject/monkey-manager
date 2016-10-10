import time
from Task import Task


class Project:

    def __init__(self, name="New Project", description="Add description"):
        self.created_date = time.strftime("%H:%M:%S, %d/%m/%Y")
        self.name = name
        self.description = description
        self.tasks = []
        self.categories = []

    def find_task_by_name(self, name):
        i = 0
        found = False
        for project in self.tasks:
            if project.name == name:
                found = True
                break
            i += 1

        if found:
            return i
        else:
            return -1

    def remove_task(self, index):
        del self.tasks[index]

    def add_task(self, new_task):
        self.tasks.append(new_task)