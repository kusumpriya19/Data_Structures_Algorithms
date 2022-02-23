// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

/* Link list node */
struct Node {
	int data;
	struct Node *next;
	Node(int x) {
		data = x;
		next = NULL;
	}
};

/* Function to print linked list */
void printList(struct Node *head)
{
	struct Node *temp = head;
	while (temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
}




 // } Driver Code Ends
//User function Template for C++

/*Link list node
struct Node {
	int data;
	struct Node *next;
	Node(int x) {
		data = x;
		next = NULL;
	}
};*/

class Solution
{
    public:
    Node* insertionSort(struct Node* head_ref)
    {
       Node* temp=head_ref;
        deque<int> q;
        q.push_back(temp->data);
        temp=temp->next;
        while(temp!=NULL){
            stack<int> s;
            if(q.back()>temp->data){
                while(!q.empty() && q.back()>temp->data){
                    s.push(q.back());
                    q.pop_back();
                }
                q.push_back(temp->data);
                while(!s.empty()){
                    q.push_back(s.top());
                    s.pop();
                }
            }
            else if(q.back()<=temp->data){
                q.push_back(temp->data);
            }
            temp=temp->next;
        }
        Node* dummy=new Node(-1);
        Node* ans=dummy;
        while(!q.empty()){
            ans->next=new Node(q.front());
            ans=ans->next;
            q.pop_front();
        }
        return dummy->next;
    }
    
};

// { Driver Code Starts.
int main()
{
	int T;
	cin >> T;

	while (T--)
	{
		int n;
		cin >> n;

		Node *head = NULL;
		Node *temp = head;

		for (int i = 0; i < n; i++) {
			int data;
			cin >> data;
			if (head == NULL)
				head = temp = new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}

        Solution ob;

		head = ob.insertionSort(head);
		printList(head);

		cout << "\n";



	}
	return 0;
}  // } Driver Code Ends