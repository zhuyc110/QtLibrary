#ifndef _BOOK_STORAGE_H_
#define _BOOK_STORAGE_H_

#include "Book.h"
#include <QList>
#include <QMap>
#include <QString>

class BookStorage
{
public:
    BookStorage();
    QMap<QString, int> BookStorages;
    QList<Book*>* AllBooks;
};


#endif
