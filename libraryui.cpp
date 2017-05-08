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

    addBookButton = new QPushButton(this);
    addBookButton->setText("Add a new book");
    connect(addBookButton, SIGNAL(clicked()), this, SLOT(onAddNewBook()));
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
    auto book = new Book("Moc", "dg");
    bookManager->AddBook(book);
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
