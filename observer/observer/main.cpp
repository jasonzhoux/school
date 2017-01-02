//
//  main.cpp
//  observer
//
//  Created by apple on 2016/12/01.
//  Copyright © 2016年 apple. All rights reserved.
//

#include <iostream>
#include "Observer.h"
using namespace std;

int main()
{
    // 创建目标人物，某一女生
    ConcreteSubject *pGirl = new ConcreteSubject();
    
    // 创建观察人物，小明和小光
    Observer *pBoy1 = new ConcreteObserver1(pGirl);
    Observer *pBoy2 = new ConcreteObserver2(pGirl);
    
    // 女生的朋友圈内容
    string message ;
    message = "我喜欢你！" ;
    pGirl->SetStatus(message);
    // 创建观察（关注）关系，两个男孩关注了女孩
    pGirl->Attach(pBoy1);
    pGirl->Attach(pBoy2);
    pGirl->Notify();
    // 这个时候，两个男孩都会得到女孩朋友圈更新消息的提示
    
    // 小明选择取关女孩
    pGirl->Detach(pBoy1);
    // 女孩发表新的朋友圈
    message = "最近心情不好！" ;
    pGirl->SetStatus(message);
    pGirl->Notify();
    // 因为小明已经对女孩进行了取关，并不会得到更新信息
    
    delete pBoy1;
    delete pBoy2;
    delete pGirl;
}
