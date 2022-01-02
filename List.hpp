#pragma once
#include <memory>
#include <iostream>
#include "Node.h"
#include "List.h"

using namespace std;

namespace homework
{
    template <class T> List<T>::List()
        : head(nullptr)
        , tail(nullptr)
        , pCurr(nullptr)
        , mSize(0)
    {}

    template <class T> void List<T>::addFront(const T &value)
    {
        shared_ptr<Node<T>> temp = make_shared<Node<T>>(value);
        if (head != nullptr) {
            head->SetPrev(temp);
        }
        temp->SetNext(head);
        head = temp;
        if (pCurr == nullptr) {
            pCurr = head;
        }
        if (tail == nullptr) {
            tail = head;
        }
        mSize += 1;
    }

    template <class T> void List<T>::addLast(const T &value)
    {
        shared_ptr<Node<T>> temp = make_shared<Node<T>>(value);
        if (tail != nullptr) {
            tail->SetNext(temp);
        }
        temp->SetPrev(tail);
        tail = temp;
        if (pCurr == nullptr) {
            pCurr = tail;
        }
        if (head == nullptr) {
            head = tail;
        }
        mSize += 1;
    }

    template <class T> bool List<T>::moveNext()
    {
        if (pCurr == nullptr) {
            return false;
        }
        shared_ptr<Node<T>> after = pCurr->GetNext();
        if (after == nullptr) {
            return false;
        }
        pCurr = after;
        return true;
    }

    template <class T> bool List<T>:: movePrev()
    {
        if (pCurr == nullptr) {
            return false;
        }
        shared_ptr<Node<T>> before = pCurr->GetPrev();
        if (before == nullptr) {
            return false;
        }
        pCurr = before;
        return true;
    }
    
    template <class T> bool List<T>::removeFront()
    {
        if(head == nullptr) {
            return false;
        }
        if(head == tail) {
            head = nullptr;
            tail = nullptr;
        } else {
            head = head->GetNext();
            head->SetPrev(nullptr);
        }
        mSize -= 1;
        return true;
    }

    template <class T> bool List<T>::removeLast()
    {
        if(tail == nullptr) {
            return false;
        }
        if(head == tail) {
            head == nullptr;
            tail == nullptr;
        } else {
            tail = tail->GetPrev();
            tail->SetNext(nullptr);
        }
        mSize -= 1;
        return true;
    }

    template <class T> bool List<T>::move(const int index)
    {
        if( index < 0 || index >= mSize ) {
            return false;
        }
        shared_ptr<Node<T>> temp = head;
        for (int i = 0; i < index; i++)
        {
            temp = temp->GetNext();
        }
        pCurr = temp;
        return true; 
    }

    template <class T> void List<T>::add(const T &value)
    {
        if (pCurr == head) {
            addFront(value);
            return;
        } else if (pCurr == tail) {
            addLast(value);
            return;
        }
        shared_ptr<Node<T>> temp = make_shared<Node<T>>(value);
        temp->SetPrev(pCurr->GetPrev());
        temp->SetNext(pCurr);
        pCurr->GetPrev()->SetNext(temp);
        pCurr->SetPrev(temp);
        pCurr = temp;
        return;
    }

    template <class T> bool List<T>::remove()
    {
        if (pCurr == nullptr) {
            return false;
        }
        if (head == tail) {
            head = nullptr;
            tail = nullptr;
            pCurr = nullptr;
        } else {
            pCurr->GetPrev()->SetNext(pCurr->GetNext());
            pCurr->GetNext()->SetPrev(pCurr->GetPrev());
            pCurr = pCurr->GetNext();
        }
        return true;
    }

    template <class T> void List<T>::printFromFront()
    {
        moveFront();
        do {
            cout << getValue() << " ";
        } while (moveNext());
        cout << endl;
    }

    template <class T> void List<T>::printFromLast()
    {
        moveLast();
        do {
            cout << getValue() << " ";
        } while (movePrev());
        cout << endl;
    }
}
