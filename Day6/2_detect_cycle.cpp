/*
    Detect a Cycle in a Linked List
    In this article, we will solve the most asked interview question: Detect a Cycle in a Linked List

    Problem Statement: Given head, the head of a linked list, determine if the linked list has a cycle in it. There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer.

    Return true if there is a cycle in the linked list. Otherwise, return false.

    Examples:

    Example 1:
    Input:
    Head = [1,2,3,4]
    Output:
    true
    Explanation: Here, we can see that we can reach node at position 1 again by following the next pointer. Thus, we return true for this case.

    Example 2:
    Input:
    Head = [1,2,3,4]
    Output:
    false
    Explanation: Neither of the nodes present in the given list can be visited again by following the next pointer. Hence, no loop exists. Thus, we return false.

    Brute force approach :
        Using hash-table and check each curr node whether it present in the hashtable or not if present then return it as cycle

        Time complexity : O(N)
        Space complexity : O(N)

    Optimal approach :
        using slow and fast pointers slow move one step where fast  move two steps until they collide
        if they collide them assign slow to the head and make a move simultaneously both slow and fast to move one step and again they collide that's where the cycle 

        Time complexity: O(N)
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
    Node(){}
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


Node *brute(Node *head){
    set<Node *> st;
    Node *temp = head;
    while(temp!=NULL){
        if(st.count(temp)>0){
            return temp;
        }
        else{
            st.insert(temp);
        }
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
    while(slow == fast){
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}

int main(){
    Node *head = input();
    // Node *btr = brute(head);
    // print(btr);
    Node *opt = optimal(head);
    print(opt);
    return 0;
}