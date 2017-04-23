#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    c = new client() ;

    connect(ui->stopButton, SIGNAL(clicked()), this, SLOT(stopIt())) ;
    connect(ui->highVolButton,SIGNAL(clicked()), this, SLOT(raiseVol())) ;
    connect(ui->lowVolButton,SIGNAL(clicked()), this, SLOT(lowerVol())) ;
    connect(ui->previousSongButton,SIGNAL(clicked()), this, SLOT(previousSong())) ;
    connect(ui->backwardButton,SIGNAL(clicked()), this, SLOT(lowerSpeedSong())) ;
    connect(ui->pauseButton, SIGNAL(toggled(bool)), this, SLOT(togglePause(bool))) ;
    connect(ui->playButton, SIGNAL(toggled(bool)), this, SLOT(togglePlay(bool))) ;
    connect(ui->fastFowardingButton,SIGNAL(clicked()), this, SLOT(raiseSpeedSong())) ;
    connect(ui->nextSongButton,SIGNAL(clicked()), this, SLOT(nextSong())) ;
    connect(ui->shuffleButton,SIGNAL(clicked()), this, SLOT(shufflePlaylist())) ;
    connect(ui->repeatButton,SIGNAL(toggled(bool)), this, SLOT(repeatSong(bool))) ;

    initWatcher();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initWatcher()
{
    //set icon when hover
    watcherHighVol = new ButtonHoverWatcher("../imgIcon/highVol.png","../imgIcon/highVolActive.png",this);
    watcherLowVol = new ButtonHoverWatcher("../imgIcon/lowVol.png","../imgIcon/lowVolActive.png",this);
    watcherMute = new ButtonHoverWatcher("../imgIcon/muteButton.png","../imgIcon/muteActiveButton.png",this);
    watcherPreviousSong = new ButtonHoverWatcher("../imgIcon/previousSongButton.png","../imgIcon/previousSongActiveButton.png",this);
    watcherBackward = new ButtonHoverWatcher("../imgIcon/getBackButton.png","../imgIcon/getBackActiveButton.png",this);
    watcherStop = new ButtonHoverWatcher("../imgIcon/stopButton.png","../imgIcon/stopActiveButton.png",this);
    watcherFoward = new ButtonHoverWatcher("../imgIcon/fastFowardingButton.png","../imgIcon/fastFowardingActiveButton.png",this);
    watcherNextSong = new ButtonHoverWatcher("../imgIcon/nextSongButton.png","../imgIcon/nextSongActiveButton.png",this);
    watcherShuffle = new ButtonHoverWatcher("../imgIcon/shuffleButton.png","../imgIcon/shuffleActiveButton.png",this);
    watcherRepeat = new ButtonHoverWatcher("../imgIcon/repeatButton.png","../imgIcon/repeatActiveButton.png",this);

    ui->highVolButton->installEventFilter(watcherHighVol);
    ui->lowVolButton->installEventFilter(watcherLowVol);
    ui->muteButton->installEventFilter(watcherMute);
    ui->previousSongButton->installEventFilter(watcherPreviousSong);
    ui->backwardButton->installEventFilter(watcherBackward);
    ui->stopButton->installEventFilter(watcherStop);
    ui->fastFowardingButton->installEventFilter(watcherFoward);
    ui->nextSongButton->installEventFilter(watcherNextSong);
    ui->shuffleButton->installEventFilter(watcherShuffle);
    ui->repeatButton->installEventFilter(watcherRepeat);
}


void MainWindow::raiseVol()
{
    sendOrders(raiseVolume);
}

void MainWindow::lowerVol()
{
    sendOrders(lowerVolume);
}

void MainWindow::muteSong(bool b)
{
    if(b)
        sendOrders(muteOn);
    else
        sendOrders(muteOff);
}

void MainWindow::stopIt()
{
    sendOrders(stop);
}

void MainWindow::togglePause(bool b)
{
    if(b)
    {
        sendOrders(pauseOrder);
    }
}

void MainWindow::togglePlay(bool b)
{
    if(b)
    {
        sendOrders(play) ;
    }
}

void MainWindow::lowerSpeedSong()
{
    sendOrders(speedDown);
}

void MainWindow::raiseSpeedSong()
{
    sendOrders(speedUp);
}

void MainWindow::previousSong()
{
    sendOrders(previous);
}

void MainWindow::nextSong()
{
    sendOrders(next);
}

void MainWindow::shufflePlaylist()
{
        sendOrders(shuffle);
}

void MainWindow::repeatSong(bool b)
{
    if(b)
        sendOrders(repeatOn);
    else
        sendOrders(repeatOff);
}

void MainWindow::sendOrders(orders o)
{
    QJsonArray toSend ;
    switch(o)
    {
        case pauseOrder :
            toSend.append("cycle");
            toSend.append("pause");
            toSend.append("0");
        break ;
        case play :
            toSend.append("cycle");
            toSend.append("pause");
            toSend.append("1");
        break ;
        case stop :
            toSend.append("stop");
        break ;

        case previous :
            toSend.append("playlist-prev");
            toSend.append("weak");
        break ;
        case next :
            toSend.append("playlist-next");
            toSend.append("weak");
        break ;
        case speedUp :
            toSend.append("multiply");
            toSend.append("speed");
            toSend.append("2");
        break ;
        case speedDown :
            toSend.append("multiply");
            toSend.append("speed");
            toSend.append("0.5");
        break ;

        case raiseVolume :
            toSend.append("add");
            toSend.append("volume");
            toSend.append("10");
        break ;
        case lowerVolume :
            toSend.append("add");
            toSend.append("volume");
            toSend.append("-10");
        break ;
        case muteOn :
            toSend.append("cycle");
            toSend.append("mute");
            toSend.append("1");
        break ;
        case muteOff :
        toSend.append("cycle");
        toSend.append("mute");
        toSend.append("1");
        break ;

        case shuffle :
            toSend.append("playlist-shuffle");
        break ;
        case repeatOn :
            toSend.append("cycle-values");
            toSend.append("loop-files");
            toSend.append("inf");
        break ;
        case repeatOff :
        toSend.append("cycle-values");
        toSend.append("loop-files");
        toSend.append("no");
        break ;

        default :
            return ;
        break ;
    }

    QJsonObject jsonObject ;
    jsonObject["command"]=toSend;

    QByteArray bytes = QJsonDocument(jsonObject).toJson(QJsonDocument::Compact)+"\n";
    c->writeSock(bytes);
}

void MainWindow::isActiveSongModeTab()
{
    ui->fastFowardingButton->setEnabled(true);
    ui->backwardButton->setEnabled(true);
    ui->pauseButton->setEnabled(true);
}

void MainWindow::isActiveRadioModeTab()
{
    ui->fastFowardingButton->setEnabled(false);
    ui->backwardButton->setEnabled(false);
    ui->pauseButton->setEnabled(false);
}


