#ifndef EBOOK_H
#define EBOOK_H

#include <QMainWindow>

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

private:
    Ui::Ebook *ui;
};
#endif // EBOOK_H
