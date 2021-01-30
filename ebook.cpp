#include "ebook.h"
#include "ui_ebook.h"
#include <QFile>
int mode=0;
Ebook::Ebook(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Ebook)
{
    ui->setupUi(this);
    ui->show->hide();
    ui->localbook->hide();
}

Ebook::~Ebook()
{
    delete ui;
}
void Ebook::display()
{
    if(mode==0)
    {
        ui->show->hide();
        ui->localbook->show();
    }
    if(mode==1)
    {
        ui->show->show();
        ui->localbook->hide();
        QFile file("test.txt");
        if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            ui->show->setText("can't open this file");
        }
        while(!file.atEnd())
        {
            QByteArray line = file.readLine();
            QString str(line);
            ui->show->textCursor().insertText(str);
            ui->show->moveCursor(QTextCursor::End);
        }
    }
}

void Ebook::on_mainpage_clicked()
{
    mode=0;
    display();
}

void Ebook::on_readbook_clicked()
{
    mode=1;
    display();
}

void Ebook::on_reply_clicked()
{
    mode=2;
    display();
}

void Ebook::on_shop_clicked()
{
    mode=3;
    display();
}

void Ebook::on_personal_clicked()
{
    mode=4;
    display();
}

void Ebook::on_system_clicked()
{
    mode=5;
    display();
}

void Ebook::on_localbook_clicked()
{
    mode=1;
    display();
}
