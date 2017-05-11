#include "User.h"
#include <QString>

int User::_userId = 1;

User::User()
{
    UserId = _userId;
    _userId++;
}

User::User(QString userName)
:_userName(userName)
{
    UserId = _userId;
    _userId++;
}

QString User::toString(QString sep) const
{
    QStringList list;
    list<<UserName();
    for(auto i = 0; i < BorrowedBooks.size(); i++)
    {
        list<< QString("Book %1 : %2").arg(i).arg(BorrowedBooks.at(i)->BookTitle);
    }
    return list.join(sep);
}

QString User::UserName() const
{
    return _userName;
}
