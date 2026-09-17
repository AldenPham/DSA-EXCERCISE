#include <iostream>

using namespace std;

int doubling(int N){
    int capacity = 1;
    int size = 0;
    int element_copies = 0;

    while(size < N){
        if(size == capacity){
            capacity = capacity*2;
            element_copies += size;
            size++;
        }
        else{
            size++;
        }   
    }

    return element_copies;
}

int additive(int N, int K){
    int capacity = 1;
    int size = 0;
    int element_copies = 0;

    while(size < N){
        if(size == capacity){
            capacity += K;
            element_copies += size;
            size++;
        }
        else{
            size++;
        }
    }

    return element_copies;
}


int main(){
    int N, K;
    cin >> N >> K;

    cout << doubling(N) << "\n";
    cout << additive(N, K) << "\n";


    int compare = doubling(N) - additive(N, K);
    if(compare > 0){
        cout << "ADDITIVE" << "\n";
    }
    else if(compare < 0){
        cout << "DOUBLING" << "\n";
    }
    else{
        cout << "TIE" << "\n";
    }

    

}
