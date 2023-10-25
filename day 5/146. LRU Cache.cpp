class LRUCache { 
    class ListNode{
        public:
        ListNode *prev;
        ListNode *next;
        int key;
        int value;
        ListNode(int key,int value){
            this->key=key;
            this->value=value;
        }
    };
    int cap;
    int count=0;
    ListNode *head=NULL;
    ListNode *tail=NULL;
    map<int,ListNode*>mp;
public:
    LRUCache(int capacity) {
        cap=capacity;
        head=new ListNode(0,0);
        tail=new ListNode(0,0);
        head->next=tail;
        tail->prev=head;
        head->prev=NULL;
        tail->next=NULL;
    }
    int get(int key) {
          if(mp.find(key)!=mp.end()){
              auto itr=mp[key];
              ListNode *prev=itr->prev;
              ListNode *next=itr->next;
              prev->next=next;
              next->prev=prev;
              next=head->next;
              head->next=itr;
              itr->prev=head;
              itr->next=next;
              next->prev=itr;
              return itr->value;
          } 
        else{
            return -1;
        }
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
             auto itr=mp[key]; 
               itr->value=value;
              ListNode *prev=itr->prev;
              ListNode *next=itr->next;
              prev->next=next;
              next->prev=prev;
              mp.erase(itr->key);
              delete(itr);
        }
        else if(mp.size()==cap){
              // remove the leasr used key 
              // add the  latest key;
            ListNode *prev=tail->prev;
            ListNode *tailprev=prev->prev;
            tailprev->next=tail;
            tail->prev=tailprev;
            mp.erase(prev->key);
            delete(prev);
        }
        ListNode *temp=new ListNode(key,value);
        temp->next=head->next;
        head->next->prev=temp;
        head->next=temp;
        temp->prev=head;
        mp[key]=temp;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
