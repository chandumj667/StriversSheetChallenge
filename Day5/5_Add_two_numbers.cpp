/*
    Add two numbers represented as Linked Lists
    Problem Statement: Given the heads of two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.


    Input Format:
    (Pointer/Access to the head of the two linked lists)
    num1  = 243, 
    num2 = 564

    l1 = [2,4,3]
    l2 = [5,6,4]
    Result: sum = 807; L = [7,0,8]
    Explanation: Since the digits are stored in reverse order, reverse the numbers first to get the or                                                original number and then add them as → 342 + 465 = 807. Refer to the image below.

    Input Format:
    (Pointer/Access to the head of the two linked lists)
    l1 = [9,9,9,9,9,9,9], 
    l2 = [9,9,9,9]

    Result: [8,9,9,9,0,0,0,1]
    Explanation: Since the digits are stored in reverse order, reverse the numbers first to get the     original number and then add them as → 9999999 + 9999 = 8999001. Refer to the image below.
    
    Brute force approach :


*/

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(){}
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL";
    cout << endl;
}

Node *input()
{
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

Node *addTwo(Node *l1, Node *l2){
    Node *d = new Node();
    Node *t = d;
    int c = 1;
    while(l1!= NULL || l2!=NULL || c){
        int s= 0;
        if(l1!=NULL){
            s += l1->data;
            l1 = l1->next;
        }
        if(l2!=NULL){
            s += l2->data;
            l2 = l2->next;
        }
        s+=c;
        c = s / 10;
        Node *node = new Node(s % 10);
        t->next = node;
        t = t->next;
    }
    return d->next;
}

int main(){
    cout << "\nEnter the nodes in to the First linked list " << endl;
    Node *l1 = input();
    cout << "\nEnter the nodes in to the Second linked list " << endl;
    Node *l2 = input();
    Node *head = addTwo(l1, l2);
    print(head);
    return 0;
}