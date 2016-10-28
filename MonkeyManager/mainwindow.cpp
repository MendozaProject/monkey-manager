#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QDesktopWidget>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->centerAndResize();
    newProjectButton = ui->newProjectButton;
    projectListView = ui->projectsList;
    model = new QStringListModel(projectListView);
    model->setStringList(list);
    projectListView->setModel(model);

    //Connections
    connect(newProjectButton, SIGNAL (released()), this, SLOT(onNewProjectButtonClick()));
}

void MainWindow::centerAndResize() {
    // get the dimension available on this screen
    QSize availableSize = qApp->desktop()->availableGeometry().size();
    int width = availableSize.width();
    int height = availableSize.height();
    qDebug() << "Available dimensions " << width << "x" << height;
    width *= 0.85; // 90% of the screen size
    height *= 0.85; // 90% of the screen size
    qDebug() << "Computed dimensions " << width << "x" << height;
    QSize newSize( width, height );

    setGeometry(
        QStyle::alignedRect(
            Qt::LeftToRight,
            Qt::AlignCenter,
            newSize,
            qApp->desktop()->availableGeometry()
        )
    );
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onNewProjectButtonClick()
{
    qDebug() << "Button";
    list.append("Project");
    model->setStringList(list);
}
