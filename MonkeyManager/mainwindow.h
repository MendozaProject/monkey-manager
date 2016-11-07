#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#pragma once

#include <QMainWindow>
#include <QPushButton>
#include <QListView>

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

private slots:
    void onNewProjectButtonClick();
    void onDeleteProjectButtonClick();
    void onNewTaskButtonClicked();

private:
    Ui::MainWindow *ui;

    QPushButton *newProjectButton;
    QPushButton *deleteProjectButton;
    QPushButton *newTaskButton;

    QLabel *projectNameLabel;

    QListView *projectListView;
    ProjectListModel *projectModel;

    vector<Project> projectVector;
    TaskDialog *taskDialog;

    Project m_project;
};

#endif // MAINWINDOW_H
