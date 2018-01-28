#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 150;
int n;
int data[maxn],goal[maxn];
bool _isInsert = false;

bool compare(int a[],int b[]){
    for(int i = 1 ; i <= n ; i++){
        if(a[i] != b[i]) return false;
    }
    return true;
}

void isInsert(int a[],int b[]){
    int i,j;
    bool onemore = false;
    for(i = 2 ; i <= n ; i++){
        int temp = a[i];
        for(j = i ; j > 1 ; j--){
            if(a[j-1] < temp) break;
            a[j] = a[j-1];
        }
        a[j] = temp;
        if(onemore) return;
        else {
            _isInsert = compare(a,b);
        }
        if(_isInsert) onemore = true;
    }
}

void HS_once(){
    int N ;
    for(int i = n ; i>0 ; i--){
        if(goal[1]>goal[i]) {
            swap(goal[1],goal[i]);
            N = i-1;
            break;
        }
    }
    int i = 1 ,j = i * 2;
    while(j <= N){
        if(j + 1 <= N && goal[j+1] > goal[j]) {
            j++;
        }
        if(goal[j] > goal[i]){
            swap(goal[j],goal[i]);
            i = j;
            j = i * 2;
        } else {
            break;
        }
    }
}

int main() {
    scanf("%d",&n);
    for(int i = 1 ; i <= n ; i++){
        scanf("%d",&data[i]);
    }
    for(int i = 1 ; i <= n ; i++){
        scanf("%d",&goal[i]);
    }
    isInsert(data,goal);
    if(_isInsert){
        printf("Insertion Sort\n");
        for(int i = 1 ; i <= n ; i++){
            printf("%d",data[i]);
            if(i<n) printf(" ");
            else printf("\n");
        }
    } else {
        HS_once();
        printf("Heap Sort\n");
        for (int i = 1; i <= n; i++) {
            printf("%d", goal[i]);
            if (i < n) printf(" ");
            else printf("\n");
        }
    }
    return 0;
}