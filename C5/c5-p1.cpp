#include <iostream>
#include <vector>
using namespace std;

pair<int, int> findMax(vector<int> a, int N, int T){
    pair<int, int> result(0, 0);
    bool firstUpdate = false;

    for(int i = 0; i < N; i++){
        for(int j = i + 1; j < N; j++){
            if((a[i] + a[j] == T) && firstUpdate == false){
                result.first = i;
                result.second = j;
                firstUpdate = true;
            }
            else if((a[i] + a[j] == T) && firstUpdate == true){
                if(result.first == i && result.second > j){
                    result.second = j;
                }
            }
            
        }
    }

    if(firstUpdate == false){
        result.first = -1;
        result.second = -1;
        return result;
    }
    else{
        return result;
    }
}


int main(){
    int N, T; /* N: So luong san pham, T: Gia tri tong 2 sp */
    cin >> N >> T;

    vector<int> a(N);
    for(int i = 0; i < N; i++){
        cin >> a[i];
    }

    pair<int, int> result = findMax(a, N, T);
    if(result.first == -1){
        cout << "-1" << "\n";
    }
    else{
        cout << result.first  << " " << result.second << "\n";
    }
}