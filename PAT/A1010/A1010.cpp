#include <iostream>
#include <cstring>
#include <math.h>
#include <algorithm>
using namespace std;

long long inf = (1 << 63) - 1;
long long char2ten(char *p,long long a){
    if(*(p+1)=='\0') {
        if(*p<='z'&&*p>='a') return *p-'a'+10;
        else return *p-'0';
    } else {
        int len = strlen(p);
        if(*p<='z'&&*p>='a') return (*p-'a'+10)*pow(a,len-1)+char2ten(p+1,a);
        else return (*p-'0')*pow(a,len-1)+char2ten(p+1,a);
    }
}

int char2int(char p){
    if(p<='z'&&p>='a') return p -'a'+10;
    else return p - '0';
}

int main() {
    char N[2][40];
    long long goal,r;
    int tag,ans;
    scanf("%s %s %d %lld",N[0],N[1],&tag,&r);
    goal = char2ten(N[tag-1],r);
    char max='0';
    for(int i=0;i<strlen(N[!(tag-1)]);i++){
        if(N[!(tag-1)][i]>max) max = N[!(tag-1)][i];
    }
    long long left = char2int(max)+1,right = 35,mid,flag=0;
    long long test;
    if(strlen(N[!(tag-1)])==1){
        test = char2ten(N[!(tag-1)],left);
        if(test == goal) {
            flag = 1;
            ans = left;
        }
    } else  {
        while(left<=right){
            mid = left + (right-left)/2;
            test = char2ten(N[!(tag-1)],mid);
            if(test == goal) {
                flag = 1;
                ans = mid;
                break;
            }
            else if (test > goal ) right = mid -1 ;
            else left = mid + 1;
        }
    }
    if(flag==1) printf("%lld",ans);
    else printf("Impossible");
    return 0;
}