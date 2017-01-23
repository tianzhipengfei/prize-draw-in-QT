#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <cstdio>
#include <QStringListModel>
#include <QStringList>
#include <Qstring>
#include <QListView>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <QDebug>
#include <synchapi.h>
using namespace std;

const int MAXN = 100;
char namelist[MAXN][10];
bool isstop = false;
int totalnum = 0;

int autoinput()
{
    int num = 0;
    char tempname[10];
    FILE *fp = fopen("C:/Users/think/Desktop/in.txt","r");
    while(fscanf(fp,"%s",tempname)!=EOF)
    {
        strcpy(namelist[num++],tempname);
    }
    return num;
}

void MainWindow::freshName()
{
    int luckynum = rand()%totalnum;
    while(!luckynum){
        luckynum = rand()%totalnum;
    }
    ui->label_luckyname->setText(namelist[luckynum]);
}


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    srand(time(0));
    isstop = true;
    memset(namelist,0,sizeof(namelist));
    totalnum = autoinput();
    for(int i = 1; i < totalnum; i++){
        ui->listWidget->addItem(namelist[i]);
    }
    timer = new QTimer(this);
      if(timer==NULL)
       {
      qDebug()<<"fail timer!";
      }
      else{
      connect(timer,SIGNAL(timeout()),this,SLOT(freshName()));
     timer->setInterval(10);
      }
}

MainWindow::~MainWindow()
{
    timer->stop();
    delete timer;
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    timer->start(0);
}


void MainWindow::on_pushButton_2_clicked()
{
    timer->stop();
}
