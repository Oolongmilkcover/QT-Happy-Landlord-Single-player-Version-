#ifndef GAMECONTROL_H
#define GAMECONTROL_H
#include"robot.h"
#include"userplayer.h"
#include"cards.h"
#include <QObject>

class GameControl : public QObject
{
    Q_OBJECT
public:
    //游戏状态
    enum GameStatus{
        DispatchCard, // 发牌状态
        CallingLord,    //叫地主状态
        PlayingHand   //出牌状态
    };

    //玩家状态
    enum PlayerStatus{
        ThinkingForCallLord, //考虑是否叫地主
        ThinkingForPlayHand,  //考虑出牌
        Winning //赢咯
    };

    explicit GameControl(QObject *parent = nullptr);

    //初始化玩家
    void playerInit();

    //得到玩家的实例对象
    Robot* getLeftRobot();
    Robot* getRightRobot();
    UserPlayer* getUserPlayer();
    void setCurrentPlayer(Player* play);
    Player* getCurrentPlayer();

    //得到出牌玩家和打出的牌
    Player* getPendPlayer();
    Cards getPendCards();

    //初始化扑克牌
    void initAllCards();

    //每次发一张牌
    Card takeOneCard();
    //得到最后的三张牌
    Cards getSurplusCards();

    //重置卡牌数据
    void resetCardData();

    //准备叫地主
    void startLordCard();
    //成为地主
    void becomeLord(Player* player);

    //清空所有玩家的得分
    void clearPlayerScore();

    //处理叫地主

    //处理出牌
signals:



private:
    Robot* m_robotLeft;
    Robot* m_robotRight;
    UserPlayer* m_user;
    Player* m_currPlayer;
    Cards m_pendCards;
    Player* m_pendPlayer;
    Cards m_allCards;
};

#endif // GAMECONTROL_H
