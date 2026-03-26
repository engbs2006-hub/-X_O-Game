#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;
short ReadPositiveNumber()
{
    short Number;
    do
    {
        cin >> Number;
    } while (Number <= 0);
    return Number;
}

short Range(string massage)
{
    short range;
    do
    {
        cout << massage;
        range = ReadPositiveNumber();
    } while (range >= 10);
    return range;
}

short ChoiceRoundsCount()
{
    short RoundsCount;
    RoundsCount = Range("How many Rounds you Want ?thr rounds  must be  between (1,9) !");
    return RoundsCount;
}

string PlayerChoice()
{
    string Tool;
    do
    {
        cout << "Player1 Choice : X,O ?";
        cin >> Tool;
    } while (Tool != "X" && Tool != "O");
    return Tool;
}

string ComputerChoice(string tool)
{
    string Tool;
        cout << "Computer Choice : X,O ?";
        if (tool == "X")
            Tool = "O";
        else
            Tool = "X";
        cout << Tool << endl;
    return Tool;
}

void SetPlayersChoice(string Players[2])
{
        cout << "            Players Choice !\n";
        Players[0] = PlayerChoice();
        Players[1] = ComputerChoice(Players[0]);
}

bool ComparisonStage(string XO[10], string Players[2], string Winar[4])
{
    if (XO[1] != "" && XO[1] == XO[2] && XO[1] == XO[3] ||
        XO[1] != "" && XO[1] == XO[4] && XO[1] == XO[7] ||
        XO[1] != "" && XO[1] == XO[5] && XO[1] == XO[9])
    {
        if (Players[0] == XO[1])
        {
            Winar[1] = "Player";
        }
        else if (Players[1] == XO[1])
        {
            Winar[2] = "Computer";
        }
        return true;
    }
    else if (XO[2] != "" && XO[2] == XO[5] && XO[2] == XO[8])
    {
        if (Players[0] == XO[2])
        {
            Winar[1] = "Player";
        }
        else if (Players[1] == XO[2])
        {
            Winar[2] = "Computer";
        }
        return true;
    }
    else if (XO[3] != "" && XO[3] == XO[5] && XO[3] == XO[7] ||
        XO[3] != "" && XO[3] == XO[6] && XO[3] == XO[9])
    {
        if (Players[0] == XO[3])
        {
            Winar[1] = "Player";

        }
        else if (Players[1] == XO[3])
        {
            Winar[2] = "Computer";

        }
        return true;
    }
    else if (XO[4] != "" && XO[4] == XO[5] && XO[4] == XO[6])
    {
        if (Players[0] == XO[4])
        {
            Winar[1] = "Player";
        }
        else if (Players[1] == XO[4])
        {
            Winar[2] = "Computer";
        }
        return true;
    }
    else if (XO[7] != "" && XO[7] == XO[8] && XO[7] == XO[9])
    {
        if (Players[0] == XO[7])
        {
            Winar[1] = "Player";
        }
        else if (Players[1] == XO[7])
        {
            Winar[2] = "Computer";
        }
        return true;
    }
    else
    {
        Winar[3] = "Draw";
        return false;
    }
}

int RandomNumber(int From, int To)
{
    int Number = rand() % (To - From + 1) + From;
    return Number;
}

string StartGame(string Players[2], string Winar[4])
{
    SetPlayersChoice(Players);
    string XO[10];
    short place = 0;
    for (int i = 1;i <= 5;i++)
    {
        do
        {
            cout << "Enter Place : ";
            place = Range("The Place must :{ be between (1,9) && defferent  the previous steps.} ?");
            if (XO[place] == "")
            {
                XO[place] = Players[0];
                break;
            }
        } while (XO[place] != "");


        cout << endl;
        cout << " " << XO[1] << " | " << XO[2] << " | " << XO[3] << endl;
        cout << "---+---+---" << endl;
        cout << " " << XO[4] << " | " << XO[5] << " | " << XO[6] << endl;
        cout << "---+---+---" << endl;
        cout << " " << XO[7] << " | " << XO[8] << " | " << XO[9] << endl;
        cout << endl;
        if (ComparisonStage(XO, Players, Winar) == true)
        {
            if (XO[place] == Players[0])
                return Winar[1];
            else
                return Winar[2]; 
        }
      
        if (i == 5)
            break;
        do
        {
            cout << "Computer Choice : ";
            place = RandomNumber(1, 9);
            cout << place;
            if (XO[place] == "")
            {
                XO[place] = Players[1];
                break;
            }
        } while (XO[place] != "");

        cout << endl;
        cout << " " << XO[1] << " | " << XO[2] << " | " << XO[3] << endl;
        cout << "---+---+---" << endl;
        cout << " " << XO[4] << " | " << XO[5] << " | " << XO[6] << endl;
        cout << "---+---+---" << endl;
        cout << " " << XO[7] << " | " << XO[8] << " | " << XO[9] << endl;
        cout << endl;
        if (ComparisonStage(XO, Players, Winar) == true)
        {
            if (XO[place] == Players[0])
                return Winar[1];
            else
                return Winar[2];
        }
    }
    return Winar[3];
}

bool RePlay()
{
    bool replay;
    cout << "                                    Do you want to play again ? Y :[1] / N :[0] ? ";
    cin >> replay;
    return replay;
}

string SetTheFinalWinar(int frequency[4])
{
    if (frequency[1] > frequency[2])
    {
        return "Player";
    }
    else if (frequency[2] > frequency[1])
    {
        return "Computer";
    }
    else
        return "Draw";
}

void frequancyResults(string& GameWinar, int frequancy[4])
{
    string Players[2], Winar[4];
    GameWinar = StartGame(Players, Winar);
    if (GameWinar == Winar[1])
    {
        frequancy[1]++;
    }
    else if (GameWinar == Winar[2])
    {
        frequancy[2]++;
    }
    else
        frequancy[3]++;
}

void TurnSqreenToChangeColor(string GameWinar)
{
    if (GameWinar == "Player")
    {
        system("color 2F");
        cout << "\a";
    }
    else if (GameWinar == "Computer")
        system("color 4F");
    else if (GameWinar == "Draw")
        system("color 6F");
}

void FrequancyGame(int frequancy[4], int& Rounds, string GameWinar)
{
    string Winar[4], Players[2];
    Rounds = ChoiceRoundsCount();
    for (int i = 1;i <= Rounds;i++)
    {
        cout << "__________________Round [" << i << "]__________________" << endl;
        {
            frequancyResults(GameWinar, frequancy);
            cout << GameWinar << endl;
            TurnSqreenToChangeColor(GameWinar);
        }
    }
}

void GameOver(int frequancy[4], int Rounds, string GameWinar)
{
    FrequancyGame(frequancy, Rounds, GameWinar);
    string FinamlWinar = SetTheFinalWinar(frequancy);
    cout << "                                    ___________________________________________________________________________\n\n";
    cout << "                                                              +++ Game Over +++                                \n\n";
    cout << "                                    ___________________________________________________________________________\n\n";
    cout << "                                    ____________________________ [Game Results] _______________________________\n\n";
    cout << "                                    Game Rounds         : " << Rounds << endl;
    cout << "                                    Player won times   : " << frequancy[1] << endl;
    cout << "                                    Computer won times   : " << frequancy[2] << endl;
    cout << "                                    Draw times          : " << frequancy[3] << endl;
    cout << "                                    Final winner        : " << FinamlWinar << "\n\n";
    TurnSqreenToChangeColor(FinamlWinar);
    cout << "                                    ___________________________________________________________________________\n\n";
    bool replay = RePlay();
    if (replay == true)
    {
        system("cls");
        system("color 0F");
        frequancy[1] = 0; frequancy[2] = 0; frequancy[3] = 0;
        GameOver(frequancy, Rounds, GameWinar);
    }
}


int main()
{
    srand((unsigned)time(NULL));
    string  Players[2] = { " " }, Winar[4] = { " " }, GameWinar; 
    int frequancy[4] = { 0 }, Rounds = 0;
    GameOver(frequancy, Rounds, GameWinar);

    return 0;
}
