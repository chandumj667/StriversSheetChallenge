/*
    Find middle element in a Linked List
    Problem Statement: Given the head of a singly linked list, return the middle node of the linked list. If there are two middle nodes, return the second middle node.

    Input:
    head = [1,2,3,4,5]
    Result:
    head = [3,4,5]
    ( As we will return the middle of Linked list the further linked list will be still available )
    Explanation: The middle node of the list is node 3 as in the below image.

    Input: head = [1,2,3,4,5,6]
    Result: [4,5,6]
    Explanation:
    Since the list has two middle nodes with values 3 and 4, we return the second one.


    Brute force approach :
        Traverse the linked list by maintaining the count of the all the nodes and then make the count divided by 2 to get the middle
        then again traverse the linked list upto middle and return it

        Time complexity : O(n^2)
        Space complexity : O(1)

    Optimal approach:
        Fast and slow pointers technique
        We can use this technique to find the duplicate element in an array

        Slow pointer moves one point
        while the fast pointer moves tow pointers

        when the fast reaches to the last node then slow is at the middle of the linked list
        then return slow;

        Time complexity :O(n)
        Space complexity : O(1)


*/

#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node *next;
        Node(int val)
        {
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
}


Node *input(){
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


Node *brute(Node *head){
    int count = 0;
    Node *temp = head;
    while(temp!=NULL){
        temp = temp->next;
        count++;
    }
    // if(count%2 == 0){
    //     count = count/2 + 1;
    // }
    temp = head;
    for (int i = 0; i < count/2; i++){
        temp = temp->next;
    }
    return temp;
}

Node *optimal(Node *head){
    Node *slow = head;
    Node *fast = head;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}


int main()
{
    Node *head = input();
    print(head);
    cout << endl;
    Node *brt = brute(head);
    print(brt);
    cout << endl;
    Node *opt = optimal(head);
    print(opt);
    return 0;
}