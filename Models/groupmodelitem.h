#ifndef GROUPMODELITEM_H
#define GROUPMODELITEM_H

#include "SubListedListItem.h"
#include "ListModel.h"

class GroupModelItem : public Models::SubListedListItem
{
    Q_OBJECT
public:
    enum GroupModelItemRoles
    {
       groupId  =   Qt::UserRole + 1,
       groupNameRole
    };

    explicit GroupModelItem(QObject* parent = 0);
    int id() const;
    QVariant data(int role) const;
    QHash<int, QByteArray> roleNames() const;
    Models::ListModel*  submodel()  const;
private:
    int _id;
    static int g_id;
    QString groupName;
    Models::ListModel* settingsListModel;
};

#endif
