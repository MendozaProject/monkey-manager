#include "projectlistmodel.h"

int ProjectListModel::rowCount(const QModelIndex& parent) const {
    return projectList.size();
}
QVariant ProjectListModel::data(const QModelIndex& index, int role) const {
    if (!index.isValid()) return QVariant();
    if (index.row() >= projectList.size()) return QVariant();
    if (role == Qt::DisplayRole) {
        return QVariant(projectsList.at(index.row())->get_name());
    } else {
        return QVariant();
    }
}
QVariant StringListModel::headerData(int section, Qt::Orientation orientation,
                                      int role) const{
     if (role != Qt::DisplayRole)
         return QVariant();

     if (orientation == Qt::Horizontal)
         return QString("Column %1").arg(section);
     else
         return QString("Row %1").arg(section);
 }
