//
//  main.cpp
//  com
//
//  Created by apple on 2016/12/01.
//  Copyright © 2016年 apple. All rights reserved.
//

#include<iostream>
#include"Composite.h"
using namespace std;

//依次纵深为总公司，分公司（总公司直属部门），分公司部门，分公司部门员工
//只显示了添加叶结点操作，当然也可以使用移除操作
//show将显示当前节点下的组织结构，show后的系数表示当前节点的纵深（层次）
//层次将用--来区分
int main()
{
    //总公司，有直属的财务部,总经理办公室， 财务部有职员 小明
    Company *root = new ConcreteCompany("总公司");
    Company *rFinance =new Department("财务部");
    Company *rOffice =new Department("总经理办公室");
    Company *rF_worker1 = new Worker("小明");
    root->Add(rFinance);
    root->Add(rOffice);
    rFinance->Add(rF_worker1);
    
    //上海分公司，下属财务部和销售部，销售部下有职员 小光
    Company *branch1 = new ConcreteCompany("上海分公司");
    Company *b1Finance =new Department("财务部");
    Company *b1sales =new Department("销售部");
    Company *b1salesworker1 = new Worker("小光");
    branch1->Add(b1Finance);
    branch1->Add(b1sales);
    b1sales->Add(b1salesworker1);
    root->Add(branch1);
    
    //北京分公司，下属财务部，人力资源部
    Company *branch2 =new ConcreteCompany("北京分公司");
    Company *b2Finance =new Department("财务部");
    Company *b2HR =new Department("人力资源部");
    branch2 ->Add(b2Finance);
    branch2 ->Add(b2HR);
    root->Add(branch2);
    
    //显示整个公司的组织结构图
    branch1->Show(0);
    

    return 0;
}
