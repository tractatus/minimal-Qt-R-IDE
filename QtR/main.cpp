#include <QApplication>
#include <QStyleFactory>
#include <QSettings>
#include <QFont>
#include <QFontDatabase>

#include "qtr.h"

int main( int argc, char *argv[] )
{
    RInside R( argc, argv );

    QApplication app( argc, argv );
    qApp->setStyle(QStyleFactory::create("Fusion"));

    QPalette darkPalette;
    darkPalette.setColor(QPalette::Window, QColor(53,53,53));
    darkPalette.setColor(QPalette::WindowText, Qt::white);
    darkPalette.setColor(QPalette::Base, QColor(25,25,25));
    darkPalette.setColor(QPalette::AlternateBase, QColor(53,53,53));
    darkPalette.setColor(QPalette::ToolTipBase, Qt::white);
    darkPalette.setColor(QPalette::ToolTipText, Qt::white);
    darkPalette.setColor(QPalette::Text, Qt::white);
    darkPalette.setColor(QPalette::Button, QColor(53,53,53));
    darkPalette.setColor(QPalette::ButtonText, Qt::white);
    darkPalette.setColor(QPalette::BrightText, Qt::red);
    darkPalette.setColor(QPalette::Link, QColor(76, 150, 137));
    darkPalette.setColor(QPalette::Highlight, QColor(76, 150, 137));
    darkPalette.setColor(QPalette::HighlightedText, Qt::black);

    qApp->setPalette(darkPalette);

    qApp->setStyleSheet("QToolTip { color: #ffffff; background-color: #2a82da; border: 1px solid white; }");

    qApp->setStyleSheet(
           "QStatusBar {"
                "padding-left:8px;"
                "background:#e7c0b9;"
                "color:black;"
                "font-weight:bold;"
           "}"
           "QPushButton {"
                "font-weight: 600; "
                "margin: 1px;"
                "border-color: white;"
                "border-style: outset;"
                "border-radius: 3px;"
                "border-width: 2px;"
                "color: white;"
                "background-color: #4c9689;"
            "}"
                "QPushButton:hover {"
                    "background-color: white;"
                    "color: #535353;"
                "}"
            "QPushButton:pressed {"
                "background-color: white;"
                "color: #e7c0b9;"
            "}"
                );

    QFontDatabase::addApplicationFont(":/monaco.ttf");

    //specify a new font.
    QFont newFont("Monaco", 11);
    //set font of application
    QApplication::setFont(newFont);


    QApplication::setCursorFlashTime( 0 );
    RQtTest rqttest( R );
    rqttest.show();
    return app.exec();
}
