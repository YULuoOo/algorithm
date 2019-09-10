//P1003 铺地毯

#include <iostream>
#include <stdio.h>
using namespace std;
int main() {
    int n;
    int aa[10001][4];
    int a,b;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d %d %d %d",&aa[i][0],&aa[i][1],&aa[i][2],&aa[i][3]);
    }
    scanf("%d %d",&a,&b);
    for(int i=n-1;i>=0;i--){
        if(aa[i][0]<=a && aa[i][1]<= b &&aa[i][0]+aa[i][2]>=a&&aa[i][1]+aa[i][3]>=b){
            printf("%d",i+1);
            return 0;
        }
    }
    printf("-1");
    return 0;
}