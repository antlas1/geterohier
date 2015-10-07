#include "groupmodelitem.h"
#include "settingsmodelitem.h"

int GroupModelItem::g_id = 0;

GroupModelItem::GroupModelItem(QObject *parent):SubListedListItem(parent),
    _id(g_id++)
{
    groupName = QString("Group %1").arg(_id);
    settingsListModel = new Models::ListModel(new SettingsModelItem());
    //DEBUG
    settingsListModel->appendRow(new SettingsModelItem());
    settingsListModel->appendRow(new SettingsModelItem());
    settingsListModel->appendRow(new SettingsModelItem());
    settingsListModel->appendRow(new SettingsModelItem());
    settingsListModel->appendRow(new SettingsModelItem());
    settingsListModel->appendRow(new SettingsModelItem());
}

int GroupModelItem::id() const
{
    return _id;
}

QVariant GroupModelItem::data(int role) const
{
    switch (role)
    {
    case groupId:
        return this->id();
    case groupNameRole:
        return this->groupName;
    default:
        return QVariant();
    }
}

QHash<int, QByteArray> GroupModelItem::roleNames() const
{
    QHash<int, QByteArray>  roles;

    roles[groupId]   = "groupId";
    roles[groupNameRole] = "groupName";

    return roles;
}

Models::ListModel *GroupModelItem::submodel() const
{
    return settingsListModel;
}

