#ifndef SUBJECTLISTITEM_H
#define SUBJECTLISTITEM_H

#include <QObject>
#include "SubListedListItem.h"

class SubjectListItem : public Models::SubListedListItem
{
    Q_OBJECT
public:
    enum SubjectItemRoles
    {
        subjectId  =   Qt::UserRole + 1,
        subjectName
    };
    SubjectListItem(QObject *parent = 0);
    ~SubjectListItem();

    int                     id()                const;
    QVariant                data(int role)      const;
    QHash<int, QByteArray>  roleNames()         const;

    Models::ListModel*      submodel()          const;
};

#endif // SUBJECTLISTITEM_H
