//
// Created by 赵奕威 on 2019/9/10.
// 贪心
//
#include<bits/stdc++.h>
using namespace std;
int n,m,ans=1;
int mmax;
int i;
int a[100001];
int main(){
    scanf("%d %d",&n,&m);
    for(i=0;i<n;i++)
        cin>>a[i];
    mmax = a[0];
    for(i=1;i<n;i++){
        if(a[i]+mmax<=m){
            mmax += a[i];
        } else{
            ans++;
            mmax = a[i];
        }
    }
    printf("%d",ans);
    return 0;
}
