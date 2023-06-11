/*
    Merge two sorted Linked Lists
    In this article, we will solve the most asked coding interview question: ” Merge two sorted Linked Lists “
    Problem Statement: Given two singly linked lists that are sorted in increasing order of node values, merge two sorted linked lists and return them as a sorted list. The list should be made by splicing together the nodes of the first two lists.

    Example 1:
    Input Format :
    l1 = {3,7,10}, l2 = {1,2,5,8,10}
    Output :
    {1,2,3,5,7,8,10,10}
    Explanation :
    merge two sorted linked list example 1
    Merge two sorted linked lists example
    These are the two lists given. Both lists are sorted. We have to merge both lists and create a list that contains all nodes from the above nodes and it should be sorted.


    Example 2:
    Input Format :
    l1 = {}, l2 = {3,6}
    Output :
    {3,6}
    Explanation :
    l1 is an empty list. l2 has two nodes. So, when we merge them, we will have the same list as l2.
    Disclaimer: Don’t jump directly to the solution, try it out yourself first.
    Solution 1: Using an externally linked list to store answers.


*/


#include<bits/stdc++.h>
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
    while (temp != NULL)
    {
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

void insert(Node *tail, int val){
    Node *node = new Node(val);
    if(tail == NULL){
        tail = node;
    }
    else{
        tail->next = node;
    }
}


Node *brute(Node *l1, Node *l2){
    Node *head = NULL;
    Node *tail = NULL;
    if(l1->data <= l2->data){
        head = l1;
        l1 = l1->next;
    }
    else{
        head = l2;
        l2 = l2->next;
    }
    tail = head;
    while (l1!= NULL && l2!= NULL){
        if (l1->data <= l2->data){
            insert(tail, l1->data);
            tail = tail->next;
            l1 = l1->next;
        }
        else{
            insert( tail, l2->data);
            tail = tail->next;
            l2 = l2->next;
        }
    }
    while (l1!= NULL){
        insert( tail, l1->data);
        tail = tail->next;

        l1 = l1->next;
    }
    while(l2!= NULL){
        insert( tail, l2->data);
        tail = tail->next;

        l2 = l2->next;
    }
    return head;
}

Node *optimal(Node *l1, Node *l2){
    if(l1 == NULL)
        return l2;
    if(l2 == NULL)
        return l1;

    if(l1->data > l2->data){
        swap(l1, l2);
    }
    Node *out = l1;
    while(l1!= NULL && l2!=NULL){
        Node *tmp = NULL;
        while(l1 != NULL && l1->data <= l2->data){
            tmp = l1;
            l1 = l1->next;
        }

        tmp->next = l2;
        swap(l1, l2);
    }
    return out;
}


int main(){
    cout << "\nEnter the nodes in to the First linked list " << endl;
    Node *l1 = input();
    cout << "\nEnter the nodes in to the Second linked list " << endl;
    Node *l2 = input();
    print(l1);
    print(l2);
    cout << "Brute force approach :" << endl;
    // Node *brt = brute(l1, l2);
    // print(brt);
    cout << "Optimal approach :" << endl;
    Node *opt = optimal(l1, l2);
    print(opt);
}

