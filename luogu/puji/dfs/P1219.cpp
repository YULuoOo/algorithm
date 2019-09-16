//
// Created by 赵奕威 on 2019/9/10.
//
#include<bits/stdc++.h>
using namespace std;
int n;
int a[4][30] = {0};
int ret = 0;

void dfs(int line){
    if(line > n){
        ret++;
        if(ret < 4){
            cout<<a[3][1];
            for(int i = 2;i<=n;i++)
                cout<<" "<<a[3][i];
            cout<<endl;
            return;
        } else return;
    }
    for(int i=1;i<=n;i++){
        if(!a[0][i] && (!a[1][line+i]) && (!a[2][line-i+n])) {
            a[3][line] = i;
            a[0][i] = a[1][line+i] = a[2][line-i+n] = 1;
            dfs(line + 1);
            a[0][i] = a[1][line+i] = a[2][line-i+n] = 0;
        }
    }
}

int main(){
    cin>>n;
    dfs(1);
    cout<<ret<<endl;
    return 0;
}

