import time
from Task import Task


class Project:

    def __init__(self, name="New Project", description="Add description"):
        self.created_date = time.strftime("%H:%M:%S, %d/%m/%Y")
        self.name = name
        self.description = description
        self.tasks = []
        self.categories = []

    