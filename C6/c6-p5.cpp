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

    void push_Front_Node(node* target){
        if(target == nullptr){
            return;
        }
        else if(target == head && target == tail){
            return;
        }

        //Tim node truoc target
        node* curr = head;
        while(curr->next != target && curr->next != nullptr){
            curr = curr->next;
        }

        //Cat target
        curr->next = target->next;
        target->next = head;
        head = target;
    }

    void push_Back_Node(node* target){
        if(target == nullptr){
            return;
        }
        else if(target == head && target == tail){
            return;
        }

        //Tim node truoc target
        node* curr = head;
        while(curr->next != target && curr->next != nullptr){
            curr = curr->next;
        }

        //Cat target
        curr->next = target->next;
        target->next = nullptr;
        tail->next = target;
        tail = target;
    }

    void pop_Front(){
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

    void pop_Back(){
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

            curr = curr->next;
        }
         
    }

    void insert_At_Node(node* target, node* insert) /*Insert node ngay sau target*/{
        if(target == nullptr || insert == nullptr){
            return;
        }
        else if(target == tail){
            tail->next = insert;
            tail = insert;
        }
        else if(insert == tail){
            //Tim node truoc đó
            node* curr = head;
            while(curr->next != insert && curr->next != nullptr){
                curr = curr->next;
            }
            curr->next = nullptr;
            tail = curr;
            insert->next = target->next;
            target->next = insert;
        }
        else{
            insert->next = target->next;
            target->next = insert;
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

node* searchMid(node* head){
    node* slow = head;
    node* fast = head;
    while(fast != nullptr && fast->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

int main(){
    //Input
    int N;
    cin >> N;

    singly_Linked_List a;
    for(int i = 0; i < N; i++){
        int value;
        cin >> value;
        a.push_Back(value);
    }

    //Algo
    node* curr = a.get_Head();
    node* mid_Node = searchMid(a.get_Head());

    while(mid_Node != a.get_Tail()){
        a.insert_At_Node(curr, a.get_Tail());
        curr = curr->next->next;
    }

    //Output
    cout << a.get_Size() << "\n";
    curr = a.get_Head();
    for(int i = 0; i < N; i++){
        cout << curr->val << " ";
        curr = curr->next;
    }

}


