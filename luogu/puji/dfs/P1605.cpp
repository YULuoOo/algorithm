//
// Created by 赵奕威 on 2019/9/16.
//

#include<bits/stdc++.h>
using namespace std;
int n,m,t;
int xx,yy,x2,y2;
int nn,mm;
int a[7][7] = {0};
int ret = 0;
int dir[][2] = {{0,1},{1,0},{0,-1},{-1,0}};

bool canGo(int d,int x,int y){
    return (!a[x+dir[d][0]][y+dir[d][1]] && x+dir[d][0]>0 && x+dir[d][0]<=n && y+dir[d][1]>0 && y+dir[d][1]<=n);
}

void dfs(int x,int y){
    a[x][y]=1;//要把第一步设为已经访问 不然只有70分
    if(x==x2&&y==y2){
        ret++;
        return;
    }
    for(int i=0;i<4;i++){
        if(canGo(i,x,y)) {
            dfs(x+dir[i][0],y+dir[i][1]);
            a[x+dir[i][0]][y+dir[i][1]] = 0;
        }
    }
}

int main(){
    cin>>n>>m>>t;
    cin>>xx>>yy>>x2>>y2;
    for(int i =0;i<t;i++){
        cin>>nn>>mm;
        a[nn][mm] = 1;
    }
    dfs(xx,yy);
    cout<<ret<<endl;
    return 0;
}

