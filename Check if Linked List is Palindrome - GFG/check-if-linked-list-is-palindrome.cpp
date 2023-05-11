//{ Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;
/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};




// } Driver Code Ends
/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/
#include <vector>
#include <stack>

class Solution{
  private:
    void reverse(Node* &root){
        Node* curr = root;
        Node* prev = NULL;
        while(curr != NULL){
            Node* forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        root = prev;
    }
  public:
    //Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
        // Approach 1
        // store it in an array
        // vector<int> arr;
        // Node* curr = head;
        // while(curr != NULL){
        //     arr.push_back(curr->data);
        //     curr = curr->next;
        // }
        // int i = 0;
        // int j = arr.size() - 1;
        // while(i < j){
        //     if(arr[i] != arr[j]) return false;
        //     i++;
        //     j--;
        // }
        // return true;
        
        // Approach 2
        // Using Reverse
        if(head == NULL || head->next == NULL) return true;
        Node* slow = head;
        Node* fast = head->next;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        slow = slow->next;
        reverse(slow);
        fast = head;
        while(slow != NULL){
            if(slow->data != fast->data) return false;
            slow = slow->next;
            fast = fast->next;
        }
        reverse(slow);
        return true;
        
        // Approach 3
        // Using Stack
        // if(head == NULL || head->next == NULL) return true;
        // Node* slow = head;
        // Node* fast = head->next;
        // stack<int> stk;
        // while(fast != NULL && fast->next != NULL){
        //     stk.push(slow->data);
        //     slow = slow->next;
        //     fast = fast->next;
        //     if(fast != NULL)
        //         fast = fast->next;
            
        // }
        // if(fast != NULL){
        //     stk.push(slow->data);
        //     slow = slow->next;
        // }
        // else{
        //     slow = slow->next;
        // }
        // while(slow != NULL){
        //     int num = stk.top();
        //     stk.pop();
        //     if(slow->data != num) return false;
        //     slow = slow->next;
        // }
        // return true;
    }
};



//{ Driver Code Starts.
/* Driver program to test above function*/
int main()
{
  int T,i,n,l,firstdata;
    cin>>T;
    while(T--)
    {
        
        struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        // taking first data of LL
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
    Solution obj;
   	cout<<obj.isPalindrome(head)<<endl;
    }
    return 0;
}


// } Driver Code Ends