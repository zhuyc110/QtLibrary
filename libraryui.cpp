#include "libraryui.h"
#include <QCoreApplication>
#include <QString>
#include <QPushButton>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QRegExp>

LibraryUi::LibraryUi(QWidget *parent) : QMainWindow(parent)
{
    bookManager = new BookManager();
    exitButton = new QPushButton(this);
    exitButton->setText(QString("Quit"));
    connect(exitButton, SIGNAL(clicked()), this, SLOT(onQuit()));
}

void LibraryUi::onQuit()
{
    QCoreApplication::quit();
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
