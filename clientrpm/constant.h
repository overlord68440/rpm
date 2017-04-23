#ifndef CONSTANT_H
#define CONSTANT_H


enum speed
{
    fastBackward = -4 ,
    backward=-2,
    normal=1 ,
    forward=2,
    fastForward=4
};

enum stoppedState
{
    musicStopped =0,
    musicListecleared = 1
};

enum orders
{
    loadFile= 1,
    loadFlux= 2 ,
    loadPlaylist= 3 ,
    pauseOrder = 4 ,
    play = 5,
    stop = 6,

    previous = 11,
    next = 12,
    speedUp= 13,
    speedDown = 14,

    raiseVolume = 21,
    lowerVolume = 22 ,
    muteOn = 23,
    muteOff = 24,

    shuffle = 31 ,
    repeatOn = 32,
    repeatOff= 33,
};





#endif // CONSTANT_H
