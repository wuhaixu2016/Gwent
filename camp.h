#ifndef CAMP_H
#define CAMP_H
#include"card.h"
#include <QMessageBox>
#include <string>
#define maxCardNumber 40

class camp
{
public:
    camp();
    bool checkAdd(card* temp);
    int checkDel(std::string);
    void initCamp();
    bool checkSaveAndQuit();
public:
    int data;//用来存储胜利局数
    int giveUp;//是否弃牌
    card* group[maxCardNumber];//表示牌组套牌,最初设定一部分内容
    int cardN;
    int rankCardN[4];
};

#endif // CAMP_H
