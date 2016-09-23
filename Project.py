from datetime import date


class Project:

    tasks = []
    categories = []

    def __init__(self, name="New Project", description="Add description"):
        self.created_date = date.strfdate("%x")
        self.name = name
        self.description = description

    def edit_Project(new_name, new_description):
        name = new_name
        description = new_description