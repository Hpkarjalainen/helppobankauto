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
    delete objectMainMenu;
    objectMainMenu=nullptr;
}


void MainWindow::on_btn_login_clicked()
{
    card_id=ui->text_id->text();        //syötetään merkit card_id kenttään
    QString pin=ui->text_pin->text();   //syötetään merkit PIN-kenttään

    QJsonObject jsonObj;                //QJsonObject muuttuja jsonObj;
    jsonObj.insert("card_id",card_id);
    jsonObj.insert("pin",pin);

    QString site_url=myUrl::getBaseUrl()+"/login";
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
    int test=QString::compare(response_data, "false");
    qDebug()<<test;

    if(response_data.length()==0){
        ui->label_info->setText("Palvelin ei vastaa");
    }
    else{
        if(QString::compare(response_data,"-4078")==0){
            ui->label_info->setText("Virhe tietokanta-yhteydessä");
        }
        else{
            if(test==-1){
                objectMainMenu=new main_menu_window(card_id);
                objectMainMenu->setWebToken(response_data);  //setWebToken?
                objectMainMenu->show();  //avataan Main Menu

            }
            else{
                ui->text_id->clear();
                ui->text_pin->clear();
                ui->label_info->setText("Eipä mennyt oikein ihan");
            }
        }
    }


}

