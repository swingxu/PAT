#include <iostream>
#include <string>
using namespace std;

/*
 * 总结：
 * 可以直接用STL：to_string（a+b）
 */

string int2string(long long int a){
    string ans;
    int num = 0;
    if(a == 0) return "0";
    if(a < 0) a = -a;
    while(a){
        if(!(num%3)&&num!=0) ans.insert(ans.begin(),',');
        num++;
        ans.insert(ans.begin(),a%10+'0');
        a /= 10;
    }
    return ans;
}
int main() {
    long long int a,b;
    scanf("%lld %lld",&a,&b);
    if(a+b < 0) printf("-");
    cout<<int2string(a+b)<<endl;
    return 0;
}