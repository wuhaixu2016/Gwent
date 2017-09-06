#ifndef PLAYER_H
#define PLAYER_H
#include <string>


class player
{
private:
    int degree;
    std::string name;
    std::string password;

public:
    player();
    int check(std::string n, std::string p);
    void addPlayer(std::string n, std::string p);
};

#endif // PLAYER_H
