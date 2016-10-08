#ifndef GAMERECORD_HEAD
#define GAMERECORD_HEAD
//#pragma once

class GameRecord
{
    public:
        GameRecord(int tries = 0, int rights = 0) { Tries = tries; Rights = rights; }
        int Tries;
        int Rights;
};

#endif