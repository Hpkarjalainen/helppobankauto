#ifndef MAIN_MENU_WINDOW_H
#define MAIN_MENU_WINDOW_H

#include <QDialog>


namespace Ui {
class main_menu_window;
}

class main_menu_window : public QDialog
{
    Q_OBJECT

public:
    explicit main_menu_window(QString card_id,QWidget *parent = nullptr);  //lisä id_card
    ~main_menu_window();

private:
    Ui::main_menu_window *ui;

};

#endif // MAIN_MENU_WINDOW_H
