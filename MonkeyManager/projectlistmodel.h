#ifndef PROJECTLISTMODEL_H
#define PROJECTLISTMODEL_H

#include <QStringList>
#include <QAbstractListModel>
#include <QVariant>

using namespace std;

class ProjectListModel : public QAbstractListModel{
    Q_OBJECT
public:
    //temp values are strings while making sure code works
    ProjectListModel(const QStringList &strings, QObject *parent = 0):
        QAbstractListModel(parent), stringList(strings){}
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation,
                        int role = Qt::DisplayRole) const;

private:
    QStringList stringList;
};

#endif // PROJECTLISTMODEL_H
