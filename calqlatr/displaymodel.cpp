#include "displaymodel.h"

DisplayItem::DisplayItem()
{
    this->value = "";
    this->isOperator = false;
}

DisplayItem::DisplayItem(QString value, bool isOperator = false)
{
    this->value = value;
    this->isOperator = isOperator;
}

DisplayModel::DisplayModel(QObject *parent) :
    QAbstractListModel(parent)
{
}

DisplayModel::DisplayModel(QList<DisplayItem> &items, QObject *parent) :
    QAbstractListModel(parent)
{
    this->items = QList<DisplayItem>(items);
}

int DisplayModel::rowCount(const QModelIndex &parent) const
{
    if(parent.isValid())
    {
        return 0;
    }
    return this->items.size();
}

QVariant DisplayModel::data(const QModelIndex &index, int role) const
{
    if (index.row() < 0
        || index.row() > this->items.size())
    {
        return QVariant();
    }
    switch (role)
    {
        case kDisplayRoleValue:
        case Qt::DisplayRole:
        case Qt::EditRole:
            return this->items[index.row()].value;
        case kDisplayRoleIsOperator:
            return this->items[index.row()].isOperator;
        case Qt::ToolTipRole:
            return (this->items[index.row()].isOperator)
                       ? QVariant(QString("Operator"))
                       : QVariant(QString("Number"));
        default:
            return QVariant();
    }
}

QHash<int, QByteArray> DisplayModel::roleNames() const
{
     QHash<int, QByteArray> roles;
     roles[kDisplayRoleValue] = "value";
     roles[kDisplayRoleIsOperator] = "isOperator";
     return roles;
}
