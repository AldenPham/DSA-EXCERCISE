#include <iostream>
#include <utility>

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

class singly_Linked_List
{
    private:
    node* head = nullptr;
    node* tail = nullptr;
    int size = 0;
    
    public:
    void push_Front(int id){
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

    void pop_Front(){
        if(head == nullptr){
            return;
        }
        else{
            node* p = head;
            head = head->next;
            delete(p);
            size--;
        }
    }
    
    void delete_Value(int id){
        node* curr = head;
        
        if(head == nullptr){
            return;
        }

        if(head->val == id){
            pop_Front();
            return;
        }

        while(curr->next != nullptr){
            if(curr->next->val == id){
                node* p = curr->next;
                
                curr->next = curr->next->next;
                        
                if(p == tail){
                    tail = curr;
                }

                delete(p);
                size--;
                return;
            }        
        }
         
    }

    int get_Size(){
        return size;
    }

    node* get_Head(){
        return head;
    }

};

pair<node* , int> splitWork(node* head){
    node* slower = nullptr;
    node* slow = head;
    node* fast = head;
    
    int index = 0;

    while(fast != nullptr && fast->next != nullptr){
        slower = slow;
        slow = slow->next;
        fast = fast->next->next;
        index++;
    }

    return {slower, index};
}

int main(){
    int N;
    cin >> N; //So luong cong viec

    singly_Linked_List a;
    for(int i = 0; i < N; i++){
        int job_Id;
        cin >> job_Id;

        a.push_Back(job_Id);
    }

    //OUTPUT
    pair<node*, int> info = splitWork(a.get_Head());
    if(info.first == nullptr){
        cout << a.get_Head()->val << "\n";
        cout << "0" << "\n";
        cout << a.get_Size() << " " << a.get_Head()->val << "\n";
    }
    else{
        //split
        node* head1 = a.get_Head();
        node* head2 = info.first->next;
        info.first->next = nullptr;
        cout << head2->val << "\n";
        //BLOCK A
        cout << info.second << " ";
        for(int i = 0; i < info.second; i++){
            cout << head1->val << " ";
            head1 = head1->next;
        }
        cout << "\n";

        //BLOCK B;
        cout << a.get_Size() - info.second << " ";
        for(int i = info.second; i < a.get_Size(); i++){
            cout << head2->val << " ";
            head2 = head2->next;
        }
    }
    
}