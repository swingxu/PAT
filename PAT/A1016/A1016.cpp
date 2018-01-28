#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
int fee[25],records_sum;

typedef struct RECORD {
    int time,day,hour,min;
    bool flag;
} REC;

struct USER {
    string name;
    int month;
    vector<REC> record;
} user[1050];

map<string,int> fname;

bool cmp_name(USER a,USER b){
    return a.name<b.name;
}

bool cmp_time(REC a, REC b){
    return a.time<b.time;
}

double fee_sum(REC on,REC off){
    double sum = 0.0;
    while(on.time < off.time){
        on.time++;
        sum += fee[on.hour];
        on.min++;
        if(on.min == 60){
            on.min = 0 ;
            on.hour++;
            if(on.hour == 24){
                on.hour = 0;
                on.day++;
            }
        }
    }
    return sum/100.00;
}
void bill(int x){
    sort(user[x].record.begin(),user[x].record.end(),cmp_time);
    bool mark = true;
    double sum = 0.0;
    cout<<user[x].name<<" ";
    printf("%02d\n",user[x].month);
    for(int j = 0 ; j <user[x].record.size();j++){
        int on,off;
        if(mark == true) {
            if(user[x].record[j].flag == true){
                on = j;
                mark = false;
            }
        } else {
            if(user[x].record[j].flag == true) {
                on = j;
            } else {
                off = j;
                mark = true;
                printf("%02d:%02d:%02d ",user[x].record[on].day,user[x].record[on].hour,user[x].record[on].min);
                printf("%02d:%02d:%02d ",user[x].record[off].day,user[x].record[off].hour,user[x].record[off].min);
                printf("%d ",user[x].record[off].time-user[x].record[on].time);
                double sum_temp = fee_sum(user[x].record[on],user[x].record[off]);
                printf("$%.2lf\n",sum_temp);
                sum += sum_temp;
            }
        }
    }
    printf("Total amount: $%.2lf\n",sum);
    return;
}

int main() {
    for(int i = 0 ; i < 24 ; i++){
        scanf("%d",&fee[i]);
    }
    scanf("%d",&records_sum);
    int mon,count=0;
    string name,lf;
    REC temp;
    for(int i = 0 ; i < records_sum ; i++){
        int no;
        cin>>name;
        if(fname.find(name) == fname.end()) {  /* 没找到名字 */
            no = count++;
            fname[name] = no;
            user[no].name = name ;
        } else {
            no = fname.find(name) -> second;
        }
        scanf("%d:%d:%d:%d",&mon,&temp.day,&temp.hour,&temp.min);
        temp.time = (temp.day-1) * 24 * 60 + temp.hour * 60 + temp.min;
        cin>>lf;
        if(lf == "on-line"){
            temp.flag = true;
        } else {
            temp.flag = false;
        }
        user[no].month = mon;
        user[no].record.push_back(temp);
    }
    sort(user,user+count,cmp_name);
    for(int i = 0 ; i < count ; i++){
        bill(i);
    }
    return 0;
}