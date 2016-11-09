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
    deleteProjectButton= ui->deleteProjectButton;

    if (ProjectUtils::Instance()->get_projects().empty()){
        ProjectUtils::Instance()->add_project(Project());
    }
    ProjectUtils::Instance()->open_project(ProjectUtils::Instance()->get_projects()[0].get_name());
    m_project = ProjectUtils::Instance()->get_open_project();

    projectListView = ui->projectsList;
    projectModel = new ProjectListModel(ProjectUtils::Instance()->get_projects());
    projectListView->setModel(projectModel);
    newTaskButton = ui->newTaskButton;

    projectNameLabel = ui->projectNameLabel;

    //Connections
    connect(newProjectButton, SIGNAL (released()), this, SLOT(onNewProjectButtonClick()));
    connect(deleteProjectButton, SIGNAL(released()), this, SLOT(onDeleteProjectButtonClick()));
    connect(newTaskButton, SIGNAL(released()), this, SLOT(onNewTaskButtonClicked()));

    projectNameLabel->setText(QString::fromStdString(m_project.get_name()));

}

void MainWindow::centerAndResize()
{
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
    qDebug() << "New Project Button";
    Project newProject("New Project", "");
    projectModel->addProject(newProject, Qt::EditRole);
}

void MainWindow::onDeleteProjectButtonClick()
{
    qDebug() << "Delete Project Button";
    if(projectListView->selectionModel()->selectedIndexes().isEmpty())
        return;
    projectModel->deleteProject(projectListView->selectionModel()->selectedIndexes().first(), Qt::EditRole);
}

void MainWindow::onNewTaskButtonClicked()
{
    qDebug() << "Add New Task Button";
    //ProjectUtils::Instance()->open_task(Task(ProjectUtils::Instance()->get_open_project().assign_ticket()));
    taskDialog = new TaskDialog();
    taskDialog->show();
}
