#include "subjectlistitem.h"

SubjectListItem::SubjectListItem(QObject *parent):SubListedListItem(parent)
{

}

SubjectListItem::~SubjectListItem()
{

}

int SubjectListItem::id() const
{

}

QVariant SubjectListItem::data(int role) const
{
    switch (role)
    {
    case subjectId :
        return this->id();
    case subjectName :
        return this->room->getRoomName();
    default :
        return QVariant();
    }
}

QHash<int, QByteArray> SubjectListItem::roleNames() const
{
    QHash<int, QByteArray>  roles;

    roles[subjectId]       = "subjectId";
    roles[subjectName]     = "subjectName";

    return roles;
}

Models::ListModel *SubjectListItem::submodel() const
{
    return this->room->getRoomPluginsModel();
}

