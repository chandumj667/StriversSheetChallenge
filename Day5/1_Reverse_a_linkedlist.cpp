/*
    Reverse a Linked List
    Problem Statement: Given the head of a singly linked list, write a program to reverse the linked list, and return the head pointer to the reversed list.


    Input:
    head = [3,6,8,10]
    This means the given linked list is 3->6->8->10 with head pointer at node 3.
    output:
    Output = [10,6,8,3]
    This means, after reversal, the list should be 10->6->8->3 with the head pointer at node 10.


    brute force approach :

*/


#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node *next;
        Node (int val){
            data = val;
            next = NULL;
        }
};


/*
void insertatlast(Node* &head, int val){
    Node *n = new Node(val);
    if(head == NULL){
        head = n;
    }
    Node *temp = head;
    while(temp->next!= NULL){
        temp = temp->next;
    }
    temp->next = n;
}
*/

void print(Node *head){
    Node *temp = head;
    while(temp!=NULL){
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
    while(data!=-1){
        Node *n = new Node(data);
        if(head == NULL){
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

Node *reverse_list(Node *head){
    Node *hd = NULL;
    if(head == NULL || head->next == NULL)
        return head;
    while(head!=NULL){
        Node *next = head->next;
        head->next = hd;
        hd = head;
        head = next;
    }
    return hd;
}

int main(){
    Node *head = input();
    print(head);
    cout <<endl;
    Node *hd = reverse_list(head);
    print(hd);
    return 0;
}