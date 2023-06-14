/*
    Flattening a Linked List
    Problem Statement: Given a Linked List of size N, where every node represents a sub-linked-list and contains two pointers:

    (i) a next pointer to the next node,
    (ii) a bottom pointer to a linked list where this node is head.

    Each of the sub-linked-list is in sorted order.
    Flatten the Link List such that all the nodes appear in a single level while maintaining the sorted order.
    Note: The flattened list will be printed using the bottom pointer instead of the next pointer.

    Example 1:
    Input:
    Number of head nodes = 4
    Array holding length of each list with head and bottom = [4,2,3,4]
    Elements of entire linked list = [5,7,8,30,10,20,19,22,50,28,35,40,45]
    Output:
    Flattened list = [5,7,8,10,19,20,22,28,30,35,40,45,50]
    Explanation:
    Flattened list is the linked list consisting entire elements of the given list in sorted order


    Example 2:
    Input:
    Number of head nodes = 4
    Array holding length of each list with head and bottom = [4,1,3,1]
    Elements of entire linked list = [5,7,8,30,10,19,22,50,28]
    Output:
    Flattened list = [5,7,8,10,19,22,28,30,50]
    Explanation:
    Flattened list is the linked list consisting entire elements of the given list in sorted order


    Approach :
        using recursion for getting all the main nodes and merger to merge all the nodes in a sorted order;

        Time complexity: O(n)
        Space complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node *next;
    Node(int val){
        data = val;
        next = NULL;
    }
};

void print(Node *head){
    Node *temp = head;
    while (temp != NULL){
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL";
    cout << endl;
}

Node *input(){
    int data;
    cout << "Enter -1 to exit : ";
    cin >> data;
    Node *head = NULL;
    Node *tail = NULL;
    while (data != -1){
        Node *n = new Node(data);
        if (head == NULL){
            head = n;
            tail = n;
        }
        else{
            tail->next = n;
            tail = tail->next;
        }
        cout << "Enter -1 to exit : ";
        cin >> data;
    }
    return head;
}


Node *merger(Node *a, Node *b){
    Node *temp = new Node(0);
    Node *out = temp;

    while(a!=NULL && b!=NULL){
        if(a->data<b->data){
            temp->next = a;
            temp = temp->next;
            a = a->next;
        }
        else{
            temp->next = b;
            temp = temp->next;
            b = b->next;
        }
    }
    if(a){
        temp->next = a;
    }
    else{
        temp->next = b;
    }
    return out;
}

Node *approach(Node *head){
    if(head == NULL || head->next == NULL)
        return head;
    head->next = approach(head->next);
    head = merger(head, head->next);
    return head;
}

int main(){
    Node *head = input();
    Node *app = approach(head);
}