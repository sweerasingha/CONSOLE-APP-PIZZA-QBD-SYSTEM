#pragma once
#include<iostream>
#include <cstddef>

using namespace std;

class NodeM
{
public:
    int elem;
    //string elem;
    NodeM* next;

    NodeM()
    {
        elem = -1;
        next = NULL;
    }

    NodeM(int val)
    {
        elem = val;
        next = NULL;
    }
};

class Menu {
private:
    NodeM* head;
    NodeM* tail;
    int size;
public:
    Menu()
    {
        size = 0;
        head = NULL;
        tail = NULL;
    }

    void insertFirst(int val) {
        NodeM* temp = new NodeM(val);
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

    void insertLast(int val) {
        NodeM* temp = new NodeM(val);
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

    void insertAt(int pos, int elem) {
        if (pos < 0 || pos > size) {
            cout << "Invalid Position" << endl;
        }
        else if (pos == 0) {
            insertFirst(elem);
        }
        else if (pos == size) {
            insertLast(elem);
        }
        else {
            NodeM* temp = new NodeM(elem);
            NodeM* current = head;

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
            NodeM* current = head;
            for (int i = 0; i < pos - 1; i++) {
                current = current->next;
            }
            NodeM* temp = current->next;
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
            NodeM* temp = head;
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
            NodeM* temp = tail;
            if (size == 1) {
                delete temp;
                head = NULL;
                tail = NULL;
                size = 0;
            }
            else {
                NodeM* current = head;
                while (current->next != tail) {
                    current = current->next;
                }
                tail = current;
                tail->next = NULL;
                delete temp;
                size--;
            }
        }
    }

    void deleteNode(int value) {
        if (head == NULL) {
            cout << "List is empty" << endl;
        }
        NodeM* current = head;
        if (current->elem == value) {
            head = head->next;
            return;
        }
        while (current->next != nullptr && current->next->elem != value) {
            current = current->next;
        }
        if (current->next == nullptr) {
            return;
        }
        NodeM* temp = current->next;
        current->next = current->next->next;
        delete temp;
    }

    void insertNewPizza(int pos, int elem) {
        insertAt(pos, elem);
    }

    void insertNewPizza(int elem) {
        insertLast(elem);
    }

    void removePizzaByPos(int pos) {
        deleteAt(pos);
    }

    void removePizza(int val) {
        deleteNode(val);
    }

    void insertPromo(int pos, int elem, int prepos) {
        deleteAt(prepos);
        insertAt(pos - 1, elem);
    }

    void insertPromo(int elem, int prepos) {
        deleteAt(prepos);
        insertFirst(elem);
    }

    void insertNewPromo(int pos, int elem) {
        insertAt(pos, elem);
    }

    void insertNewPromo(int elem) {
        insertFirst(elem);
    }

    void removePromoPizza() {
        deleteFirst();
    }

    void print() {
        NodeM* current = head;
        while (current != NULL) {
            cout << current->elem << " ";
            current = current->next;
        }
        cout << endl;
    }
};
