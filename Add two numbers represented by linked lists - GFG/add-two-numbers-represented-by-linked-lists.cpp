// { Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


 // } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    //Function to add two numbers represented by linked list.
    
    struct Node* reverse(struct Node* head){
        if(head == NULL || head->next == NULL)
        return head;
        
        Node* curr = head, *prev = NULL , *next = NULL;
        
        while(curr != NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    
    
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        
        Node* p1 = reverse(first);
        Node* p2 = reverse(second);
        Node* temp = new Node(0);
        
        Node* t = temp;
        int carry = 0;
        
        while(p1 && p2){
            carry += p1->data;
            carry += p2->data;
            Node* var = new Node(carry%10);
            t->next = var;
            t = t->next;
            carry = carry/10;
            p1 = p1->next;
            p2 = p2->next;
        }
        
        while(p1){
            carry += p1->data;
            Node* var = new Node(carry%10);
            t->next = var;
            t = t->next;
            carry = carry/10;
            p1 = p1->next;
        }
        
        while(p2){
            carry += p2->data;
            Node* var = new Node(carry%10);
            t->next = var;
            t = t->next;
            carry = carry/10;
            p2 = p2->next;
        }
        
        if(carry>0){
            Node* var = new Node(carry%10);
            t->next = var;
            t = t->next;
        }
        return reverse(temp->next);
        
        
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}
  // } Driver Code Ends