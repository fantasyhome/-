#include"DrawWidget.h"
#include <QtGui>
#include <QPen>
//看书界面“随意画”按钮切换画笔模式，控制此源文件画笔开关
extern bool paint_on;
DrawWidget::DrawWidget(QWidget *parent) : QWidget(parent)
{
    setAutoFillBackground(true);
    //Qt::transparent可以使绘画层透明，实现在图书层之上显示，且方便后续笔记擦除
    setPalette(QPalette(Qt::transparent));
    pix =new QPixmap(size());
    pix->fill(Qt::transparent);
}
void DrawWidget::setStyle(int s)
{
    style = s;
}
void DrawWidget::setWidth(int w)
{
    weight = w;
}
void DrawWidget::setColor(QColor c)
{
    color = c;
}
void DrawWidget::mousePressEvent(QMouseEvent *e)
{
    startPos = e->pos();
}
//画笔模式开启时从按下开始画到放开为止
void DrawWidget::mouseMoveEvent(QMouseEvent *e)
{
    if(paint_on==1)
    {
    QPainter *painter = new QPainter;
    QPen pen;
    pen.setStyle((Qt::PenStyle)style);
    pen.setWidth(weight);
    pen.setColor(color);
    painter->begin(pix);
    painter->setPen(pen);
    painter->drawLine(startPos,e->pos());
    painter->end();
    startPos =e->pos();
    update();
    }
}
void DrawWidget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.drawPixmap(QPoint(0,0),*pix);
}
void DrawWidget::resizeEvent(QResizeEvent *event)
{
    if(height()>pix->height()||width()>pix->width())
    {
        QPixmap *newPix = new QPixmap(size());
        newPix->fill(Qt::transparent);
        QPainter p(newPix);
        p.drawPixmap(QPoint(0,0),*pix);
        pix = newPix;
    }
    QWidget::resizeEvent(event);
}
void DrawWidget::clear()
{
    QPixmap *clearPix =new QPixmap(size());
    clearPix->fill(Qt::transparent);
    pix = clearPix;
    update();
}
