#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "player.h"
#include <string>
#include <QDebug>
using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle(tr("GWENT"));
    //setFixedSize(winW, winH);
    m_camp = new camp;//阵营
    tempCardNumber = -1;

    initWindow();//初始化ui控件
    textInit();
    buttonInit();
    connectInit();
    setBeginBackgroud();
}

void MainWindow::initWindow()
{
    ui->background->setCurrentIndex(0);
    ui->r0Number->display(m_camp->rankCardN[0]);
    ui->r1Number->display(m_camp->rankCardN[1]);
    ui->r2Number->display(m_camp->rankCardN[2]);
    ui->r3Number->display(m_camp->rankCardN[3]);

    string s[4] = {""};

    for(int i = 0; i<m_camp->cardN; i++)
    {
        s[m_camp->group[i]->getRank()] += m_camp->group[i]->getName();
        s[m_camp->group[i]->getRank()] += " ";
    }
    QString s1[4];
    for(int i = 0; i<4; i++)
    {
        s1[i] = QString::fromStdString(s[i]);
    }
    ui->r0Text->setText(s1[0]);
    ui->r1Text->setText(s1[1]);
    ui->r2Text->setText(s1[2]);
    ui->r3Text->setText(s1[3]);
}

void MainWindow::connectInit()
{
    connect(ui->newPlayer, SIGNAL(clicked()), this, SLOT(clickNP()));
    connect(ui->oldPlayer, SIGNAL(clicked()), this, SLOT(clickOP()));
    connect(ui->sign, SIGNAL(clicked()), this, SLOT(clickSign()));
    connect(ui->loginButton, SIGNAL(clicked()), this, SLOT(clickLogin()));
    connect(ui->returnN, SIGNAL(clicked()), this, SLOT(clickR()));
    connect(ui->returnO, SIGNAL(clicked()), this, SLOT(clickR()));
    connect(ui->cardManage, SIGNAL(clicked()), this, SLOT(clickCM()));
    connect(ui->nextGroup, SIGNAL(clicked()), this, SLOT(changeCardList()));
    connect(ui->comfirmButton, SIGNAL(clicked()), this, SLOT(addCard()));
    connect(ui->gUButton, SIGNAL(clicked()), this, SLOT(delCard()));
    connect(ui->saveButton, SIGNAL(clicked()), this, SLOT(quitCardM()));
    connect(ui->aiPlayerButton, SIGNAL(clicked()), this, SLOT(aiFightBackground()));
    connect(ui->cardGroup1, SIGNAL(clicked()), this, SLOT(beginFight()));

    for(int i  = 0; i<cardNumber;i ++)
    {
        cardButton[i]->installEventFilter(this);
    }
}

void MainWindow::textInit()
{
    pathString[0] = QString::fromStdString("QPushButton{border-image:url(../gwent_v1/res/cardPicture/暗影长者.png);}");
    pathString[1] = QString::fromStdString("QPushButton{border-image:url(../gwent_v1/res/cardPicture/暴怒的狼.png);}");
    pathString[2] = QString::fromStdString("QPushButton{border-image:url(../gwent_v1/res/cardPicture/贝克尔的扭曲之镜.png);}");
    pathString[3] = QString::fromStdString("QPushButton{border-image:url(../gwent_v1/res/cardPicture/蔽日浓雾.png);}");
    pathString[4] = QString::fromStdString("QPushButton{border-image:url(../gwent_v1/res/cardPicture/次级土元素.png);}");
    pathString[5] = QString::fromStdString("QPushButton{border-image:url(../gwent_v1/res/cardPicture/刺骨冰霜.png);}");
    pathString[6] = QString::fromStdString("QPushButton{border-image:url(../gwent_v1/res/cardPicture/达冈.png);}");
    pathString[7] = QString::fromStdString("QPushButton{border-image:url(../gwent_v1/res/cardPicture/大狮鹫.png);}");
    pathString[8] = QString::fromStdString("QPushButton{border-image:url(../gwent_v1/res/cardPicture/盖尔.png);}");
    pathString[9] = QString::fromStdString("QPushButton{border-image:url(../gwent_v1/res/cardPicture/杰洛特：伊格尼法印.png);}");
    pathString[10] = QString::fromStdString("QPushButton{border-image:url(../gwent_v1/res/cardPicture/卡兰希尔.png);}");
    pathString[11] = QString::fromStdString("QPushButton{border-image:url(../gwent_v1/res/cardPicture/狂猎骑士.png);}");
    pathString[12] = QString::fromStdString("QPushButton{border-image:url(../gwent_v1/res/cardPicture/老巫妪呢喃婆.png);}");
    pathString[13] = QString::fromStdString("QPushButton{border-image:url(../gwent_v1/res/cardPicture/老巫妪织婆.png);}");
    pathString[14] = QString::fromStdString("QPushButton{border-image:url(../gwent_v1/res/cardPicture/老巫妪煮婆.png);}");
    pathString[15] = QString::fromStdString("QPushButton{border-image:url(../gwent_v1/res/cardPicture/雷霆药水.png);}");
    pathString[16] = QString::fromStdString("QPushButton{border-image:url(../gwent_v1/res/cardPicture/林妖.png);}");
    pathString[17] = QString::fromStdString("QPushButton{border-image:url(../gwent_v1/res/cardPicture/萝卜.png);}");
    pathString[18] = QString::fromStdString("QPushButton{border-image:url(../gwent_v1/res/cardPicture/破晓.png);}");
    pathString[19] = QString::fromStdString("QPushButton{border-image:url(../gwent_v1/res/cardPicture/倾盆大雨.png);}");
    pathString[20] = QString::fromStdString("QPushButton{border-image:url(../gwent_v1/res/cardPicture/晴空.png);}");
    pathString[21] = QString::fromStdString("QPushButton{border-image:url(../gwent_v1/res/cardPicture/赛尔伊诺鹰身女妖.png);}");
    pathString[22] = QString::fromStdString("QPushButton{border-image:url(../gwent_v1/res/cardPicture/撕裂.png);}");
    pathString[23] = QString::fromStdString("QPushButton{border-image:url(../gwent_v1/res/cardPicture/土元素.png);}");
    pathString[24] = QString::fromStdString("QPushButton{border-image:url(../gwent_v1/res/cardPicture/畏惧者.png);}");
    pathString[25] = QString::fromStdString("QPushButton{border-image:url(../gwent_v1/res/cardPicture/蜥蜴人战士.png);}");
    pathString[26] = QString::fromStdString("QPushButton{border-image:url(../gwent_v1/res/cardPicture/小雾妖.png);}");
    pathString[27] = QString::fromStdString("QPushButton{border-image:url(../gwent_v1/res/cardPicture/蟹蜘蛛.png);}");
    pathString[28] = QString::fromStdString("QPushButton{border-image:url(../gwent_v1/res/cardPicture/蟹蜘蛛巨兽.png);}");
    pathString[29] = QString::fromStdString("QPushButton{border-image:url(../gwent_v1/res/cardPicture/蟹蜘蛛幼虫.png);}");
    pathString[30] = QString::fromStdString("QPushButton{border-image:url(../gwent_v1/res/cardPicture/鹰身女妖蛋.png);}");
    pathString[31] = QString::fromStdString("QPushButton{border-image:url(../gwent_v1/res/cardPicture/鹰身女妖幼崽.png);}");
    pathString[32] = QString::fromStdString("QPushButton{border-image:url(../gwent_v1/res/cardPicture/指挥号角.png);}");
    pathString[33] = QString::fromStdString("QPushButton{border-image:url(../gwent_v1/res/cardPicture/重整.png);}");

    explainString[0] = QString::fromStdString("暗影长者，领袖，战力：5，部署：吞噬1个友军单位，吸收它们的战力为自身的基础战力。重复两次。");
    explainString[1] = QString::fromStdString("暴怒的狼，铜，战力：1，佚亡");
    explainString[2] = QString::fromStdString("贝克尔的扭曲之镜，银，战力：0，对场上最强的单位造成数值等同于其战力的伤害，但最多不超过10点（无视护甲），并使场上最弱的非同名单位获得相同数值的增益。");
    explainString[3] = QString::fromStdString("蔽日浓雾，铜，战力：0，在对方单排降下“蔽日浓雾”每当己方回合开始时，对所在排最强的单位造成2点伤害");
    explainString[4] = QString::fromStdString("次级土元素，铜，战力：2，佚亡，构造体");
    explainString[5] = QString::fromStdString("刺骨冰霜，铜，战力：0，在对方单排降下“刺骨冰霜”。刺骨冰霜：每当己方回合开始时，对所在排最弱的单位造成2点伤害（己方==>被施刺骨冰霜的一方）");
    explainString[6] = QString::fromStdString("达冈，领袖，战力：6，佚亡，坚守。");
    explainString[7] = QString::fromStdString("大狮鹫，铜，战力：8，部署：移除所在排的天气效果。将1张铜色牌从一方墓场置入另一方墓场。");
    explainString[8] = QString::fromStdString("盖尔，金，战力：1，狂猎，部署：从牌组顶端各抽1张金色牌和银色牌。打出1张，将另1张置于牌组顶端。");
    explainString[9] = QString::fromStdString("杰洛特：伊格尼法印，金，战力：5，部署：若对方同排总战力不低于25，则摧毁其上所有最强的单位。");
    explainString[10] = QString::fromStdString("卡兰希尔，金，战力：8，狂猎，部署：将1个敌军单位移至其所在半场同排，并在此排降下刺骨冰霜");
    explainString[11] = QString::fromStdString("狂猎骑士，铜，战力：8，狂猎，使对方此排的“刺骨冰霜”伤害提高1点。");
    explainString[12] = QString::fromStdString("老巫妪呢喃婆，银，战力：6，残物，部署：从牌组打出“煮婆”和“织婆”。");
    explainString[13] = QString::fromStdString("老巫妪织婆，银，战力：6，残物，部署：从牌组打出“煮婆”和“呢喃婆”");
    explainString[14] = QString::fromStdString("老巫妪煮婆，银，战力：8，残物，部署：从牌组打出“织婆”和“呢喃婆”");
    explainString[15] = QString::fromStdString("雷霆药水，铜，战力：0，使 3 个相邻单位获得 2 点护甲和 3 点增益。");
    explainString[16] = QString::fromStdString("林妖，金，战力：5，残物，部署：生成3只“暴怒的狼”，并在对方同排降下“蔽日浓雾");
    explainString[17] = QString::fromStdString("萝卜，银，战力：4，己方每次从手牌打出金色牌时（领袖牌除外），便将牌组中的“萝卜”在其能力结算之前召唤至随机位置。");

    explainString[18] = QString::fromStdString("破晓，铜，战力：0，生成“晴空”或“重整”");
    explainString[19] = QString::fromStdString("倾盆大雨，铜，战力：0，在对方单排降下“倾盆大雨”倾盆大雨：每当己方回合开始时，对所在排最多2个随机单位造成1点伤害");
    explainString[20] = QString::fromStdString("晴空，铜，战力：0，佚亡，移除己方半场所有的天气效果。");
    explainString[21] = QString::fromStdString("赛尔伊诺鹰身女妖，铜，战力：5，部署：在自身左侧生成2个“鹰身女妖蛋”");
    explainString[22] = QString::fromStdString("撕裂，铜，战力：0，对单排所有单位造成3点伤害。");
    explainString[23] = QString::fromStdString("土元素，铜，战力：6，构造体，部署．获得护盾，遗愿：在该排末位生成2个“次级土元素”");
    explainString[24] = QString::fromStdString("畏惧者，银，战力：12，构造体，密探，佚亡，部署：从牌组顶端抽1张牌。将所在战场其他排的1个单位移至自身的同一排。");
    explainString[25] = QString::fromStdString("蜥蜴人战士，铜，战力：6，部署：吞噬右侧单位。每2回合，己方回合开始时，吞噬右侧单位。");
    explainString[26] = QString::fromStdString("小雾妖，铜，战力：4，每当己方“蔽日浓雾”在敌排生效，便从牌组打出1个“小雾妖”至己方同排。若牌组中没有“小雾妖”，则复活1个“小雾妖”至己方同排。若场上不再存在“蔽日浓雾”效果，则摧毁所有“小雾妖”");
    explainString[27] = QString::fromStdString("蟹蜘蛛，铜，战力：3，部署：从牌组打出所有“蟹蜘蛛”");
    explainString[28] = QString::fromStdString("蟹蜘蛛巨兽，铜，战力：6，每当有友军单位吞噬1张牌，便在随机排生成1只“蟹蜘蛛幼虫”，随后受到1点伤害（无视护甲）。部署：获得2点护甲");
    explainString[29] = QString::fromStdString("蟹蜘蛛幼虫，铜，战力：3，佚亡，部署：从牌组打出所有“蟹蜘蛛”单位。");

    explainString[30] = QString::fromStdString("鹰身女妖蛋，铜，战力：1，佚亡，使吞噬自身的单位获得额夕卜4点增益遗愿：在随机排生成1只影身女妖幼崽");
    explainString[31] = QString::fromStdString("鹰身女妖幼崽，铜，战力：1，佚亡");
    explainString[32] = QString::fromStdString("指挥号角，银，战力：0，使5个相邻单位获得4点增益。。");
    explainString[33] = QString::fromStdString("重整，铜，战力：0，佚亡，从牌组打出1张随机铜色单位牌。");

    cardName[0] = "暗影长者";
    cardName[1] = "暴怒的狼";
    cardName[2] = "贝克尔的扭曲之镜";
    cardName[3] = "蔽日浓雾";
    cardName[4] = "次级土元素";
    cardName[5] = "刺骨冰霜";
    cardName[6] = "达冈";
    cardName[7] = "大狮鹫";
    cardName[8] = "盖尔";
    cardName[9] = "杰洛特：伊格尼法印";
    cardName[10] = "卡兰希尔";
    cardName[11] = "狂猎骑士";
    cardName[12] = "老巫妪呢喃婆";
    cardName[13] = "老巫妪织婆";
    cardName[14] = "老巫妪煮婆";
    cardName[15] = "雷霆药水";
    cardName[16] = "林妖";
    cardName[17] = "萝卜";
    cardName[18] = "破晓";
    cardName[19] = "倾盆大雨";
    cardName[20] = "晴空";
    cardName[21] = "赛尔伊诺鹰身女妖";
    cardName[22] = "撕裂";
    cardName[23] = "土元素";
    cardName[24] = "畏惧者";
    cardName[25] = "蜥蜴人战士";
    cardName[26] = "小雾妖";
    cardName[27] = "蟹蜘蛛";
    cardName[28] = "蟹蜘蛛巨兽";
    cardName[29] = "蟹蜘蛛幼虫";
    cardName[30] = "鹰身女妖蛋";
    cardName[31] = "鹰身女妖幼崽";
    cardName[32] = "指挥号角";
    cardName[33] = "重整";
}

void MainWindow::buttonInit()
{
    QPalette pal;
    pal.setColor(QPalette::ButtonText, QColor(255, 255, 255));
    QFont ft;
    ft.setPointSize(24);
    ui->explainButton->setStyleSheet("QPushButton{border-image:url(../gwent_v1/res/cardPicture/Monster.jpg);}");

    ui->newPlayer->setStyleSheet("background-color: rgb(250, 128, 10)");
    ui->oldPlayer->setStyleSheet("background-color: rgb(250, 128, 10)");
    ui->sign ->setStyleSheet("background-color: rgb(250, 128, 10)");
    ui->returnN ->setStyleSheet("background-color: rgb(250, 128, 10)");
    ui->newNameLabel ->setStyleSheet("color: rgb(250, 128, 10)");
    ui->newPassLabel ->setStyleSheet("color: rgb(250, 128, 10)");
    ui->newPass->setEchoMode(QLineEdit::Password);
    ui->oldPass->setEchoMode(QLineEdit::Password);
    ui->loginButton ->setStyleSheet("background-color: rgb(250, 128, 10)");
    ui->returnO ->setStyleSheet("background-color: rgb(250, 128, 10)");
    ui->oldNameLabel ->setStyleSheet("color: rgb(250, 128, 10)");
    ui->oldPassLabel ->setStyleSheet("color: rgb(250, 128, 10)");

    ui->findPlayerButton->setStyleSheet("QPushButton{border-image:url(:/img/res/buttonPicture/button1.jpg);}\
                                        QPushButton:hover{border-image:url(:/img/res/buttonPicture/button_1.jpg);}");
    ui->friendPlayerButton->setStyleSheet("QPushButton{border-image:url(:/img/res/buttonPicture/button3.jpg);}\
                                          QPushButton:hover{border-image:url(:/img/res/buttonPicture/button_3.jpg);}");
    ui->aiPlayerButton->setStyleSheet("QPushButton{border-image:url(:/img/res/buttonPicture/button4.jpg);}\
                                      QPushButton:hover{border-image:url(:/img/res/buttonPicture/button_4.jpg);}");
    ui->cardManage ->setStyleSheet("QPushButton{border-image:url(:/img/res/buttonPicture/button5.jpg);}\
                                   QPushButton:hover{border-image:url(:/img/res/buttonPicture/button_5.jpg);}");

    ui->cardGroup1 ->setStyleSheet("QPushButton{border-image:url(../gwent_v1/res/buttonPicture/cardGroup1.jpg);}\
                                   QPushButton:hover{border-image:url(../gwent_v1/res/buttonPicture/cardGroup_1.jpg);}");
    ui->cardGroup2 ->setStyleSheet("QPushButton{border-image:url(../gwent_v1/res/buttonPicture/cardGroup2.jpg);}\
                                   QPushButton:hover{border-image:url(../gwent_v1/res/buttonPicture/cardGroup_2.jpg);}");

    ui->comfirmButton ->setStyleSheet("background-color: rgb(250, 128, 10)");
    ui->gUButton->setStyleSheet("background-color: rgb(250, 128, 10)");
    ui->saveButton ->setStyleSheet("background-color: rgb(250, 128, 10)");
    ui->nextGroup ->setStyleSheet("background-color: rgb(250, 128, 10)");

    ui->r0Text->setStyleSheet("background-color:lightYellow");
    ui->r1Text->setStyleSheet("background-color:lightYellow");
    ui->r2Text->setStyleSheet("background-color:lightYellow");
    ui->r3Text->setStyleSheet("background-color:lightYellow");

    cardButton[0] = ui->pushButton_1;
    cardButton[1] = ui->pushButton_2;
    cardButton[2] = ui->pushButton_3;
    cardButton[3] = ui->pushButton_4;
    cardButton[4] = ui->pushButton_5;
    cardButton[5] = ui->pushButton_6;
    cardButton[6] = ui->pushButton_7;
    cardButton[7] = ui->pushButton_8;
    cardButton[8] = ui->pushButton_9;
    cardButton[9] = ui->pushButton_10;
    cardButton[10] = ui->pushButton_11;
    cardButton[11] = ui->pushButton_12;
    cardButton[12] = ui->pushButton_13;
    cardButton[13] = ui->pushButton_14;
    cardButton[14] = ui->pushButton_15;
    cardButton[15] = ui->pushButton_16;
    cardButton[16] = ui->pushButton_17;
    cardButton[17] = ui->pushButton_18;
    cardButton[18] = ui->pushButton_19;
    cardButton[19] = ui->pushButton_20;
    cardButton[20] = ui->pushButton_21;
    cardButton[21] = ui->pushButton_22;
    cardButton[22] = ui->pushButton_23;
    cardButton[23] = ui->pushButton_24;
    cardButton[24] = ui->pushButton_25;
    cardButton[25] = ui->pushButton_26;
    cardButton[26] = ui->pushButton_27;
    cardButton[27] = ui->pushButton_28;
    cardButton[28] = ui->pushButton_29;
    cardButton[29] = ui->pushButton_30;
    cardButton[30] = ui->pushButton_31;
    cardButton[31] = ui->pushButton_32;
    cardButton[32] = ui->pushButton_33;
    cardButton[33] = ui->pushButton_34;

    for(int i = 0; i<cardNumber; i++)
    {
        cardButton[i]->setStyleSheet(pathString[i]);
    }

    ui->explainLabel->setGeometry(QRect(360, 140, 250, 420));  //四倍行距
    ui->explainLabel->setWordWrap(true);
    ui->explainLabel->setAlignment(Qt::AlignTop);
    QFont ft1;
    ft1.setPointSize(14);
    ui->explainLabel->setFont(ft1);
    //设置颜色
    QPalette pa;
    pa.setColor(QPalette::WindowText,Qt::white);
    ui->explainLabel->setPalette(pa);

    ui->r0Label->setFont(ft1);
    ui->r1Label->setFont(ft1);
    ui->r2Label->setFont(ft1);
    ui->r3Label->setFont(ft1);
    ui->r0Label->setPalette(pa);
    ui->r1Label->setPalette(pa);
    ui->r2Label->setPalette(pa);
    ui->r3Label->setPalette(pa);

    m_cardB[0][0] = ui->line0_1Button_3;
    m_cardB[0][1] = ui->line0_1Button_4;
    m_cardB[0][2] = ui->line0_1Button_5;
    m_cardB[0][3] = ui->line0_1Button_6;
    m_cardB[0][4] = ui->line0_1Button_7;
    m_cardB[0][5] = ui->line0_1Button_8;
    m_cardB[0][6] = ui->line0_1Button_9;
    m_cardB[0][7] = ui->line0_1Button_10;
    m_cardB[0][8] = ui->line0_1Button_11;
    m_cardB[0][9] = ui->line0_1Button_12;
    m_cardB[1][0] = ui->line0_2Button_3;
    m_cardB[1][1] = ui->line0_2Button_4;
    m_cardB[1][2] = ui->line0_2Button_5;
    m_cardB[1][3] = ui->line0_2Button_6;
    m_cardB[1][4] = ui->line0_2Button_7;
    m_cardB[1][5] = ui->line0_2Button_8;
    m_cardB[1][6] = ui->line0_2Button_9;
    m_cardB[1][7] = ui->line0_2Button_10;
    m_cardB[1][8] = ui->line0_2Button_11;
    m_cardB[1][9] = ui->line0_2Button_12;
    m_cardB[2][0] = ui->line0_3Button_3;
    m_cardB[2][1] = ui->line0_3Button_4;
    m_cardB[2][2] = ui->line0_3Button_5;
    m_cardB[2][3] = ui->line0_3Button_6;
    m_cardB[2][4] = ui->line0_3Button_7;
    m_cardB[2][5] = ui->line0_3Button_8;
    m_cardB[2][6] = ui->line0_3Button_9;
    m_cardB[2][7] = ui->line0_3Button_10;
    m_cardB[2][8] = ui->line0_3Button_11;
    m_cardB[2][9] = ui->line0_3Button_12;

    y_cardB[0][0] = ui->line1_1Button_3;
    y_cardB[0][1] = ui->line1_1Button_4;
    y_cardB[0][2] = ui->line1_1Button_5;
    y_cardB[0][3] = ui->line1_1Button_6;
    y_cardB[0][4] = ui->line1_1Button_7;
    y_cardB[0][5] = ui->line1_1Button_8;
    y_cardB[0][6] = ui->line1_1Button_9;
    y_cardB[0][7] = ui->line1_1Button_10;
    y_cardB[0][8] = ui->line1_1Button_11;
    y_cardB[0][9] = ui->line1_1Button_12;
    y_cardB[1][0] = ui->line1_2Button_3;
    y_cardB[1][1] = ui->line1_2Button_4;
    y_cardB[1][2] = ui->line1_2Button_5;
    y_cardB[1][3] = ui->line1_2Button_6;
    y_cardB[1][4] = ui->line1_2Button_7;
    y_cardB[1][5] = ui->line1_2Button_8;
    y_cardB[1][6] = ui->line1_2Button_9;
    y_cardB[1][7] = ui->line1_2Button_10;
    y_cardB[1][8] = ui->line1_2Button_11;
    y_cardB[1][9] = ui->line1_2Button_12;
    y_cardB[2][0] = ui->line1_3Button_3;
    y_cardB[2][1] = ui->line1_3Button_4;
    y_cardB[2][2] = ui->line1_3Button_5;
    y_cardB[2][3] = ui->line1_3Button_6;
    y_cardB[2][4] = ui->line1_3Button_7;
    y_cardB[2][5] = ui->line1_3Button_8;
    y_cardB[2][6] = ui->line1_3Button_9;
    y_cardB[2][7] = ui->line1_3Button_10;
    y_cardB[2][8] = ui->line1_3Button_11;
    y_cardB[2][9] = ui->line1_3Button_12;

    m_cards[0] = ui->m_card_0;
    m_cards[1] = ui->m_card_1;
    m_cards[2] = ui->m_card_2;
    m_cards[3] = ui->m_card_3;
    m_cards[4] = ui->m_card_4;
    m_cards[5] = ui->m_card_5;
    m_cards[6] = ui->m_card_6;
    m_cards[7] = ui->m_card_7;
    m_cards[8] = ui->m_card_8;
    m_cards[9] = ui->m_card_9;
    m_cards[10] = ui->m_card_10;

    y_cards[0] = ui->y_card_0;
    y_cards[1] = ui->y_card_1;
    y_cards[2] = ui->y_card_2;
    y_cards[3] = ui->y_card_3;
    y_cards[4] = ui->y_card_4;
    y_cards[5] = ui->y_card_5;
    y_cards[6] = ui->y_card_6;
    y_cards[7] = ui->y_card_7;
    y_cards[8] = ui->y_card_8;
    y_cards[9] = ui->y_card_9;
    y_cards[10] = ui->y_card_10;

    for(int i = 0; i<3; i++)
    {
        for(int j = 0; j<10; j++)
        {
            m_cardB[i][j]->setFlat(true);
            y_cardB[i][j]->setFlat(true);
        }
    }
    for(int i = 0; i<11; i++)
    {
        m_cards[i]->setFlat(true);
        y_cards[i]->setFlat(true);
    }

    ui->cardShow0->setStyleSheet("background-color: rgb(244,164,96)");
    ui->cardShow1->setStyleSheet("background-color: rgb(244,164,96)");
    ui->line0_1->setStyleSheet("background-color: rgb(244,164,96)");
    ui->line0_2->setStyleSheet("background-color: rgb(244,164,96)");
    ui->line0_3->setStyleSheet("background-color: rgb(244,164,96)");
    ui->line1_1->setStyleSheet("background-color: rgb(244,164,96)");
    ui->line1_2->setStyleSheet("background-color: rgb(244,164,96)");
    ui->line1_3->setStyleSheet("background-color: rgb(244,164,96)");
}

//处理卡牌选择界面的事件
bool MainWindow::eventFilter(QObject *watched, QEvent *event)
{
    if(event->type() == QEvent::Enter)
    {
        QPushButton* temp = dynamic_cast<QPushButton*>(watched);
        temp->resize(110,150);
        for(int i = 0; i<cardNumber; i++)
        {
            if(temp == cardButton[i])
            {
                explainButtonChange(i);
                ui->explainLabel->setText(explainString[i]);
                tempCardNumber = i;
            }
        }

        return true;
    }
    if(event->type() == QEvent::Leave)
    {
        QPushButton* temp = dynamic_cast<QPushButton*>(watched);
        temp->resize(100,140);
        return true;
    }

    return false;
}

//设置卡牌解释按钮的变化
void MainWindow::explainButtonChange(int sig)
{
    ui->explainButton->setStyleSheet(pathString[sig]);
}

//选择card中下一组
void MainWindow::changeCardList()
{
    int x = ui->cardList->currentIndex();
    x += 1;
    x %= 3;
    ui->cardList->setCurrentIndex(x);
}

//进入卡牌设置界面
void MainWindow::clickCM()
{
    ui->background->setCurrentIndex(4);
    setChooseBackgroud();
}

//设置开始界面的背景
void MainWindow::setBeginBackgroud()
{
    QPixmap pixmap = QPixmap(":/img/res/background/background2.jpg");
    QPalette palette(this->palette());
    palette.setBrush(QPalette::Background, QBrush(pixmap));
    this->setPalette(palette);
}

//设置其他背景
void MainWindow::setChooseBackgroud()
{
    QPixmap pixmap;
    if(ui->background->currentIndex() == 3)
    {
        pixmap = QPixmap(":/img/res/background/background3.jpg");

    }
    else if(ui->background->currentIndex() == 4)
    {
        pixmap = QPixmap(":/img/res/background/background1.jpg");

    }
    else if(ui->background->currentIndex() == 5)
    {
        pixmap = QPixmap("../gwent_v1/res/background/background4.jpg");
    }
    else if(ui->background->currentIndex() == 6)
    {
        pixmap = QPixmap("../gwent_v1/res/background/background5.jpg");
    }
    QPalette palette(this->palette());
    palette.setBrush(QPalette::Background, QBrush(pixmap));
    this->setPalette(palette);
    return ;
}

//设置ai对战选择卡牌的背景
void MainWindow::aiFightBackground()
{
    ui->background->setCurrentIndex(5);
    setChooseBackgroud();
}

//注册界面
void MainWindow::clickNP()
{
    ui->background->setCurrentIndex(1);
}

//注册
void MainWindow::clickSign()
{
    string s1 = ui->newName->text().toStdString();
    string s2 = ui->newPass->text().toStdString();

    if(s1.length() != 0 && s2.length() != 0)
    {
        player newplayer;
        newplayer.addPlayer(s1, s2);
        QMessageBox::warning(NULL, "提示", "注册成功", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
    }
    else
    {
        QMessageBox::warning(NULL, "warning", "用户名或密码填写有误", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
    }
    string s = "";
    QString ss = QString::fromStdString(s);
    ui->newPass->setText(ss);
    ui->newName->setText(ss);
}

//登陆界面
void MainWindow::clickOP()
{
    ui->background->setCurrentIndex(2);
}

//登陆
void MainWindow::clickLogin()
{
    string s1 = ui->oldName->text().toStdString();
    string s2 = ui->oldPass->text().toStdString();
    player newplayer;
    int result = newplayer.check(s1, s2);
    if(result == 0)
    {
        QMessageBox::warning(NULL, "warning", "密码错误", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
    }

    else if(result == 2)
    {
        QMessageBox::warning(NULL, "warning", "用户不存在", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
    }
    else
    {
        ui->background->setCurrentIndex(3);
        setChooseBackgroud();
    }
    string s = "";
    QString ss = QString::fromStdString(s);
    ui->oldPass->setText(ss);
    ui->oldName->setText(ss);
}

//设置出牌界面
void MainWindow::beginFight()
{
    ui->background->setCurrentIndex(6);
    setChooseBackgroud();
}

//保存修改卡牌
void MainWindow::quitCardM()
{
    if(m_camp->checkSaveAndQuit())
    {
        ui->background->setCurrentIndex(3);
        setChooseBackgroud();
    }
}

//返回最开始界面
void MainWindow::clickR()
{
    ui->background->setCurrentIndex(0);
    string s = "";
    QString ss = QString::fromStdString(s);
    ui->newPass->setText(ss);
    ui->newName->setText(ss);
    ui->oldPass->setText(ss);
    ui->oldName->setText(ss);
}

//设置卡牌中增加卡牌
void MainWindow::addCard()
{
    card *p = new card(cardName[tempCardNumber]);
    if(m_camp->checkAdd(p))
    {
        m_camp->group[m_camp->cardN] = p;
        m_camp->rankCardN[p->getRank()] ++;
        m_camp->cardN ++;
        QTextEdit *t = nullptr;
        switch (p->getRank()) {
        case 0:
            t = ui->r0Text;
            break;
        case 1:
            t = ui->r1Text;
            break;
        case 2:
            t = ui->r2Text;
            break;
        case 3:
            t = ui->r3Text;
            break;
        default:
            break;
        }
        QString s = t->toPlainText();
        string s1 = s.toStdString();
        s1 += p->getName();
        s1 += " ";
        s = QString::fromStdString(s1);
        t->setText(s);

        ui->r0Number->display(m_camp->rankCardN[0]);
        ui->r1Number->display(m_camp->rankCardN[1]);
        ui->r2Number->display(m_camp->rankCardN[2]);
        ui->r3Number->display(m_camp->rankCardN[3]);
    }
    else
    {
        delete p;
        p = nullptr;
    }
}

//设置卡牌中删除卡牌
void MainWindow::delCard()
{
    card *p = new card(cardName[tempCardNumber]);
    int temp = m_camp->checkDel(cardName[tempCardNumber]);
    if(temp >= 0)
    {
        delete (m_camp->group[temp]);
        m_camp->group[temp] = nullptr;
        for(int i = temp+1; i<m_camp->cardN; i++)
        {
            m_camp->group[i-1] = m_camp->group[i];
        }
        QTextEdit *t = nullptr;
        switch (p->getRank()) {
        case 0:
            t = ui->r0Text;
            break;
        case 1:
            t = ui->r1Text;
            break;
        case 2:
            t = ui->r2Text;
            break;
        case 3:
            t = ui->r3Text;
            break;
        default:
            break;
        }
        QString s = t->toPlainText();
        string s1 = s.toStdString();
        int pos = s1.find(cardName[tempCardNumber]);
        if(pos > -1)
        {
            s1.erase(pos, cardName[tempCardNumber].length() + 1);
        }
        s = QString::fromStdString(s1);
        t->setText(s);
        m_camp->group[m_camp->cardN-1] = nullptr;
        m_camp->cardN --;
        m_camp->rankCardN[p->getRank()] --;
        ui->r0Number->display(m_camp->rankCardN[0]);
        ui->r1Number->display(m_camp->rankCardN[1]);
        ui->r2Number->display(m_camp->rankCardN[2]);
        ui->r3Number->display(m_camp->rankCardN[3]);
    }
    delete p;
    p = nullptr;
}

MainWindow::~MainWindow()
{
    delete ui;
}
