#include <iostream>
#include <unordered_map>

using namespace std;

int main(){
    int N;
    cin >> N;

    unordered_map<string, bool> ticketsList;

    for(int i = 0; i < N; i++){
        string ticket;
        cin >> ticket;

        ticketsList[ticket] = false;
    }

    int Q;
    cin >> Q;

    for(int i = 0; i < Q; i++){
        string ticket;
        cin >> ticket;

        auto it = ticketsList.find(ticket);

        if(it == ticketsList.end()){
            cout << "INVALID\n";
        }
        else{
            if(it->second == false){
                cout << "VALID\n";
                it->second = true;
            }
            else{
                cout << "DUPLICATE\n";
            }
        }
    }
}