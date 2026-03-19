#include "gamepanel.h"
#include "cards.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // 新增：注册自定义类型，解决跨线程信号槽传参问题
    qRegisterMetaType<Cards>();
    qRegisterMetaType<Cards>("Cards&"); // 注册非 const 引用
    qRegisterMetaType<Cards>("const Cards&"); // 推荐：同时注册 const 引用（更安全）

    GamePanel w;
    w.show();
    return a.exec();
}
