#include "createpage.h"
#include "loginpage.h"
#include "ui_createpage.h"
#include <QMessageBox>
#include <QPixmap>
#include <QFile>
#include <QTextStream>
#include <QApplication>
#include <QByteArray>
#include "usermanager.h"


createPage::createPage(QWidget *parent) :   QDialog(parent),    ui(new Ui::createPage){
    ui->setupUi(this);
    QPixmap pix ("/home/student/Desktop/PasswordProject/oof1.PNG");
    int w = ui->picCreateAccount_label->width();
    int h = ui->picCreateAccount_label->height();
    ui->picCreateAccount_label->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
}

createPage::~createPage()
{
    delete ui;
}

void createPage::on_createAccount_button_clicked(){

    QString username = ui->createUsername_lineEdit->text();             // Save entered QString as username
    QByteArray charUsername = username.toLocal8Bit();                   //
    char *theUsername = charUsername.data();                                 // Turn String into char

    QString password = ui->createPassword_lineEdit->text();
    QByteArray charPassword = password.toLocal8Bit();
    char *thePassword = charPassword.data();

    QString rePassword = ui->reCreatePassword_lineEdit->text();


    currentUser = new userManager(theUsername);
    bool correct = currentUser->checkUsernamePassword(password,rePassword);


    if((correct == true) && (password != "") && (username != "") && (password == rePassword)){
        currentUser->addAccount(thePassword);
        hide();
        new_login = new loginPage();
        new_login->show();
    }

}
