#include "card.h"
/*
int power;//力量值
int camp;//所属阵营，0表示对方，1表示己方
int place;//在场上的位置,-1表示敌方任意，0表示我方任意，1表示前排，2表示中排，3表示后排
int type;//比如1在场上，2在场上没有发出，3在牌组里，4在墓地，5消失
std::string name;
int rank;//金银铜（1为金，2为银，3为铜），0表示首领
int feature;//属性:1佚亡，2狂猎，3间谍，4构造体,0表示一般情况, 5表示残物//还有坚守
//间谍在skill体现
//一局战斗后重置所有属性
*/
card::card(std::string n)
{
    name = n;
    type = 3;//构造时默认为在牌组里
    if(name == "破晓")
    {
        power = 0;
        camp = 1;
        place = 0;
        rank = 3;
        feature = 1;
    }
    if(name == "晴空")
    {
        power = 0;
        camp = 1;
        place = 0;
        rank = 3;
        feature = 1;
    }
    if(name == "重整")
    {
        power = 0;
        camp = 1;
        place = 0;
        rank = 3;
        feature = 1;
    }
    if(name == "刺骨冰霜")
    {
        power = 0;
        camp = 1;
        place = -1;
        rank = 3;
        feature = 0;
    }
    if(name == "蔽日浓雾")
    {
        power = 0;
        camp = 1;
        place = -1;
        rank = 3;
        feature = 0;
    }
    if(name == "倾盆大雨")
    {
        power = 0;
        camp = 1;
        place = -1;
        rank = 3;
        feature = 0;
    }
    if(name == "撕裂")
    {
        power = 0;
        camp = 1;
        place = -1;
        rank = 3;
        feature = 0;
    }
    if(name == "指挥号角")
    {
        power = 0;
        camp = 1;
        place = 0;
        rank = 2;
        feature = 0;
    }
    if(name == "贝克尔的扭曲之镜")
    {
        power = 0;
        camp = 1;
        place = 0;
        rank = 2;
        feature = 0;
    }
    if(name == "杰洛特：伊格尼法印")
    {
        power = 5;
        camp = 1;
        place = 0;
        rank = 1;
        feature = 0;
    }
    if(name == "达冈")
    {
        power = 6;
        camp = 1;
        place = 0;
        rank = 0;
        feature = 1;
    }
    if(name == "小雾妖")
    {
        power = 4;
        camp = 1;
        place = 0;
        rank = 3;
        feature = 0;
    }
    if(name == "盖尔")
    {
        power = 1;
        camp = 1;
        place = 0;
        rank = 1;
        feature = 2;
    }
    if(name == "赛尔伊诺鹰身女妖")
    {
        power = 5;
        camp = 1;
        place = 0;
        rank = 3;
        feature = 0;
    }
    if(name == "鹰身女妖蛋")
    {
        power = 1;
        camp = 1;
        place = 0;
        rank = 3;
        feature = 1;
    }
    if(name == "鹰身女妖幼崽")
    {
        power = 1;
        camp = 1;
        place = 0;
        rank = 3;
        feature = 1;
    }
    if(name == "林妖")
    {
        power = 5;
        camp = 1;
        place = 0;
        rank = 1;
        feature = 5;
    }
    if(name == "暴怒的狼")
    {
        power = 1;
        camp = 1;
        place = 0;
        rank = 3;
        feature = 1;
    }
    if(name == "土元素")
    {
        power = 6;
        camp = 1;
        place = 1;
        rank = 3;
        feature = 4;
    }
    if(name == "次级土元素")
    {
        power = 2;
        camp = 1;
        place = 0;
        rank = 3;
        feature = 1;   //这里还是构造体##
    }
    if(name == "老巫妪织婆")
    {
        power = 6;
        camp = 1;
        place = 3;
        rank = 2;
        feature = 5;
    }
    if(name == "老巫妪煮婆")
    {
        power = 8;
        camp = 1;
        place = 3;
        rank = 2;
        feature = 5;
    }
    if(name == "老巫妪呢喃婆")
    {
        power = 6;
        camp = 1;
        place = 3;
        rank = 2;
        feature = 5;
    }
    if(name == "大狮鹫")
    {
        power = 8;
        camp = 1;
        place = 0;
        rank = 3;
        feature = 0;
    }
    if(name == "狂猎骑士")
    {
        power = 8;
        camp = 1;
        place = 0;
        rank = 3;
        feature = 2;
    }
    if(name == "卡兰希尔")
    {
        power = 8;
        camp = 1;
        place = 0;
        rank = 1;
        feature = 2;
    }
    if(name == "畏惧者")
    {
        power = 12;
        camp = 1;
        place = 0;
        rank = 2;
        feature = 1;  //还是构造体
    }
    if(name == "暗影长者")
    {
        power = 5;
        camp = 1;
        place = 0;
        rank = 0;
        feature = 1;
    }
    if(name == "蟹蜘蛛")
    {
        power = 3;
        camp = 1;
        place = 3;
        rank = 3;
        feature = 0;
    }
    if(name == "蜥蜴人战士")
    {
        power = 6;
        camp = 1;
        place = 0;
        rank = 3;
        feature = 0;
    }
    if(name == "蟹蜘蛛巨兽")
    {
        power = 6;
        camp = 1;
        place = 1;
        rank = 3;
        feature = 0;
    }
    if(name == "蟹蜘蛛幼虫")
    {
        power = 3;
        camp = 1;
        place = 0;
        rank = 3;
        feature = 1;
    }
    if(name == "雷霆药水")
    {
        power = 0;
        camp = 1;
        place = 0;
        rank = 3;
        feature = 0;
    }
    if(name == "萝卜")
    {
        power = 4;
        camp = 1;
        place = 0;
        rank = 2;
        feature = 0;
    }
}

std::string card::getName()
{
    return name;
}

int card::getRank()
{
    return rank;
}
