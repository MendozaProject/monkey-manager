#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#pragma once

#include <QMainWindow>
#include <QPushButton>
#include <QListView>
#include <QFrame>
#include <QBoxLayout>

#include "taskdialog.h"
#include "projectlistmodel.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void centerAndResize();
    void updateTaskInToDo();
    void updateTaskInDoing();
    void updateTaskInTesting();
    void updateTaskInToDone();
    void update_ui();
    void DisplayDetailedView(Task task);

    bool getEditFlag();
    void setEditFlag(bool);

    static MainWindow *getInstance();


public slots:
    void onTaskDialogAccepted();

private slots:
    void onNewProjectButtonClick();
    void onDeleteProjectButtonClick();
    void onNewTaskButtonClicked();
    void onEditTaskButtonClicked();
    void item_selected_in_list();
    void remove_all_widgets(QBoxLayout* layout);
    void mousePressEvent(QMouseEvent *event);

    void on_saveProjectsButton_clicked();

    void on_saveCurrentProjectBotton_clicked();

    void on_pushButton_2_clicked();

    void on_deleteTaskButton_clicked();

private:
    void load_fonts();

    Ui::MainWindow *ui;

    QPushButton *newProjectButton;
    QPushButton *deleteProjectButton;
    QPushButton *newTaskButton;
    QPushButton *editTaskButton;

    QLabel *projectNameLabel;
    QFrame *toDoFrame;

    bool editingTask;

    QListView *projectListView;
    ProjectListModel *projectModel;

    vector<Project> projectVector;
    TaskDialog *taskDialog;

    QBoxLayout *toDoLayout;
    QBoxLayout *doingLayout;
    QBoxLayout *doneLayout;
    QBoxLayout *testingLayout;

    QWidget *taskDescriptionWidget;

    Project m_project;
};

#endif // MAINWINDOW_H
