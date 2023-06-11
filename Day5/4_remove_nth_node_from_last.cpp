/*
    Remove N-th node from the end of a Linked List
    Problem Statement: Given a linked list, and a number N. Find the Nth node from the end of this linked list and delete it. Return the head of the new modified linked list.

    Example 1 :
    Input: head = [1,2,3,4,5], n = 2
    Output: [1,2,3,5]
    Explanation: Refer Below Image

    Example 2:
    Input: head = [7,6,9,4,13,2,8], n = 6
    Output: [7,9,4,13,2,8]
    Explanation: Refer Below Image

    Example 3:
    Input: head = [1,2,3], n = 3
    Output: [2,3]

    Brute force :
        traverse the list and count the number of nodes present in the list
        and again traverse the list upto (count-k) maintaining curr, prev and nxt pointers
        when the loop reaches count - k then prev->next = curr->next; delete(curr)

        Time complexity : O(n)+O(n-k) = O(2n)
        Space complexity : O(1)

    Optimal approach:
        Using two pointer technique
        x+n = total
        total - n = x
        so then fast pointer traverse till x and then slow and fast pointers traverse simultaneously at one step forward
        if the fast->next == NULL then we reach the position
        slow->next = slow->next->next;

        Time complexity : O(n)
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
    cout << endl;
}

Node *input()
{
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

Node *brute(Node *head, int k){
    int count = 0;
    Node *temp = head;

    if(head == NULL || head->next == NULL)
        return head;
    while(temp!=NULL){
        count++;
        temp = temp->next;
    }

    if(count<k)
        return head;
    int lp = count -k-1;
    temp = head;
    while(lp--){
        temp = temp->next;
    }
    Node *curr = temp->next;
    temp->next = temp->next->next;
    free(curr);
    return head;
}


Node *optimal(Node *head, int k){
    Node *st = new Node();
    Node *fast = st;
    Node *slow = st;
    st->next = head;
    for (int i = 1; i<=k; i++){
        fast = fast->next;
    }
    while(fast->next != NULL){
        fast = fast->next;
        slow = slow->next;
    }
    Node *curr = slow->next;
    slow->next = slow->next->next;
    free(curr);
    return st->next;
}

int main(){
    Node *head = input();
    int k;
    cout << "Enter the k : ";
    cin >> k;
    // Node *btr = brute(head, k);
    // print(btr);
    Node *opt = optimal(head, k);
    print(opt);
}