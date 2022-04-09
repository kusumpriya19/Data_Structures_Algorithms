// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data; 
        node = node->next; 
    }  
    cout<<"\n";
} 


 // } Driver Code Ends
//User function template for C++

/* 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    
    Node* reverse(Node *head){
        Node *curr = head, *prev = NULL, *next = NULL;
        while(curr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            
        }
        return prev;
    }
    
    Node* addOne(Node *head) 
    {
        if(head == NULL)
        return NULL;
        
        head = reverse(head);
        Node *curr = head, *next = head->next;
        
        while(curr){
            if(curr->data == 9 && next == NULL){
                Node *node = new Node(1);
                curr->data = 0;
                curr->next = node;
                break;
            }
            else if(curr->data <=8){
                curr->data += 1;
                break;
            }
            else if(curr->data == 9 && next != NULL){
                curr->data = 0;
                curr = curr->next;
                next = next->next;
            }
        }
        
        head = reverse(head);
        return head;
        
    }
};

// { Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 
  // } Driver Code Ends