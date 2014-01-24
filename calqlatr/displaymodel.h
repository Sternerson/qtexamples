#ifndef CALCLATR_DISPLAYMODEL_H
#define CALCLATR_DISPLAYMODEL_H

#include <QString>
#include <QAbstractListModel>
#include <QStringListModel>

#ifndef null
#ifdef nullptr
#define null nullptr
#else
#include <stddef.h>
#define null NULL
#endif // nullptr
#endif // null

class DisplayItem
{
public:
    DisplayItem();
    DisplayItem(QString value, bool isOperator);

    QString value;
    bool isOperator;
};

/**
 * @brief The DisplayModel class
 */
class DisplayModel : public QAbstractListModel
{
    Q_OBJECT
    Q_ENUMS(DisplayRoles)

public:
    /**
     * @brief The DisplayRoles enum
     */
    enum DisplayRoles {
        kDisplayRoleValue = Qt::UserRole,
        kDisplayRoleIsOperator
    };

    explicit DisplayModel(QObject *parent = 0);

    DisplayModel(QList<DisplayItem> &items, QObject *parent);

private:
    QList<DisplayItem> items;

signals:

public slots:


    // QAbstractItemModel interface
public:
    int rowCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    QHash<int, QByteArray> roleNames() const;
};

#endif // CALCLATR_DISPLAYMODEL_H
