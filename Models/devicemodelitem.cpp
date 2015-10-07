#include "devicemodelitem.h"
#include "SubListedListModel.h"
#include "groupmodelitem.h"

int DeviceModelItem::g_id = 0;

DeviceModelItem::DeviceModelItem(QObject *parent):SubListedListItem(parent),
    _id(g_id++)
{
    deviceName = QString("Device %1").arg(_id);
    groupListModel = new Models::SubListedListModel(new GroupModelItem());
    //DEBUG
    groupListModel->appendRow(new GroupModelItem());
    groupListModel->appendRow(new GroupModelItem());
}

int DeviceModelItem::id() const
{
    return _id;
}

QVariant DeviceModelItem::data(int role) const
{
    switch (role)
    {
    case deviceId:
        return this->id();
    case deviceNameRole:
        return this->deviceName;
    default:
        return QVariant();
    }
}

QHash<int, QByteArray> DeviceModelItem::roleNames() const
{
    QHash<int, QByteArray>  roles;

    roles[deviceId]   = "deviceId";
    roles[deviceNameRole] = "deviceName";

    return roles;
}

Models::ListModel *DeviceModelItem::submodel() const
{
    return groupListModel;
}

