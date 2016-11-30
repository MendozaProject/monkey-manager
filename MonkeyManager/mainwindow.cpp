#include "mainwindow.h"

static MainWindow *s_pMainWindow = NULL;

///Public Functions
/**
 * @brief Constructor
 * @param parent : QT default
 */
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

    ProjectUtils::instance()->set_projects(load_all_projects());
    if (ProjectUtils::instance()->get_projects().empty()){
        ProjectUtils::instance()->add_project(Project());
    }
    ProjectUtils::instance()->set_open_project(ProjectUtils::instance()->get_projects()[0].get_name());
    m_project = ProjectUtils::instance()->get_open_project();

    projectListView = ui->projectsList;
    projectModel = new ProjectListModel(ProjectUtils::instance()->get_projects());
    projectListView->setModel(projectModel);
    projectListView->setCurrentIndex(projectModel->index(0,0));

    newTaskButton = ui->newTaskButton;
    editTaskButton = ui->editTaskButton;
    deleteTaskButton = ui->deleteTaskButton;

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
    connect(deleteTaskButton, SIGNAL(released()), this, SLOT(onDeleteTaskButtonClicked()));
    projectNameLabel->setText(QString::fromStdString(m_project.get_name()));

}

/**
 * @brief returns the instance of MainWindow
 * @return
 */
MainWindow *MainWindow::getInstance()
{
    return s_pMainWindow;
}

/**
 * @brief Deconstructor
 */
MainWindow::~MainWindow()
{
    delete ui;
}

/**
 * @brief Formats the frame based on the window size
 */
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

/**
 * @brief Removes, updates and restores all widgets in the task layouts for the selected project
 */
void MainWindow::update_ui(){
    QModelIndexList index = projectListView->selectionModel()->selectedIndexes();
    remove_all_widgets(toDoLayout);
    remove_all_widgets(doingLayout);
    remove_all_widgets(testingLayout);
    remove_all_widgets(doneLayout);
    if(ProjectUtils::instance()->get_projects().empty())
        return;

    projectNameLabel->setText(QString::fromStdString(ProjectUtils::instance()->get_open_project().get_name()));
    taskDescriptionWidget->hide();

    vector<Task> tasks = ProjectUtils::instance()->get_projects().at(index.first().row()).get_tasks();
    if(!tasks.empty()) {
        for(uint8_t i = 0; i < tasks.size(); i++){
            ProjectUtils::instance()->open_task(tasks.at(i));
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
}

/**
 * @brief Displays the detailed view of the selected task
 * @param task : currently selected task
 */
void MainWindow::DisplayDetailedView(Task task) {
    ui->taskName->setText(QString::fromStdString(task.get_name()));
    ui->taskDueDate->setText(task.get_due_date().toString("MM/dd/yyyy"));
    ui->taskCreatedDate->setText(task.get_created_date().toString("MM/dd/yyyy"));
    ui->taskDescription->setText(QString::fromStdString(task.get_description()));
    taskDescriptionWidget->show();
}

/**
 * @brief Accessor for the editingTask flag
 * @return editingTask : Boolean flag for whether the taskDialog is editing or creating a task
 */
bool MainWindow::getEditFlag()
{
    return editingTask;
}

/**
 * @brief Mutator for the editingTask flag
 * @param f : the passed boolean value
 */
void MainWindow::setEditFlag(bool f)
{
    editingTask = f;
}


///Slots
/**
 * @brief Adds the new or edited task widget to and updates the layout upon accepted taskDialog window
 */
void MainWindow::onTaskDialogAccepted()
{
    TaskWidget *task = new TaskWidget;
    Task current = ProjectUtils::instance()->get_open_task();
    if(current.get_status() == "To Do")
        ui->Todo_List->addWidget(task);
    else if(current.get_status() == "Doing")
        ui->Doing_List->addWidget(task);
    else if(current.get_status() == "Testing")
        ui->Testing_List->addWidget(task);
    else if(current.get_status() == "Done")
        ui->Done_List->addWidget(task);

    update_ui();
}

/**
 * @brief Creates a new project and adds it to the vector on button press
 */
void MainWindow::onNewProjectButtonClick()
{
    Project newProject("New Project", "");
    projectModel->add_project(newProject, Qt::EditRole);
}

/**
 * @brief Deletes the currently selected project and updates the layouts
 */
void MainWindow::onDeleteProjectButtonClick()
{
    QModelIndexList index = projectListView->selectionModel()->selectedIndexes();
    if(ProjectUtils::instance()->get_projects().empty())
        return;
    ProjectUtils::instance()->set_current_project_index(index.first().row());
    remove_json_project(ProjectUtils::instance()->get_projects().at(ProjectUtils::instance()->get_current_project_index()).get_name());
    projectModel->delete_project(projectListView->selectionModel()->selectedIndexes().first(), Qt::EditRole);
    projectListView->setCurrentIndex(projectModel->index(0,0));
    update_ui();
}

/**
 * @brief Instantiates the taskDialog window for creation of a new task
 */
void MainWindow::onNewTaskButtonClicked()
{
    QModelIndexList index = projectListView->selectionModel()->selectedIndexes();
    if(ProjectUtils::instance()->get_projects().empty())
        return;
    ProjectUtils::instance()->set_current_project_index(index.first().row());
    setEditFlag(false);
    taskDialog = new TaskDialog();
    taskDialog->show();
}

/**
 * @brief Instantiates the taskDialog window for the currently selected task
 */
void MainWindow::onEditTaskButtonClicked()
{
    QModelIndexList index = projectListView->selectionModel()->selectedIndexes();
    if(ProjectUtils::instance()->get_projects().empty())
        return;
    ProjectUtils::instance()->set_current_project_index(index.first().row());
    //ProjectUtils::instance()->get_open_task();
    setEditFlag(true);
    taskDialog = new TaskDialog();
    taskDialog->show();
}

/**
 * @brief Calls update_ui when a project is selected
 */
void MainWindow::item_selected_in_list(){
    update_ui();
}

/**
 * @brief Clears the task widget layouts for update_ui
 * @param layout : the currently selected project's layout
 */
void MainWindow::remove_all_widgets(QBoxLayout* layout){
    QLayoutItem *child;
    while ((child = layout->takeAt(0)) != 0) {
        delete child->widget();
        delete child;
    }
}

/**
 * @brief Signal for the save_all_projects function for Json_utils
 */
void MainWindow::on_saveProjectsButton_clicked()
{
    if(ProjectUtils::instance()->get_projects().empty())
        return;
    save_all_projects(ProjectUtils::instance()->get_projects());
}

/**
 * @brief Signal to save currently selected project
 */
void MainWindow::on_saveCurrentProjectBotton_clicked()
{
    QModelIndexList index = projectListView->selectionModel()->selectedIndexes();
    if(ProjectUtils::instance()->get_projects().empty())
        return;
    ProjectUtils::instance()->set_current_project_index(index.first().row());
    create_json_project(ProjectUtils::instance()->get_projects().at(ProjectUtils::instance()->get_current_project_index()));
}

/**
 * @brief Hides whatever detailed view is opened
 */
void MainWindow::on_closeTaskInfoButton_clicked(){
    taskDescriptionWidget->hide();
}

/**
 * @brief Deletes the currently selected task from the vector and updates the layouts
 */
void MainWindow::onDeleteTaskButtonClicked()
{
    QModelIndexList index = projectListView->selectionModel()->selectedIndexes();
    if(ProjectUtils::instance()->get_projects().empty())
        return;
    ProjectUtils::instance()->set_current_project_index(index.first().row());
    string temp_name = ProjectUtils::instance()->get_open_task().get_name();
    vector<Task>::iterator temp_index = ProjectUtils::instance()->get_projects().at(index.first().row()).find_task_by_name(temp_name);
    ProjectUtils::instance()->get_projects().at(index.first().row()).remove_task(temp_index);

    update_ui();
}

/**
 * @brief Shows/Hides the Project list view
 */
void MainWindow::on_hideProjectsButton_clicked()
{
    if (ui->frame->isHidden()){
        ui->frame->show();
    } else {
        ui->frame->hide();
    }
}


///Other  functions
/**
 * @brief Sets all layout fonts
 */
void MainWindow::load_fonts(){
    QFontDatabase database;
    database.addApplicationFont(":/fonts/fonts/Roboto-Regular.ttf");
    database.addApplicationFont(":/fonts/fonts/Roboto-Medium.ttf");
    database.addApplicationFont(":/fonts/fonts/Roboto-Light.ttf");
    database.addApplicationFont(":/fonts/fonts/Roboto-Bold.ttf");
}

