#ifndef CALCLATR_DISPLAYMODEL_H
#define CALCLATR_DISPLAYMODEL_H

#include <QAbstractListModel>

class DisplayModel : public QAbstractListModel
{
    Q_OBJECT
public:
    enum DisplayRoles {
        DISPLAY_ROLE_DATA = Qt::UserRole + 1,
        DISPLAY_ROLE_TYPE
    };

    explicit DisplayModel(QObject *parent = 0);

signals:

public slots:


    // QAbstractItemModel interface
public:
    QModelIndex sibling(int row, int column, const QModelIndex &idx) const;
    int rowCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role);
    bool insertRows(int row, int count, const QModelIndex &parent);
    bool removeRows(int row, int count, const QModelIndex &parent);
    Qt::ItemFlags flags(const QModelIndex &index) const;
    QHash<int, QByteArray> roleNames() const;
};

#endif // CALCLATR_DISPLAYMODEL_H
