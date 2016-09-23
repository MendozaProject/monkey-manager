from datetime import date


class Task:

    name = ""
    description = ""
    due_date = date.max

    def __init__(self):
        pass

    def edit_task(new_name, new_date, new_description):
        name = new_name
        due_date = new_date
        description = new_description
