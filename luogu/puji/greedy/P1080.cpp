//
// Created by 赵奕威 on 2019/9/10.
// 贪心
//
#include<bits/stdc++.h>
using namespace std;
int n,a[101],sum,ans;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]),sum+=a[i];
    int avg = sum/n;
    for(int i=1;i<=n;i++)
        if(a[i]-avg)
            a[i+1]+=a[i]-avg,ans++;
    printf("%d",ans);
    return 0;
}

