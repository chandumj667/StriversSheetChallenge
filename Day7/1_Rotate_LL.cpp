/*
    Rotate a Linked List
    In this article, we will solve the problem: “Rotate a Linked List”

    Problem Statement: Given the head of a linked list, rotate the list to the right by k places.

    Examples:

    Example 1:
    Input:
        head = [1,2,3,4,5]
        k = 2
    Output:
    head = [4,5,1,2,3]
    We have to rotate the list to the right twice.


    Example 2:
    Input:
        head = [1,2,3]
        k = 4
    Output:
    head = [3,1,2]

    Approach :
        count the length of the linked list with a tail node and at the last node we get the length of the linked list and make the tail->next = head;
        and k = len-k;
        now traverse the head until k == 0 and Node *nex = head->next;
        head->next to null and head = nex;

        Time Complexity: O(n) + O(n-n%k) === O(n)
        Space Complexity : O(1)
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


Node *approach(Node *head, int k){
    if(!head || !head->next || k==0)
        return head;
    
    int len = 1;
    Node *tail = head;
    while(tail->next != NULL){
        len++;
        tail = tail->next;
    }
    tail->next = head;
    k = k % len;
    k = len - k;
    while(k--){
        tail = tail->next;
    }
    head = tail->next;
    tail->next = NULL;
    return head;
}


int main(){
    cout << "\nEnter the nodes in to the linked-list: " << endl;
    Node *head = input();
    cout << "Enter the k length : ";
    int k;
    cin >> k;
    print(head);
    cout << endl;
    Node *app = approach(head, k);
    print(app);
}