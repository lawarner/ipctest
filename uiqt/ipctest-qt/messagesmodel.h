#ifndef MESSAGESMODEL_H
#define MESSAGESMODEL_H

#include <QAbstractTableModel>

namespace ipctest
{
class TestBase;
}

class MessagesModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    explicit MessagesModel(ipctest::TestBase& testBase, QObject *parent = 0);

    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;

signals:
    
public slots:

private:
    const ipctest::TestBase& testBase_;
};

#endif // MESSAGESMODEL_H
