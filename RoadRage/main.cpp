#include <QtGui/QApplication>
#include "diagramwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DiagramWindow w;
    w.show();

    return a.exec();
}
