#ifndef DEVICEMODELITEM_H
#define DEVICEMODELITEM_H

#include "SubListedListItem.h"
#include "ListModel.h"

class DeviceModelItem : public Models::SubListedListItem
{
    Q_OBJECT
public:
    enum GroupModelItemRoles
    {
       deviceId  =   Qt::UserRole + 1,
       deviceNameRole
    };

    DeviceModelItem(QObject* parent = 0);
    int id() const;
    QVariant data(int role) const;
    QHash<int, QByteArray> roleNames() const;
    Models::ListModel*  submodel()  const;
private:
    int _id;
    static int g_id;
    QString deviceName;
    Models::ListModel* groupListModel;
};

#endif
