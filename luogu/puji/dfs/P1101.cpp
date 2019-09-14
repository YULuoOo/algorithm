//
// Created by 赵奕威 on 2019/9/14.
//
#include<bits/stdc++.h>
using namespace std;
int n;
char a[101][101];
bool b[101][101];
struct mypair{
    int x;
    int y;
    struct mypair *next;
    mypair(int x,int y){
        this->x = x;
        this->y = y;
        next = NULL;
    }
};

const int dir[][2]={{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};//八向的常量数组
const char ans[] = {'z','h','o','n','g'};
void dfs(int x,int y,int direction,int step){
    if(step == 5){
        for(int i=0;i<7;i++){
            b[x][y]=true;
            x -= dir[direction][0];
            y -= dir[direction][1];
        }
        return;
    }
    if(x+dir[direction][0]>=0
    &&y+dir[direction][1]>=0
    &&x+dir[direction][0]<n
    &&y+dir[direction][1]<n
    &&a[x+dir[direction][0]][y+dir[direction][1]]==ans[step]){
        dfs(x+dir[direction][0],y+dir[direction][1],direction,step+1);
    }
}

int main(){
    mypair *pp = new mypair(0,0);
    mypair *head = pp;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
            if(a[i][j]=='y'){
                pp->next = new mypair(i,j);
                pp = pp->next;
            }
        }
    }
    while(head != NULL && head->next != NULL){
        head = head->next;
        for(int k=0;k<8;k++){
            int x=head->x+dir[k][0];
            int y=head->y+dir[k][1];
            if(x>=0&&y>=0&&x<n&&y<n&&a[x][y]=='i')
                dfs(x,y,k,0);
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<(b[i][j]?a[i][j]:'*');
        }
        cout<<endl;
    }
    return 0;
}

