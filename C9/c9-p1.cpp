#include <iostream>
#include <vector>

using namespace std;

int main(){
    int N, X;
    cin >> N >> X;

    vector<int> log(N);

    for(int& a : log){
        cin >> a;
    }
    bool isError = false;
    for(int i = 0; i < N; i++){
        if(log[i] == X){
            isError = true;
            cout << i << " ";
        }
    }

    if(!isError){
        cout << -1 << endl;
    }
}