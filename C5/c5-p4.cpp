#include <iostream>
#include <vector>

using namespace std;

bool binarySearch(vector<int> a, int vector_Size, int target){
    int L = 0, 
        R = a[vector_Size - 1], 
        Mid;

    while(L <= R){
        Mid = (L + R) / 2;
        if(a[Mid] == target){
            return true;
        }
        else if(a[Mid] < target){
            L = Mid + 1;
        }
        else{
            R = Mid - 1;
        }
    }

    return false;
}


int main(){
    int N, M;
    cin >> N >> M; //Nhập kích thước mảng A và B


    vector<int> A(N), B(M); 
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }
    for(int i = 0; i < M; i++){
        cin >> B[i];
    } //Nhập 2 mảng A, B

    //Main algo
    vector<int> JointedTable;
    int i = 0,
        j = 0,
        dupplicate = 0;
        
    while(i < N && j < M){
        if(A[i] == B[j]){
            JointedTable.push_back(A[i]);
            dupplicate++;
            i++;
            j++;
            
        }
        else if(A[i] < B[j]){
            JointedTable.push_back(A[i]);
            i++;    
        }
        else{
            JointedTable.push_back(B[j]);
            j++;
        }
    }

    while(j < M){
        JointedTable.push_back(B[j]);
        j++;
    }

    while(i < N){
        JointedTable.push_back(A[i]);
        i++;
    }

    //output
    cout << JointedTable.size() << "\n";
    for(int count = 0; count < JointedTable.size(); count++){
        cout << JointedTable[count] << " ";
    } 
    cout << "\n" << dupplicate;
}