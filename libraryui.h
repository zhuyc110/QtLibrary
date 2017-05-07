#ifndef LIBRARYUI_H
#define LIBRARYUI_H

#include <QMainWindow>
#include <QPushButton>
#include <QString>

#include "BookManager.h"

class LibraryUi : public QMainWindow
{
    Q_OBJECT
public:
    explicit LibraryUi(QWidget *parent = 0);
    void printAllBooks();
    BookManager::BorrowResult borrowBook(QString book, QString user);
    User* GetUser(QString user) const;

signals:

private slots:
    void onQuit();

private:
    QPushButton* exitButton;
    BookManager* bookManager;
};

#endif // LIBRARYUI_H
