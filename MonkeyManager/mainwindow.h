#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#pragma once

#include <QMainWindow>
#include <QPushButton>
#include <QListView>
#include <QFrame>
#include <QBoxLayout>
#include <QDesktopWidget>
#include <QLabel>
#include <QPalette>
#include <QFontDatabase>
#include <QFont>
#include <QPushButton>

#include "projectlistmodel.h"
#include "ui_mainwindow.h"
#include "taskwidget.h"
#include "taskdialog.h"
#include "project.h"
#include "Json_utils.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief Constructor
     * @param parent : QT default
     */
    explicit MainWindow(QWidget *parent = 0);

    /**
     * @brief returns the instance of MainWindow
     * @return
     */
    static MainWindow *getInstance();

    /**
     * @brief Deconstructor
     */
    ~MainWindow();

    /**
     * @brief Formats the frame based on the window size
     */
    void centerAndResize();

    /**
     * @brief Removes, updates and restores all widgets in the task layouts for the selected project
     */
    void update_ui();

    /**
     * @brief Displays the detailed view of the selected task
     * @param task : currently selected task
     */
    void DisplayDetailedView(Task task);

    /**
     * @brief Accessor for the editingTask flag
     * @return editingTask : Boolean flag for whether the taskDialog is editing or creating a task
     */
    bool getEditFlag();

    /**
     * @brief Mutator for the editingTask flag
     * @param f : the passed boolean value
     */
    void setEditFlag(bool);

public slots:
    /**
     * @brief Adds the new or edited task widget to and updates the layout upon accepted taskDialog window
     */
    void onTaskDialogAccepted();

private slots:
    /**
     * @brief Creates a new project and adds it to the vector on button press
     */
    void onNewProjectButtonClick();

    /**
     * @brief Deletes the currently selected project and updates the layouts
     */
    void onDeleteProjectButtonClick();

    /**
     * @brief Instantiates the taskDialog window for creation of a new task
     */
    void onNewTaskButtonClicked();

    /**
     * @brief Instantiates the taskDialog window for the currently selected task
     */
    void onEditTaskButtonClicked();

    /**
     * @brief Calls update_ui when a project is selected
     */
    void item_selected_in_list();

    /**
     * @brief Clears the task widget layouts for update_ui
     * @param layout : the currently selected project's layout
     */
    void remove_all_widgets(QBoxLayout* layout);

    /**
     * @brief Signal for the save_all_projects function for Json_utils
     */
    void on_saveProjectsButton_clicked();

    /**
     * @brief Signal to save currently selected project
     */
    void on_saveCurrentProjectBotton_clicked();

    /**
     * @brief Hides whatever detailed view is opened
     */
    void on_closeTaskInfoButton_clicked();

    /**
     * @brief Deletes the currently selected task from the vector and updates the layouts
     */
    void onDeleteTaskButtonClicked();

    /**
     * @brief Shows/Hides the Project list view
     */
    void on_hideProjectsButton_clicked();

private:
    /**
     * @brief Sets all layout fonts
     */
    void load_fonts();

    Ui::MainWindow *ui;

    QPushButton *newProjectButton;
    QPushButton *deleteProjectButton;
    QPushButton *newTaskButton;
    QPushButton *editTaskButton;
    QPushButton *deleteTaskButton;

    QLabel *projectNameLabel;

    QListView *projectListView;
    ProjectListModel *projectModel;

    TaskDialog *taskDialog;

    QBoxLayout *toDoLayout;
    QBoxLayout *doingLayout;
    QBoxLayout *doneLayout;
    QBoxLayout *testingLayout;

    QWidget *taskDescriptionWidget;

    Project m_project;
    bool editingTask;
};

#endif // MAINWINDOW_H
