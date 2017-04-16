#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //connect(ui->stopButton, SIGNAL(clicked()), this, SLOT(stopIcon())) ;
    connect(ui->pauseButton, SIGNAL(toggled(bool)), this, SLOT(togglePauseIcon(bool))) ;
    connect(ui->playButton, SIGNAL(toggled(bool)), this, SLOT(togglePlayIcon(bool))) ;
    connect(ui->highVolButton,SIGNAL(clicked()), this, SLOT(raiseVol())) ;
    connect(ui->lowVolButton,SIGNAL(clicked()), this, SLOT(lowerVol())) ;

    ButtonHoverWatcher * watcherHighVol = new ButtonHoverWatcher("../imgIcon/highVol.png","../imgIcon/highVolActive.png",this);
    ButtonHoverWatcher * watcherLowVol = new ButtonHoverWatcher("../imgIcon/lowVol.png","../imgIcon/lowVolActive.png",this);
    ButtonHoverWatcher * watcherMute = new ButtonHoverWatcher("../imgIcon/muteButton.png","../imgIcon/muteActiveButton.png",this);
    ButtonHoverWatcher * watcherPreviousSong = new ButtonHoverWatcher("../imgIcon/previousSongButton.png","../imgIcon/previousSongActiveButton.png",this);
    ButtonHoverWatcher * watcherBackward = new ButtonHoverWatcher("../imgIcon/getBackButton.png","../imgIcon/getBackActiveButton.png",this);
    ButtonHoverWatcher * watcherStop = new ButtonHoverWatcher("../imgIcon/stopButton.png","../imgIcon/stopActiveButton.png",this);
    ButtonHoverWatcher * watcherFoward = new ButtonHoverWatcher("../imgIcon/fastFowardingButton.png","../imgIcon/fastFowardingActiveButton.png",this);
    ButtonHoverWatcher * watcherNextSong = new ButtonHoverWatcher("../imgIcon/nextSongButton.png","../imgIcon/nextSongActiveButton.png",this);

    ui->highVolButton->installEventFilter(watcherHighVol);
    ui->lowVolButton->installEventFilter(watcherLowVol);
    ui->muteButton->installEventFilter(watcherMute);
    ui->previousSongButton->installEventFilter(watcherPreviousSong);
    ui->backwardButton->installEventFilter(watcherBackward);
    ui->stopButton->installEventFilter(watcherStop);
    ui->fastFowardingButton->installEventFilter(watcherFoward);
    ui->nextSongButton->installEventFilter(watcherNextSong);



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
        ui->pauseButton->setIcon(QIcon("../imgIcon/pauseActiveButton.png"));
    else
        ui->pauseButton->setIcon(QIcon("../imgIcon/pauseButton.png"));
}

void MainWindow::togglePlayIcon(bool b)
{
    if(b)
        ui->playButton->setIcon(QIcon("../imgIcon/PlayActiveButton.png"));
    else
        ui->playButton->setIcon(QIcon("../imgIcon/playButton.png"));
}

void MainWindow::raiseVol()
{
    ui->volumeSlider->setValue(ui->volumeSlider->value()+10);
}

void MainWindow::lowerVol()
{
    ui->volumeSlider->setValue(ui->volumeSlider->value()-10) ;
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

















