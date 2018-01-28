#include <iostream>

struct student{
    char no[20];
    int checkin;
    int checkout;
}stu[100];

int main() {
    int num,hour,min,sec,cin=86400,cout=0,noin,nout;
    scanf("%d",&num);
    for(int i = 0 ; i < num ; i++){
        scanf("%s",stu[i].no);
        scanf("%d:%d:%d",&hour,&min,&sec);
        stu[i].checkin = 3600*hour+60*min+sec;
        scanf("%d:%d:%d",&hour,&min,&sec);
        stu[i].checkout = 3600*hour+60*min+sec;
    }
    for(int i = 0 ; i < num ; i++){
        if(stu[i].checkin<cin) {
            cin = stu[i].checkin;
            noin = i;
        }
        if(stu[i].checkout>cout){
            cout = stu[i].checkout;
            nout = i;
        }
    }
    printf("%s %s\n",stu[noin].no,stu[nout].no);
    return 0;
}