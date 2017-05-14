#ifndef LIBRARYUI_H
#define LIBRARYUI_H

#include <QMainWindow>
#include <QPushButton>
#include <QString>

#include "BookManager.h"
#include "ui_libraryui.h"

class LibraryUi : public QMainWindow
{
    Q_OBJECT
public:
    explicit LibraryUi(QWidget *parent = 0);
    ~LibraryUi();
    void printAllBooks();
    BookManager::BorrowResult borrowBook(QString book, QString user);
    User* GetUser(QString user) const;

signals:

private slots:
    void onQuit();
    void onAddNewBook();
    void onAddNewUser();
    void onPlainTextEditChanged();

private:
    Ui::LibraryUi* ui;
    BookManager* bookManager;
};

#endif // LIBRARYUI_H
