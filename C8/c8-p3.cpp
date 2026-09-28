#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int findSubArray(vector<int> array){
    int sum = 0;
    int ans = 0;
    unordered_map<long long, int> prefix;
    prefix[0] = -1;

    for(int i = 0; i < array.size(); i++){
        sum += array[i];

        if(prefix.find(sum) != prefix.end()){
            ans = max(ans, i - prefix[sum]); 
        } 
        else{
            prefix[sum] = i;
        }
    }   

    return ans;
}


int main(){
    int N;
    cin >> N;
    vector<int> array(N);
    for(int& x : array){
        cin >> x;
    }

    cout << findSubArray(array) << endl;

}