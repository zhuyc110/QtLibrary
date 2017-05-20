#ifndef _BOOK_MANAGER_H_
#define _BOOK_MANAGER_H_

#include "Book.h"
#include "User.h"
#include "BookStorage.h"
#include <QString>
#include <QList>
#include <QObject>

static const QString bookFileName = "books.dat";
static const QString userFileName = "users.dat";

class BookManager : public QObject
{
    Q_OBJECT
public:

    enum BorrowResult
    {
        Succeed,
        InputError,
        NotEnough
    };

    BookManager();
    void init();
    void AddBook(Book* book, int amount=1);
    void AddUser(User* user);
    Book* GetBook(QString bookTitle) const;
    User* GetUser(QString userName) const;
    void printAllBooks();
    void ShowBookInfo(Book book);

    BorrowResult borrowBook(QString book, QString user);
    void saveData();

signals:
    void onBookAdded(Book* book);

private:
    BookStorage* _bookStorage;
    QList<User*>* _users;
    void initBooks();
    void initUsers();
};

#endif
