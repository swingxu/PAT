#include <iostream>
#include <string>
using namespace std;

int main() {
    string s1;
    cin >> s1;
    int sum = 0;
    for(int i = 0 ; i < s1.size() ; i++){
        sum += (s1[i] - '0');
    }
    string s = to_string(sum);
    string a[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight","nine"};
    for(int i = 0 ; i < s.size() ; i++){
        cout << a[s[i]-'0'] ;
        if(i < s.size() - 1){
            cout << " ";
        } else {
            cout << endl;
        }
    }
    return 0;
}