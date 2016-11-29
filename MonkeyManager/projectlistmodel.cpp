#include "projectlistmodel.h"

int ProjectListModel::rowCount(const QModelIndex& parent) const {
    return (int)m_projects_list.size();
}
QVariant ProjectListModel::data(const QModelIndex& index, int role) const {
    if (!index.isValid())
        return QVariant();
    if (index.row() >= m_projects_list.size())
        return QVariant();
    if (role == Qt::DisplayRole) {
        const Project &project = m_projects_list[index.row()];
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
bool ProjectListModel::setData(const QModelIndex &index, const QVariant &value, int role){
    if(!index.isValid())
        return false;
    if(role != Qt::EditRole)
        return false;
    Project &temp = m_projects_list[index.row()];
    string old_name= temp.get_name();
    if (!(value.toString().trimmed() == ""))
        temp.set_name(value.toString().trimmed().toStdString());
    if(project_exists(old_name))
    rename_project(old_name, temp.get_name());
    return true;
}
/**
 * @brief ProjectListModel::add_project Addes project to the end of m_projects_list
 *
 * @param value A refrence to the project that is going to be added
 * @param role Needs to be set to Qt::EditRole
 * @return true if the project was added or false if it fails.
 */
bool ProjectListModel::add_project(Project &value, int role){
    if(role == Qt::EditRole){
        m_projects_list.push_back(value);

        QModelIndex topLeft = QAbstractItemModel::createIndex(0,0);
        QModelIndex bottomRight = QAbstractItemModel::createIndex((rowCount() - 1), 1);
        emit dataChanged(topLeft, bottomRight);
        return true;
    }
    return false;
}
/**
 * @brief ProjectListModel::delete_project Removes the project at a given index
 * @param index Index of the project to be removed
 * @param role Needs to be set to Qt::EditRole
 * @return false if the project could not be deleted, true otherwise
 */
bool ProjectListModel::delete_project(QModelIndex &index, int role){
    if(index.isValid() && role == Qt::EditRole){
        m_projects_list.erase(m_projects_list.begin() + index.row());

        QModelIndex topLeft = QAbstractItemModel::createIndex(0,0);
        QModelIndex bottomRight = QAbstractItemModel::createIndex((rowCount() - 1), 1);
        emit dataChanged(topLeft, bottomRight);
        return true;
    }
    return false;
}
