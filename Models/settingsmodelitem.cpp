#include "settingsmodelitem.h"

int SettingsModelItem::g_id = 0;

SettingsModelItem::SettingsModelItem(QObject *parent):ListItem(parent),
    _id(g_id++)
{
    settingsName = QString("Settings %1").arg(_id);
    settingsType = g_id % 3;
}

int SettingsModelItem::id() const
{
    return _id;
}

QVariant SettingsModelItem::data(int role) const
{
   switch (role)
   {
   case settingsId:
       return this->id();
   case settingsNameRole:
       return this->settingsName;
   case settingsTypeRole:
       return this->settingsType;
   default:
       return QVariant();
   }
}

QHash<int, QByteArray> SettingsModelItem::roleNames() const
{
    QHash<int, QByteArray>  roles;

    roles[settingsId]   = "settingsId";
    roles[settingsNameRole] = "settingsName";
    roles[settingsTypeRole] = "settingsType";

    return roles;
}

