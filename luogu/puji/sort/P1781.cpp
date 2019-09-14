//
// Created by 赵奕威 on 2019/9/14.
//
#include<bits/stdc++.h>
using namespace std;
int n;
char *a = new char[101];
char *b = new char[101];
char *c = new char[101];
bool f = true;
int x;
bool a_bigger_b(char qq[],char pp[]){
    int l1 = strlen(qq);
    int l2 = strlen(pp);
    if(l1!=l2)
        return l1>l2;
    for(int i=0;i<l1;i++){
        if(qq[i]==pp[i])
            continue;
        return qq[i]>pp[i];
    }
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        cin>>(f?b:a);
        if(a_bigger_b(a,b)) {
            x = f?x:i;
            f = true;
            c = a;
        } else{
            x = f?i:x;
            f = false;
            c = b;
        }
    }
    cout<<x<<endl<<c<<endl;
}
