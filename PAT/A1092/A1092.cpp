#include <iostream>
#include <cstring>
#include <cstdio>

int hash(char a){
    if(a>='0'&&a<='9') return a-'0';
    if(a>='a'&&a<='z') return a-'a'+10;
    if(a>='A'&&a<='Z') return a-'A'+36;
}

int main() {
    char a[1010],b[1010];
    int key[128]={0},sum=0;
    scanf("%s%s",a,b);
    for(int i=0;a[i]!='\0';i++){
        key[hash(a[i])]++;
        sum++;
    }
    int flag=1,lose=0,used=0;
    for(int i=0;b[i]!='\0';i++){
        key[hash(b[i])]--;
        if(key[hash(b[i])]<0) {
            flag=0;
            lose++;
        }
    }
    if(flag==0){
        printf("No %d\n",lose);

    }
    else{
        printf("%Yes %d\n",strlen(a)-strlen(b));
    }
    return 0;
}