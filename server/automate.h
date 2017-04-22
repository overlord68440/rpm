#ifndef AUTOMATE_H
#define AUTOMATE_H


#include <QStateMachine>
#include <QState>
#include <QFinalState>
#include <QSignalTransition>

class automate
{
public:

    //const

    automate();

    //destr

    ~automate() ;

    //var

    QStateMachine * player = new QStateMachine() ;


    QState *radioMode = new QState(player) ;
    QState *musicMode = new QState(player) ;
    QState *mute = new QState(player) ;
    QState *function = new QState(player) ;

    QState *speedMusic = new QState(function) ;
    QState *playing = new QState(function) ;
    QState *pausedMusic = new QState(function) ;
    QState *stopMusic = new QState(function) ;

    QFinalState *fin = new QFinalState(player) ;


};

#endif // AUTOMATE_H
