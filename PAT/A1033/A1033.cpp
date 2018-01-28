#include <cstdio>
#include <algorithm>
#include <math.h>
using namespace std;

struct station{
    double price,distance;
} stations[510];

bool cmp(station a,station b){
    return a.distance<b.distance;
};

int main() {
    double cmax,dis,avg;
    int N;
    double maxdis;
    scanf("%lf%lf%lf%d",&cmax,&dis,&avg,&N);
    maxdis = cmax * avg;
    for(int i = 0 ; i<N ; i++){
        scanf("%lf%lf",&stations[i].price,&stations[i].distance);
    }
    stations[N].price = 0;
    stations[N].distance = dis;
    sort(stations,stations+N,cmp);
    double cost = 0.0,road = 0.0,price,tank=0.0;
    int flag = 1;
    if(round(stations[0].distance)!=0){
        flag = 0;
        road = 0;
    } else {
        for (int i = 0; i < N; ) {
            if ((stations[i + 1].distance - stations[i].distance) > maxdis) {
                flag = 0;
                road = stations[i].distance + maxdis;
                break;
            }
            price = stations[i].price;
            int nextstation = i+1, findmin = 0;
            double minprice = stations[i + 1].price;
            for (int j = i + 1; (stations[j].distance <= (stations[i].distance + maxdis)) && (j <= N); j++) {
                if (stations[j].price < price) {
                    nextstation = j;
                    findmin = 1;
                    break;
                } else {
                    if (stations[j].price < minprice) {
                        nextstation = j;
                        minprice = stations[j].price;
                    }
                }
            }
            if (findmin) {
                cost += ((stations[nextstation].distance - stations[i].distance) / avg - tank) * price;
                tank = 0.0;
            } else {
                cost += price * (cmax-tank);
                tank = cmax - (stations[nextstation].distance - stations[i].distance) / avg;
            }
            i = nextstation;
        }
    }
    if(flag == 0 ){
        printf("The maximum travel distance = %.2lf",road);
    } else {
        printf("%.2lf\n",cost);
    }
    return 0;
}