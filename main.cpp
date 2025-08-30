#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    // ResizableWidget *centralWidget = new ResizableWidget(&w);
    // w.setCentralWidget(centralWidget);
    // w.resize(350, 250);
    w.show();
    return a.exec();
}
