#include <string>
#include <sstream>
#include <vector>
#include <iostream>

using namespace std;


struct node{
    public:
    node* next;
    int val;

    node(int val){
        next = nullptr;
        this->val = val;
    }
};

class queue
{
    private:
    node* head = nullptr;
    node* tail = nullptr;
    int size = 0;
    public:
    void push_Back(int id){
        node* curr = new node(id);
        if(head == nullptr){
            head = curr;
            tail = curr;
        }
        else{
            tail->next = curr;
            tail = curr;
        }

        size++;
    }

    void pop(){
        if(head == nullptr){
            return;
        }
        else if(head == tail){
            node* p = head;
            head = nullptr;
            tail = nullptr;
            delete p;
            size--;   
        }
        else{
            node* p = head;
            head = head->next;
            delete p;
            size--;
        }
    }

    int peak(){
        if(head == nullptr){
            return -1;
        }
        else{
            return head->val;
        }
    }


    void delete_Stack(){
        for(int i = 0; i < size; i++){
            pop();
        }
    }

    int get_Size(){
        return size;
    }
    
    node* get_Head(){
        return head;
    }

    node* get_Tail(){
        return tail;
    }
};

void run_Command(string command, queue &bufferList, int K){
    string action;
    int val;

    stringstream ss(command);
    // action ""
    ss >> action >> val;

    if(action == "RECORD"){
        if(bufferList.get_Size() < K){
            bufferList.push_Back(val);
        }
        else{
            bufferList.pop();
            bufferList.push_Back(val);
        }
    }
    else if(action == "READ"){
        if(bufferList.get_Size() != 0){
            cout << bufferList.peak() << "\n";
            bufferList.pop();
        }
        else{
            cout << "EMPTY" << "\n";
        }
    }
    else if(action == "PEEK_OLDEST"){
        if(bufferList.get_Size() != 0){
            cout << bufferList.peak() << "\n";
        }
        else{
            cout << "EMPTY" << "\n";
        }
    }
    else if(action == "SIZE"){
        cout << bufferList.get_Size() << "\n";
    }
}

int main(){
    int K, Q;
    cin >> K >> Q;

    cin.ignore();
    vector<string> cmd(Q);
    queue bufferList;
    for(int i = 0; i < Q; i++){
        getline(cin, cmd[i]);
        run_Command(cmd[i], bufferList, K);
    }
}