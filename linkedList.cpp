#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <string>
using namespace std;

struct PersonNode;

struct SpouseNode {
    string name;
    SpouseNode* next;
};

struct ChildNode {
    PersonNode* person;
    ChildNode* next;
};

SpouseNode* createSpouse(string name) {
    SpouseNode* p = new SpouseNode;
    p->name = name;
    p->next = NULL;
    return p;
}

void addSpouse(SpouseNode*& head, string name) {
    SpouseNode* p = createSpouse(name);
    if (head == NULL) {
        head = p;
        return;
    }
    SpouseNode* cur = head;
    while (cur->next != NULL)
        cur = cur->next;
    cur->next = p;
}

SpouseNode* findSpouse(SpouseNode* head, string name) {
    SpouseNode* cur = head;
    while (cur != NULL) {
        if (cur->name == name)
            return cur;
        cur = cur->next;
    }
    return NULL;
}

bool removeSpouse(SpouseNode*& head, string name) {
    SpouseNode* prev = NULL;
    SpouseNode* cur = head;
    while (cur != NULL && cur->name != name) {
        prev = cur;
        cur = cur->next;
    }
    if (cur == NULL)
        return false;
    if (prev == NULL)
        head = cur->next;
    else
        prev->next = cur->next;
    delete cur;
    return true;
}

bool renameSpouse(SpouseNode* head, string oldName, string newName) {
    SpouseNode* p = findSpouse(head, oldName);
    if (p == NULL)
        return false;
    p->name = newName;
    return true;
}

void printSpouses(SpouseNode* head) {
    if (head == NULL) {
        cout << "Khong co";
        return;
    }
    SpouseNode* cur = head;
    while (cur != NULL) {
        cout << cur->name;
        if (cur->next != NULL)
            cout << ", ";
        cur = cur->next;
    }
}

void clearSpouses(SpouseNode*& head) {
    while (head != NULL) {
        SpouseNode* tmp = head;
        head = head->next;
        delete tmp;
    }
}

ChildNode* createChild(PersonNode* person) {
    ChildNode* p = new ChildNode;
    p->person = person;
    p->next = NULL;
    return p;
}

void addChild(ChildNode*& head, PersonNode* person) {
    ChildNode* p = createChild(person);
    if (head == NULL) {
        head = p;
        return;
    }
    ChildNode* cur = head;
    while (cur->next != NULL)
        cur = cur->next;
    cur->next = p;
}

ChildNode* findChild(ChildNode* head, PersonNode* person) {
    ChildNode* cur = head;
    while (cur != NULL) {
        if (cur->person == person)
            return cur;
        cur = cur->next;
    }
    return NULL;
}

bool removeChild(ChildNode*& head, PersonNode* person) {
    ChildNode* prev = NULL;
    ChildNode* cur = head;
    while (cur != NULL && cur->person != person) {
        prev = cur;
        cur = cur->next;
    }
    if (cur == NULL)
        return false;
    if (prev == NULL)
        head = cur->next;
    else
        prev->next = cur->next;
    delete cur;
    return true;
}

void traverseChildren(ChildNode* head, void (*visit)(PersonNode*)) {
    ChildNode* cur = head;
    while (cur != NULL) {
        visit(cur->person);
        cur = cur->next;
    }
}

int countChildren(ChildNode* head) {
    int count = 0;
    ChildNode* cur = head;
    while (cur != NULL) {
        count++;
        cur = cur->next;
    }
    return count;
}

void clearChildren(ChildNode*& head) {
    while (head != NULL) {
        ChildNode* tmp = head;
        head = head->next;
        delete tmp;
    }
}

#endif
