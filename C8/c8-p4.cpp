#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<string> adn(N);
    for(string& x : adn){
        cin >> x;
    }

    unordered_map<string, vector<string>> groups;
    vector<string> order;
    for(string x : adn){
        string key = x;
        sort(key.begin(), key.end());

        if(groups.find(key) != groups.end()){
            groups[key].push_back(x);
        }
        else{
            order.push_back(key);
            groups[key].push_back(x);
        }
        
    }

    for(string a : order){
        for(string x : groups[a]){
            cout << x << " ";
        }

        cout << endl;
    }
}