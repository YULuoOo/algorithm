//
// Created by 赵奕威 on 2019/9/16.
//
#include<bits/stdc++.h>
using namespace std;
int m,n;
int a[1005][1005];//外面包一圈
int vis[1005][1005] = {0};
int ret = 0;
queue <int > q;
int dir[][2] = {{0,1},{1,0},{0,-1},{-1,0}};
void bfs(int x, int y)
{
    vis[x][y] = 1 ;
    q.push(x);
    q.push(y);
    int xx,yy;
    while(!q.empty())
    {
        int w = q.front();
        q.pop();
        int e = q.front();
        q.pop();
        for(int i=0;i<4;i++){
            xx = w+dir[i][0];
            yy = e+dir[i][1];
            if(xx>=0 && yy>=0 && xx<=n+1 && yy<=n+1 && a[xx][yy]==2 && !vis[xx][yy]){
                a[xx][yy]=0;
                vis[xx][yy]=1;
                q.push(xx);
                q.push(yy);
            }
        }
    }
}
int main(){
    cin>>n>>m;
    for(int i =1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
        }
    }
    for(int i =0;i<=n+1;i++){
        for(int j=0;j<=n+1;j++){
            if(a[i][j]==0)
                a[i][j]=2;
        }
    }
    a[0][0]=0;
    bfs(0,0);
    for(int i =1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
