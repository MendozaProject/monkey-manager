#ifndef TASKDIALOG_H
#define TASKDIALOG_H
#pragma once

#include <QDialog>
#include "task.h"
#include "ui_taskdialog.h"
#include "projectutils.h"

namespace Ui {
class TaskDialog;
}
Q_DECLARE_METATYPE(Task)//might not be needed
class TaskDialog : public QDialog
{
    Q_OBJECT

signals:
    void task_add(Task task);

public:
    explicit TaskDialog(QWidget *parent = 0);
    ~TaskDialog();
    Task getTask(Task task);

private slots:
    void on_buttonBox_accepted();

private:
    Task m_task;
    Ui::TaskDialog *ui;
    QDialogButtonBox *taskDialogAccept;
};

#endif // taskdialog_H
