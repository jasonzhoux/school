//
//  Observer.h
//  observer
//
//  Created by apple on 2016/12/01.
//  Copyright © 2016年 apple. All rights reserved.
//

#ifndef Observer_h
#define Observer_h

#include <iostream>
#include <list>
#include <cstdio>
#include <string>
using namespace std;

class Observer
{
public:
    Observer(){};
    virtual void Update(string s){} ;
};
//观察者

class Subject
{
public:
    virtual void Attach(Observer *) = 0;
    virtual void Detach(Observer *) = 0;
    virtual void Notify() = 0;
    virtual void Setstatus(string s){ m_iStatus = s;};
    virtual string Getstatus(){ return m_iStatus;};
protected:
    string m_iStatus;
};
//目标

class ConcreteObserver1 : public Observer
{
public:
    ConcreteObserver1(Subject *pSubject) : m_pSubject(pSubject){}
    
    void Update(string s)
    {
        cout << "小明，你关注的她发表了新的朋友圈。朋友圈内容是:" << s << endl;
    }
    
private:
    Subject *m_pSubject;
};
//具体观察者，小明

class ConcreteObserver2 : public Observer
{
public:
    ConcreteObserver2(Subject *pSubject) : m_pSubject(pSubject){}
    
    void Update(string s)
    {
        cout << "小光，你关注的她发表了新的朋友圈。朋友圈内容是:" << s << endl;
    }
    
private:
    Subject *m_pSubject;
};
//具体观察者2，小光

class ConcreteSubject : public Subject
{
public:
    void Attach(Observer *pObserver);
    void Detach(Observer *pObserver);
    void Notify();
    
    void SetStatus(string status)
    {
        m_iStatus = status;
    };
private:
    list<Observer *> m_ObserverList;
protected:
    string m_iStatus;
};
//具体目标

void ConcreteSubject::Attach(Observer *pObserver)
{
    m_ObserverList.push_back(pObserver);
}

void ConcreteSubject::Detach(Observer *pObserver)
{
    m_ObserverList.remove(pObserver);
}

void ConcreteSubject::Notify()
{
    list<Observer *>::iterator it = m_ObserverList.begin();
    while (it != m_ObserverList.end())
    {
        (*it)->Update(m_iStatus);
        ++it;
    }
}



#endif /* Observer_h */
