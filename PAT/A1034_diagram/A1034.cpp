#include <map>
#include <cstdio>
#include <string>
#include <iostream>
using namespace std;
const int maxn = 2010;

int n,k,G[maxn][maxn],weight[maxn],pnum = 0;
bool vis[maxn] = {false};

map<string,int> string_int;
map<int,string> int_string;
map<string,int> Gang;

int s2int(string str){
    if(string_int.find(str) != string_int.end()) {
        return string_int[str];
    } else {
        string_int[str] = pnum;
        int_string[pnum] = str;
        return pnum++;
    }
}

void DFS(int nowvisit, int& head, int& numMember, int& totalvalue){
    numMember++;
    vis[nowvisit] = true;
    if(weight[nowvisit] > weight[head]){
        head = nowvisit;
    }
    for(int i = 0 ; i < pnum ; i++){
        if(G[nowvisit][i] > 0){
            totalvalue += G[nowvisit][i];
            G[nowvisit][i] = G[i][nowvisit] = 0;
            if(vis[i] == false){
                DFS(i,head,numMember,totalvalue);
            }
        }
    }
}

void DFSTrave(){
    for(int i = 0 ; i < pnum ; i++){
        if(vis[i] == false) {
            int head = i , numMember = 0 , totalvalue = 0;
            DFS(i,head,numMember,totalvalue);
            if(numMember > 2 && totalvalue > k){
                Gang[int_string[head]] = numMember;
            }
        }
    }
}

int main(){
    int w;
    cin >> n >> k;
    string str1,str2;
    for(int i = 0 ; i < n ; i++){
        cin >> str1 >> str2 >> w ;
        int x = s2int(str1);
        int y = s2int(str2);
        G[x][y] += w;
        G[y][x] += w;
        weight[x] += w;
        weight[y] += w;
    }
    DFSTrave();
    cout << Gang.size() << endl;
    map<string,int>::iterator it;
    for(it = Gang.begin();it != Gang.end() ; it++){
        cout << it->first << " " << it->second << endl;
    }
    return 0;
}