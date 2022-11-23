#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_btn_login_clicked()
{
    card_id=ui->text_id->text();
    QString pin=ui->text_pin->text();

    QJsonObject jsonObj;
    jsonObj.insert("card_id",card_id);
    jsonObj.insert("pin",pin);

    QString site_url="http://localhost:3000/login";
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    loginManager = new QNetworkAccessManager(this);
    connect(loginManager, SIGNAL(finished (QNetworkReply*)), this, SLOT(loginSlot(QNetworkReply*)));

    reply = loginManager->post(request, QJsonDocument(jsonObj).toJson());

}

void MainWindow::loginSlot(QNetworkReply *reply)
{
    response_data=reply->readAll();
    qDebug()<<response_data;
    /*
    if(card_id.length()==4){
        objectMainMenu=new main_menu_window(card_id);  //annetaan syötteeksi card_id
        objectMainMenu->show();             //avataan main menu window

    }
    else{
        ui->text_id->clear();
        ui->text_pin->clear();
        ui->label_info->setText("Eipä mennyt oikein ihan");
    }*/
}

