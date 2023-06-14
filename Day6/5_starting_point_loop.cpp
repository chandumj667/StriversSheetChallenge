/*
    Starting point of loop in a Linked List
    In this article, we will learn how to solve the most asked coding interview question: “Starting point of the loop in a Linked List“

    Problem Statement: Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null.

    There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that the tail’s next pointer is connected to (0-indexed). It is -1 if there is no cycle. Note that pos is not passed as a parameter.

    Do not modify the linked list.


    Example 1:
    Input:
    head = [1,2,3,4,3,6,10]
    Output:
    tail connects to node index 2

    Example 2:
    Input:
    head = [1,2]
    Output:
    no cycle

    Brute force approach:
        Using hash-table
        Traverse the Linked-list and for every node check whether it is present it in the hash-table or not if present it the node which have cycle in the linked-list

        Time complexity : O(N)
        Space complexity: O(N)

    

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

void cle(Node *head, int pos){
    Node *ptr = head;
    Node *tmp = head;
    
    while(tmp->next!=NULL){
        if(pos--){
            ptr = ptr->next;
        }
        tmp = tmp->next;
    }
    tmp->next = ptr;
}


Node *brute(Node *head){
    if(head == NULL || head->next==NULL)
        return head;
    Node *temp = head;
    unordered_set<Node *> st;
    while(temp!=NULL){
        if(st.find(temp)!=st.end())
            return temp;
        st.insert(temp);
        temp = temp->next;
    }
    return NULL;
}


Node *optimal(Node *head){
    Node *slow = head;
    Node *fast = head;
    do{
        slow = slow->next;
        fast = fast->next->next;

    } while (slow != fast);
    slow = head;
    while(slow!=fast){
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}

int main(){
    cout << "\nEnter the nodes in linked-list: " << endl;
    Node *head = input();
    int pos;
    cout << "enter the position: ";
    cin >> pos;
    cle(head, pos);
    print(head);
    Node *brt = brute(head);
    print(brt);
    Node *opt = optimal(head);
    print(opt);
}