#pragma once
#include <memory>
#include <iostream>
using namespace std;

namespace old
{
    template <class T> struct Node
    {
        T info;
        Node *next;
        Node *prev;
        Node(T val)
            : info(val)
            , next(NULL)
            , prev(NULL)
        {}
    };

    template <class T> class List
    {
        private:
            Node<T> *head;
            Node<T> *tail;
            Node<T> *pCurr;
        public:
            List()
                : head(NULL)
                , tail(NULL)
                , pCurr(NULL)
            {};
            ~List();

            void addFront(const T &value);
            void addLast(const T &value);
            void removeFront();
            void moveFront() { pCurr = head; }
            void moveLast() { pCurr = tail; }
            bool moveNext();
            bool movePrev();
            bool chkEmpty() const { return head == NULL; }
            bool chkIfFront() const { return pCurr == head; }
            bool chkIfLast() const { return pCurr == NULL || pCurr->next == NULL; }
            T getValue() const { return pCurr->info; }
            bool setValue(const T &value);
    };

    template <class T> List<T>::~List()
    {
        Node<T> *temp = head;
        while (temp) {
            head = temp->next;
            delete temp;
            temp = head;
        }
    }

    template <class T> void List<T>::addFront(const T &value)
    {
        Node<T> *temp = new Node<T>(value);
        if (head != NULL) {
            head->prev = temp;
        }
        temp->next = head;
        head = temp;
        if (pCurr == NULL) {
            pCurr = head;
        }
        if (tail == NULL) {
            tail = head;
        }
    }

    template <class T> void List<T>::addLast(const T &value)
    {
        Node<T> *temp = new Node<T>(value);
        if (tail != NULL) {
            tail->next = temp;
        }
        temp->prev = tail;
        tail = temp;
        if (pCurr == NULL) {
            pCurr = tail;
        }
        if (head == NULL) {
            head = tail;
        }
    }

    template<class T> void List<T>::removeFront()
    {
        Node<T> *temp = head;
        if (pCurr == head) {
            pCurr = head->next;
        }
        head = head->next;
        delete temp;
    }

    template<class T> bool List<T>::moveNext()
    {
        if (pCurr != NULL && pCurr->next != NULL) {
            pCurr = pCurr->next;
            return true;
        }
        return false;
    }

   template<class T> bool List<T>::movePrev()
    {
        if (pCurr != NULL && pCurr->prev != NULL) {
            pCurr = pCurr->prev;
            return true;
        }
        return false;
    }

    template<class T> bool List<T>::setValue(const T &value)
    {
        if (pCurr != NULL) {
            pCurr->info = value;
            return true;
        }
        return false;
    }
};
