#pragma once
#include <memory>

using namespace std;

namespace homework
{
	template<class T> class Node
	{
	public:
		Node() = delete;
		Node(T data);
		~Node() = default;

		void SetNext(const shared_ptr<Node<T>> next);
		void SetPrev(const shared_ptr<Node<T>> prev);
		shared_ptr<Node<T>> GetNext() const;
		shared_ptr<Node<T>> GetPrev() const;
		T GetData() const;

	private:
		T mData;
		shared_ptr<Node<T>> mNext;
        weak_ptr<Node<T>> mPrev;
	};
}

#include "Node.hpp"