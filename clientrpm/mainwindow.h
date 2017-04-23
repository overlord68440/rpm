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


    ButtonHoverWatcher * watcherHighVol ;
    ButtonHoverWatcher * watcherLowVol ;
    ButtonHoverWatcher * watcherMute ;
    ButtonHoverWatcher * watcherPreviousSong ;
    ButtonHoverWatcher * watcherBackward ;
    ButtonHoverWatcher * watcherStop ;
    ButtonHoverWatcher * watcherFoward ;
    ButtonHoverWatcher * watcherNextSong ;
    ButtonHoverWatcher * watcherShuffle ;
    ButtonHoverWatcher * watcherRepeat ;

    void sendOrders(orders o) ;

    void initWatcher();
private slots :
    void stopIt() ;
    void togglePause(bool b);
    void togglePlay(bool b);


    void raiseVol() ;
    void lowerVol() ;
    void muteSong(bool b);
    void previousSong() ;
    void nextSong() ;
    void shufflePlaylist();
    void repeatSong(bool b);

    void isActiveSongModeTab();
    void isActiveRadioModeTab();


    void lowerSpeedSong();
    void raiseSpeedSong();
};

#endif // MAINWINDOW_H
