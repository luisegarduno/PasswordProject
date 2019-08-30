#ifndef SESSIONMANAGER_H
#define SESSIONMANAGER_H

#include <QDialog>

namespace Ui {
class sessionManager;
}

class sessionManager : public QDialog
{
    Q_OBJECT

public:
    explicit sessionManager(QWidget *parent = nullptr);
    ~sessionManager();

private:
    Ui::sessionManager *ui;
};

#endif // SESSIONMANAGER_H
