#ifndef TASKDIALOG_H
#define TASKDIALOG_H
#pragma once

#include <QDialog>
#include "task.h"

namespace Ui {
class TaskDialog;
}

class TaskDialog : public QDialog
{
    Q_OBJECT

public:
    explicit TaskDialog(QWidget *parent = 0);
    ~TaskDialog();

private slots:
    void on_buttonBox_accepted();

    //void on_lineEdit_editingFinished();

    //void on_dateEdit_userDateChanged(const QDate &date);

private:
    Task m_task;
    Ui::TaskDialog *ui;
};

#endif // taskdialog_H
