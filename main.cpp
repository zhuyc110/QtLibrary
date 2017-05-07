#include "BookManager.h"
#include <QApplication>
#include "Book.h"
#include "libraryui.h"
#include <QTextStream>

int main(int argc, char* argv[])
{
    QTextStream cout(stdout);
    QApplication app(argc, argv);

    LibraryUi ui;
    ui.show();
    ui.printAllBooks();
    ui.borrowBook("World", "user1");
    ui.borrowBook("World", "user1");
    auto user = ui.GetUser("user1");
    cout<<user->toString()<<endl;
    return app.exec();
}
