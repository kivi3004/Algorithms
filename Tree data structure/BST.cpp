/*IMPLEMENTATION OF BST
   1. INSERTION
   2. DELETION
   3. TRAVERSE
   */

#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int val;
    Node *left;
    Node *right;

    Node(int x)
    {
        val = x;
        left = NULL;
        right = NULL;
    }
};

Node *insertRecursive(Node *head, int data)
{
    if (head == NULL)
        return new Node(data);
    if (head->val > data)
        head->left = insertRecursive(head->left, data);
    else
        head->right = insertRecursive(head->right, data);
    return head;
}

Node *insertIterative(Node *head, int data)
{
    if (head == NULL)
        return new Node(data);
    Node *root = head;
    Node *temp;
    int flag = 0;
    while (root)
    {
        if (root->val > data)
        {
            temp = root;
            root = root->left;
        }
        else
        {
            temp = root;
            root = root->right;
        }
    }
    if (temp->val < data)
    {
        temp->right = new Node(data);
    }
    else
    {
        temp->left = new Node(data);
    }
    return head;
}

int minval(Node* head){
    if(head->left)
        head = head->left;
    return head->val;
}

Node *deleteRecursive(Node *head, int data){
    if(head==NULL)
        return NULL;
    if(head->val > data)
        head->left = deleteRecursive(head->left, data);
    else if(head->val < data)
        head->right = deleteRecursive(head->right, data);
    else{
        if(head->right==NULL)
            return head->left;
        if(head->left == NULL)
            return head->right;
        head->val = minval(head->right);
        head->right = deleteRecursive(head->right, head->val);
    }
    return head;
}

Node *deleteIterative(Node *head, int data){
    if(head==NULL)
        return NULL;
    Node *root = head;
    Node *tp;
    while(root){
        if(root->val == data){
            break;
        }
        else if(root->val > data){
            tp = root;
            root= root->left;
        }
        else{
            tp = root;
            root = root->right;
        }
    }
    if(root==NULL)
        return head;
    if(!root->left && !root->right){
        if(tp->val > data)
            tp->left = NULL;
        else
            tp->right = NULL;
    }
    else if(!root->left){
        if(tp->left == root)
            tp->left = root->right;
        else
            tp->right = root->right;
    }
    else if(!root->right){
        if(tp->left == root)
            tp->left = root->left;
        else
            tp->right = root->left;
    }
    else{
        Node *p = root->right;
        while(p->left)
            p= p->left;

        root->val = p->val;
        deleteIterative(root->right, p->val);
    }
    return head;
}

void traverseIn(Node *head)
{
    stack<Node *> st;
    while(head || !st.empty()){
        while(head){
            st.push(head);
            head = head->left;
        }
        Node* tp = st.top();
        st.pop();

        cout<<tp->val<<" ";
        head = tp->right;
    }
}

void traversepre(Node *head)
{
    stack<Node *> st;
    while(head || !st.empty()){
        while(head){
            cout<<head->val<<" ";
            st.push(head);
            head = head->left;
        }
        Node* tp = st.top();
        st.pop();

        head = tp->right;
    }

}

void traverseLevelByLevel(Node *head)
{
    queue<Node*> q;
    q.push(head);
    while(q.size()){
        Node *tp = q.front();
        q.pop();
        cout<<tp->val<<" ";
        if(tp->left)
            q.push(tp->left);
        if(tp->right)
            q.push(tp->right);
    }
}

void traversepost(Node *head)
{
    stack<Node *> st;
    Node *prev = NULL;
    while(head || !st.empty()){
        while(head){
            st.push(head);
            head = head->left;
        }
        while(head==NULL && !st.empty()){
            head = st.top();
            if(head->right==NULL || head->right == prev){
                cout<<head->val<<" ";
                st.pop();
                prev = head;
                head = NULL;
            }
            else
                head = head->right;
        }
    }
}

int main()
{
    Node *head = NULL;
    int ch;
    while (1)
    {
        //system("cls");
        cout << "Enter your choice\n";
        cout << "1. Insertion through recusion\n";
        cout << "2. Insertion through Iteration\n";
        cout << "3. Deletion through recusion\n";
        cout << "4. Deletion through Iteration\n";
        cout << "5. Traverse\n";
        cout << "6. exit(0)\n";
        cin >> ch;
        int x;
        switch (ch)
        {
        case 1:
            cout << "Enter Node value : ";
            cin >> x;
            head = insertRecursive(head, x);
            break;
        case 2:
            cout << "Enter Node value : ";
            cin >> x;
            head = insertIterative(head, x);
            break;
        case 3:
            cout<<"Enter value : ";
            cin>>x;
            head = deleteRecursive(head, x);
            break;
        case 4:
            cout<<"Enter value : ";
            cin>>x;
            head = deleteIterative(head, x);
            break;
        case 5:
            cout<<"\nInorder : ";
            traverseIn(head);
            cout<<"\nPreorder : ";
            traversepre(head);
            cout<<"\nPostorder : ";
            traversepost(head);
            cout<<"\nLevelByLevel : ";
            traverseLevelByLevel(head);
            cout<<endl;
            break;
        case 6:
            exit(0);
        default:
            cout << "ERROR";
        }
    }
    return 0;
}
