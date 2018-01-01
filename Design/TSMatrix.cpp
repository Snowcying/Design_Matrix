//
//  TSMatrix.cpp
//  Design
//
//  Created by Snowcying on 2017/12/24.
//  Copyright © 2017年 Snowcying. All rights reserved.
///

#include <stdio.h>
#include <iostream>
#include <string>
#include "TSMatrix.h"
#include "Fun.h"

using namespace std;

void PrintCin(string str){
    cout<<"输入"<<str<<":";
}

void TSMatrix::InitMatrix(){
    int mu,nu,tu;
    
    
    PrintCin("mu");cin>>mu;
    PrintCin("nu");cin>>nu;
    PrintCin("tu");cin>>tu;
    
    this->mu=mu;
    this->nu=nu;
    this->tu=tu;
    
    int i,j,e;
    for(int k=1;k<=this->tu;k++){
        PrintCin("i");cin>>i;
        PrintCin("j");cin>>j;
        PrintCin("e");cin>>e;
        cout<<endl;
        this->data[k].i=i;
        this->data[k].j=j;
        this->data[k].e=e;
        
    }
    MultRepos();
}

void TSMatrix::PrintArrayWithMa()
{
    int a[SIZE][SIZE];
    int num=this->tu,m=this->mu,n=this->nu;
    MemsetMatrix(a, m, n);
    for(int i=1;i<=num;i++)
    {
        a[this->data[i].i][this->data[i].j]=this->data[i].e;
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

void TSMatrix::PrintArray()
{
    int len=this->tu;
    for(int i=1;i<=len;i++)
    {
        cout<<this->data[i].i<<" "<<this->data[i].j<<" "<<this->data[i].e<<endl;
    }
}

void TSMatrix::MultRepos(){
    
    int size=this->mu+1;
    int Repos[size];
    for(int i=1;i<=this->mu;i++) Repos[i]=0;
    for(int i=1;i<=this->tu;i++){
        Repos[this->data[i].i]++;
    }
    
    
    this->rpos[1]=1;
    
    for(int i=2;i<=this->mu;i++){
        this->rpos[i]=this->rpos[i-1]+Repos[i-1];
    }
    
}



