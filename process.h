#ifndef PROCESS_H
#define PROCESS_H

class process
{
public:
    process();
public:
    void chooseCamp();//开始选择先后手
    void chooseCard();//过程中每局开始选择替换卡牌
    void produceCard();//每局开始开始时生产卡牌
    void judgeRes();//最后判定结果
public:
    int weather;//反应场上的天气状况。
};

#endif // PROCESS_H
