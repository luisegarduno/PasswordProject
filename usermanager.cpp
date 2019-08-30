#include "usermanager.h"
#include "codemaker.h"
#include <QMessageBox>
#include <QPixmap>
#include <QFile>
#include <QTextStream>
#include <QChar>
#include <QDataStream>
#include <iostream>
#include <cstring>

static QFile theAccounts("/home/student/Desktop/PasswordProject/.accounts.bat");

userManager::userManager(char * username){
    this->username = new char[94];
    strcpy(this->username,username);
}

bool userManager::checkUsernamePassword(QString password, QString rePassword){
    output = new char[300];
    QTextStream in(&theAccounts);
    if(password != rePassword){
        QMessageBox::warning(nullptr, "Error", "Username/Password is not valid");
        return false;
    }
    if(!theAccounts.open(QFile::ReadWrite | QFile::Text)){
        QMessageBox::warning(nullptr,"Error", "File does not exist or is not found");
        return false;
    }


    while(!in.atEnd()){
        string theString = "";
        int i = 0;

        QString tempString = "";                                             // tempString is initiated
        tempString = in.readLine();                                 // tempString is filled with a line
        QByteArray charAccount = tempString.toLocal8Bit();                   //
        output = charAccount.data();                                         // tempString converted to char output

        finalText = myCoder.decode(output);
        std::cout << finalText << endl;


        while(finalText[i] != ','){
            theString.push_back(finalText[i]);
            i++;
        }

        string strUsername = username;

        if(theString == strUsername){
            QMessageBox::warning(nullptr,"Username","Username found, please enter new Username");
            return false;
        }
    }

    theAccounts.flush();
    theAccounts.close();
    return true;
}

char * userManager::getUsername(){
    return username;
}

char * userManager::getPassword(){
    return password;
}

void userManager::setUsername(char * username){
    strcpy(this->username,username);
}

void userManager::setPassword(char * password){
    strcpy(this->password,password);
}

void userManager::addAccount(char * password){
    theAccounts.open(QFile::WriteOnly | QFile::Text);
    QTextStream in(&theAccounts);

    userText = username;
    pass = password;
    originalText = userText + "," + pass;
    std::cout << originalText << endl;
    secretCode = QString::fromStdString(myCoder.encode(originalText));

    in << secretCode;

    QMessageBox::information(nullptr,"New Account","Account has been succesfully created, press ok to login");
    theAccounts.flush();
    theAccounts.close();

    string textFile = "/home/student/Desktop/PasswordProject/." + userText + ".bat";
    fstream accountFile(textFile, ios::out | ios::app);


}
