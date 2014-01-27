#include "displaymodel.h"

//DisplayItem impl

DisplayItem::DisplayItem()
{
    this->value = "";
    this->isOperator = false;
}

DisplayItem::DisplayItem(QString value, bool isOperator)
{
    this->value = value;
    this->isOperator = isOperator;
}

//*****************DisplayModel impl*******************
//Constructors
DisplayModel::DisplayModel(QObject *parent) :
    QAbstractListModel(parent)
{
}
DisplayModel::DisplayModel(QList<DisplayItem> &items, QObject *parent) :
    QAbstractListModel(parent)
{
    this->items = QList<DisplayItem>(items);
}

//Members

void DisplayModel::Digit(QChar digit)
{
    if (0 < this->items.size() && !this->items[this->items.size() - 1].isOperator)
    { //Append the digit
        this->items[this->items.size() - 1].value.append(digit);
    }
    else
    { //Create a new number entry
        this->items[this->items.size()] = DisplayItem(QString(digit));
    }
    //TODO: Emit dataChanged()
}

void DisplayModel::Number(double number)
{
    if(0 < this->items.size() && !this->items[this->items.size() - 1].isOperator)
    { //Last item is a number, replace it
        this->items[this->items.size() - 1].value = QString::number(number);
    }
    else
    { //Create a new number entry
        this->items[this->items.size()] = DisplayItem(QString::number(number));
    }
    //TODO: Emit dataChanged()
}

void DisplayModel::Operator(QChar op)
{
    if(0 < this->items.size() && this->items[this->items.size() - 1].isOperator)
    { //Last item is an operator, replace it
        this->items[this->items.size() - 1].value = op;
    }
    else
    { //Create a new operator entry
        this->items[this->items.size()] = DisplayItem(QString(op), true);
    }
    //TODO: Emit dataChanged()
}

void DisplayModel::NewLine()
{
    //TODO: The newline registers as a number, Digit()
    //and Number() will replace the newline...
    this->items[this->items.size()] = DisplayItem();
    //TODO: Emit dataChanged()
}

void DisplayModel::Clear()
{
    this->items.clear();
    //TODO: Emit dataChanged()
}

//AbstractListModel interface

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
