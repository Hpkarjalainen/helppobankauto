#ifndef MAIN_MENU_WINDOW_H
#define MAIN_MENU_WINDOW_H

#include <QDialog>
#include <QDebug>  //tarvitaanko?
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>


namespace Ui {
class main_menu_window;
}

class main_menu_window : public QDialog
{
    Q_OBJECT

public:
    explicit main_menu_window(QString card_id,QWidget *parent = nullptr);  //lisä id_card
    ~main_menu_window();

    const QString &getWebToken() const;
    void setWebToken(const QString &newWebToken);

private slots:
    void on_btn_balance_clicked();
    void balanceSlot (QNetworkReply *reply); //kopioitu ja muokattu nimeksi balance

private:
    Ui::main_menu_window *ui;
    QString webToken;
    QString myStudentId;  //tästä en oo varma

    QNetworkAccessManager *balanceManager; //kopioitu esim. sivulta, muokattu balance nimeksi
    QNetworkReply *reply;
    QByteArray response_data;

};

#endif // MAIN_MENU_WINDOW_H
