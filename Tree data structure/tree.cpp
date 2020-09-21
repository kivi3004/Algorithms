#include<bits/stdc++.h>

using namespace std;
struct Node{
    Node* left;
    int val;
    Node* right;
    Node(int x){
        val = x;
        left = right = NULL;
    }
};
Node* insert(Node* root, int value, queue<Node*>& q){
    Node* head = new Node(value);
    if(root==NULL)
        root =  head;
    else if(q.front()->left==NULL)
        q.front()->left = head;
    else{
        q.front()->right = head;
        q.pop();
    }
    q.push(head);
    return root;
}
Node* constructTree(vector<int> t){
    Node* root = NULL;
    queue<Node*> q;
    for(int i=0; i<t.size(); i++){
        root = insert(root, t[i],q);
    }
    return root;
}
bool del(Node* root, int v, vector<Node*>& add){
    if(root==NULL)
        return false;
    queue<Node*> q;
    q.push(root);
    while(q.size()){
        Node* head = q.front();
        q.pop();
        if(head->left){
            if(head->left->val==v){
                if(head->left->left)
                    add.push_back(head->left->left);
                if(head->left->right)                    
                    add.push_back(head->left->right);
                head->left=NULL;
                return true;
            }
            q.push(head->left);
        }
        if(head->right){
            if(head->right->val==v){
                if(head->right->left)
                    add.push_back(head->right->left);
                if(head->right->right)                    
                    add.push_back(head->right->right);
                head->right=NULL;
                return true;
            }
            q.push(head->right);
        }
    }
    return false;
}
void deleteNode(vector<Node*>& add, int v){
    bool flag=false;
    for(int i=0; i<add.size() && !flag ; i++){
        if(add[i]->val == v){
            if(add[i]->left)
                add.push_back(add[i]->left);
            if(add[i]->right)
                add.push_back(add[i]->right);
            add.erase(add.begin()+i);
            break;
        }
        else{
            flag = del(add[i], v,add);
        }
    }
}
void print(vector<Node*> add){    //print tree nodes in level order Traversal
    for(auto root : add){
        cout<<"[ ";
        queue<Node*> q;
        q.push(root);
        while(q.size()){
            int size = q.size();
            while(size--){
                cout<<q.front()->val<<" ";
                if(q.front()->left)
                    q.push(q.front()->left);
                if(q.front()->right)
                    q.push(q.front()->right);
                q.pop();
            }
        } 
        cout<<"]"<<endl;
    }   
}
int main(){
    vector<int> t = {1,2,3,4,5,6,7};
    //int dele[] = {3,5};
    Node* root = constructTree(t);    
    vector<Node*> add;
    add.push_back(root);
    print(add);
    cout<<endl;
    deleteNode(add, 2);
    deleteNode(add, 5);
    print(add);
    cout<<endl;
}