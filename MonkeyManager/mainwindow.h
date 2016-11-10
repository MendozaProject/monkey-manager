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

private slots:
    void onNewProjectButtonClick();
    void onDeleteProjectButtonClick();
    void onNewTaskButtonClicked();
    void mousePressEvent(QMouseEvent *event);

private:
    Ui::MainWindow *ui;

    QPushButton *newProjectButton;
    QPushButton *deleteProjectButton;
    QPushButton *newTaskButton;

    QLabel *projectNameLabel;
    QFrame *toDoFrame;

    QListView *projectListView;
    ProjectListModel *projectModel;

    vector<Project> projectVector;
    TaskDialog *taskDialog;

    QBoxLayout *toDoLayout;
    QBoxLayout *doingLayout;
    QBoxLayout *doneLayout;
    QBoxLayout *testingLayout;

    Project m_project;
};

#endif // MAINWINDOW_H
