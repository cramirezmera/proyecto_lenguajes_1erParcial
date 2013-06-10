#include "ventanaprincipal.h"
#include "ui_ventanaprincipal.h"
#include "sudoku.h"
#include <QTimer>

VentanaPrincipal::VentanaPrincipal(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::VentanaPrincipal)
{
    ui->setupUi(this);
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(tiempoFuera()));
}

VentanaPrincipal::~VentanaPrincipal()
{
    delete ui;
}

void VentanaPrincipal::changeEvent(QEvent *e){
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

/*void VentanaPrincipal::entrada(){

    static short valor = 0;
    ui->barra->setValue(valor);
    ++valor;
    if(valor == 100)    timer->stop();
    this->close();
    sudoku *sudo = new sudoku();
    sudo->show();
}*/

void VentanaPrincipal::on_entrar_clicked()
{
    timer->start();
}

void VentanaPrincipal::tiempoFuera(){
    static short valor = 0;
    ui->barra->setValue(valor);
    ++valor;
    if(valor == 101){
        timer->stop();
        this->close();
        sudoku *sudo = new sudoku();
        sudo->show();
    }

}