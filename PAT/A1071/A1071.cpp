#include <iostream>
#include <string>
#include <map>
using namespace std;

map<string,int> dict_;

/* s.erase 左闭右开
 * */

void clear_s(string str){
    string word;
    for(int i = 0 ; i < str.length() ; i++){
        if((str[i]>='0'&&str[i]<='9')||(str[i]>='A'&&str[i]<='Z')||(str[i]>='a'&&str[i]<='z')){
            if(str[i]>='A'&&str[i]<='Z') str[i] = str[i]- 'A' + 'a';
            word += str[i];
        } else if(str[i] ==' '){
            if(dict_.find(word)!=dict_.end()) dict_[word]++;
            else dict_[word] = 1;
            word.clear();
        } else {
            str.erase(str.begin()+i);
            i--;
        }

    }
    if(str.length()!=0){
        if(dict_.find(word)!=dict_.end()) dict_[word]++;
        else dict_[word] = 1;
    }

}
int main() {
    string s;
    getline(cin,s);
    clear_s(s);
    int MAX=0;
    string max;
    for (map<string,int>::iterator it=dict_.begin();it!=dict_.end();it++) {
        if(it->second >= MAX){
            if(it->second==MAX){
                if(it->first<max) {
                    MAX = it->second;
                    max = it->first;
                }
            } else{
                MAX = it->second;
                max = it->first;
            }
        }
    }
    if(MAX==0){
        cout<<'0'<<endl;
    } else{
        cout<<max<<" "<<MAX<<endl;

    }
    return 0;
}