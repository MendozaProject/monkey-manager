#include "projectlistmodel.h"
#include <QString>
#include <string>

int ProjectListModel::rowCount(const QModelIndex& parent) const {
    return projectsList.size();
}
QVariant ProjectListModel::data(const QModelIndex& index, int role) const {
    if (!index.isValid())
        return QVariant();
    if (index.row() >= projectsList.size())
        return QVariant();
    if (role == Qt::DisplayRole) {
        string temp = projectsList.at(index.row())->get_name();
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
bool ProjectListModel::addProject(Project* &value, int role){
    if(role == Qt::EditRole){
        projectsList.push_back(value);

        QModelIndex topLeft = QAbstractItemModel::createIndex(0,0);
        QModelIndex bottomRight = QAbstractItemModel::createIndex((rowCount() - 1), 1);
        emit dataChanged(topLeft, bottomRight);
        return true;
    }
    return false;
}
