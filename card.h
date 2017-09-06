#ifndef CARD_H
#define CARD_H
#include <string>
#define cardNumber 34
class card
{
public:
    card(std::string n);//初始化需要得到名字

public:
    virtual void skill();//skill召唤的，可以改做召唤卡牌的skill,(到底是一上场被触发，还是怎么样需要考虑)，触发条件可以connect
    virtual void setAgain();//对比赛造成的变化进行重置，即返回到最新的位置

    std::string getName();
    int getRank();
protected:
    int power;//力量值
    int camp;//所属阵营，0表示对方，1表示己方
    int place;//在场上的位置,0表示任意，1表示前排，2表示中排，3表示后排
    int type;//比如在场上，没有被发出，或者在墓地，或者消失
    std::string name;
    int rank;//金银铜（1为金，2为银，3为铜）
    int feature;//属性:1佚亡，2狂猎，3间谍，4构造体
};

#endif // CARD_H
