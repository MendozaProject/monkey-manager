#ifndef PROJECTLISTMODEL_H
#define PROJECTLISTMODEL_H
#include <QAbstractListModel>
#include <vector>

#include "project.h"

class ProjectListModel : public QAbstractListModel{
    Q_OBJECT
public:
    explicit ProjectListModel(const vector<Project*>& projects, QObject* parent = 0)
        :QAbstractListModel(parent), projectsList(projects){}

    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation,
                             int role = Qt::DisplayRole) const;
    bool addProject(Project* &value, int role = Qt::EditRole);
    bool deleteProject(QModelIndex &index, int role = Qt::EditRole);
private:
    vector<Project*> projectsList;
};

#endif // PROJECTLISTMODEL_H
