#include "GameRecord.h"
#include "User.h"

#pragma once

class GameRecordManager
{
    public:
        void LoadGameData(User & user);
        void SaveGameRecord(User & user, GameRecord & record);
};