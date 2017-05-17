#include "BookManager.h"
#include "Book.h"
#include <QMessageBox>
#include <QString>
#include <vector>
#include <algorithm>
#include <QTextStream>
#include <QFile>
using namespace std;

QTextStream cout(stdout);

BookManager::BookManager()
{
    _bookStorage = new BookStorage();
    _users = new QList<User*>();
    cout<<"=== Starting recovering books ==="<<endl;
    initBooks();
    cout<<"=== Starting recovering users ==="<<endl;
    initUsers();
}

void BookManager::initBooks()
{
    auto file = new QFile(bookFileName);
    if(!file->exists())
    {
        cout<<QString("Book file %1 does not exist. Creating a new one...").arg(bookFileName)<<endl;
        if(!file->open(QIODevice::ReadWrite))
        {
            cout<<"Can not create book data file."<<endl;
            return;
        }
    }
    else if(!file->open(QIODevice::ReadOnly))
    {
        cout<<"Can not read file."<<endl;
        return;
    }

    QTextStream fileContent(file);
    while(!fileContent.atEnd())
    {
        auto oneLine = fileContent.readLine();
        QRegExp bookReg(QString("(\\w*)\\s*:\\s*(\\w*)"));
        auto pos = bookReg.indexIn(oneLine);
        if(pos > -1)
        {
            auto bookTitle = bookReg.cap(1);
            auto auther = bookReg.cap(2);
            auto book = new Book(bookTitle, auther);
            AddBook(book);
        }
    }
    file->close();
    delete file;
}

void BookManager::initUsers()
{
    auto file = new QFile(userFileName);
    if(!file->exists())
    {
        cout<<QString("User file %1 does not exist. Creating a new one...").arg(userFileName)<<endl;
        if(!file->open(QIODevice::ReadWrite))
        {
            cout<<"Can not create user data file."<<endl;
            return;
        }
    }
    else if(!file->open(QIODevice::ReadOnly))
    {
        cout<<"Can not read user file."<<endl;
        return;
    }

    QTextStream fileContent(file);

    while(!fileContent.atEnd())
    {
        auto oneLine = fileContent.readLine();
        QRegExp userReg(QString("(\\w+)\\$Book \\d+ : (\\w+)"));
        auto pos = userReg.indexIn(oneLine);
        if(pos > -1)
        {
            auto username = userReg.cap(1);
            auto bookTitle = userReg.cap(2);
            auto user = new User(username);
            AddUser(user);
            auto book = GetBook(bookTitle);
            user->BorrowedBooks.append(book);
        }
        else
        {
            cout<<QString("Can not determine %1").arg(oneLine)<<endl;
        }
    }

}

void BookManager::ShowBookInfo(Book book)
{
	QMessageBox::information(NULL, QString("Book: %1").arg(book.BookTitle),QString("Author: %2").arg(book.Author));
}

void BookManager::AddBook(Book* book, int amount /*= 1*/)
{
    _bookStorage->BookStorages[book->BookTitle] += amount;

    auto index = _bookStorage->AllBooks->indexOf(book);
    {
        if(index == -1)
        {
            _bookStorage->AllBooks->append(book);
            cout<<QString("Adding book: %1").arg(book->BookTitle)<<endl;
        }
    }
}

void BookManager::AddUser(User *user)
{
    auto index = GetUser(user->UserName());
    if(index == nullptr)
    {
        _users->append(user);
        cout<<QString("Adding user: %1").arg(user->UserName())<<endl;
    }
    else
    {
        cout<<QString("User already exists!").arg(user->UserName())<<endl;
    }
}

User* BookManager::GetUser(QString userName) const
{
    for(auto i = 0; i < _users->size(); i++)
    {
        if(_users->at(i)->UserName() == userName)
        {
            return _users->at(i);
        }
    }

    cout<<QString("Can not find user: %1").arg(userName)<<endl;
    return nullptr;
}

Book* BookManager::GetBook(QString bookTitle) const
{
    for(auto i = 0; i < _bookStorage->AllBooks->size(); i++)
    {
        if(_bookStorage->AllBooks->at(i)->BookTitle == bookTitle)
        {
            return _bookStorage->AllBooks->at(i);
        }
    }

    cout<<"GetBook: null ptr"<<endl;
	return nullptr;
}

void BookManager::printAllBooks()
{
    for(auto i = 0; i < _bookStorage->AllBooks->size(); i++)
    {
        auto book = _bookStorage->AllBooks->at(i);
        cout<<QString("Book: %1, Author: %2, Amount: %3").arg(book->BookTitle).arg(book->Author).arg(_bookStorage->BookStorages.value(book->BookTitle))<<endl;
    }
}

BookManager::BorrowResult BookManager::borrowBook(QString book, QString user)
{
    auto bookPtr = GetBook(book);
    if(bookPtr == nullptr)
    {
        cout<<QString("Can not find book %1").arg(book)<<endl;
        return BorrowResult::InputError;
    }

    auto userPtr= GetUser(user);
    if(userPtr == nullptr)
    {
        cout<<QString("Can not find user %1").arg(user)<<endl;
        return BorrowResult::InputError;
    }

    auto storage = _bookStorage->BookStorages.value(bookPtr->BookTitle);
    if(storage <= 0)
    {
        cout<<QString("Not enough [%1] in storage").arg(book)<<endl;
        return BorrowResult::NotEnough;
    }

    for(auto i = 0; i< userPtr->BorrowedBooks.size(); i++)
    {
        if(userPtr->BorrowedBooks.at(i)->BookTitle == bookPtr->BookTitle)
        {
            cout<<QString("Book %1 is already borrowed by user %2").arg(bookPtr->BookTitle).arg(userPtr->UserName())<<endl;
            return BorrowResult::InputError;
        }
    }

    userPtr->BorrowedBooks.append(bookPtr);
    _bookStorage->BookStorages[bookPtr->BookTitle] = storage - 1;
    cout<<QString("[%1] borrowed book [%2]").arg(user).arg(book)<<endl;
    return BorrowResult::Succeed;
}

void BookManager::saveData()
{
    auto bookFile = new QFile(bookFileName);
    if(!bookFile->open(QIODevice::WriteOnly|QIODevice::Text))
    {
        cout<<"Can not save book file."<<endl;
        return;
    }
    QTextStream bookOut(bookFile);
    for(auto i = 0; i < _bookStorage->AllBooks->size(); i++)
    {
        auto book = _bookStorage->AllBooks->at(i);
        bookOut << QString("%1 : %2").arg(book->BookTitle).arg(book->Author)<<"\n";
    }
    bookFile->close();
    delete bookFile;

    auto userFile = new QFile(userFileName);
    if(!userFile->open(QIODevice::WriteOnly|QIODevice::Text))
    {
        cout<<"Can not save user file."<<endl;
        return;
    }
    QTextStream userOut(userFile);
    for(auto i = 0; i < _users->size(); i++)
    {
        auto user = _users->at(i);
        userOut << user->toString()<<"\n";
    }
    userFile->close();
    delete userFile;
}
