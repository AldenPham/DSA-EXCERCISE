#include <vector>
#include <iostream>

using namespace std;

int insertionSort(vector<int>& a){
    int shift = 0;
    for(int i = 1; i < a.size(); i++){
        int key = a[i];
        int j = i - 1;

        while(j >= 0 && a[j] > key){
            a[j + 1] = a[j];
            j--;
            shift++;
        }

        a[j + 1] = key;
    }

    return shift;
}

int countInversion(const vector<int>& a){
    int inversion = 0;
    for(int j = a.size() - 1; j >= 0; j--){
        for(int i = 0; i < j; i++){
            if(a[i] > a[j]){
                inversion++;
            }
        }
    }
    return inversion;
}

int main(){
    int N;
    cin >> N;
    vector<int> list(N);

    for(int& a : list){
        cin >> a;
    }
    int inversions = countInversion(list);
    int shifts = insertionSort(list);
    cout << inversions << endl;
    if(inversions == 0){
        cout << "SORTED" << endl;
    }
    else if(inversions <= N){
        cout << "NEARLY SORTED" << endl;
    }
    else{
        cout << "HIGHLY DISORDERED" << endl;
    }
    cout << shifts << endl;
}