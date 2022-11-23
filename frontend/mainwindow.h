#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>

#include "main_menu_window.h"
#include "myurl.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btn_login_clicked();
    void loginSlot (QNetworkReply *reply);

private:
    Ui::MainWindow *ui;
    main_menu_window *objectMainMenu; //luodaan objectMainMenu niminen pointteri, tyyppiä main_menu
    QNetworkAccessManager *loginManager;
    QNetworkReply *reply;
    QByteArray response_data;
    QString card_id;

};
#endif // MAINWINDOW_H
