#include <vector>
#include <iostream>
#include <string>
#include <utility>
#include <sstream>

using namespace std;

int hashFunc(int x, int M){
    return x % M;
}

//-1 = empty, -2 = tombstone

void PUT(int k, int v, vector<pair<int,int>>& openHash){
    if(openHash[hashFunc(k, openHash.size())].first == -1){
        openHash[hashFunc(k, openHash.size())].first = k;
        openHash[hashFunc(k, openHash.size())].second = v;
    }
    else if(openHash[hashFunc(k, openHash.size())].first == k){
        openHash[hashFunc(k, openHash.size())].second = v;
    }
    else{
        for(int i = 0; i < openHash.size(); i++){
            if(openHash[hashFunc(k + i, openHash.size())].first == -1 ){
                openHash[hashFunc(k + i, openHash.size())].first = k;
                openHash[hashFunc(k + i, openHash.size())].second = v;
                return;
            }
            else if(openHash[hashFunc(k + i, openHash.size())].first == k) {
                openHash[hashFunc(k + i, openHash.size())].second = v;
                return;
            }
        }
        cout << "FULL" << endl;
    }
}

void GET(int k, vector<pair<int,int>>& openHash){
    if(openHash[hashFunc(k, openHash.size())].first == k){
        cout << openHash[hashFunc(k, openHash.size())].second << endl;
        return;
    }
    for(int i = 0; i < openHash.size(); i++){
        if(openHash[hashFunc(k + i, openHash.size())].first == k){
            cout << openHash[hashFunc(k + i, openHash.size())].second << endl;
            return;
        }

        if(openHash[hashFunc(k + i, openHash.size())].first == -1){
            cout << "NOT_FOUND" << endl;
            return;
        }
    }

    cout << "NOT_FOUND" << endl;
    
}

void DEL(int k, vector<pair<int,int>>& openHash){
    for(int i = 0; i < openHash.size(); i++){
        if(openHash[hashFunc(k + i, openHash.size())].first == k){
            openHash[hashFunc(k + i, openHash.size())].first = -2;
            cout << "DELETED" << endl;
            return;
        }
        if(openHash[hashFunc(k + i, openHash.size())].first == -1){
            cout << "NOT_FOUND" << endl;
            return;
        }
    }

    cout << "NOT_FOUND" << endl;
}

int main(){
    int M, Q;
    cin >> M >> Q;
    vector<pair<int, int>> openHash(M, {-1,-1});
    
    cin.ignore();
    for(int i = 0; i < Q; i++){
        string cmd;
        getline(cin, cmd);

        stringstream ss(cmd);
        string action;
        int key, val;

        ss >> action >> key >> val; 

        if(action == "PUT"){
            PUT(key, val, openHash);
        }
        else if(action == "GET"){
            GET(key, openHash);
        }
        else if(action == "DEL"){
            DEL(key, openHash);
        }
    }
}