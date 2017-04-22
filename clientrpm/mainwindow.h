#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
#include "buttonhoverwatcher.h"
#include "constant.h"
#include "client.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    client *c ;

    void sendOrders(orders o) ;

private slots :
    void stopIcon() ;
    void togglePauseIcon(bool b);
    void togglePlayIcon(bool b);


    void raiseVol() ;
    void lowerVol() ;
    void previousSong() ;
    void nextSong() ;
    void shuffleSong();
    void repeatSong(bool b);

    void isActiveSongModeTab();
    void isActiveRadioModeTab();

};

#endif // MAINWINDOW_H
