#include "libraryui.h"
#include <QCoreApplication>
#include <QString>
#include <QPushButton>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QRegExp>

LibraryUi::LibraryUi(QWidget *parent) : QMainWindow(parent), ui(new Ui::LibraryUi)
{
    ui->setupUi(this);

    bookManager = new BookManager();

    connect(ui->exitButton, SIGNAL(clicked()), this, SLOT(onQuit()));

    connect(ui->addBookButton, SIGNAL(clicked()), this, SLOT(onAddNewBook()));
    connect(ui->addUserButton, SIGNAL(clicked()), this, SLOT(onAddNewUser()));

    connect(ui->plainTextEditBookName, SIGNAL(textChanged()), this, SLOT(onBookPlainTextEditChanged()));
    connect(ui->plainTextEditAuthor, SIGNAL(textChanged()), this, SLOT(onBookPlainTextEditChanged()));

    connect(ui->plainTextEditUserName, SIGNAL(textChanged()), this, SLOT(onUserPlainTextEditChanged()));
}

LibraryUi::~LibraryUi()
{
    delete ui;
}

void LibraryUi::onQuit()
{
    bookManager->saveData();
    QCoreApplication::quit();
}

void LibraryUi::onAddNewBook()
{
    auto book = new Book(ui->plainTextEditBookName->toPlainText(), ui->plainTextEditAuthor->toPlainText());
    bookManager->AddBook(book);
}

void LibraryUi::onAddNewUser()
{
    auto user = new User(ui->plainTextEditUserName->toPlainText());
    bookManager->AddUser(user);
}

void LibraryUi::onBookPlainTextEditChanged()
{
    if(ui->plainTextEditBookName->toPlainText().isEmpty() || ui->plainTextEditAuthor->toPlainText().isEmpty())
    {
        ui->addBookButton->setEnabled(false);
    }
    else
    {
        ui->addBookButton->setEnabled(true);
    }
}

void LibraryUi::onUserPlainTextEditChanged()
{
    if(ui->plainTextEditUserName->toPlainText().isEmpty())
    {
        ui->addUserButton->setEnabled(false);
    }
    else
    {
        ui->addUserButton->setEnabled(true);
    }
}

void LibraryUi::printAllBooks()
{
    bookManager->printAllBooks();
}

BookManager::BorrowResult LibraryUi::borrowBook(QString book, QString user)
{
    return bookManager->borrowBook(book, user);
}

User* LibraryUi::GetUser(QString user) const
{
    return bookManager->GetUser(user);
}
