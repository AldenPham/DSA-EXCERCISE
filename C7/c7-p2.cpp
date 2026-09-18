#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

struct node{
    public:
    node* next;
    string val;

    node(string val){
        next = nullptr;
        this->val = val;
    }
};

class stack
{
    private:
    node* head = nullptr;
    node* tail = nullptr;
    int size = 0;
    public:
    void push_Back(string id){
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
            node* p = tail;
            head = nullptr;
            tail = nullptr;
            delete p;
            size--;   
        }
        else{
            //Tim node truoc target
            node* curr = head;
            while(curr->next != tail && curr->next != nullptr){
                curr = curr->next;
            }
            curr->next = nullptr;
            delete tail;
            tail = curr;
            size--;
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




void run_Command(string command, stack& undo, stack& redo){
    string action;
    string val;

    stringstream ss(command);
    // action ""
    ss >> action >> val;

    if(action == "TYPE"){
        undo.push_Back(val);
        if(redo.get_Size() != 0){
            redo.delete_Stack();
        }
    }
    else if(action == "UNDO"){
        if(undo.get_Size() != 0){
            redo.push_Back(undo.get_Tail()->val);
            undo.pop();
        }
    }
    else if(action == "REDO"){
        if(redo.get_Size() != 0){
            undo.push_Back(redo.get_Tail()->val);
            redo.pop();
        }
    }
}

int main(){
    int Q;
    cin >> Q;
    vector<string> cmd(Q);
    stack undo, redo;
    cin.ignore();
    for(int i = 0; i < Q; i++){
        getline(cin, cmd[i]);
        run_Command(cmd[i], undo, redo);
    }

    if(undo.get_Size() != 0){
        cout << undo.get_Size() << "\n";
        node* curr = undo.get_Head();
        for(int i = 0; i < undo.get_Size(); i++){
            cout << curr->val << " ";
            curr = curr->next;
        }
    }
    else{
        cout << 0 << "\n";
    }
}