#include <iostream>
#include <vector>
using namespace std;
int main() {
    int N;
    int a[10010];
    scanf("%d",&N);
    for(int i = 0 ; i < N ; i++){
        scanf("%d",&a[i]);
    }
    vector<int> temp;
    vector<int> ans;
    int temp_sum = 0,ans_sum = -100000;
    for(int i = 0 ; i < N ; i++){
        if(temp_sum <= 0){
            if(a[i] >= temp_sum){
                temp.clear();
                temp_sum = 0;
                temp.push_back(a[i]);
                temp_sum += a[i];
            } else {
                if(temp.size() == 0){
                    temp.push_back(a[i]);
                    temp_sum += a[i];
                }
            }
        } else {
            temp.push_back(a[i]);
            temp_sum += a[i];
        }
        if(temp_sum > ans_sum){
            ans = temp;
            ans_sum = temp_sum;
        }
    }
    if(ans_sum >= 0){
        printf("%d %d %d\n",ans_sum,*ans.begin(),*(ans.end()-1));
    } else {
        printf("0 %d %d\n",a[0],a[N-1]);
    }
    return 0;
}