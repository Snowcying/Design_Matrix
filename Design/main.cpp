//
//  main.cpp
//  Design
//
//  Created by Snowcying on 2017/12/15.
//  Copyright © 2017年 Snowcying. All rights reserved.
///

#include <iostream>
#include "TSMatrix.h"
#include "Fun.h"
using namespace std;

int main(){
    //define
    TSMatrix M,N,ANS;
    freopen("data.txt","r",stdin);

    //init and print
    M.InitMatrix();
    M.PrintArrayWithMa();

    N.InitMatrix();
    N.PrintArrayWithMa();

    //multi
    QuickMultiMatrix(M, N, ANS);

    //print the answer
    ANS.PrintArrayWithMa();

    return 0;
}

