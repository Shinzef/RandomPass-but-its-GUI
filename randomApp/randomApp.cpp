#include "randomApp.h"

#include "ult.h"

#include <QKeyEvent>
#include <qmessagebox.h>
#include <QTextStream>
#include <QIntValidator>
#include <QLineEdit>
#include <QClipboard>

setting settings;

randomApp::randomApp(QWidget *parent)
    : QMainWindow(parent)
{
    ui->setupUi(this);
	
    ui->lineEdit->setValidator(new QIntValidator(1, 1024, this));

    connect(ui->uppercase, SIGNAL(clicked(bool)), this, SLOT(whenUpperChecked()));
    connect(ui->lower, SIGNAL(clicked(bool)), this, SLOT(whenLowerChecked()));
    connect(ui->number, SIGNAL(clicked(bool)), this, SLOT(whenNumberChecked()));
    connect(ui->symbol, SIGNAL(clicked(bool)), this, SLOT(whenSymbolChecked()));
    connect(ui->lineEdit, SIGNAL(editingFinished()), this, SLOT(whenLength()));
    connect(ui->Generate, SIGNAL(clicked()), this, SLOT(generatePass()));
    connect(ui->copy, SIGNAL(clicked()), this, SLOT(whencopy()));
}

randomApp::~randomApp()
{}

void randomApp::whenUpperChecked()
{
    if (ui->uppercase->isChecked()) 
    {
        settings.includeUppercaseChar = true;
    }
    else
    {
        settings.includeUppercaseChar = false;
    }
}

void randomApp::whenLowerChecked()
{
    if (ui->lower->isChecked())
    {
        settings.includeLowercaseChar = true;
    }
    else
    {
        settings.includeLowercaseChar = false;
    }
}

void randomApp::whenNumberChecked()
{
    if (ui->number->isChecked())
    {
        settings.includeNumber = true;
    }
    else
    {
        settings.includeNumber = false;
    }
}

void randomApp::whenSymbolChecked()
{
    if (ui->symbol->isChecked())
    {
        settings.includeSymbol = true;
    }
    else
    {
        settings.includeSymbol = false;
    }
}

void randomApp::whenLength()
{
    QString str = ui->lineEdit->text();
    int length = str.toInt();
    settings.passwordLength = length;
}

void randomApp::generatePass()
{
    std::string pass = generatePassword(settings);
    QString genPass = QString::fromStdString(pass);
    ui->password->setText(genPass);
}

void randomApp::whencopy()
{
    QString pass = ui->password->text();
    QClipboard* clipboard = QApplication::clipboard();
    clipboard->setText(pass);

}