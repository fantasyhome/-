#include "ebook.h"
#include"DrawWidget.h"
#include "ui_ebook.h"
#include <QFile>
int mode=0;
bool paint_on=0;
Ebook::Ebook(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Ebook)
{
    ui->setupUi(this);
    ShowStyle();
    ui->draw->setWidth(ui->widthSpinBox->value());
    ui->draw->setColor(Qt::black);
    ui->draw->setStyle(Qt::SolidLine);
    ui->show->hide();
    ui->localbook->hide();
    tool_off();
    ui->load_b->hide();ui->username->hide();ui->username_l->hide();ui->code->hide();ui->code_l->hide();
    createToolBar();
    ToolBar_off();
}
void Ebook::ShowStyle()
{
    ui->draw->setStyle(ui->styleComboBox->itemData(
        ui->styleComboBox->currentIndex(),Qt::UserRole).toInt());
}
void Ebook::ShowColor()
{
    QColor color = QColorDialog::getColor(static_cast<int> (Qt::black), this);
    //使用标准颜色对话框QColorDialog获得一个颜色值
    if(color.isValid())
    {
       //将新选择的颜色传给绘制区，用于改变画笔的颜色值
        ui->draw->setColor(color);
        QPixmap p(20,20);
        p.fill(color);
        ui->colorBtn->setIcon(QIcon(p));		//更新颜色选择按钮上的颜色显示
    }
}
Ebook::~Ebook()
{
    delete ui;
}
void Ebook::tool_on()
{

    ui->tool_1->show();ui->tool_2->show();ui->tool_3->show();ui->tool_4->show();ui->tool_5->show();ui->tool_6->show();
    ui->tool_7->show();ui->tool_8->show();ui->tool_9->show();ui->tool_10->show();ui->tool_11->show();ui->tool_12->show();
    ui->tool_13->show();ui->tool_14->show();ui->tool_15->show();
}
void Ebook::tool_off()
{
    ui->tool_1->hide();ui->tool_2->hide();ui->tool_3->hide();ui->tool_4->hide();ui->tool_5->hide();ui->tool_6->hide();
    ui->tool_7->hide();ui->tool_8->hide();ui->tool_9->hide();ui->tool_10->hide();ui->tool_11->hide();ui->tool_12->hide();
    ui->tool_13->hide();ui->tool_14->hide();ui->tool_15->hide();
}
void Ebook::ToolBar_on()
{
    ui->label->show();ui->label_2->show();ui->styleComboBox->show();ui->widthSpinBox->show();ui->colorBtn->show();ui->clearBtn->show();
}
void Ebook::ToolBar_off()
{
    ui->label->hide();ui->label_2->hide();ui->styleComboBox->hide();ui->widthSpinBox->hide();ui->colorBtn->hide();ui->clearBtn->hide();
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
    ui->draw->show();
    tool_on();
}
void Ebook::one_off()
{
    ui->show->hide();
    ui->draw->hide();
    tool_off();
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
        if(paint_on)
        {
            ToolBar_on();
            tool_off();
            ui->tool_11->show();
        }
        else
        {
            ToolBar_off();
            tool_on();
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
void Ebook::createToolBar()
{
    ui->styleComboBox->addItem(tr("SolidLine"),
                                static_cast<int>(Qt::SolidLine));
    ui->styleComboBox->addItem(tr("DashLine"),
                                static_cast<int>(Qt::DashLine));
    ui->styleComboBox->addItem(tr("DotLine"),
                                static_cast<int>(Qt::DotLine));
    ui->styleComboBox->addItem(tr("DashDotLine"),
                                static_cast<int>(Qt::DashDotLine));
    ui->styleComboBox->addItem(tr("DashDotDotLine"),
                                static_cast<int>(Qt::DashDotDotLine));

    QPixmap pixmap(20,20);
    pixmap.fill(Qt::black);
    ui->colorBtn->setIcon(QIcon(pixmap));
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
    display();
}

void Ebook::on_styleComboBox_activated(int index)
{
    ShowStyle();
    display();
}

void Ebook::on_widthSpinBox_valueChanged(int arg1)
{
    ui->draw->setWidth(arg1);
    display();
}

void Ebook::on_colorBtn_clicked()
{
    ShowColor();
    display();
}

void Ebook::on_clearBtn_clicked()
{
    ui->draw->clear();
    display();
}
