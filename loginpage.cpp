#include "loginpage.h"
#include "ui_loginpage.h"
#include <QPixmap>

loginPage::loginPage(QWidget *parent) : QDialog(parent), ui(new Ui::loginPage){
    ui->setupUi(this);
    QPixmap pix ("/home/student/Desktop/PasswordProject/oof1.PNG");
    int w = ui->picLogin_label->width();
    int h = ui->picLogin_label->height();
    ui->picLogin_label->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
}

loginPage::~loginPage(){
    delete ui;
}
