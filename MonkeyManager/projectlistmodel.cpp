#include "projectlistmodel.h"
#include <QString>
#include <string>
#include <projectutils.h>
#include "json_utils.h"
#include <QDebug>

int ProjectListModel::rowCount(const QModelIndex& parent) const {
    return projectsList.size();
}
QVariant ProjectListModel::data(const QModelIndex& index, int role) const {
    if (!index.isValid())
        return QVariant();
    if (index.row() >= projectsList.size())
        return QVariant();
    if (role == Qt::DisplayRole) {
        const Project &project = projectsList[index.row()];
        string temp = project.get_name();
        QString tempQ = QString::fromStdString(temp);
        return QVariant(tempQ);
    } else {
        return QVariant();
    }
}
QVariant ProjectListModel::headerData(int section, Qt::Orientation orientation,
                                      int role) const{
     if (role != Qt::DisplayRole)
         return QVariant();
     if (orientation == Qt::Horizontal)
         return QString("Column %1").arg(section);
     else
         return QString("Row %1").arg(section);
 }
Qt::ItemFlags ProjectListModel::flags(const QModelIndex &index) const{
    if(!index.isValid())
        return Qt::NoItemFlags;
    return Qt::ItemIsSelectable|Qt::ItemIsEditable|Qt::ItemIsEnabled;
}
bool ProjectListModel::addProject(Project &value, int role){
    if(role == Qt::EditRole){
        projectsList.push_back(value);

        QModelIndex topLeft = QAbstractItemModel::createIndex(0,0);
        QModelIndex bottomRight = QAbstractItemModel::createIndex((rowCount() - 1), 1);
        emit dataChanged(topLeft, bottomRight);
        return true;
    }
    return false;
}
bool ProjectListModel::deleteProject(QModelIndex &index, int role){
    if(index.isValid() && role == Qt::EditRole){
        projectsList.erase(projectsList.begin() + index.row());

        QModelIndex topLeft = QAbstractItemModel::createIndex(0,0);
        QModelIndex bottomRight = QAbstractItemModel::createIndex((rowCount() - 1), 1);
        emit dataChanged(topLeft, bottomRight);
        return true;
    }
    return false;
}
bool ProjectListModel::setData(const QModelIndex &index, const QVariant &value, int role){
    if(!index.isValid())
        return false;
    if(role != Qt::EditRole)
        return false;
    Project &temp = projectsList[index.row()];
    string old_name= temp.get_name();
    if (!(value.toString().trimmed() == ""))
        temp.set_name(value.toString().trimmed().toStdString());
    if(project_exists(old_name))
    rename_project(old_name, temp.get_name());
    return true;
}
