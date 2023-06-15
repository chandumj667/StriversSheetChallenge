/*
    Clone Linked List with Random and Next Pointer
    In this article we will solve the most asked coding interview problem “Clone Linked List”.
    Problem Statement: Given a Linked list that has two pointers in each node and one of which points to the first node and the other points to any random node. Write a program to clone the LinkedList.

    Example 1:
    Input:
        head = [[1,3],[2,0],[3,null],[4,1]]
    Output:
        head = [[1,3],[2,0],[3,null],[4,1]]


    Example 2:
    Input:
        head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
    Output:
        head = [[7,null],[13,0],[11,4],[10,2],[1,0]]



*/




#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node *next;
    Node *random;
    Node(int val){
        data = val;
        next = NULL;
        random = NULL; 
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

/*
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
*/

Node *brute(Node *head){
    unordered_map<Node *, Node *> mpp;
    Node *temp = head;
    while(temp!=NULL){
        Node *n = new Node(temp->data);
        mpp[temp] = n;
        temp = temp->next;
    }
    Node *t = head;

    while(t!= NULL){
        Node *nd = mpp[t];
        nd->next = (t->next != NULL) ? mpp[t->next] : NULL;
        nd->random = (t->random != NULL) ? mpp[t->random] : NULL;
        t = t->next;
    }
    return mpp[head];
}




int main(){
    Node *head = NULL;
    Node *n1 = new Node(1);
    Node *n2 = new Node(2);
    Node *n3 = new Node(3);
    Node *n4 = new Node(4);
    Node *n5 = new Node(5);
    Node *n6 = new Node(6);
    Node *n7 = new Node(7);
    Node *n8 = new Node(8);

    head = n1;
    head->next = n2;
    head->next->next = n3;
    head->next->next->next = n4;
    head->next->next->next->next = n5;
    head->next->next->next->next->next = n6;
    head->next->next->next->next->next->next = n7;
    head->next->next->next->next->next->next->next = n8;

    head->random = n3;
    head->next->random = n6;
    head->next->next->random = n7;
    head->next->next->next->random = NULL;
    head->next->next->next->next->random = n8;
    head->next->next->next->next->next->random = n4;
    head->next->next->next->next->next->next->random =n1;
    head->next->next->next->next->next->next->next->random = n2;
    print(head);
    cout << endl<<"after cloning the original one to cloned one "<<endl;

    Node *brt = brute(head);
    print(brt);
    return 0;
}