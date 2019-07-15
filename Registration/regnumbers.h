#ifndef REGNUMBERS_H
#define REGNUMBERS_H

#include <QAbstractListModel>
#include <QStringList>

class RegNumbers : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit RegNumbers(QObject *parent = 0);

    // must provide implementation of these functions
    int rowCount(const QModelIndex &) const;
    QVariant data(const QModelIndex &index, int role) const;

    // well-behaved models include this function
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;

    // editable models need these functions
    bool setData(const QModelIndex &index, const QVariant &value, int role);
    Qt::ItemFlags flags(const QModelIndex &index) const;
    bool removeRows(int row, int count, const QModelIndex &parent);

    // our own add function
    void add(QString r);


signals:

public slots:

private:
    QStringList regNumbers;
};

#endif // REGNUMBERS_H
