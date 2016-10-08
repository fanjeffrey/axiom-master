#include <iostream>
#include <fstream>

#include "GameRecord.h"
#include "User.h"
#include "GameRecordManager.h"

using namespace std;

void GameRecordManager::LoadGameData(User & user)
{
    ifstream f("game-data.sav");
    
    if (! f)
    {
        cerr << "Oops! Unable to open game data file for user: " << user.GetName() << endl;
        return;
    }
    
    vector<GameRecord> gameRecords;

    string user_name;
    int tries, rights;
    while(f >> user_name)
    {
        f >> tries >> rights;

        if (user_name == user.GetName())
        {
            GameRecord rec(tries, rights);
            gameRecords.push_back(rec);
        }
    }

    f.close();

    user.SetGameRecords(gameRecords);
}

void GameRecordManager::SaveGameRecord(User & user, GameRecord & record)
{
    ofstream f ("game-data.sav", ios_base::app);

    if (! f)
    {
        cerr << "Oops! Unable to open game data file to save game record for user: " << user.GetName() << endl;
        return;
    }

    f << user.GetName() << " " << record.Tries << " " << record.Rights << endl;

    f.close();
}