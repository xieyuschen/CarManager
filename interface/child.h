#ifndef CHILD_H
#define CHILD_H

#include <QMainWindow>

namespace Ui {
class child;
}

class child : public QMainWindow
{
    Q_OBJECT

public:
    explicit child(QWidget *parent = nullptr);
    ~child();

private:
    Ui::child *ui;
};

#endif // CHILD_H
