#include "Book.h"
#include <QString>
#include <QTextStream>
#include <stdio.h>
#include <QInputDialog>
#include <QApplication>

Book::Book(QString title, QString author):BookTitle(title), Author(author)
{
}

void Book::ShowBookInfo() const
{
	QTextStream cout(stdout);
    cout<<QString("Book is %1, author is %2.").arg(BookTitle).arg(Author)<<endl;
}

bool Book::operator==(const Book &otherBook)
{
	QTextStream cout(stdout);
    //cout<<QString("Comparing book: %1 to book: %2").arg(BookTitle).arg( otherBook.BookTitle)<<endl;

	return BookTitle == otherBook.BookTitle;
}

