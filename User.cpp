#include "User.h"
#include <QString>

int User::_userId = 1;

User::User(QString userName)
:UserName(userName)
{
    UserId = _userId;
    _userId++;
}

QString User::toString(QString sep) const
{
    QStringList list;
    list<<UserName;
    list<<QString::number(UserId);
    for(auto i = 0; i < BorrowedBooks.size(); i++)
    {
        list<< BorrowedBooks.at(i)->BookTitle;
    }
    return list.join(sep);
}
