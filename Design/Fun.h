//
//  Fun.h
//  Design
//
//  Created by Snowcying on 2017/12/25.
//  Copyright © 2017年 Snowcying. All rights reserved.
//

#ifndef Fun_h
#define Fun_h
#include "TSMatrix.h"
#define SIZE 100


void Fun();
void MemsetMatrix(int a[SIZE][SIZE],int m,int n);
void ArrayToMa(TSMatrix M,int a[SIZE][SIZE]);
void MaToArray(TSMatrix &M,int a[SIZE][SIZE],int m,int n);
void SumMatrix(TSMatrix m1,TSMatrix m2,TSMatrix &ans);
void SubMatrix(TSMatrix m1,TSMatrix m2,TSMatrix &ans);
void MultiMatrix(TSMatrix m1,TSMatrix m2,TSMatrix &ans);
void QuickMultiMatrix(TSMatrix M,TSMatrix N,TSMatrix &Q);


#endif /* Fun_h */

