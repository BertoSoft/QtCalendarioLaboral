#include "mainwindow.h"

#include <QApplication>
#include <QIcon>

#include "funcaux.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    w.setWindowTitle(FuncAux().getAppame());
    w.setWindowIcon(QIcon(":/Imagenes/icono.png"));
    w.showMaximized();
    w.show();

    return a.exec();
}
