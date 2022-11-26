#include "main_menu_window.h"
#include "ui_main_menu_window.h"
#include "myurl.h"

main_menu_window::main_menu_window(QString card_id,QWidget *parent) : //tänne tulee card_id jota ei ole account-taulussa
    QDialog(parent),
    ui(new Ui::main_menu_window)
{
    ui->setupUi(this);
    ui->label_card_id->setText(card_id);   //lisätty, viedään main menu ikkunaan card_id teksti
    myStudentId = card_id;  //sijoitetaan card_id ->myStudentId. Pitäisi saada user_id
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
    //qDebug()<<"Webtoken="+wb;  //webtoken tulee konsoliin

    QString site_url=myUrl::getBaseUrl()+"/checkbalance/"+myStudentId;  //luento 2.11. aika 1:10 tarkista mystudentid nimi
    QNetworkRequest request((site_url));
    //WEBTOKEN ALKU
    //QByteArray myToken="Bearer "+wb;
    //request.setRawHeader(QByteArray("Authorization"),(myToken));
    //WEBTOKEN LOPPU
    balanceManager = new QNetworkAccessManager(this);

    connect(balanceManager, SIGNAL(finished (QNetworkReply*)), this, SLOT(balanceSlot(QNetworkReply*)));
    //connect(lähettäjä, lähettäjän SIGNAL(funktio)) -> vastaanottaja, vastaanottajan SLOT(slot-funktio))

    reply = balanceManager->get(request);
}

void main_menu_window::balanceSlot(QNetworkReply *reply)
{
    response_data=reply->readAll();
    ui->labelInfo->setText(response_data);
    //qDebug()<<response_data;

}

