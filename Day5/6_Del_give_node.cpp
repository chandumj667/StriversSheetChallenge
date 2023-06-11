/*
    Delete given node in a Linked List : O(1) approach
    Problem Statement: Write a function to delete a node in a singly-linked list. You will not be given access to the head of the list instead, you will be given access to the node to be deleted directly. It is guaranteed that the node to be deleted is not a tail node in the list.

    Example 1:
    Input:
    Linked list: [1,4,2,3]
        Node = 2
    Output:
    Linked list: [1,4,3]
    Explanation: Access is given to node 2. After deleting nodes, the linked list will be modified to [1,4,3].

    Example 2:
    Input:
    Linked list: [1,2,3,4]
        Node = 1
    Output: Linked list: [2,3,4]
    Explanation:
    Access is given to node 1. After deleting nodes, the linked list will be modified to [2,3,4].

    Optimal approach:
        we have the pointer of the node to be deleted 
        we have access to its right elements then change the values to its right
        and last one to be deleted change it to the null

        Time complexity : O(n)
        Space complexity :O(1)

*/

#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node *next;
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};


void print(Node *head){
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL";
}

Node *input(){
    int data;
    cout << "Enter -1 to exit : ";
    cin >> data;
    Node *head = NULL;
    Node *tail = NULL;
    while (data != -1)
    {
        Node *n = new Node(data);
        if (head == NULL)
        {
            head = n;
            tail = n;
        }
        else
        {
            tail->next = n;
            tail = tail->next;
        }
        cout << "Enter -1 to exit : ";
        cin >> data;
    }
    return head;
}

Node *solve(Node *head, int n){
    while(head->data!=n)
        head = head->next;
    return head;
}

void dlt(Node *n){
    n->data = n->next->data;
    n->next = n->next->next;
    return;
}
int main(){
    Node *head = input();
    int n;
    cout << "Enter the value to be delete : ";
    cin >> n;
    Node *hd = solve(head, n);
    dlt(hd);
    print(head);
    return 0;
}
