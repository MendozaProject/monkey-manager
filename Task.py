from datetime import date


class Task:

    def __init__(self, name="New Task", due_date=date.max, description="New Description", id_number=0):
        self.name = name
        self.due_date = due_date
        self.description = description
        self.id = id_number
