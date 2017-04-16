#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <buttonhoverwatcher.h>
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


private slots :
    void stopIcon() ;
    void togglePauseIcon(bool b);
    void togglePlayIcon(bool b);


    void raiseVol() ;
    void lowerVol() ;

    void isActiveSongModeTab();
    void isActiveRadioModeTab();
};

#endif // MAINWINDOW_H
