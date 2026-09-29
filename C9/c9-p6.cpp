#include <vector>
#include <iostream>


using namespace std;

int stratA(const vector<int>& target,const vector<int>& baseArray){
    int cost = 0;
    for(const int& targetInt : target){
        for(const int& a : baseArray){
            if(a == targetInt){
                cost++;
                break;
            }

            cost++;
        }
    }
    

    return cost;
}

int stratB(const vector<int>& target, vector<int>& baseArray){
    int cost = 0;
    //sap xep = insertion sort
    for(int i = 1; i < baseArray.size(); i++){
        int key = baseArray[i];
        int j = i - 1;

        while(j >= 0 && baseArray[j] > key){
            cost++;
            baseArray[j + 1] = baseArray[j];
            j--;
        }
        if(j >= 0){
            cost++;
        }
        

        baseArray[j + 1] = key;
    }

    for(const int& targetInt : target){
        for(const int& a : baseArray){
            if(a >= targetInt){
                cost++;
                break;
            }

            cost++;
        }
    }

    return cost;

}

int main(){
    int N, Q;
    cin >> N >> Q;
    vector<int> baseArray(N);
    vector<int> targetArray(Q);

    for(int& a : baseArray){
        cin >> a;
    }

    for(int& a : targetArray){
        cin >> a;
    }


    int costA = stratA(targetArray, baseArray);
    int costB = stratB(targetArray, baseArray);

    cout << costA << endl << costB << endl;
    if(costA < costB){
        cout << "STRATEGY A\n"; 
    }
    else{
        cout << "STRATEGY B\n";
    }
}