from datetime import date


class Task:

    def __init__(self, name="New Task", due_date=date.max, description="New Description", id_number=0, is_complete=False):
        self.name = name
        self.due_date = due_date
        self.description = description
        self.id_number = id_number
        self.is_complete = is_complete

    def edit_task(self, name="New Name", due_date=date.max, description="New Description", id_number=0, is_complete=False):
        self.name = name
        self.due_date = due_date
        self.description = description
        self.id_number = id_number
        self.is_complete = is_complete
