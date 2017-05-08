#ifndef _BOOK_MANAGER_H_
#define _BOOK_MANAGER_H_

#include "Book.h"
#include "User.h"
#include "BookStorage.h"
#include <QString>
#include <QList>

static const QString bookFileName = "books.dat";

class BookManager
{
public:

    enum BorrowResult
    {
        Succeed,
        InputError,
        NotEnough
    };

    BookManager();
    void AddBook(Book* book, int amount=1);
    void AddUser(User* user);
    Book* GetBook(QString bookTitle) const;
    User* GetUser(QString user) const;
    void printAllBooks();
    void ShowBookInfo(Book book);

    BorrowResult borrowBook(QString book, QString user);
    void saveData();

private:
    BookStorage* _bookStorage;
    QList<User*>* _users;
    void initBooks();
    void initUsers();
};

#endif
