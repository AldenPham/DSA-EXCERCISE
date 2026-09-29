#include <vector>
#include <iostream>
#include <utility>
#include <sstream>
#include <string>

using namespace std;

void insertionSort(vector<pair<string, int>>& a){
    for(int i = 1; i < a.size(); i++){
        pair<string, int> key = a[i];
        int j = i - 1;

        while(j >= 0 && a[j].second < key.second ){
            a[j + 1] = a[j];
            j--;
        }

        a[j+1] = key;
    }
}


int main(){
    int N;
    cin >> N;
    vector<pair<string, int>> list(N);

    cin.ignore();
    for(pair<string, int>& a : list){
        string input;
        getline(cin, input);
        stringstream ss(input);

        string name;
        int point;
        ss >> name >> point;

        a.first = name;
        a.second = point;
    }

    insertionSort(list);
    for(const pair<string, int>& a : list){
        cout << a.first << " " << a.second << endl;
    }
}