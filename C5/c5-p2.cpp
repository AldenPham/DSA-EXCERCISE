#include <iostream>
#include <vector>

using namespace std;

int findMax(vector<int> a, int N, int K){
    int max = 0;
    if(N == K){ //special case - N = K (only 1 window) O(K)
        for(int i = 0; i < N; i++){
            max += a[i]; 
        }
        return max;
    }

    int sum = 0; //first window slide
    for(int i = 0; i < K; i++){
        sum += a[i];
    }
    max = sum;
    
    //search the rest of the window 
    int index = K;
    for(index; index < N; index++){
        sum = sum - a[index - K];
        sum = sum + a[index];
        if(sum > max){
            max = sum;
        }
    }

    return max; 
}


int main(){
    int N, K; /* N: So luong ngay, K: Do dai cua so */
    cin >> N >> K;

    vector<int> a(N);
    for(int i = 0; i < N; i++){
        cin >> a[i];
    }

    cout << findMax(a, N, K);
}