#ifndef CREATEPAGE_H
#define CREATEPAGE_H

#include <QDialog>
#include "loginpage.h"
#include "usermanager.h"


namespace Ui {
class createPage;
}

class createPage : public QDialog {
    Q_OBJECT

public:
    explicit createPage(QWidget *parent = nullptr);
    ~createPage();

private slots:
    void on_createAccount_button_clicked();


private:
    Ui::createPage *ui;
    loginPage * new_login;
    int option;
    userManager * currentUser;
};

#endif // CREATEPAGE_H
