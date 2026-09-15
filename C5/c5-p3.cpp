#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

void QSum(vector<int> a, int L, int R){
    int sum = 0;
    for(L; L <= R; L++){
        sum = sum + a[L];
    }
    cout << sum << "\n";

}

void readCMD(string cmd, vector<int> a){
    int L;
    int R;
    
    stringstream ss (cmd);
    ss >> L >> R;

    QSum(a, L, R);
}

int main(){
    int N, Q; //N So ngay, Q So truy van
    cin >> N >> Q;
    
    vector<int> a(N); //Input bien dong tai chinh moi ngay
    for(int i = 0; i < N; i++){
        cin >> a[i];
    }

    cin.ignore(); //Input truy van
    vector<string> cmd(Q);
    for(int i = 0; i < Q; i++){
        getline(cin, cmd[i]);
    }

    for(int i = 0; i < Q; i++){ //Doc lenh
        readCMD(cmd[i], a);
    }
}

