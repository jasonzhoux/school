//
//  main.cpp
//  redoundo
//
//  Created by apple on 2016/12/02.
//  Copyright © 2016年 apple. All rights reserved.
//

#include "command.h"

//模拟输入字符串,然后对输入的字符串进行undo redo操作
//这里记录的是完整记录,即在undo 或 redo 过程中的数据改变
//默认在历史记录中修改值被认为是最新的值，不需要再redo
int main()
{
    //默认没有输入字符串可以是空，这里为了演示赋值一个特殊的字符串
    Commander *p = new Commander( new InputCommand( "[页首]" ) );
    
    //输入我叫小明
    p->ExecuteCommand( new InputCommand( "我叫小明" ) );
    //输入今年二十岁
    p->ExecuteCommand( new InputCommand( "今年二十岁" ) );
    //输入最近很开心
    p->ExecuteCommand( new InputCommand( "最近很开心" ) );
    
    //执行一次undo 撤销到 今年二十岁
    p->Undo();
    //执行一次undo 撤销到 我叫小明
    p->Undo();
    
    //undo后中间输入新字符串 今年二十一岁 ，因为修改值是最新值， redo将会被清空
    p->ExecuteCommand( new InputCommand( "今年二十一岁" ) );
    
    //执行一次undo 撤销到 我叫小明
    p->Undo();
    
    //执行一次undo 撤销到最初情况 [页首]
    p->Undo();
    
    //执行失败已经undo 到最原始情况，会显示无法撤销
    p->Undo();
    
    //执行一次redo 重做到 我叫小明
    p->Redo();
    //执行一次redo 重做到 今年二十一岁
    p->Redo();
    //执行一次redo 因为已到最近一次的最终状态 无法重做
    p->Redo();
    
    //redo后中间输入新字符串 最近很难过
    p->ExecuteCommand( new InputCommand( "最近很难过" ) );
    
    //执行一次undo 撤销到 今年二十一岁
    p->Undo();
    
    //执行一次redo 重做到 最近很难过
    p->Redo();
    
    //执行一次redo 因为已是最近一次的最终状态 无法重做
    p->Redo();

    delete p;
    return 0;
}
