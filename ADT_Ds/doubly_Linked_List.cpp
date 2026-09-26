struct node{
    public:
    node* next;
    node* prev;
    int val;

    node(int val){
        next = nullptr;
        prev = nullptr;
        this->val = val;
    }
};

class doubly_Linked_List{
    private:
        node* head = nullptr;
        node* tail = nullptr;
        int size = 0;
    public:
        void push_Back(int value){
            node* curr = new node(value);
            if(head == nullptr){
                head = curr;
                tail = curr;
                size++;
            }
            else{
                tail->next = curr;
                curr->prev = tail;
                tail = curr;
                size++;
            }
        }

        void push_Front(int value){
            node* curr = new node(value);
            if(head == nullptr){
                head = curr;
                tail = curr;
                size++;
            }
            else{
                head->prev = curr;
                curr->next = head;
                head = curr;
                size++;
            }
        }

        void pop_Back(){
            if(head == nullptr){
                return;
            }
            else if(head == tail){
                delete head;
                head = nullptr;
                tail = nullptr;
                size--;
            }
            else{
                node* old_Tail = tail;
                tail = tail->prev;
                tail->next = nullptr;
                delete old_Tail;
                size--;
            }

        }

        void pop_Front(){
            if(head == nullptr){
                return;
            }
            else if(head == tail){
                delete head;
                head = nullptr;
                tail = nullptr;
                size--;
            }
            else{
                node* old_Head = head;
                head = head->next;
                head->prev = nullptr;
                delete old_Head;
                size--;
            }
        }

        node* search_Val(int value){
            node* curr = head;
            if(curr == nullptr){
                return nullptr;
            }
            while(curr->val != value){
                if(curr->next == nullptr){
                    return nullptr;
                }
                
                curr = curr->next;
            }
            return curr;
        }

        void delete_Val(int value){
            //Find node
            node* curr = search_Val(value);
            if(curr == nullptr){
                return;
            }

            if(curr == head){
                pop_Front();
            }
            else if(curr == tail){
                pop_Back();
            }
            else{
                curr->prev->next = curr->next;
                curr->next->prev = curr->prev;
                delete curr;
                size--;
            }
        }

        void delete_Node(node* targetNode){
            if(targetNode == nullptr){
                return;
            }
            else if(targetNode == head){
                pop_Front();
            }
            else if(targetNode == tail){
                pop_Back();
            }
            else{
                targetNode->prev->next = targetNode->next;
                targetNode->next->prev = targetNode->prev;
                delete targetNode;
                size--;
            }
        }

        void swap_Front(node* target) {
            node* prev = target->prev;
            if(prev == nullptr){
                return;
            }

            node* before = prev->prev;
            node* after = target->next;

            // connect node before prev -> target
            if(before){
                before->next = target;
            }
            else{
                head = target;
            }
                

            // target
            target->prev = before;
            target->next = prev;

            // prev
            prev->prev = target;
            prev->next = after;

            // node after target
            if (after)
                after->prev = prev;
            else
                tail = prev;
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
