//
//  TSMatrix.h
//  Design
//
//  Created by Snowcying on 2017/12/24.
//  Copyright © 2017年 Snowcying. All rights reserved.
//

#ifndef TSMatrix_h
#define TSMatrix_h

#include "Triple.h"
#define MAXSIZE 100
#define SIZE 100

class TSMatrix
{
public:
    Triple data[MAXSIZE+1];
    int rpos[SIZE+1];
    int mu,nu,tu;
    void InitMatrix();
    void PrintArrayWithMa();
    void PrintArray();
    void MultRepos();
    


};

#endif /* TSMatrix_h */
