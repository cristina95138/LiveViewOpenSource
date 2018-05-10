#include <QApplication>
#include <QDesktopWidget>
#include <QPixmap>
#include <QSplashScreen>
#include <QStyle>
#include <QTextStream>

#include "lvmainwindow.h"

#ifndef HOST
#define HOST "unknown location"
#endif

#ifndef UNAME
#define UNAME "unknown person"
#endif

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
    QFile f(":qdarkstyle/style.qss");
    if (!f.exists())
    {
        printf("Unable to set stylesheet, file not found\n");
    }
    else
    {
        f.open(QFile::ReadOnly | QFile::Text);
        QTextStream ts(&f);
        qApp->setStyleSheet(ts.readAll());
    }

    QPixmap logo_pixmap(":images/aviris-logo-transparent.png");
    QSplashScreen splash(logo_pixmap);
    splash.show();
    splash.showMessage(QObject::tr("Loading LiveView... Compiled on " __DATE__ ", " __TIME__ " PDT by " UNAME "@" HOST), Qt::AlignCenter | Qt::AlignBottom, Qt::gray);

    qDebug() << "This version of LiveView was compiled on" << __DATE__ << "at" << __TIME__ << "using gcc" << __GNUC__;
    qDebug() << "The compilation was performed by" << UNAME << "@" << HOST << "\n";
    LVMainWindow w;
    w.setGeometry(   QStyle::alignedRect(
                             Qt::LeftToRight,
                             Qt::AlignCenter,
                             w.size(),
                             a.desktop()->availableGeometry()
                             ));
    w.show();
    splash.finish(&w);

    return a.exec();

}
