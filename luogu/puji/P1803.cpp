//
// Created by 赵奕威 on 2019/9/10.
// 贪心
//
#include<bits/stdc++.h>
using namespace std;
struct pp{
    int l;
    int r;
}p[1000001];
bool cmp(pp p1,pp p2){
    if(p1.r==p2.r)
        return p1.l<p2.l;
    return p1.r<p2.r;
}
int n,ans,i;
int main(){
    scanf("%d",&n);
    for(i=0;i<n;i++)
        cin>>p[i].l>>p[i].r;
    sort(p,p+n,cmp);
    int now=0;
    for(i=0;i<n;i++){
        if(p[i].l>=now){
            ans++;
            now = p[i].r;
        }
    }
    printf("%d",ans);
    return 0;
}


