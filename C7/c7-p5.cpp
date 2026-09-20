#include <iostream>
#include <string>
#include <sstream>
#include <vector>

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

class stack
{
    private:
    node* head = nullptr;
    node* tail = nullptr;
    int size = 0;
    public:
    void push(int id){
        node* curr = new node(id);

        if(head == nullptr){
            head = curr;
            tail = curr;
            size++;
        }
        else{
            curr->next = head;
            head = curr;
            size++;
        }
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
            delete(p);
            size--;
        }
    }

    int peak(){
        if(head != nullptr){
            return head->val;
        }
        else{
            return -1;
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

void ooh(vector<string> a, vector<int> &res){
    stack list;
    for(int i = a.size() - 1; i >= 0; i--){
        if(i == a.size() - 1){
            res[i] = 0;
            list.push(i);
        }
        else{
            while(list.get_Size() != 0){
                if(stoi(a[i]) <= stoi(a[list.peak()])){
                    res[i] = list.peak() - i;
                    break;
                }
                else{
                    list.pop();
                }
            }
            if(list.get_Size() == 0){
                res[i] = 0;
            }

            list.push(i);
        }
    }
}

int main(){
    int N;
    cin >> N;
    vector<string> a(N);
    
    cin.ignore();
    for(int i = 0; i < N; i++){
        cin >> a[i];
    }

    vector<int> res(N);

    ooh(a, res);
    for(int i = 0; i < N; i++){
        cout << res[i] << " ";
    }

}