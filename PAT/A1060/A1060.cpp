#include <iostream>
#include <string>
using namespace std;

int n;

string deletedot(string a,int& e){
    string res;
    while(a[0]=='0'&&a.length()>0){
        a.erase(a.begin());
    };
    if(a[0]=='.') {
        a.erase(a.begin());
        while(a[0] == '0' && a.length()>0){
            a.erase(a.begin());
            e--;
        }
        if(a.length()==0) e=0;
    }  else {
        int pos;
        if(a.find(".") != string::npos){
            pos = a.find(".");
            a.erase(a.begin()+pos);
        } else {
            pos = a.length();
        }
        e = pos ;
    }
    if(a.length()>=n){
        res = a.substr(0,n);
    } else {
        res = a.substr(0,a.length());
        while (res.length()<n){
            res += "0";
        }
    }
    return res;
}

int main() {
    string str1,str2,s1,s2;
    cin >> n >> str1 >> str2 ;
    int e1 = 0 , e2 = 0 ;
    s1 = deletedot(str1,e1);
    s2 = deletedot(str2,e2);
    if(s1==s2&&e1==e2) {
        cout << "YES 0." << s1 << "*10^" << e1 << endl ;
    } else {
        cout << "NO 0." << s1 << "*10^" << e1 << " 0." << s2 << "*10^" << e2 << endl ;
    }
    return 0;
}