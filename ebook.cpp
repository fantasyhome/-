#include "ebook.h"
#include "ui_ebook.h"
#include <QFile>
int mode=0;
bool paint_on=0;
Ebook::Ebook(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Ebook)
{
    ui->setupUi(this);
    ui->draw->setWidth(/*widthSpinBox->value()*/1);
    ui->draw->setColor(Qt::black);
    ui->show->hide();
    ui->localbook->hide();
    ui->tool_1->hide();ui->tool_2->hide();ui->tool_3->hide();ui->tool_4->hide();ui->tool_5->hide();ui->tool_6->hide();
    ui->tool_7->hide();ui->tool_8->hide();ui->tool_9->hide();ui->tool_10->hide();ui->tool_11->hide();ui->tool_12->hide();
    ui->tool_13->hide();ui->tool_14->hide();ui->tool_15->hide();
    ui->load_b->hide();ui->username->hide();ui->username_l->hide();ui->code->hide();ui->code_l->hide();
}

Ebook::~Ebook()
{
    delete ui;
}
void Ebook::zero_on()
{
    ui->localbook->show();
}
void Ebook::zero_off()
{
    ui->localbook->hide();
}
void Ebook::one_on()
{
    ui->show->show();
    ui->tool_1->show();ui->tool_2->show();ui->tool_3->show();ui->tool_4->show();ui->tool_5->show();ui->tool_6->show();
    ui->tool_7->show();ui->tool_8->show();ui->tool_9->show();ui->tool_10->show();ui->tool_11->show();ui->tool_12->show();
    ui->tool_13->show();ui->tool_14->show();ui->tool_15->show();
}
void Ebook::one_off()
{
    ui->show->hide();
    ui->tool_1->hide();ui->tool_2->hide();ui->tool_3->hide();ui->tool_4->hide();ui->tool_5->hide();ui->tool_6->hide();
    ui->tool_7->hide();ui->tool_8->hide();ui->tool_9->hide();ui->tool_10->hide();ui->tool_11->hide();ui->tool_12->hide();
    ui->tool_13->hide();ui->tool_14->hide();ui->tool_15->hide();
}
void Ebook::two_on()
{

}
void Ebook::two_off()
{

}
void Ebook::three_on()
{

}
void Ebook::three_off()
{

}
void Ebook::four_on()
{

}
void Ebook::four_off()
{

}
void Ebook::five_on()
{

}
void Ebook::five_off()
{

}
void Ebook::six_on()
{
    ui->load_b->show();ui->username->show();ui->username_l->show();ui->code->show();ui->code_l->show();
}
void Ebook::six_off()
{
    ui->load_b->hide();ui->username->hide();ui->username_l->hide();ui->code->hide();ui->code_l->hide();
}
void Ebook::display()
{
    if(mode==0)
    {
        zero_on();one_off();two_off();three_off();four_off();five_off();six_off();
    }
    if(mode==1)
    {
        zero_off();one_on();two_off();three_off();four_off();five_off();six_off();
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
    if(mode==6)
    {
        zero_off();one_off();two_off();three_off();four_off();five_off();six_on();
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

void Ebook::on_load_clicked()
{
    mode=6;
    display();
}


void Ebook::on_load_b_clicked()
{

}

void Ebook::on_draw_customContextMenuRequested(const QPoint &pos)
{

}

void Ebook::on_tool_11_clicked()
{
    paint_on=!paint_on;
}
