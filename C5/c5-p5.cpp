//Nếu giờ làm kiểu tổng N

//Kiểm tra -> liệu array có hợp lý (best case O(1), worse case O(N))
//O(N + (N - 1))


#include <iostream>
#include <vector>

using namespace std;

int main(){
    int N, T;
    cin >> N >> T;

    vector<int> a(N);
    for(int i = 0; i < N; i++){
        cin >> a[i];
    }

    int window_Size = 0;
    int sum = 0;

    //Check for the smallest valid window or is list valid (have sum >= T with N -1 element)
    for(int i = 0; i < N; i++){
        sum += a[i];
        window_Size++;
        
        if(sum >= T){
            break;
        }
    }
    if(sum < T){
        cout << "-1";
        return 0;
    }

    //Innitialize the first window - 1 and start checking for any possible window with smaller size
    
    window_Size = window_Size - 1;
    sum =sum - a[window_Size] ;
    
    for(int i = window_Size; i > 0; i--){
        bool isWindowSizeValid = false;
        
        for(int j = i; j < N; j++){
            if(sum >= T){
                sum -= a[j];
                isWindowSizeValid = true;
                break;
            }

            sum += a[j];
            sum -= a[j - window_Size];
        } 

        if(isWindowSizeValid == false){
            break;
        }
        window_Size--;
    }

    cout << window_Size;
}