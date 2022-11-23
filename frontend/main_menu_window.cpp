#include "main_menu_window.h"
#include "ui_main_menu_window.h"

main_menu_window::main_menu_window(QString card_id,QWidget *parent) : //kopioitu card_id
    QDialog(parent),
    ui(new Ui::main_menu_window)
{
    ui->setupUi(this);
    ui->label_card_id->setText(card_id);   //lisätty, viedään main menu ikkunaan card_id teksti

}


main_menu_window::~main_menu_window()
{
    delete ui;
}

const QString &main_menu_window::getWebToken() const
{
    return webToken;
}

void main_menu_window::setWebToken(const QString &newWebToken)
{
    webToken = newWebToken;
}

void main_menu_window::on_btn_balance_clicked()
{
    QString wb=this->getWebToken();
    qDebug()<<"Webtoken="+wb;
}

