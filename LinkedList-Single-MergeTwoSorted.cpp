// https://www.hackerrank.com/challenges/merge-two-sorted-linked-lists/problem

#include <bits/stdc++.h>

using namespace std;

class SinglyLinkedListNode {
    public:
        int data;
        SinglyLinkedListNode *next;

        SinglyLinkedListNode(int node_data) {
            this->data = node_data;
            this->next = nullptr;
        }
};

class SinglyLinkedList {
    public:
        SinglyLinkedListNode *head;
        SinglyLinkedListNode *tail;

        SinglyLinkedList() {
            this->head = nullptr;
            this->tail = nullptr;
        }

        void insert_node(int node_data) {
            SinglyLinkedListNode* node = new SinglyLinkedListNode(node_data);

            if (!this->head) {
                this->head = node;
            } else {
                this->tail->next = node;
            }

            this->tail = node;
        }
};

void print_singly_linked_list(SinglyLinkedListNode* node, string sep, ofstream& fout) {
    while (node) {
        fout << node->data;

        node = node->next;

        if (node) {
            fout << sep;
        }
    }
}

void free_singly_linked_list(SinglyLinkedListNode* node) {
    while (node) {
        SinglyLinkedListNode* temp = node;
        node = node->next;

        free(temp);
    }
}

// Complete the mergeLists function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
SinglyLinkedListNode* mergeLists(SinglyLinkedListNode* list1, SinglyLinkedListNode* list2) {
    SinglyLinkedListNode *head, *trav;

    // Check for null
    if (!list1) return list2;
    if (!list2) return list1;

    // Set the head & current
    if (list1->data < list2->data) {
        head = trav = list1;
        list1 = list1->next;
    }
    else {
        head = trav = list2;
        list2 = list2->next;
    }

    // Build the list
    while (list1 && list2) {
        if (list1->data < list2->data) {
            trav->next = list1;
            trav = trav->next;
            list1 = list1->next;
        }
        else {
            trav->next = list2;
            trav = trav->next;
            list2 = list2->next;
        }
    }

    // Attach the rest of the list
    if (!list1) trav->next = list2;
    else        trav->next = list1;

    return head;
}

int main()