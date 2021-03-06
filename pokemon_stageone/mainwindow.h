#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ashe.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

     Pokemon *test;

private slots:
    void on_generate_pokemon_clicked();

    void on_getExp_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
