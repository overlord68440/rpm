#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //c = new client() ;


    //connect(ui->stopButton, SIGNAL(clicked()), this, SLOT(stopIcon())) ;
    connect(ui->highVolButton,SIGNAL(clicked()), this, SLOT(raiseVol())) ;
    connect(ui->lowVolButton,SIGNAL(clicked()), this, SLOT(lowerVol())) ;
    connect(ui->previousSongButton,SIGNAL(clicked()), this, SLOT(previousSong())) ;
    connect(ui->pauseButton, SIGNAL(toggled(bool)), this, SLOT(togglePauseIcon(bool))) ;
    connect(ui->playButton, SIGNAL(toggled(bool)), this, SLOT(togglePlayIcon(bool))) ;
    connect(ui->nextSongButton,SIGNAL(clicked()), this, SLOT(nextSong())) ;
    connect(ui->shuffleButton,SIGNAL(clicked()), this, SLOT(shufflePlaylist())) ;

    //set icon when hover
    ButtonHoverWatcher * watcherHighVol = new ButtonHoverWatcher("../imgIcon/highVol.png","../imgIcon/highVolActive.png",this);
    ButtonHoverWatcher * watcherLowVol = new ButtonHoverWatcher("../imgIcon/lowVol.png","../imgIcon/lowVolActive.png",this);
    ButtonHoverWatcher * watcherMute = new ButtonHoverWatcher("../imgIcon/muteButton.png","../imgIcon/muteActiveButton.png",this);
    ButtonHoverWatcher * watcherPreviousSong = new ButtonHoverWatcher("../imgIcon/previousSongButton.png","../imgIcon/previousSongActiveButton.png",this);
    ButtonHoverWatcher * watcherBackward = new ButtonHoverWatcher("../imgIcon/getBackButton.png","../imgIcon/getBackActiveButton.png",this);
    ButtonHoverWatcher * watcherStop = new ButtonHoverWatcher("../imgIcon/stopButton.png","../imgIcon/stopActiveButton.png",this);
    ButtonHoverWatcher * watcherFoward = new ButtonHoverWatcher("../imgIcon/fastFowardingButton.png","../imgIcon/fastFowardingActiveButton.png",this);
    ButtonHoverWatcher * watcherNextSong = new ButtonHoverWatcher("../imgIcon/nextSongButton.png","../imgIcon/nextSongActiveButton.png",this);
    ButtonHoverWatcher * watcherShuffle = new ButtonHoverWatcher("../imgIcon/shuffleButton.png","../imgIcon/shuffleActiveButton.png",this);
    ButtonHoverWatcher * watcherRepeat = new ButtonHoverWatcher("../imgIcon/repeatButton.png","../imgIcon/repeatActiveButton.png",this);

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

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::stopIcon()
{
    ui->pauseButton->setChecked(false);
    ui->playButton->setChecked(false);
    ui->pauseButton->setIcon(QIcon("../imgIcon/pauseButton.png"));
    ui->playButton->setIcon(QIcon("../imgIcon/playButton.png"));
    ui->pauseButton->setEnabled(false);
    ui->playButton->setEnabled(false);
}


void MainWindow::togglePauseIcon(bool b)
{
    if(b)
    {
        sendOrders(pauseOrder);
    }
}

void MainWindow::togglePlayIcon(bool b)
{
    if(b)
    {
        sendOrders(play) ;
    }
}

void MainWindow::raiseVol()
{
    sendOrders(raiseVolume);
}

void MainWindow::lowerVol()
{
    sendOrders(lowerVolume);
}

void MainWindow::previousSong()
{
    sendOrders(previous);
}

void MainWindow::nextSong()
{
    sendOrders(next);
}

void MainWindow::shuffleSong()
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
            toSend.append("0.5");
        break ;
        case speedDown :
            toSend.append("multiply");
            toSend.append("speed");
            toSend.append("2.0");
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
        case muteDown :
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

















