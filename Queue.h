#pragma once
#include <iostream>

using namespace std;

class NodeQ
{
public:
    int elem[2];
    NodeQ* next;

    NodeQ()
    {
        elem[0] = -1;
        elem[1] = -1;
        //uId = -1;
        next = NULL;
    }

    NodeQ(int val, int id)
    {
        elem[0] = val;
        elem[1] = id;

        next = NULL;
    }
};

class Queue {
private:
    NodeQ* head;
    NodeQ* tail;
    int size;
public:
    Queue()
    {
        size = 0;
        head = NULL;
        tail = NULL;
    }

    void insertFirst(int val, int id) {
        NodeQ* temp = new NodeQ(val, id);
        if (head == NULL) {
            head = temp;
            tail = temp;
        }
        else {
            temp->next = head;
            head = temp;
        }
        size++;
    }

    void insertLast(int val, int id) {
        NodeQ* temp = new NodeQ(val, id);
        if (tail == NULL) {
            head = temp;
            tail = temp;
        }
        else {
            tail->next = temp;
            tail = temp;
        }
        size++;
    }

    void insertAt(int pos, int elem, int id) {
        if (pos < 0 || pos > size) {
            cout << "Invalid Position" << endl;
        }
        else if (pos == 0) {
            insertFirst(elem, id);
        }
        else if (pos == size) {
            insertLast(elem, id);
        }
        else {
            NodeQ* temp = new NodeQ(elem, id);
            NodeQ* current = head;

            for (int i = 0; i < pos - 1; i++) {
                current = current->next;
            }

            temp->next = current->next;
            current->next = temp;
            size++;
        }
    }

    void deleteAt(int pos) {
        if (pos < 0 || pos >= size) {
            cout << "Invalid Position" << endl;
        }
        else if (pos == 0) {
            deleteFirst();
        }
        else if (pos == size - 1) {
            deleteLast();
        }
        else {
            NodeQ* current = head;
            for (int i = 0; i < pos - 1; i++) {
                current = current->next;
            }
            NodeQ* temp = current->next;
            current->next = temp->next;
            delete temp;
            size--;
        }
    }

    void deleteFirst() {
        if (head == NULL) {
            cout << "List is empty" << endl;
        }
        else {
            NodeQ* temp = head;
            if (size == 1) {
                delete temp;
                head = NULL;
                tail = NULL;
                size = 0;
            }
            else {
                head = head->next;
                delete temp;
                size--;
            }
        }
    }

    void deleteLast() {
        if (tail == NULL) {
            cout << "List is empty" << endl;
        }
        else {
            NodeQ* temp = tail;
            if (size == 1) {
                delete temp;
                head = NULL;
                tail = NULL;
                size = 0;
            }
            else {
                NodeQ* current = head;
                for (int i = 0; i < size - 2; i++) {
                    current = current->next;
                }
                tail = current;
                tail->next = NULL;
                delete temp;
                size--;
            }
        }
    }

    void insertVipCustomer(int elem, int id) {
        insertAt(2, elem, id);
    }

    void newOrderPlaced(int val, int id) {
        insertLast(val, id);
    }

    void orderCancelled(int pos) {
        deleteAt(pos - 1);
    }

    void jobDone() {
        cout << head->elem[1] << endl;
        deleteFirst();

    }

    void emergencySituation(int pos) {
        if (pos < 2 || pos >= size) {
            cout << "Invalid Position" << endl;
        }
        else {
            NodeQ* current = head;
            for (int i = 0; i < pos - 1; i++) {
                current = current->next;
            }
            NodeQ* temp = current->next;
            current->next = temp->next;
            insertAt(1, temp->elem[0], temp->elem[1]);
            delete temp;
            size++;
        }
    }

    void search(int id) {
        NodeQ* current = head;
        cout << "Positions of the Nodes with element: ";
        for (int i = 0; i < size; i++) {
            //cout << current->elem[1] << " ";
            if (current->elem[1] == id) {
                cout << i + 1 << " ";
            }
            current = current->next;
        }
        cout << endl;
    }

    void print() {
        NodeQ* current = head;
        cout << "Current Queue: ";
        while (current != NULL) {
            cout << current->elem[1] << " ";
            current = current->next;
        }
        cout << endl;
    }
};