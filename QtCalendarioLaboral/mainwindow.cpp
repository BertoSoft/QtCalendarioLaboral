#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QTimer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow){

    ui->setupUi(this);

    //
    // Instalamos un filtro de eventos en la aplicacion
    //
    qApp->installEventFilter(this);
    this->installEventFilter(this);

    //
    //Iniciamos la app
    //
    initReloj();

}

MainWindow::~MainWindow(){

    delete ui;
}

bool MainWindow::eventFilter(QObject *obj, QEvent *ev){

    //
    // Si se pulsa la x en la aplicacion vamos a la funcion salir
    //
    if(obj == this && ev->type() == QEvent::Close){

        salir();
    }

    return QObject::eventFilter(obj, ev);
}

void MainWindow::initReloj(){

    //
    // Hacemos que cada segundo refresque la hora
    //
    QTimer *qtReloj = new QTimer();
    connect(qtReloj, &QTimer::timeout, [this](){refrescaReloj();});
    qtReloj->start(1000);

}

void MainWindow::refrescaReloj(){

}

void MainWindow::salir(){

    exit(0);
}
