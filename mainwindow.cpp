#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "loginpage.h"
#include "createpage.h"
#include <QMessageBox>
#include <QPixmap>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix ("/home/student/Desktop/PasswordProject/oof1.PNG");
    int w = ui->picLabel->width();
    int h = ui->picLabel->height();
    ui->picLabel->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::on_loginButton_clicked(){
    hide();
    login_page = new loginPage(this);
    login_page->show();
}

void MainWindow::on_createButton_clicked(){
    hide();
    create_page = new createPage();
    create_page->show();
}
