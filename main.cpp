#include <QApplication>
#include <QDesktopWidget>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow* w = new MainWindow();
    w->resize(390,280);

    w->setGeometry(
        QStyle::alignedRect(
            Qt::LeftToRight,
            Qt::AlignCenter,
            w->size(),
            qApp->desktop()->availableGeometry()
        )
    );

    w->show();

    return app.exec();
}


