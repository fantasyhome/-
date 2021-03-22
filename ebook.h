#ifndef EBOOK_H
#define EBOOK_H

#include <QMainWindow>
#include <QToolButton>
#include <QLabel>
#include <QComboBox>
#include <QSpinBox>
#include <QToolBar>
#include <QColorDialog>
#include"DrawWidget.h"
QT_BEGIN_NAMESPACE
namespace Ui { class Ebook; }
QT_END_NAMESPACE

class Ebook : public QMainWindow
{
    Q_OBJECT

public:
    Ebook(QWidget *parent = nullptr);
    ~Ebook();

private slots:
    void on_mainpage_clicked();

    void on_readbook_clicked();

    void on_reply_clicked();

    void on_shop_clicked();
    void display();
    void on_personal_clicked();

    void on_system_clicked();

    void on_localbook_clicked();

    void on_load_clicked();

    void on_load_b_clicked();
    void zero_on();
    void zero_off();
    void one_on();
    void one_off();
    void two_on();
    void two_off();
    void three_on();
    void three_off();
    void four_on();
    void four_off();
    void five_on();
    void five_off();
    void six_on();
    void six_off();
    void tool_on();
    void tool_off();
    void on_draw_customContextMenuRequested(const QPoint &pos);
    void createToolBar();
    void on_tool_11_clicked();
    void ShowStyle();
    void ShowColor();
    void ToolBar_on();
    void ToolBar_off();
    void on_styleComboBox_activated(int index);

    void on_widthSpinBox_valueChanged(int arg1);

    void on_colorBtn_clicked();

    void on_clearBtn_clicked();

private:
    Ui::Ebook *ui;
};
#endif // EBOOK_H
