from datetime import date


class Project:

    def __init__(self, name="New Project", description="Add description"):
        self.created_date = date.strfdate("%x")
        self.name = name
        self.description = description
        self.tasks = []
        self.categories = []

    