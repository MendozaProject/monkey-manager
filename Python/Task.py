# Last Edited on 10/4/2016 by Brittany Dibble.
# Functions edited: __init__ and edit_task
from datetime import date
import time


class Task:

    def __init__(self, name="New Task", due_date=date.max,
                 description="New Description", id_number=0, is_complete=False,
                 status = 1):
        self.name = name
        self.due_date = due_date
        self.description = description
        self.id_number = id_number
        self.is_complete = is_complete
        self.created_date = time.strftime("%H:%M:%S, %d/%m/%Y")
        self.status = status


    def edit_task(self, name="New Name", due_date=date.max,
                  description="New Description", id_number=0, is_complete=False,
                  status = 1):
        self.name = name
        self.due_date = due_date
        self.description = description
        self.id_number = id_number
        self.is_complete = is_complete
        self.status = status

    def get_status(self):
        if self.status == 1:
            return "New"
        if self.status == 2:
            return "Doing"
        if self.status == 3:
            return "Done"
        if self.status == 4:
            return "Closed"
