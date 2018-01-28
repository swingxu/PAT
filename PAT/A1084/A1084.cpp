#include <iostream>
#include <cstdio>
#include <cstring>

int hash(char a){
    if(a>='0'&&a<='9') return a-'0';
    if(a>='a'&&a<='z') return a-'a'+10;
    if(a>='A'&&a<='Z') return a-'A'+10;
    if(a=='_') return 36;
}

int main() {
    char a[10000],b[10000];
    int key[40]={0},i=0;
    gets(a);
    gets(b);
    while(b[i]!=0){
        key[hash(b[i])]=1;
        i++;
    }
    for(i=0;a[i]!='\0';i++){
        if(key[hash(a[i])]==0){
            if(a[i]>='a'&&a[i]<='z'){
                printf("%c",a[i]-'a'+'A');
            }
            else printf("%c",a[i]);
            key[hash(a[i])]=1;
        }
    }
    return 0;
}