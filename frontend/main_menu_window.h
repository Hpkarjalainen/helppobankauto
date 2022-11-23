#ifndef MAIN_MENU_WINDOW_H
#define MAIN_MENU_WINDOW_H

#include <QDialog>
#include <QDebug>  //tarvitaanko?


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

private:
    Ui::main_menu_window *ui;
    QString webToken;

};

#endif // MAIN_MENU_WINDOW_H
