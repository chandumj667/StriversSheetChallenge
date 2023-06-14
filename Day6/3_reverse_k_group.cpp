/*
    Reverse Linked List in groups of Size K
    In this article, we will solve a very popular question Reverse Linked List in groups of Size K.

    Problem Statement: Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list. k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.
    Note: Also check this article to reverse a linked list


    Example 1:
    Input:
    head = [1,2,3,4,5,6,7,8] k=3
    Output:
    head = [3,2,1,6,5,4,7,8]

    Example 2:
    Input:
    head = [1,2,3,4,5,6,7,8] k=2
    Output:
    head = [2,1,4,3,6,5,8,7]

    approach :
        . get the length of the linked list and check whether its length less than k or not
        . use three pointers as curr, nex, prev assigned to dummy
        . cur = dummy->next;
        . nex = cur->next;
        . using loops for k-1 link changes
        . cur ->next = nex->next;
        . nex->next = prev->next;
        . pre->next = nex;
        . nex = cur->next
        pre = cur;
        count -=k;
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



void print(Node *head){
    Node *temp = head;
    while(temp!=NULL){
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


Node *reverse_list_k(Node *head, int k){
    if(head == NULL ||head->next == NULL || k==1)
        return head;
    Node *d = new Node(0);
    d->next = head;
    Node *cur;
    Node *nxt;
    Node *pre = d;
    Node *temp = head;
    int count = 0;
    while(temp!= NULL){

        temp = temp->next;
        count++;
    }

    while(count >= k){

        cur = pre->next;
        nxt = cur->next;

        for (int i = 1; i < k; i++){

            cur->next = nxt->next;
            nxt->next = pre->next;
            pre->next = nxt;
            nxt = cur->next;
        }
        pre = cur;
        count -= k;
    }
    return d->next;
}

int main(){
    cout << "\nEnter the node value in to the linked-list :-"<<endl;
    Node *head = input();
    print(head);
    int k;
    cout << "\nEnter the group size k : ";
    cin >> k;
    Node *hd = reverse_list_k(head, k);
    print(hd);
    return 0;
}