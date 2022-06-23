#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_randomApp.h"



class randomApp : public QMainWindow
{
    Q_OBJECT

public:
    randomApp(QWidget *parent = nullptr);
    ~randomApp();

private:
    Ui::randomAppClass *ui;

private slots:
    void whenUpperChecked();
    void whenLowerChecked();
    void whenNumberChecked();
    void whenSymbolChecked();
    void whenLength();
    void generatePass();
    void whencopy();
};

