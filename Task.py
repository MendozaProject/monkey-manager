from datetime import date


class Task:

    def __init__(self, name="New Task", due_date=date.max, description="New Description"):
        self.name = name;
        self.due_date = due_date;
        self.description =  description;

    def edit_task(self, new_name, new_date, new_description):
        self.name = new_name
        self.due_date = new_date
        self.description = new_description
