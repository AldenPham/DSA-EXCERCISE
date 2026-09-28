#include <vector>
#include <iostream>

using namespace std;

int selectionSort(vector<int>& a){
    int swap = 0;
    for(int i = 0; i < a.size() - 1; i++){
        int min_Index = i;
        for(int j = i + 1; j < a.size(); j++){
            if(a[j] < a[min_Index]){
                min_Index = j;
            }
        }

        if(min_Index != i){
            int temp = a[i];
            a[i] = a[min_Index];
            a[min_Index] = temp;

            swap++;
        }
    }

    return swap;
}

int main(){
    int N;
    cin >> N;

    vector<int> array(N);
    for(int &a : array){
        cin >> a;
    }

    int swap = selectionSort(array);

    for(const int& a : array){
        cout << a << " ";
    }
    cout << "\n" << swap << "\n";
}