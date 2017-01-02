//
//  Composite.h
//  com
//
//  Created by apple on 2016/12/01.
//  Copyright © 2016年 apple. All rights reserved.
//

#ifndef Composite_h
#define Composite_h

#include<iostream>
#include<list>
using namespace std;

//作为基类
class Company
{
public:
    Company(string name) { m_name = name; }
    virtual ~Company(){}
    virtual void Add(Company *pCom){}
    virtual void Remove(Company *pCom){}
    virtual void Show(int depth) {}
protected:
    string m_name;
};

//具体公司(分公司),可以增加子树,即添加分公司（部门）
class ConcreteCompany : public Company
{
public:
    ConcreteCompany(string name): Company(name) {}
    virtual ~ConcreteCompany() {}
    void Add(Company *pCom)
    {
        m_listCompany.push_back(pCom);
    }
    //可以增加分支，也可以是叶子节点
    void Remove(Company *pCom)
    {
        m_listCompany.remove(pCom);
    }
    //可以移除分支
    void Show(int depth)
    {
        //用--表示纵深
        for(int i = 0;i < depth; i++)
            cout<<"-";
        cout<<m_name<<endl;
        list<Company *>::iterator iter=m_listCompany.begin();
        for(; iter != m_listCompany.end(); iter++) //显示下层结点
            (*iter)->Show(depth + 2);
    }
private:
    list<Company *> m_listCompany;
};

//具体部门，可能下属于总公司，也可能下属于分公司，下有员工
class Department : public Company
{
public:
    Department(string name): Company(name) {}
    virtual ~Department() {}
    void Add(Company *pCom)
    {
        m_listCompany.push_back(pCom);
    }
    //作为部门，可以添加下属员工
    void Remove(Company *pCom)
    {
        m_listCompany.remove(pCom);
    }
    //可以移除分支，即移除员工
    void Show(int depth)
    {
        for(int i = 0;i < depth; i++)
            cout<<"-";
        cout<<m_name<<endl;
        list<Company *>::iterator iter=m_listCompany.begin();
        for(; iter != m_listCompany.end(); iter++) //显示下层结点
            (*iter)->Show(depth + 2);
    }
private:
    list<Company *> m_listCompany;
};

//具体的职员，作为叶子节点，没有添加移除下层节点的操作等
class Worker : public Company
{
public:
    Worker(string name):Company(name){}
    virtual ~Worker() {}
    virtual void Show(int depth) //只需显示，无限添加函数，因为已是叶结点
    {
        for(int i = 0; i < depth; i++)
            cout<<"-";
        cout<<m_name<<endl;
    }
};





#endif /* Composite_h */

