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
#include "Menu.h"
using namespace std;

int main(){
    TSMatrix M,N,ANS;

//    freopen("data.txt","r",stdin);
    int choice;
    while(1){
        system("clear");
        start();
        cin>>choice;
        switch (choice) {
            case 1:
                initMuNuTuIJE(M,N);
                break;
                
            case 2:
                printMatrix(M,N);
                break;
                
            case 3:
                sum(M,N,ANS);
                break;
            
            case 4:
                sub(M,N,ANS);
                break;
                
            case 5:
                multi(M,N,ANS);
                break;
                
            case 6:
                printAnswer(ANS);
                break;
                
            default:
                break;
        }
    }
    return 0;
}

