#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

string uDigit[13] = {
        "tret","jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"
};

string tDigit[13] = {
        "tret","tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"
};

string numtostring[170];
map<string,int> stringtonum;

void init(){
    for (int i = 0 ; i < 13 ; i++){
        for (int j = 0 ; j < 13 ; j++){
            if(i == 0 ){
                numtostring[j] = uDigit[j];
                stringtonum[uDigit[j]] = j;
            } else {
                if(j==0) {
                    numtostring[13*i + j] = tDigit[i];
                    stringtonum[tDigit[i]] = i*13 + j ;
                } else {
                    numtostring[13*i + j] = tDigit[i] + " " + uDigit[j];
                    stringtonum[tDigit[i] + " " + uDigit[j]] = i*13 + j ;
                }
            }
        }
    }
}

int s2int (string a){
    int ans = 0;
    for (int i = 0; i < a.length(); i++) {
        ans = ans*10 + (a[i]-'0');
    }
    return ans;
}

string int2s (int a){
    string ans;
    char x;
    while(a!=0){
        x = '0' + a%10;
        a = a/10;
        ans.insert(ans.begin(),x);
    }
    return ans;
}

int main() {
    init();
    int N;
    string s,ans[120];
    scanf("%d%*c",&N);
    for (int i = 0; i < N; i++) {
        getline(cin,s);
        if( s[0]<='9' && s[0]>='0') {
            int temp;
            temp = s2int(s);
            ans[i] = numtostring[temp] ;
        } else {
            int temp = stringtonum[s] ;
            ans[i] = int2s(temp);
        }
    }
    for(int i = 0 ; i < N ; i++){
        cout<<ans[i]<<endl;
    }
    return 0;
}