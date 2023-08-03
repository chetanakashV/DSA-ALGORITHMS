// FLoyd cycle detection Method: It uses two pointers which run at speed one twice than the other returns the first point where they become equal or Null if they become NULL before. 
// Used to detect the first point of the linked list
#include <bits/stdc++.h> 
using namespace std; 

class Node{
    public: 
    int val ; 
    Node* next ; 

   Node(int x){val = x; next = NULL; }
    
}; 

Node* head = NULL; 
Node* tail = NULL; 

void Insert(int v){
    if(tail){
        Node* new_node = new Node(v); 
        tail->next = new_node; 
        tail = tail->next; 
    }
    else {
        Node* new_node = new Node(v); 
        tail = new_node; 
        head = new_node; 
    }
}

Node* findLoop(){
    Node* slow = head;  Node* fast = head; 
    while(true){
        slow = slow->next; 
        if(fast->next) fast = fast->next->next; 
        if(!slow) return NULL; if(!fast) return NULL;if(!fast->next) return NULL; 
        if(slow == fast) return slow; 
    }

    return NULL; 
}

int main() {

   
    Insert(10); 
    Insert(20); 
    Insert(30); 
    Insert(40); 
    Insert(50); 

    Node* cursor = head; tail->next = head->next; 
    

    Node* loop = findLoop(); 

    if(!loop) cout << " No Loop"; else cout << " Loop at " << loop->val; 

    return 0; 
}