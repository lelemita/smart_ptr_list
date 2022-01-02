#pragma once
#include <memory>
#include <iostream>
#include "Node.h"

using namespace std;

namespace homework
{
    template <class T> class List
    {
        private:
            shared_ptr<Node<T>> head;
            shared_ptr<Node<T>> tail;
            shared_ptr<Node<T>> pCurr;
            int mSize;
        public:
            List();
            ~List() = default;
            void addFront(const T &value);
            void addLast(const T &value);
            bool moveNext();
            bool movePrev();
            bool chkEmpty() const { return head == nullptr; }
            T getValue() const { return pCurr->GetData(); }
            void moveFront() { pCurr = head; }
            void moveLast() { pCurr = tail; }
            bool removeFront();
            bool removeLast();
            bool move(const int index);
            void add(const T &value);
            bool remove();
            int size() { return mSize; };
            void printFromFront();
            void printFromLast();
    };
}

#include "List.hpp"
