#ifndef _BOOK_H_
#define _BOOK_H_
#include <QString>

class Book
{
public:
	Book(QString title, QString author);

	QString const BookTitle;
	QString const Author;
	void ShowBookInfo() const;
    bool operator == (const Book &otherBook);
};


#endif
