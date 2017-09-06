#include "player.h"
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;

player::player()
{
    degree = 0;
}

//返回0表示密码错误，返回1表示可以通过，返回2表示没有此用户
int player::check(std::string n, std::string p)
{
    ifstream ifile;
    ifile.open("../gwent_v1/res/playerdata/player_data.txt");
    char line[1024] = {'\0'};
    string x = "";
    string y = "";
    while(ifile.getline(line, sizeof(line)))
    {
        stringstream ou(line);
        ou >> x;
        ou >> y;
        if(n == x && p == y)
        {
            ifile.close();
            return 1;
        }
        else if(n == x && p != y)
        {
            ifile.close();
            return 0;
        }
    }
    ifile.close();
    return 2;
}

void player::addPlayer(std::string n, std::string p)
{
    ofstream ofile;
    ofile.open("../gwent_v1/res/playerdata/player_data.txt", ios::app);
    ofile << n << " " << p << endl;
    ofile.close();
}




