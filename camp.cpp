#include "camp.h"

camp::camp()
{
    initCamp();
}

void camp::initCamp()
{
    for(int i = 0; i<maxCardNumber; i++)
    {
        group[i] = nullptr;
    }
    group[0] = new card("破晓");
    group[1] = new card("刺骨冰霜");
    group[2] = new card("刺骨冰霜");
    group[3] = new card("蔽日浓雾");
    group[4] = new card("小雾妖");
    group[5] = new card("赛尔伊诺鹰身女妖");
    group[6] = new card("赛尔伊诺鹰身女妖");
    group[7] = new card("大狮鹫");
    group[8] = new card("狂猎骑士");
    group[9] = new card("蟹蜘蛛");
    group[10] = new card("指挥号角");
    group[11] = new card("老巫妪织婆");
    group[12] = new card("老巫妪煮婆");
    group[13] = new card("老巫妪呢喃婆");
    group[14] = new card("蟹蜘蛛");
    group[15] = new card("雷霆药水");
    group[16] = new card("萝卜");
    group[17] = new card("畏惧者");
    group[18] = new card("蜥蜴人战士");
    group[19] = new card("蟹蜘蛛巨兽");
    group[20] = new card("大狮鹫");
    group[21] = new card("蔽日浓雾");
    group[22] = new card("卡兰希尔");
    group[23] = new card("暗影长者");
    group[24] = new card("林妖");
    group[25] = new card("杰洛特：伊格尼法印");

    cardN = 26;
    rankCardN[0] = 1;
    rankCardN[1] = 3;
    rankCardN[2] = 6;
    rankCardN[3] = 16;
}

bool camp::checkSaveAndQuit()
{
    if(rankCardN[0] < 1)
    {
        QMessageBox::warning(NULL, "warning", "至少有一张领袖牌", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
        return false;
    }
    if(cardN < 25)
    {
        QMessageBox::warning(NULL, "warning", "至少有25张牌", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
        return false;
    }
    return true;
}

//0表示不可以添加，1表示可以添加
bool camp::checkAdd(card* temp)
{

    if(cardN >= 40)
    {
        QMessageBox::warning(NULL, "warning", "卡牌最多40张", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
        return false;
    }
    if(temp->getRank() == 2 && rankCardN[2] >= 6)
    {
        QMessageBox::warning(NULL, "warning", "银卡牌最多6张", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
        return false;
    }
    if(temp->getRank() == 1 && rankCardN[1] >= 4)
    {
        QMessageBox::warning(NULL, "warning", "金卡牌最多4张", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
        return false;
    }
    if(temp->getRank() == 0 && rankCardN[0] >= 1)
    {
        QMessageBox::warning(NULL, "warning", "领袖牌最多一张", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
        return false;
    }
    int n = 0;
    for(int i = 0; i<cardN; i++)
    {
        if(group[i]->getName() == temp->getName())
            n++;
    }
    if(temp->getRank() == 2 && n >= 1)
    {

        QMessageBox::warning(NULL, "warning", "银卡牌同名牌最多1张", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
        return false;
    }
    if(temp->getRank() == 1 && n >= 1)
    {
        QMessageBox::warning(NULL, "warning", "金卡牌同名牌最多1张", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
        return false;
    }
    if(temp->getRank() == 3 && n >= 3)
    {
        QMessageBox::warning(NULL, "warning", "铜卡牌同名牌最多3张", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
        return false;
    }
    if(temp->getName() == "晴空" || temp->getName() == "重整" || temp->getName() == "鹰身女妖蛋"
            || temp->getName() == "鹰身女妖幼崽" || temp->getName() == "蟹蜘蛛幼虫" || temp->getName() == "暴怒的狼" || temp->getName() == "次级土元素")
    {
        QMessageBox::warning(NULL, "warning", "此牌不可以直接选择", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
        return false;
    }

    return true;
}

int camp::checkDel(std::string name)
{
    for(int i = 0; i<cardN; i++)
    {
        if(group[i]->getName() == name)
            return i;
    }
    QMessageBox::warning(NULL, "warning", "您的牌组里没有这张牌", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
    return -1;
}
