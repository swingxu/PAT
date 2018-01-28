#include <iostream>
#include <algorithm>
using namespace std;

const int size=100000;
int main() {
    int N,sum,a[size];
    scanf("%d %d",&N,&sum);
    for (int i = 0; i < N ; ++i) {
        scanf("%d",&a[i]);
    }
    sort(a,a+N);
    bool flag= false;
    int i=0,j=N-1;
    if(sum<=a[0])  flag=false;
    else {
        while(i<j){
            if(a[i]+a[j]==sum) {
                flag = true;
                break;
            }
            else if(a[i]+a[j]<sum) i++;
            else j--;
        }
    }
    if(flag==false) printf("No Solution");
    else printf("%d %d\n",a[i],a[j]);
    return 0;
}