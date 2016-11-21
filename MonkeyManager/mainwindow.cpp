#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QDesktopWidget>
#include <QLabel>
#include <QFontDatabase>
#include <QFont>
#include "taskwidget.h"
#include "taskdialog.h"
#include "project.h"
#include "Json_utils.h"

static MainWindow *s_pMainWindow = NULL;

MainWindow *MainWindow::getInstance()
{
    return s_pMainWindow;
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    load_fonts();

    s_pMainWindow = this;
    ui->setupUi(this);
    this->centerAndResize();
    newProjectButton = ui->newProjectButton;
    deleteProjectButton= ui->deleteProjectButton;

    ProjectUtils::Instance()->set_projects(load_all_projects());
    if (ProjectUtils::Instance()->get_projects().empty()){
        ProjectUtils::Instance()->add_project(Project());
    }
    ProjectUtils::Instance()->open_project(ProjectUtils::Instance()->get_projects()[0].get_name());
    m_project = ProjectUtils::Instance()->get_open_project();

    projectListView = ui->projectsList;
    projectModel = new ProjectListModel(ProjectUtils::Instance()->get_projects());
    projectListView->setModel(projectModel);
    newTaskButton = ui->newTaskButton;
    editTaskButton = ui->editTaskButton;

    toDoLayout = ui->Todo_List;
    doingLayout = ui->Doing_List;
    testingLayout = ui->Testing_List;
    doneLayout = ui->Done_List;

    projectNameLabel = ui->projectNameLabel;

    taskDescriptionWidget = ui->taskDescriptionWidget;
    taskDescriptionWidget->hide();

    //Connections
    connect(newProjectButton, SIGNAL (released()), this, SLOT(onNewProjectButtonClick()));
    connect(deleteProjectButton, SIGNAL(released()), this, SLOT(onDeleteProjectButtonClick()));
    connect(newTaskButton, SIGNAL(released()), this, SLOT(onNewTaskButtonClicked()));
    connect(editTaskButton, SIGNAL(released()), this, SLOT(onEditTaskButtonClicked()));
    connect(projectListView, SIGNAL(pressed(QModelIndex)), this, SLOT(item_selected_in_list()));

    projectNameLabel->setText(QString::fromStdString(m_project.get_name()));
}

void MainWindow::centerAndResize()
{
    // get the dimension available on this screen
    QSize availableSize = qApp->desktop()->availableGeometry().size();
    int width = availableSize.width();
    int height = availableSize.height();
    width *= 0.85; // 90% of the screen size
    height *= 0.85; // 90% of the screen size
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
    qDebug() << "Main Window New Project Button";
    Project newProject("New Project", "");
    projectModel->addProject(newProject, Qt::EditRole);
}

void MainWindow::onDeleteProjectButtonClick()
{
    qDebug() << "Main Window Delete Project Button";
    if(projectListView->selectionModel()->selectedIndexes().isEmpty())
        return;
    projectModel->deleteProject(projectListView->selectionModel()->selectedIndexes().first(), Qt::EditRole);
    remove_json_project(ProjectUtils::Instance()->get_open_project().get_name());
}

void MainWindow::onNewTaskButtonClicked()
{
    qDebug() << " Main Window Add New Task Button";
    QModelIndexList index = projectListView->selectionModel()->selectedIndexes();
    if(index.isEmpty())
        return;
    ProjectUtils::Instance()->set_current_project_index(index.first().row());
    setEditFlag(false);
    taskDialog = new TaskDialog();
    taskDialog->show();
}

void MainWindow::onEditTaskButtonClicked()
{
    qDebug() << " Main Window Edit Task Button";
    QModelIndexList index = projectListView->selectionModel()->selectedIndexes();
    if(index.isEmpty())
        return;
    ProjectUtils::Instance()->set_current_project_index(index.first().row());
    //ProjectUtils::Instance()->get_open_task();
    setEditFlag(true);
    taskDialog = new TaskDialog();
    taskDialog->show();
}

void MainWindow::onTaskDialogAccepted()
{
    TaskWidget *task = new TaskWidget;
    Task current = ProjectUtils::Instance()->get_open_task();
    if(current.get_status() == "To Do")
        ui->Todo_List->addWidget(task);
    else if(current.get_status() == "Doing")
        ui->Doing_List->addWidget(task);
    else if(current.get_status() == "Testing")
        ui->Testing_List->addWidget(task);
    else if(current.get_status() == "Done")
        ui->Done_List->addWidget(task);

    if( MainWindow::getInstance()->getEditFlag() ) {
        update_ui();
    }
}

void MainWindow::DisplayDetailedView(Task task) {
    ui->taskName->setText(QString::fromStdString(task.get_name()));
    ui->taskDueDate->setText(task.get_due_date().toString("MM/dd/yyyy"));
    ui->taskCreatedDate->setText(task.get_created_date().toString("MM/dd/yyyy"));
    ui->taskDescription->setText(QString::fromStdString(task.get_description()));
    taskDescriptionWidget->show();
}

bool MainWindow::getEditFlag()
{
    return editingTask;
}

void MainWindow::setEditFlag(bool f)
{
    editingTask = f;
}

void MainWindow::mousePressEvent(QMouseEvent *event){
    qDebug() << "Main Window Mouse";
}

void MainWindow::item_selected_in_list(){
    qDebug() << "Item Selected in QListView";
    update_ui();
}

void MainWindow::remove_all_widgets(QBoxLayout* layout){
    QLayoutItem *child;
    while ((child = layout->takeAt(0)) != 0) {
        delete child->widget();
        delete child;
    }
}

void MainWindow::on_saveProjectsButton_clicked()
{
    qDebug() << "Main Window Save All Button";
    //qDebug() << QString::fromStdString(to_string(ProjectUtils::Instance()->get_projects()[0].get_tasks().size()));
    //qDebug() << QString::fromStdString(to_string(ProjectUtils::Instance()->get_open_project().get_tasks().size()));

    save_all_projects(ProjectUtils::Instance()->get_projects());

}

void MainWindow::on_saveCurrentProjectBotton_clicked()
{
    qDebug() << "Main Window Save Button";
    if(projectListView->selectionModel()->selectedIndexes().isEmpty())
        return;
    //qDebug() << QString::fromStdString(to_string(ProjectUtils::Instance()->get_open_project().get_current_ticket()));
    //qDebug() << QString::fromStdString(to_string(ProjectUtils::Instance()->get_open_project().get_tasks()[0].get_task_number()));
    //qDebug() << QString::fromStdString(to_string(ProjectUtils::Instance()->get_open_project().get_tasks()[1].get_task_number()));
    create_json_project(ProjectUtils::Instance()->get_open_project());
}

void MainWindow::load_fonts(){
    QFontDatabase database;
    database.addApplicationFont(":/fonts/fonts/Roboto-Regular.ttf");
    database.addApplicationFont(":/fonts/fonts/Roboto-Medium.ttf");
    database.addApplicationFont(":/fonts/fonts/Roboto-Light.ttf");
    database.addApplicationFont(":/fonts/fonts/Roboto-Bold.ttf");
}

void MainWindow::on_pushButton_2_clicked(){
    taskDescriptionWidget->hide();
}

void MainWindow::update_ui(){
    QModelIndexList index = projectListView->selectionModel()->selectedIndexes();
    if(index.isEmpty())
        return;
    ProjectUtils* instance = ProjectUtils::Instance();
    instance->open_project(instance->get_projects().at(index.first().row()));
    remove_all_widgets(toDoLayout);
    remove_all_widgets(doingLayout);
    remove_all_widgets(testingLayout);
    remove_all_widgets(doneLayout);

    projectNameLabel->setText(QString::fromStdString(instance->get_open_project().get_name()));
    taskDescriptionWidget->hide();

    vector<Task> tasks = ProjectUtils::Instance()->get_projects().at(index.first().row()).get_tasks();
    for(int i = 0; i < tasks.size(); i++){
        ProjectUtils::Instance()->open_task(tasks.at(i));
        TaskWidget *task = new TaskWidget;
        if(tasks.at(i).get_status() == "To Do")
            ui->Todo_List->addWidget(task);
        else if(tasks.at(i).get_status() == "Doing")
            ui->Doing_List->addWidget(task);
        else if(tasks.at(i).get_status() == "Testing")
            ui->Testing_List->addWidget(task);
        else if(tasks.at(i).get_status() == "Done")
            ui->Done_List->addWidget(task);
    }
}
