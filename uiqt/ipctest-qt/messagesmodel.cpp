#include "messagesmodel.h"

#include "TestBase.h"

MessagesModel::MessagesModel(ipctest::TestBase& testBase, QObject *parent)
    : QAbstractTableModel(parent)
    , testBase_(testBase)
{

}

int MessagesModel::rowCount(const QModelIndex& /*parent*/) const
{
    return testBase_.messageList().size();
}

int MessagesModel::columnCount(const QModelIndex& /*parent*/) const
{
    return 1;
}

QVariant MessagesModel::data(const QModelIndex &index, int /*role*/) const
{
    unsigned int row = index.row();
    if (row < testBase_.messageList().size())
    {
        ipctest::Message* msg = testBase_.messageList()[row];
        return QString(msg->getName().c_str());
    }

    return QVariant();
}
