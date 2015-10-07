#ifndef SETTINGSMODELITEM_H
#define SETTINGSMODELITEM_H

#include "ListItem.h"

class SettingsModelItem : public Models::ListItem
{
    Q_OBJECT
public:
    enum SettingsModelItemRoles
    {
       settingsId  =   Qt::UserRole + 1,
       settingsNameRole,
       settingsTypeRole
    };

    enum SettingsType{
        ST_CHECKBOX = 0,
        ST_LINEEDIT = 1,
        ST_SLIDER = 2,
    };

    explicit SettingsModelItem(QObject* parent = 0);
    int id() const;
    QVariant data(int role) const;
    QHash<int, QByteArray> roleNames() const;
private:
    int _id;
    static int g_id;
    QString settingsName;
    int settingsType;
};

#endif
