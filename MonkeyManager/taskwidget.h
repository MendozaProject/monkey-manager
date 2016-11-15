#ifndef TASKWIDGET_H
#define TASKWIDGET_H

#include <QWidget>
#include <QLabel>

namespace Ui {
class TaskWidget;
}

class TaskWidget : public QWidget
{
    Q_OBJECT

public:
    explicit TaskWidget(QWidget *parent = 0);
    ~TaskWidget();
//    QLabel *name;
//    QLabel *date;
private:
    Ui::TaskWidget *ui;
};

#endif // TASKWIDGET_H
