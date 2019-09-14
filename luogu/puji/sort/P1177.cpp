//
// Created by 赵奕威 on 2019/9/11.
//

#include<bits/stdc++.h>
using namespace std;
int n,a[1000001];
int temp;
void qsort(int l,int r)
{
    if(l==r)
        return;
    else if(r-l==1){
        temp = a[l];
        a[l] = a[l]>a[r]?a[r]:a[l];
        a[r] = temp>a[r]?temp:a[r];
        return;
    }
    int mid=a[(l+r)/2];//中间数
    int i=l,j=r;
    do{
        while(a[i]<mid) i++;//查找左半部分比中间数大的数
        while(a[j]>mid) j--;//查找右半部分比中间数小的数
        if(i<=j)//如果有一组不满足排序条件（左小右大）的数
        {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            i++;
            j--;
        }
    }while(i<=j);//这里注意要有=
    if(l<j) qsort(l,j);//递归搜索左半部分
    if(i<r) qsort(i,r);//递归搜索右半部分
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    qsort(1,n);
    for(int i=1;i<=n;i++) printf("%d ",a[i]);
}