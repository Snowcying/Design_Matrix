//
//  Fun.cpp
//  Design
//
//  Created by Snowcying on 2017/12/25.
//  Copyright © 2017年 Snowcying. All rights reserved.
///

#include <iostream>
#include "Fun.h"
#include "TSMatrix.h"
using namespace std;


void MemsetMatrix(int a[SIZE][SIZE],int m,int n)
{
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
            a[i][j]=0;
    }
}

void ArrayToMa(TSMatrix M,int a[SIZE][SIZE])
{
    int num=M.tu,m=M.mu,n=M.nu;
    MemsetMatrix(a, m, n);
    for(int i=1;i<=num;i++)
    {
        a[M.data[i].i][M.data[i].j]=M.data[i].e;
    }
}


void MaToArray(TSMatrix &M,int a[SIZE][SIZE],int m,int n)
{
    int ValidNum=1;
    M.mu=m;
    M.nu=n;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(a[i][j]){
                M.data[ValidNum].i=i;
                M.data[ValidNum].j=j;
                M.data[ValidNum].e=a[i][j];
                ValidNum++;
            }
        }
    }
    M.tu=ValidNum;
}

void SumMatrix(TSMatrix m1,TSMatrix m2,TSMatrix &ans)
{

    int a[SIZE][SIZE],b[SIZE][SIZE];
    int c[SIZE][SIZE];
    ArrayToMa(m1,a);
    ArrayToMa(m2,b);
    int m=m1.mu,n=m1.nu;
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            c[i][j]=a[i][j]+b[i][j];
        }
    }
    MaToArray(ans,c,m,n);
}

void SubMatrix(TSMatrix m1,TSMatrix m2,TSMatrix &ans)
{
    int a[SIZE][SIZE],b[SIZE][SIZE];
    int c[SIZE][SIZE];
    ArrayToMa(m1,a);
    ArrayToMa(m2,b);
    int m=m1.mu,n=m1.nu;
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            c[i][j]=a[i][j]-b[i][j];
        }
    }
    MaToArray(ans,c,m,n);
}

void MultiMatrix(TSMatrix m1,TSMatrix m2,TSMatrix &ans)
{
    int M=m1.mu,N=m2.nu,K=m1.nu;
    int a[SIZE][SIZE],b[SIZE][SIZE];
    int c[SIZE][SIZE];
    ArrayToMa(m1,a);
    ArrayToMa(m2,b);
    for(int i=1;i<=M;i++){
        for(int j=1;j<=N;j++){
            for(int k=1;k<=K;k++){
                c[i][j]+=a[i][k]*b[k][j];
            }
        }
    }
    MaToArray(ans, c, M, N);

}

void QuickMultiMatrix(TSMatrix M,TSMatrix N,TSMatrix &Q){
    if(M.nu==N.mu){

        Q.mu=M.mu;Q.nu=N.nu;Q.tu=0;
        if(M.tu*N.tu!=0){
            for(int arow=1;arow<=M.mu;++arow){
                int ctemp[SIZE],tp;
                for(int i=0;i<SIZE;i++) ctemp[i]=0;
                Q.rpos[arow]=Q.tu+1;
                if(arow<M.mu) tp=M.rpos[arow+1];
                else tp=M.tu+1;
                for(int p=M.rpos[arow];p<tp;++p){
                    int brow=M.data[p].j,t;
                    if(brow<N.mu) t=N.rpos[brow+1];
                    else t=N.tu+1;
                    for(int q=N.rpos[brow];q<t;++q){
                        int ccol=N.data[q].j;
                        ctemp[ccol]+=M.data[p].e * N.data[q].e;
                    }

                }
                for(int ccol=1;ccol<=Q.nu;++ccol){
                    if(ctemp[ccol]){
                        Q.tu++;
                        Q.data[Q.tu].i=arow;
                        Q.data[Q.tu].j=ccol;
                        Q.data[Q.tu].e=ctemp[ccol];
                    }
                }
            }
        }

    }
}

