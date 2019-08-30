#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <QDialog>
#include <QFile>
#include <QChar>
#include <vector>
#include "codemaker.h"
#include <fstream>

using std::vector;
using std::fstream;
using std::flush;
using std::ios;



class userManager{
    public:
        userManager(char * username);
        bool checkUsernamePassword(QString,QString);
        string userText,pass,finalText,originalText;
        QString secretCode;
        CodeMaker myCoder;
        char * getUsername();
        char * getPassword();
        void setUsername(char * username);
        void setPassword(char * password);
        void addAccount(char * password);

    private:
        char * username;
        char * output;
        char * password;
        char * account;
};

#endif // USERMANAGER_H
