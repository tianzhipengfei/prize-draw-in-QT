#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("江南皮革厂倒闭了 薛根要请小姨子吃饭了");
    w.show();

    return a.exec();
}
