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