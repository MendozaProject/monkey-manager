from ProjectUtils import ProjectUtils
from Task import Task
from datetime import date


def project_menu():

    project = ProjectUtils.opened_project
    print "----------------------------------------------"
    print "  " + project.name
    print "\n  " + project.description

    while (True):
        command = raw_input('\nProject--> ')
        command = command.strip()
        if command == 'back' or command == 'b':
            break
        elif command == 'help' or command == 'h':
            help_list()
        elif command == 'new' or command == 'n':
            new_task()
        elif command == 'list' or command == 'l':
            list_tasks()
        elif command == 'delete' or command == 'd':
            delete_task()
        elif command == 'edit' or command == 'e':
            edit_task()
        elif not project.find_task_by_name(command) == -1:
            index = ProjectUtils.find_project_by_name(command)
            view_task(index)
        elif command == 'clear':
            print "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"
            print "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"
            print "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"
        else:
            print "\nCommand or Project not recognized"


def new_task():
    print "________________________________________________________________"
    print "  NEW Task (Type 'cancel' to cancel)\n"

    name = ""
    description = ""

    while True:
        name = raw_input("Task Name:  ")
        name = name.strip()
        if name == 'cancel':
            return
        if not ProjectUtils.opened_project.find_task_by_name(name) == -1:
            print "\n   Task named '" + name + "' is already taken\n"
        elif len(name) < 2:
            print "\n   Task name must at least 2 character\n"
        elif not ProjectUtils.is_reserved_word(name):
            print "\n   Task name cannot be a reserved word\n"
        else:
            break

    while description == "":
        description = raw_input("\nDescription:   ")
        description = description.strip()
        if name == 'cancel':
            return

    ProjectUtils.opened_project.add_task(Task(name, date.max , description))

    print "\n  Success! Your new task '" + name + "' has been created!"


def delete_task():
    if not ProjectUtils.opened_project.tasks:
        print "\nError: Task List is empty"
        return

    print "________________________________________________________________"
    print "  DELETE PROJECT (Type 'cancel' to cancel)\n"
    while True:
        name = raw_input("Task Name:  ")
        name = name.strip()

        if name == 'cancel':
            return

        index = ProjectUtils.opened_project.find_task_by_name(name)

        if index == -1:
            print "Project named '" + name + "' not found"
        else:
            ProjectUtils.opened_project.remove_task(index)
            print "Project '" + name + "' was deleted"
            break


def edit_task():
    project = ProjectUtils.opened_project

    if not project.tasks:
        print "\nError: Task List is empty"
        return

    print "________________________________________________________________"
    print "  EDIT TASK (Type 'cancel' to cancel)\n"

    while True:
        name = raw_input("Task name:    ")
        name = name.strip()
        if name == 'cancel':
            return

        index = project.find_task_by_name(name)

        if index == -1:
            print "\nProject named '" + name + "' not found\n"
        else:
            break

    while True:
        new_name = raw_input("\nNew Task Name: ")
        new_name = new_name.strip()
        if new_name == 'cancel':
            return
        if not project.find_task_by_name(new_name) == -1:
            print "\nProject named '" + new_name + "' is already taken"
        elif len(new_name) < 2:
            print "\nProject name must be at least 2 characters"
        elif not ProjectUtils.is_reserved_word(new_name):
            print "\nProject name cannot be a reserved word"
        else:
            break

    while True:
        new_description = raw_input("\nNew Description:  ")
        new_description = new_description.strip()
        if new_description == 'cancel':
            return
        else:
            break

    while True:
        new_status = raw_input("\nCurrent Status (new/doing/done/closed):   ")
        new_status = new_status.lower()
        if new_status == "new":
            project.tasks[index].status = 1
            break
        elif new_status == "doing":
            project.tasks[index].status = 2
            break
        elif new_status == "done":
            project.tasks[index].status = 3
            break
        elif new_status == "closed":
            project.tasks[index].status = 4
            break
        elif new_status == "cancel":
            return
        else:
            print "\nInvalid status\n"

    project.tasks[index].name = new_name
    project.tasks[index].description = new_description

    print "\n  Success! '" + name + "' ---> '" + new_name + "'"


def help_list():
    print "________________________________________________________________"
    print "  PROJECT COMMANDS\n"

    print "  <project name>       View Project Details"
    #print "  'x' or 'exit'        Exit the program"
    print "  'b' or 'back'        Back to Main"
    print "  'l' or 'list'        Lists out all your tasks"
    print "  'e' or 'edit'        Edit a task"
    print "  'd' or 'delete'      Delete a task"
    print "  'n' or 'new '        Create a new task"
    print "  'clear'              Clear the screen"


def list_tasks():
    if not ProjectUtils.opened_project.tasks:
        print "\nError: Task List is empty"
        return
    print "\n  TASK LIST:\n"
    for task in ProjectUtils.opened_project.tasks:
        print "  " + task.name


def view_task(index):
    task = ProjectUtils.opened_project.tasks[index]
    print "________________________________________________________________"
    print "  " + task.name
    print "\n  Date Created:  " + str(task.created_date)
    print "\n  Date Due:      " + str(task.due_date)
    print "\n  Description:   " + task.description
    print "\n  Status:        " + task.get_status()

