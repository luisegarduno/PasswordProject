#include "sessionmanager.h"
#include "ui_sessionmanager.h"

sessionManager::sessionManager(QWidget *parent) : QDialog(parent), ui(new Ui::sessionManager) {
    ui->setupUi(this);
}

sessionManager::~sessionManager(){
    delete ui;
}
