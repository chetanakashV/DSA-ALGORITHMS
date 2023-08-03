// Given a character and it's frequencies generate their codes in an optimal manner so that no prefix clashes occur . 
// This is called Huffman Encoding Algorithm
#include <bits/stdc++.h> 
using namespace std; 

struct Node{
    char c; 

    int freq; 

    Node* left; Node* right; 

    Node(char ch, int x){ c = ch; freq = x; }
};

struct compare {
 
    bool operator()(Node* l, Node* r)
    {
        return (l->freq > r->freq);
    }
};

void fill(vector<pair<char,string>>& res, Node* n, string s){
    if(n->c == '$') {
        fill(res, n->left, s + "0"); 
        fill(res, n->right, s + "1"); 
    }
    else {
        res.push_back({n->c, s}); 
    }
}

vector<pair<char,string>> HuffmanCoding(vector<char>& arr, vector<int>& fr){

    priority_queue<Node*, vector<Node*>, compare> pq; 
    for(int i = 0; i<arr.size(); i++) pq.push(new Node(arr[i], fr[i])); 

    while(pq.size() != 1){
        Node* temp1 = pq.top(); pq.pop(); Node* temp2 = pq.top(); pq.pop(); 
        Node* new_node = new Node('$', temp1->freq + temp2->freq); 
        new_node->left = temp1; new_node->right = temp2; 

        pq.push(new_node); 
        
    }

    vector<pair<char,string>> res; 
    fill(res, pq.top(), ""); 

    return res; 

}



int main() {

    vector<char> arr = {'a', 'b', 'c', 'd', 'e', 'f'}; 
    vector<int> fr = {5, 9, 12, 13, 16, 45};

    vector<pair<char,string>> codes = HuffmanCoding(arr, fr); 

    cout <<"Codes: " << endl; 
 
    for(int i = 0; i<codes.size(); i++) cout << codes[i].first << ": " << codes[i].second << " "; 

    return 0; 
}