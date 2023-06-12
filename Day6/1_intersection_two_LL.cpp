/*
    Find intersection of Two Linked Lists
    Problem Statement: Given the heads of two singly linked-lists headA and headB, return the node at which the two lists intersect. If the two linked lists have no intersection at all, return null.


    Example 1:
    Input:
    List 1 = [1,3,1,2,4], List 2 = [3,2,4]
    Output:
    2
    Explanation: Here, both lists intersecting nodes start from node 2.

    Example 2:
    Input:
    List1 = [1,2,7], List 2 = [2,8,1]
    Output:
    Null
    Explanation: Here, both lists do not intersect and thus no intersection node is present.


    Brute force approach :
        Traverse the entire L1 for each node in L2 to check the condition a == b

        Time complexity : O(n*m);
        Space complexity : O(1)

    Better approach:
        using hash-map pr hash-set
        traverse the lq and hash all the node address
        and again traverse l2 and check whether it present it or not

        Time complexity : O(n+m)
        Space complexity : O(n)

    Optimal 1 approach:
        using two nodes as dummy1 and dummy2
        and traverse both nodes respectively and get the length of each ll
        find the difference of those lengths and
        traverse the dummy 2 of l2 from its head until the diff
        then again traverse the both the dummy points simultaneously for both ll and when they collide return that node;

        Time complexity : O(2m)
        Space complexity : O(1)

    Optimal 2 approach : 
        traverse both dummy nodes simultaneously if any dummy reaches end then assign it to the next ll and traverse and vice versa for the both dummy nodes return their collision

        Time complexity : O(2m)
        Space complexity : O(1)

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

Node *brute(Node *l1, Node *l2){
    Node *a = l1;
    Node *b = l2;
    while(b!=NULL){
        while(a!= NULL){
            if(a == b){
                return a;
                break;
            }
            else{
                a = a->next;
            }
        }
        b = b->next;
    }
    return NULL;
}


Node *optimal(Node *l1, Node *l2){
    Node *d1 = l1;
    Node *d2 = l2;
    if(l1 == NULL || l2 == NULL )
        return NULL;
    Node *a = l1;
    Node *b = l2;
    while(a!=b){
        a = a == NULL ? l2 : a->next;
        b = b == NULL ? l1 : b->next;
    }
    return a;
}
int main(){
    cout << "\nEnter the nodes in to the First linked list " << endl;
    Node *l1 = input();
    cout << "\nEnter the nodes in to the Second linked list " << endl;
    Node *l2 = input();
    // we have to take a common reference pointer to give the intersection that is possible if wee get the tail pf l1 and tail of l2 then we insert extra nodes with intersection node 

    Node *btr = brute(l1, l2);
    Node *opt = optimal(l1, l2);
    
    print(btr);
}