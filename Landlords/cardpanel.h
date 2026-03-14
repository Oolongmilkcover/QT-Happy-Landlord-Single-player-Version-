#ifndef CARDPANEL_H
#define CARDPANEL_H

#include <QWidget>
#include"card.h"
#include"player.h"
class CardPanel : public QWidget
{
    Q_OBJECT
public:
    explicit CardPanel(QWidget *parent = nullptr);

    //设置图片函数
    void setImage(QPixmap &front,QPixmap &back);
    //获取图片函数
    QPixmap getImage();

    //扑克牌显示哪一面
    void setFrontSide(bool flag);
    bool isFrontSide();

    //窗口是否被选中
    void setSeclected(bool flag);
    bool isSelected();

    //扑克牌的花色和点数
    void setCard(Card& card);
    Card getCard();

    //扑克牌的所有者
    void setOwner(Player* player);
    Player* getOwner();

protected:
    void paintEvent(QPaintEvent* event);
    void mousePressEvent(QMouseEvent* event);
signals:
private:
    QPixmap m_front;
    QPixmap m_back;
    bool m_isfront;
    bool m_isSelect;
    Card m_card;
    Player* m_owner;
};

#endif // CARDPANEL_H
