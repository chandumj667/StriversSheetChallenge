/*
    Check if given Linked List is Palindrome
    Check if the given Linked List is Palindrome

    Problem Statement: Given the head of a singly linked list, return true if it is a palindrome.


    Example 1:
    Input: head = [1,2,3,3,2,1]
    Output:
    true
    Explanation: If we read elements from left to right, we get [1,2,3,3,2,1]. When we read elements from right to left, we get [1,2,3,3,2,1]. Both ways list remains same and hence, the given linked list is palindrome.

    Example 2:
    Input:
    head = [1,2]
    Output:
    false
    Explanation: When we read elements from left to right, we get [1,2]. Reading from right to left, we get a list as [2,1]. Both are different and hence, the given linked list is not palindrome.

    Brute force approach approach:
        using an extra data structure and check whether it is palindrome or not we are checking the values only not the addresses

        Time complexity : O(n)+O(log n)
        Space complexity :O(n)
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


bool brute(Node *head){
    vector<int> vec;
    Node *temp = head;
    while(temp!=NULL){
        vec.push_back(temp->data);
        temp = temp->next;
    }

    int l = 0;
    int r = vec.size()-1;
    while(l<=r){
        if(vec[l]!=vec[r]){
            return false;
        }
        l++;
        r--;
    }
    return true;
}

Node *rvrs(Node *head){
    Node *prev = NULL;
    Node *nxt = NULL;
    while(head!=NULL){
        nxt = head->next;
        head->next = prev;
        prev = head;
        head = nxt;
    }
    return prev;
}

bool optimal(Node *head){
    if(head == NULL||head->next == NULL)
        return true;
    Node *slow = head;
    Node *fast = head;

    while(fast->next!=NULL && fast->next->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    slow->next = rvrs(slow->next);
    slow = slow->next;
    Node *d = head;
    while(slow!=NULL){
        if(d->data!=slow->data)
            return false;
        d = d->next;
        slow = slow->next;
    }
    return true;
}


int main(){
    Node *head = input();
    print(head);
    if(brute(head)){
        cout << "\nUsing Brute force approach : Given LL is a palindrome "<<endl;
    }
    else{
        cout << "\nUsing Brute force approach : Given LL is NOT a palindrome "<<endl;
    }
    if(optimal(head)){
        cout << "\nUsing Optimal approach : Given LL is a palindrome " << endl;
    }
    else{
        cout << "\nUsing Optimal approach : Given LL is Not a palindrome " << endl;
    }
    return 0;
}