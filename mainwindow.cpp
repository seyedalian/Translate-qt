#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QThread>
#include<QPixmap>
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    this->setMaximumSize(791,579);
    this->setMinimumSize(791,579);


    this->setWindowTitle("Translate online");
    this->setWindowIcon(QIcon("../Translate/Translate.png"));
    //ui->graphicsView->setStyleSheet("background-color:#ff00aa; border:2px solid black");
    ui->graphicsView_2->setStyleSheet("background-color:#fbff00 ");

    ui->pushButton_8->setStyleSheet("background-color:#2eea04");
    ui->pushButton_7->setStyleSheet("background-color:#1184ff");
    ui->textBrowser->setStyleSheet("border:3px solid black");
    ui->textEdit->setStyleSheet("border:3px solid black");
    lang2="fa";
    ui->graphicsView->setStyleSheet("QWidget {background-image: url(../Translate/backgroup.jpg) }");
  //  ui->graphicsView->setStyleSheet("QWidget {background-image: url(../Translate/backgroup1.png) }");
   // ui->pushButton_8->setStyleSheet("QWidget {background-image: url(../Translate/shasti.jpg) }");

    lang1="en";

    ui->label_6->setText(lang2);
    ui->label_5->setText(lang1);

     manager=0;
      manager =new QNetworkAccessManager;
      reply=0;

  // QObject::connect(manager,SIGNAL(finished(reply)),this,SLOT(managerFinished(reply)));
      if(manager!=0)
     connect(manager,&QNetworkAccessManager::finished, this,&MainWindow::managerFinished);




}

MainWindow::~MainWindow()
{
    delete ui;
    delete manager;
    delete reply;

}

void MainWindow::on_pushButton_3_clicked()
{


    lang1="fa";
    ui->label_5->setText(lang1);
 ui->label_8->setText("پشتیبانی شده توسط یاندکس");

    ui->pushButton->setText("انگلیسی");
     ui->pushButton_2->setText("عربی");
     ui->pushButton_3->setText("فارسی");
     ui->pushButton_4->setText("فارسی");
      ui->pushButton_5->setText("عربی");
      ui->pushButton_6->setText("انگلیسی");



ui->pushButton_7->setText("جا به جایی");
ui->pushButton_8->setText("ترجمه");


}

void MainWindow::on_pushButton_2_clicked()
{

     lang1="ar";
     ui->label_5->setText(lang1);
     ui->label_8->setText("بدعم من ياندكس");

        ui->pushButton->setText("الإنجليزية");
         ui->pushButton_2->setText("العربية");
         ui->pushButton_3->setText("الفارسی");
         ui->pushButton_4->setText("الفارسی");
          ui->pushButton_5->setText("العربية");
          ui->pushButton_6->setText("الإنجليزية");


    ui->pushButton_7->setText("مبادلة");
    ui->pushButton_8->setText("الترجمه");
}

void MainWindow::on_pushButton_clicked()
{

    lang1="en";
    ui->label_5->setText(lang1);
    ui->label_8->setText("POwered By Yandex");

       ui->pushButton->setText("English");
        ui->pushButton_2->setText("Arabic");
        ui->pushButton_3->setText("Farsi");
        ui->pushButton_4->setText("Farsi");
         ui->pushButton_5->setText("Arabic");
         ui->pushButton_6->setText("English");


   ui->pushButton_7->setText("Swap");
   ui->pushButton_8->setText("Translate");
}

void MainWindow::on_pushButton_4_clicked()
{
    lang2="fa";

    ui->label_6->setText(lang2);
}

void MainWindow::on_pushButton_5_clicked()
{
    lang2="ar";

    ui->label_6->setText(lang2);
}

void MainWindow::on_pushButton_6_clicked()
{
    lang2="en";

    ui->label_6->setText(lang2);
}

void MainWindow::on_pushButton_7_clicked()
{

    swapText();
}

void MainWindow::on_pushButton_8_clicked()
{
    QString text,answer;
    text=ui->textEdit->toPlainText();
    QString url1="https://translate.yandex.net/api/v1.5/tr.json/translate?key=trnsl.1.1.20180626T123042Z.a14ab6be2650abce.7daa9b2c50db8c04c6005f170d206da2650d62bb&lang=";
    url1+=lang2;
    url1+="&text=";
    url1+=text;


    if(lang1==lang2)
    {
         ui->textBrowser->setText(text);
         if(text=="")
              ui->textBrowser->setText("Please type anything!");

    }else
    {




        request.setUrl(QUrl(url1));
         manager->get(request);



    }



}

void MainWindow::swapText()
{
    QString l1;
     QString l2;


    l1=lang1;
    lang1=lang2;
    lang2=l1;
    ui->label_6->setText(lang2);
    ui->label_5->setText(lang1);

    l1=ui->textBrowser->toPlainText();
    l2=ui->textEdit->toPlainText();
    if(flag==false){
    ui->textBrowser->setText(l2);
    ui->textEdit->setText(l1);
    }
}


void MainWindow::managerFinished(QNetworkReply *Reply) {
    if (Reply->error()) {
        flag=true;
        //qDebug() << Reply->errorString();
        QString error= Reply->errorString();
        if(error=="Host translate.yandex.net not found")
          ui->textBrowser->setText("Please check your Internet connect!!");
        else
            if(error=="Error downloading https://translate.yandex.net/api/v1.5/tr.json/translate?key=trnsl.1.1.20180626T123042Z.a14ab6be2650abce.7daa9b2c50db8c04c6005f170d206da2650d62bb&lang=fa&text= - server replied: Bad Request")
            {
                    ui->textBrowser->setText("Please write anything in left box!");
             }else
                if(error=="Error downloading https://translate.yandex.net/api/v1.5/tr.json/translate?key=trnsl.1.1.20180626T123042Z.a14ab6be2650abce.7daa9b2c50db8c04c6005f170d206da2650d62bb&lang=en&text= - server replied: Bad Request")
                {
                        ui->textBrowser->setText("Please write anything in left box!");
                 }else
                    if(error=="Error downloading https://translate.yandex.net/api/v1.5/tr.json/translate?key=trnsl.1.1.20180626T123042Z.a14ab6be2650abce.7daa9b2c50db8c04c6005f170d206da2650d62bb&lang=ar&text= - server replied: Bad Request")
                    {
                            ui->textBrowser->setText("Please write anything in left box!");
                     }else
            ui->textBrowser->setText("Error Translate...");
        return;
    }else{
    flag=false;
    jsonData = Reply->readAll();
    QJsonDocument document = QJsonDocument::fromJson(jsonData);
    QJsonObject object = document.object();

    QJsonValue value = object.value("text");

     QJsonArray array = value.toArray();
    foreach (const QJsonValue & v, array)


        ui->textBrowser->setText(v.toString());

    delete Reply;
    }

}

void MainWindow::on_actionAbout_triggered()
{
    QMessageBox ::about(this,tr("پل ارتباطی"),tr( "تشکر از استفاده از برنامه  لطفا هرگونه انتقادات و پیشنهاد های خود را با پل ارتباطی زیر "
                                                   "با من درمیان بگذارید"
                                                   "\n"
                                                   "seyedalian10@gmail.com"
                                                   "\n"
                                                   "با تشکر سیدسجادسیدعلیان"));


}
