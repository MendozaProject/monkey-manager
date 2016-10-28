#ifndef TASKDIALOG_H
#define TASKDIALOG_H

#include <QDialog>
#include "task.h"

namespace Ui {
class taskdialog;
}

class taskdialog : public QDialog, public Task
{
    Q_OBJECT


public:
    explicit taskdialog(QWidget *parent = 0);
    ~taskdialog();

private:
    Task m_task;
    Ui::taskdialog *ui;
};

#endif // taskdialog_H
