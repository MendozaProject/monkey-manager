#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#pragma once

#include <QMainWindow>
#include <QPushButton>

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

private:
    Ui::MainWindow *ui;
    QPushButton *newProjectButton;
};

#endif // MAINWINDOW_H
