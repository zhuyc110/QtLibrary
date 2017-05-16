#ifndef _USER_H_
#define _USER_H_

#include <stdio.h>
#include <QString>
#include <QList>
#include "Book.h"

class User
{
public:
    User();
    User(QString userName);
    QString UserName() const;
    int UserId;
    QList<Book*> BorrowedBooks;
    QString toString(QString sep="$") const;
private:
    static int _userId;
    QString _userName;
};

#endif
