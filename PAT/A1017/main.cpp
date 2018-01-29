#include <iostream>
#include <algorithm>
using namespace std;

struct cus {
    int time;
    int arrive;
} customer[10010];

int windows[110];

bool cmp(cus a,cus b){
    return a.arrive < b.arrive;
}

int main() {
    int N,windows_num,_count = 0;
    scanf("%d%d",&N,&windows_num);
    for(int i = 0 ; i < N ; i++){
        int hh,mm,ss,time;
        scanf("%d:%d:%d",&hh,&mm,&ss);
        scanf("%d",&time);
        if(hh >= 17) continue;
        customer[_count].time = time;
        if(hh >= 8){
            customer[_count++].arrive = (hh - 8) * 3600 + mm * 60 + ss;
        } else {
            customer[_count++].arrive = -((8 - hh) * 3600 - mm * 60 - ss);
        }
    }
    int sum = 0;
    sort(customer,customer+_count,cmp);
    for(int i = 0 ; i < _count ; i++){
        cus now = customer[i];
        int min = 0x3fffffff,min_win = 0;
        for(int j = 0 ; j < windows_num ; j++){
            if(windows[j] < min){
                min = windows[j];
                min_win = j;
            }
        }
        if(min >= customer[i].arrive){
            sum += (min - customer[i].arrive);
            windows[min_win] += (customer[i].time * 60);
        } else {
            windows[min_win] = customer[i].arrive + 60 * customer[i].time;
        }

    }
    printf("%.1lf\n",sum * 1.00 /(_count * 60));
    return 0;
}