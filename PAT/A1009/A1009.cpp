#include <cstdio>

struct Ploy{
    int exp;
    double cof;
} poly[1001];

double ans[2000];

int main(){
    int n,m,count=0;
    scanf("%d",&n);
    for(int i = 0 ;i<n;i++){
        scanf("%d %lf",&poly[i].exp,&poly[i].cof);
    }
    scanf("%d",&m);
    for(int i = 0;i<m;i++){
        int exp;
        double cof;
        scanf("%d %lf",&exp,&cof);
        for(int j = 0;j<n;j++){
            ans[exp +poly[j].exp] += (cof*poly[j].cof);
        }
    }
    for(int i = 0;i<2001;i++){
        if(ans[i]!= 0.0) count++;
    }
    printf("%d",count);
    for(int i = 2000;i>=0;i--){
        if(ans[i] != 0.0){
            printf(" %d %.lf",i,ans[i]);
        }
    }
    return 0;
}