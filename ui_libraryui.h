/********************************************************************************
** Form generated from reading UI file 'libraryui.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LIBRARYUI_H
#define UI_LIBRARYUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LibraryUi
{
public:
    QWidget *centralwidget;
    QPushButton *exitButton;
    QPushButton *addBookButton;
    QPlainTextEdit *plainTextEditBookName;
    QLabel *lableBookName;
    QPlainTextEdit *plainTextEditAuthor;
    QLabel *lableAuthor;
    QPushButton *addUserButton;
    QLabel *label;
    QPlainTextEdit *plainTextEditUserName;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *LibraryUi)
    {
        if (LibraryUi->objectName().isEmpty())
            LibraryUi->setObjectName(QStringLiteral("LibraryUi"));
        LibraryUi->resize(480, 320);
        centralwidget = new QWidget(LibraryUi);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        exitButton = new QPushButton(centralwidget);
        exitButton->setObjectName(QStringLiteral("exitButton"));
        exitButton->setGeometry(QRect(390, 230, 85, 29));
        addBookButton = new QPushButton(centralwidget);
        addBookButton->setObjectName(QStringLiteral("addBookButton"));
        addBookButton->setEnabled(false);
        addBookButton->setGeometry(QRect(10, 10, 85, 29));
        plainTextEditBookName = new QPlainTextEdit(centralwidget);
        plainTextEditBookName->setObjectName(QStringLiteral("plainTextEditBookName"));
        plainTextEditBookName->setGeometry(QRect(200, 10, 151, 31));
        plainTextEditBookName->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        lableBookName = new QLabel(centralwidget);
        lableBookName->setObjectName(QStringLiteral("lableBookName"));
        lableBookName->setEnabled(true);
        lableBookName->setGeometry(QRect(110, 10, 81, 21));
        plainTextEditAuthor = new QPlainTextEdit(centralwidget);
        plainTextEditAuthor->setObjectName(QStringLiteral("plainTextEditAuthor"));
        plainTextEditAuthor->setGeometry(QRect(200, 50, 151, 31));
        plainTextEditAuthor->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        lableAuthor = new QLabel(centralwidget);
        lableAuthor->setObjectName(QStringLiteral("lableAuthor"));
        lableAuthor->setGeometry(QRect(110, 50, 81, 21));
        addUserButton = new QPushButton(centralwidget);
        addUserButton->setObjectName(QStringLiteral("addUserButton"));
        addUserButton->setGeometry(QRect(10, 120, 85, 29));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(110, 120, 81, 21));
        plainTextEditUserName = new QPlainTextEdit(centralwidget);
        plainTextEditUserName->setObjectName(QStringLiteral("plainTextEditUserName"));
        plainTextEditUserName->setGeometry(QRect(200, 120, 151, 31));
        plainTextEditUserName->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        LibraryUi->setCentralWidget(centralwidget);
        menubar = new QMenuBar(LibraryUi);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 480, 26));
        LibraryUi->setMenuBar(menubar);
        statusbar = new QStatusBar(LibraryUi);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        LibraryUi->setStatusBar(statusbar);

        retranslateUi(LibraryUi);

        QMetaObject::connectSlotsByName(LibraryUi);
    } // setupUi

    void retranslateUi(QMainWindow *LibraryUi)
    {
        LibraryUi->setWindowTitle(QApplication::translate("LibraryUi", "Library", Q_NULLPTR));
        exitButton->setText(QApplication::translate("LibraryUi", "Quit", Q_NULLPTR));
        addBookButton->setText(QApplication::translate("LibraryUi", "Add book", Q_NULLPTR));
        lableBookName->setText(QApplication::translate("LibraryUi", "Book name", Q_NULLPTR));
        lableAuthor->setText(QApplication::translate("LibraryUi", "Author", Q_NULLPTR));
        addUserButton->setText(QApplication::translate("LibraryUi", "Add user", Q_NULLPTR));
        label->setText(QApplication::translate("LibraryUi", "User name", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class LibraryUi: public Ui_LibraryUi {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LIBRARYUI_H
