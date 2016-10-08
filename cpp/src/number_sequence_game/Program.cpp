#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <cstdlib>
#include <fstream>

#include "GameRecord.h"
#include "User.h"
#include "GameRecordManager.h"

using namespace std;

void welcome(const User & user);
void display_user_game_data(const User & user);
int choose_one_record_to_start(const User & user);
void display_number_sequence(vector<int> * nq);

int main ()
{
    cout << "starting ..." << endl;

    cout << "Please enter your name: ";
    string username;
    cin >> username;

    User user(username);
    welcome(user);

    // try to load game data for user
    cout << "Loading game data for you..." << endl;
    GameRecordManager grm;
    grm.LoadGameData(user);

    GameRecord newGame(0,0);

    if (user.GetGameRecords().size() < 1)
    {
        cerr << "You'll begin as a new player." << endl;
    }
    else
    {
        display_user_game_data(user);
        int selected_index = choose_one_record_to_start(user);
        GameRecord selected = user.GetGameRecords()[selected_index - 1];
        newGame.Tries = selected.Tries;
        newGame.Rights = selected.Rights;

        cout << "debug -------------" << endl;
        cout << "tries: " << newGame.Tries << endl;
        cout << "rights: " << newGame.Rights << endl;
        cout << "debug end ---------" << endl;
    }


    // start game
    const int seq_count = 6;
    string seq_names[seq_count] = {
        "Fibonacci", "Lucas", "Pell", "Triangular", "Square", "Pentagonal"
    };

    int raw_data[] = {
        1, 1, 2, 3, 5, 8, 13, 21,       // Fibonacci
        1, 3, 4, 7, 11, 18, 29, 47,     // Lucas
        1, 2, 5, 12, 29, 70, 169, 408,  // Pell
        1, 3, 6, 10, 15, 21, 28, 36,    // Triangular
        1, 4, 9, 16, 25, 36, 49, 64,    // Square
        1, 5, 12, 22, 35, 51, 70, 92    // Pentagonal
    };

    vector<int> fibonacci(raw_data, raw_data + 8);
    vector<int> lucas(raw_data + 8, raw_data + 16);
    vector<int> pell(raw_data + 16, raw_data + 24);
    vector<int> triangular(raw_data + 24, raw_data + 32);
    vector<int> square(raw_data + 32, raw_data + 40);
    vector<int> pentagonal(raw_data + 40, raw_data + 48);

    vector<int> * seq_addrs[seq_count] = {
        & fibonacci, & lucas, & pell, & triangular, & square, & pentagonal
    };

    bool wanna_play = true;
    while(wanna_play)
    {
        srand(seq_count);
        int current_seq_index = rand() % seq_count;
        string current_seq_name = seq_names[current_seq_index];
        vector<int> * current_seq = seq_addrs[current_seq_index];
        
        int correct_answer = (* current_seq)[5];

        cout << "What is the next number after these numbers below?" << endl;
        display_number_sequence(current_seq);

        bool guess_again = true;
        bool guess_right = false;
        while(!guess_right && guess_again)
        {
            cout << endl << "Please enter your answer: ";
            int user_guess;
            cin >> user_guess;
            cout << endl << "Your answer is " << user_guess << "." << endl;
            
            newGame.Tries ++;

            if (correct_answer == user_guess)
            {
                guess_right = true;
                newGame.Rights ++;

                cout << "Right!" << endl;
            }
            else
            {
                guess_right = false;

                cout << "Wrong! Want guess again? (Y/N)" << endl;
                char user_resp;
                cin >> user_resp;
                if (user_resp == 'N' || user_resp == 'n')
                {
                    guess_again = false;                    
                }
                else
                {
                    guess_again = true;
                }
            }
        }

        cout << "Wanna play more? (Y/N) ";
        char user_resp;
        cin >> user_resp;
        if (user_resp == 'N' || user_resp == 'n')
        {
            wanna_play = false;
        }
        else
        {
            wanna_play = true;
        }
        cout << endl;
    }

    // save game data
    cout << "Saving game data... ";
    grm.SaveGameRecord(user, newGame);
    cout << "Done." << endl;

    return 0;
}

void welcome(const User & user)
{
    cout << "Hello, " << user.GetName() << "!" << endl;
}

void display_user_game_data(const User & user)
{
    cout << "No." << " - " << "Tries" << "\t" << "Rights" << endl;

    for(unsigned int i=0; i < user.GetGameRecords().size(); i++)
    {
        cout << i + 1 << " - " << user.GetGameRecords()[i].Tries << "\t" 
                            << user.GetGameRecords()[i].Rights << endl;
    }
}

int choose_one_record_to_start(const User & user)
{
    int the_last_index = user.GetGameRecords().size();

    cout << "Please enter a number to choose one record to continue with that." << endl
        << "If your input is less that 1 and greater than " << the_last_index << ", "
        << "the last one will be chosen to continue." << endl;

    int n;
    cin >> n;

    if (1 <= n && n <= the_last_index)
    {
        return n;
    }
    else
    {
        return the_last_index;
    }
}

void display_number_sequence(vector<int> * ns)
{
    for(int i = 0; i < 5; i ++)
            cout << setw(4) << (* ns)[i];
}