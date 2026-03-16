#ifndef GAMEPANEL_H
#define GAMEPANEL_H
#include "cardpanel.h"
#include"gamecontrol.h"
#include <QLabel>
#include <QMainWindow>
#include <QMap>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui {
class GamePanel;
}
QT_END_NAMESPACE

class GamePanel : public QMainWindow
{
    Q_OBJECT

public:
    GamePanel(QWidget *parent = nullptr);
    ~GamePanel();
    //初始化游戏控制类信息
    void GameControlInit();
    //更新分数面板的分数
    void updatePlayerScore();
    //切割并存储图片
    void initCardMap();
    //裁剪图片
    void cropImage(QPixmap& pix,int x,int y,Card& c);
    //初始化游戏按钮组
    void initButtonGroup();
    //初始化玩家在窗口的上下文环境
    void initPlayContext();
    //初始化游戏场景
    void initGameScene();
    //处理游戏的状态
    void gameStatusPrecess(GameControl::GameStatus status);
    //发牌
    void startDispatchCard();
    //移动扑克牌
    void cardMoveStep(Player* player,int curPos);
    //处理分发得到的扑克牌
    void disposCard(Player* player,Cards& cards);
    //更新扑克牌在窗口的显示
    void updatePlayerCards(Player* player);
    //定时器处理动作
    void onDispatchCard();
    //处理玩家状态的变化
    void onPlayStatusChanged(Player* player,GameControl::PlayerStatus status);
    //处理玩家抢地主
    void onGrabLordBet(Player* player,int bet,bool flag);


protected:
    void paintEvent(QPaintEvent* ev);
private:
    enum CardAlign{ Horizontal,Vertical};
    struct PlayerContext{
        //1.玩家扑克牌的显示的区域
        QRect cardRect;
        //2.出牌的区域
        QRect playHandRect;
        //3.扑克牌的对齐方式(水平or垂直)
        CardAlign align;
        //4.扑克牌显示正面还是背面
        bool isFrontSide;
        //5.游戏过程中的提示信息,比如：不出
        QLabel* info;
        //6.玩家的头像
        QLabel* roleImg;
        //7.玩家打出的牌
        Cards lastCards;
    };

    Ui::GamePanel *ui;
    QPixmap m_bkImage;
    GameControl *m_gameCtl;
    QVector<Player*> m_playerList;
    QMap<Card,CardPanel*> m_cardMap;
    QMap<Player*,PlayerContext> m_contextMap;
    QSize m_cardSize;
    QPixmap m_cardBackImg;
    CardPanel* m_baseCard;
    QPoint m_baseCardPos;
    CardPanel* m_moveCard;
    QVector<CardPanel*> m_last3Cards;
    GameControl::GameStatus m_gameStatus;
    QTimer* m_timer;

};
#endif // GAMEPANEL_H
