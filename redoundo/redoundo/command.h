//
//  command.h
//  redoundo
//
//  Created by apple on 2016/12/02.
//  Copyright © 2016年 apple. All rights reserved.
//

#ifndef _COMMAND_HPP
#define _COMMAND_HPP

#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Command
{
public:
    Command(){}
    virtual ~Command(){}
    
    virtual void Execute() = 0;
};

//输入命令，输入字符串
class InputCommand : public Command
{
public:
    
    InputCommand( const string &input )
    {
        mInput = input;
    }
    ~InputCommand()
    {}
    
    void Execute()
    {
        cout <<  mInput.c_str() ;
    }
    
private:
    string mInput;
};


class Commander
{
public:
    Commander( Command *pCmd )
    {
        //最初的命令数据
        mUndo.push( pCmd );
    }
    ~Commander()
    {
        while( false == mUndo.empty() )
        {
            delete mUndo.top();
            mUndo.pop();
        }
        while( false == mRedo.empty() )
        {
            delete mRedo.top();
            mRedo.pop();
        }
    }
    
    void ExecuteCommand( Command *pCmd )
    {
        cout << "输入成功！" << endl;
        display();
        pCmd->Execute();
        mUndo.push( pCmd );
        cout << endl;
        while( mRedo.empty() == false )
        {
            mRedo.pop();
        }
    }
    
    void display()
    {
        cout << "当前内容:" ;
        mTemp = mUndo ;
        while( mTemp.empty() == false)
        {
            mTemp2.push( mTemp.top() );
            mTemp.pop();
        }
        while( mTemp2.empty() == false)
        {
            mTemp2.top()->Execute();
            mTemp2.pop();
        }
    }
    
    void Undo()
    {
        if( mUndo.size() < 2 )
        {
            //无法后退撤销没有数据
            cout << "无法撤销." << endl ;
            return;
        }
        
        cout << "撤销成功:" << endl;
        
        //当前命令
        auto pCmd = mUndo.top();
        
        //保存当前命令
        mRedo.push( pCmd );
        
        //弹出
        mUndo.pop();
        
        //还原到上个命令
        pCmd = mUndo.top();
        
        display();
        cout << endl;
    }
    
    void Redo()
    {
        if( mRedo.empty() )
        {
            //无法前进重做没有数据
            cout << "无法重做." << endl;
            return;
        }
        
        cout<< "重做成功:" << endl;
        
        auto pCmd = mRedo.top();
        
        
        mRedo.pop();
        
        mUndo.push( pCmd );
        
        display();
        
        cout << endl;
    }
    
private:
    stack< Command* > mUndo;
    stack< Command* > mRedo;
    stack< Command* > mTemp;
    stack< Command* > mTemp2;
};

#endif

