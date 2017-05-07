#ifndef _USER_H_
#define _USER_H_

#include <stdio.h>
#include <QString>
#include <QList>
#include "Book.h"

class User
{
public:
    User(QString userName);
	QString const UserName;
    int UserId;
    QList<Book*> BorrowedBooks;
    QString toString(QString sep="\n") const;
private:
    static int _userId;
};

#endif
