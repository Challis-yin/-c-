//linklist.h
//#pragma once
//#ifndef _LINKLIST_H_
//#define _LINKLIST_H_

#include<iostream>

using namespace std;

template<typename T>
struct Node {
    T t;
    struct Node<T>* next;
};

template<typename T>
class linklist {
public:
    linklist();
    ~linklist();
public:
    int clear();
    int getlength();
    int getnode(int pos, T &t);
    int insertnode(int pos, T &t);
    int deletenode(int pos, T &t);
private:
    int m_length;
    Node<T>* m_head;
};

template<typename T>
linklist<T>::linklist() {
    m_head = new Node<T>;
    m_head->next = NULL;
    m_length = 0;
}

template<typename T>
linklist<T>::~linklist() {
    Node<T> *temp = NULL;
    while (m_head) {
        temp = m_head->next;
        delete m_head;
        m_head = temp;
    }
}

template<typename T>
int linklist<T>::clear() {
    Node<T> *temp = NULL;
    while (m_head) {
        temp = m_head->next;
        delete m_head;
        m_head = temp;
    }
    m_head = new Node<T>;
    m_head->next = NULL;
    m_length = 0;
    return 0;
}

template<typename T>
int linklist<T>::getlength() {
    return m_length;
}

template<typename T>
int linklist<T>::getnode(int pos, T &t) {
    int ret = 0;
    if (pos < 0 || pos > m_length) {
        ret = 1;
        cout << "func getnode() pos < 0 || pos > m_length err : " << ret << endl;
        return ret;
    }
    Node<T>* current = m_head;
    int i = 0;
    while (i++ < pos)
        current = current->next;
    t = current->next->t;
    return ret;
}

template<typename T>
int linklist<T>::insertnode(int pos, T &t) {
    int ret = 0;
    if (pos < 0 || pos > m_length) {
        ret = 1;
        cout << "func getnode() pos < 0 || pos > m_length err : " << ret << endl;
        return ret;
    }
    Node<T>* current = m_head;
    int i = 0;
    while (i++ < pos)
        current = current->next;
    Node<T>* newnode = new Node<T>;
    newnode->next = NULL;
    newnode->t = t;
    newnode->next = current->next;
    current->next = newnode;
    m_length++;
    return ret;
}

template<typename T>
int linklist<T>::deletenode(int pos, T &t) {
    int ret = 0;
    if (pos < 0 || pos > m_length) {
        ret = 1;
        cout << "func getnode() pos < 0 || pos > m_length err : " << ret << endl;
        return ret;
    }
    Node<T>* current = m_head;
    int i = 0;
    while (i++ < pos)
        current = current->next;
    Node<T>* delnode = current->next;
    t = delnode->t;
    current->next = delnode->next;
    delete delnode;
    m_length--;
    return ret;
}
