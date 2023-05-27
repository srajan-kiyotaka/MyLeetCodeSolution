//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
struct Node* modifyTheList(struct Node *head);
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

void print(Node *head)
{
    Node *temp=head;
	while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout<<endl;
}


// } Driver Code Ends
/*Complete the function below
Node is as follows:
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
class Solution{
    public:
    struct Node*getmid(struct Node* head){


        struct Node*fast=head;
        struct Node*slow=head;


        while(fast && fast->next){
            fast=fast->next->next;
            slow=slow->next;
        }


        return slow;
    }

struct Node* modifyTheList(struct Node *head)
    {
     
        struct Node*mid=getmid(head);

        stack<struct Node*>s;


        while(mid){
            s.push(mid);
            mid=mid->next;
        }


        struct Node*temp=head;


        while(!s.empty()){
            int data=temp->data;
            temp->data=s.top()->data-temp->data;
            s.top()->data=data;
            s.pop();temp=temp->next;
        }


        return head;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		struct Node *head = NULL,*temp=NULL;
		while(n--){
		    int a;
            cin>>a;
			Node *newNode = new Node(a);
			if(head==NULL)
                head=newNode;
            else
                temp->next=newNode;
            temp=newNode;
		}
		Solution obj;
		head = obj.modifyTheList(head);
		print(head);
		
	}
    return 0;
}
// } Driver Code Ends