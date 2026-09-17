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

    node* get_Tail(){
        return tail;
    }
};

pair<bool, int> /*isCycle && entryVal*/ findCycle(node* head){
    node* slow = head;
    node* fast = head;

    //Find cycle
    bool isCycle = false;
    while(fast != nullptr && fast->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
        
        if(fast == slow){
            isCycle = true;
            break;
        }
    }

    if(isCycle == false){
        return {false, -1};
    }

    //Find firstNode
    int index = 0;
    slow = head;
    while(slow != fast){
        slow = slow->next;
        fast = fast->next;
        index++;
    }

    return {isCycle, index};
}

int main(){
    //INPUT linked list
    int N;
    cin >> N;

    singly_Linked_List a;
    for(int i = 0; i < N; i++){
        int web_Id;
        cin >> web_Id;
        a.push_Back(web_Id);
    }
    
    int pos;
    cin >> pos;

    //Xu ly cycle
    if(pos != -1){
        node* curr = a.get_Head();
        int index = 1;
        while(index != pos){
            curr = curr->next;
            index++;
        }
        a.get_Tail()->next = curr->next;
    }
    

    //OUTPUT
    pair<bool, int> res = findCycle(a.get_Head());
    if(res.first == false){
        cout << "NO" << "\n";
    }
    else{
        cout << "YES" << "\n";
        cout << a.get_Size() - res.second << " ";
        node* curr = a.get_Head();
        for(int i = 0; i < res.second; i++){
            curr = curr->next;
        }
        cout << curr->val;
    }
}