#ifndef PROJECTLISTMODEL_H
#define PROJECTLISTMODEL_H
#include <QAbstractListModel>
#include "Json_utils.h"

class ProjectListModel : public QAbstractListModel{
    Q_OBJECT
public:
    /**
     * @brief ProjectListModel Constructor.
     * @param projects Refrence to the project list in the singleton.
     * @param parent Parent object, defaults to 0.
     */
    explicit ProjectListModel(vector<Project>& projects, QObject* parent = 0)
        :QAbstractListModel(parent), m_projects_list(projects){
    }
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation,
                             int role = Qt::DisplayRole) const;
    Qt::ItemFlags flags(const QModelIndex &index) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role);
    /**
     * @brief add_project Adds a given project to the project list
     */
    bool add_project(Project &value, int role = Qt::EditRole);
    /**
     * @brief delete_project Deletes the project at a given index.
     */
    bool delete_project(QModelIndex &index, int role = Qt::EditRole);
private:
    vector<Project>& m_projects_list;
};

#endif // PROJECTLISTMODEL_H
