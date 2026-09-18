#include <iostream>
#include <string>
#include <sstream>

using namespace std;

struct node{
    public:
    node* next;
    char val;

    node(char val){
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
    void push_Back(char id){
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

    char peak(){
        if(tail->val == '{'){
            return '}';
        }
        else if(tail->val == '('){
            return ')';
        }
        else if(tail->val == '['){
            return ']';
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

bool isValidSQL(string cmd){
    int n = cmd.size();
    stack a;
    for(int i = 0; i < n; i++){
        if(cmd[i] == '{' || cmd[i] == '(' || cmd[i] == '['){
            a.push_Back(cmd[i]);
        }
        else if(cmd[i] == '}' || cmd[i] == ')' || cmd[i] == ']'){
            if(a.get_Size() == 0){
                return false;
            }
            else if(cmd[i] == a.peak()){
                a.pop();
            }
            else{
                return false;
            }
        }
    }

    if(a.get_Size() == 0){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    string cmd;
    getline(cin, cmd);

    if(isValidSQL(cmd) == true){
        cout << "YES" << "\n";
    }
    else{
        cout << "NO" << "\n";
    }
}
