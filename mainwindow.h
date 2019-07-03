#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtNetwork>
#include <QUrl>
#include <QDebug>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

private slots:
    void managerFinished(QNetworkReply *);

    void on_actionAbout_triggered();

private:
    void swapText();
    Ui::MainWindow *ui;
    QString lang1;
    QString lang2;


    QNetworkAccessManager *manager;
    QNetworkRequest request;
    QNetworkReply * reply;
    QByteArray jsonData;
    QString pre;
    QString url1;
    bool flag;


};

#endif // MAINWINDOW_H
