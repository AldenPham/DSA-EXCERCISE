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


int main(){
    int N;
    cin >> N;
    vector<int> array(N);
    for(int& a : array){
        cin >> a;
    }

    int shift = insertionSort(array);

    for(const int& a : array){
        cout << a << " ";
    }
    cout << "\n" << shift << endl;
}