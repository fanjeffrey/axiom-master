#include <string>
#include <vector>

#include "GameRecord.h"

using namespace std;

#pragma once

class User
{
    public:
        User(string & name) { _name = name; }
        string GetName() const { return _name; }
        const vector<GameRecord> & GetGameRecords() const { return _records; }
        void SetGameRecords(vector<GameRecord> & records) { _records = records; }

    private:
        string _name;
        vector<GameRecord> _records;
};