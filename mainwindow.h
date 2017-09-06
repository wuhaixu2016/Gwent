#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include"camp.h"
#include "card.h"
#include "player.h"
#include "process.h"
#include <QMainWindow>
#include <QPushButton>
#include <QPropertyAnimation>
#include <QSignalMapper>
#include <QString>
#define winW 1600
#define winH 900

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public slots:
    void clickNP();
    void clickOP();
    void clickSign();
    void clickLogin();
    void clickR();
    void clickCM();
    void changeCardList();
    void explainButtonChange(int);
    void addCard();
    void delCard();
    void quitCardM();
    void aiFightBackground();
    void beginFight();

public:
    explicit MainWindow(QWidget *parent = 0);
    void setBeginBackgroud();
    void setChooseBackgroud();
    ~MainWindow();
    bool eventFilter(QObject *watched, QEvent *event) override;

private:
    void initWindow();//界面内容的初始化
    void buttonInit();//设定数组
    void textInit();//文本的初始化
    void connectInit();//链接的初始化

private:
    Ui::MainWindow *ui;
    camp* m_camp;
    int tempCardNumber;//目前卡牌的id

    QPushButton *cardButton[cardNumber];//好多卡牌的索引
    QString pathString[cardNumber];//图片路径的字符串
    QString explainString[cardNumber];//解释text的字符串
    std::string cardName[cardNumber];//卡牌名称
    QPushButton* m_cards[11];//我的卡牌所在的位置
    QPushButton* y_cards[11];//对方的卡牌所在的位置
    QPushButton* m_cardB[3][10];//我这一方三排的卡牌位置
    QPushButton* y_cardB[3][10];//对方三排的卡牌位置
};

#endif // MAINWINDOW_H
