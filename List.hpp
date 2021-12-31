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
    {}

    template <class T> void List<T>::addFront(const int &value)
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
    }

    template <class T> void List<T>::addLast(const int &value)
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
    }

    template <class T> bool List<T>:: moveNext()
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
}