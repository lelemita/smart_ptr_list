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
        public:
            List();
            ~List() = default;
            void addFront(const int &value);
            void addLast(const int &value);
            bool moveNext();
            bool movePrev();
            bool chkEmpty() const { return head == nullptr; }
            int getValue() const { return pCurr->GetData(); }
            void moveFront() { pCurr = head; }
            void moveLast() { pCurr = tail; }
    };
}

#include "List.hpp"
