#include "regnumbers.h"
#include "registrationchecker.h"

RegNumbers::RegNumbers(QObject *parent) :
    QAbstractListModel(parent)
{
}

int RegNumbers::rowCount(const QModelIndex &) const
{
    return regNumbers.size();
}

QVariant RegNumbers::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if (index.row() >= regNumbers.size())
        return QVariant();

    if (role == Qt::DisplayRole)
        return regNumbers.at(index.row());

    return QVariant();
}

QVariant RegNumbers::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role != Qt::DisplayRole)
        return QVariant();

    if (orientation == Qt::Vertical)
        return QVariant();

    switch (section)
    {
    case 0: return QString("Registration number");  break;
    default: return QVariant();
    }

    return QVariant();
}

bool RegNumbers::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (index.isValid() && role == Qt::EditRole)
    {
        RegistrationChecker rc;
        int begin;
        QString temp = value.toString().toUpper();
        if (rc.validate(temp, begin)==QValidator::Acceptable)
        {
            regNumbers[index.row()]=temp;
            emit dataChanged(index, index);
            return true;
        }
    }
    return false;
}

Qt::ItemFlags RegNumbers::flags(const QModelIndex &index) const
{
    if (index.isValid())
        return (Qt::ItemIsEnabled | Qt::ItemIsSelectable | Qt::ItemIsEditable);
    else
        return 0;
}

void RegNumbers::add(QString r)
{
    int row = regNumbers.size();
    beginInsertRows(QModelIndex(), row+1, row+1);
    regNumbers.append(r);
    endInsertRows();
}

bool RegNumbers::removeRows(int row, int count, const QModelIndex &parent)
{
    Q_UNUSED(count);
    beginRemoveRows(parent, row, row);
    regNumbers.removeAt(row);
    endRemoveRows();
    return true;
}
