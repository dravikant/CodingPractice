/*
https://practice.geeksforgeeks.org/problems/reverse-a-linked-list/1?utm_source=geeksforgeeks&utm_medium=article_practice_tab&utm_campaign=article_practice_tab

1. Let's call Curr  the node to reverse.

To reverse Curr, you must set its next pointer to the previous node.

2. So, a Prev pointer is necessary to track the previous node.

But if you make Curr point to the previous node, there is a problem.

You lose the reference to the node after Curr.

3. So, a temporary Next pointer is necessary to keep a reference to the node after Curr.

Once you've done this, you can safely make Curr pointing to Prev.

4. The only remaining thing is then prepare for the next step by:

- updating Prev to Curr
- updating Curr to Next

The time complexity of this solution is O(N) for a list of N nodes.

The space complexity is O(1) since the solution only uses two additional pointers.

why 

 struct Node* reverseList(struct Node *head)
    {
        // code here
        // return head of reversed list
        struct Node *prev = NULL;
        struct Node *cur = head;
        struct Node *next = NULL;
        
        while(cur != NULL){
            
            next = cur->next;
            cur->next = prev;
            
            prev = cur;
            cur=next;
            // next=cur->next;
            
        }
        
        return prev;
    }


    and not this

     struct Node* reverseList(struct Node *head)
    {
        // code here
        // return head of reversed list
        struct Node *prev = NULL;
        struct Node *cur = head;
        struct Node *next = cur->next; --> think of what if cur==NULL
        
        while(cur != NULL){
            
            
            cur->next = prev;
            
            prev = cur;
            cur=next;
            next=cur->next;
            
        }
        
        return prev;
    }
*/


//{ Driver Code Starts
//Initial Template for C++// C program to find n'th Node in linked list
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;

/* Link list Node */
struct Node {
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};



// } Driver Code Ends
/* Linked List Node structure:

struct Node
{
    int data;
    struct Node *next;
}

*/

class Solution
{
    public:
    //Function to reverse a linked list.
    struct Node* reverseList(struct Node *head)
    {
        // code here
        // return head of reversed list
        struct Node *prev = NULL;
        struct Node *cur = head;
        struct Node *next = NULL;
        
        while(cur != NULL){
            
            next = cur->next;
            cur->next = prev;
            
            prev = cur;
            cur=next;
            // next=cur->next;
            
        }
        
        return prev;
    }
    
};
    


//{ Driver Code Starts.

void printList(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
       printf("%d ", temp->data);
       temp  = temp->next;
    }
}

/* Driver program to test above function*/
int main()
{
    int T,n,l,firstdata;
    cin>>T;

    while(T--)
    {
        struct Node *head = NULL,  *tail = NULL;

        cin>>n;
        
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        
        for (int i=1; i<n; i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
        
        Solution ob;
        head = ob. reverseList(head);
        
        printList(head);
        cout << endl;
    }
    return 0;
}


// } Driver Code Ends