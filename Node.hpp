

namespace homework
{
	template <class T> Node<T>::Node(T data)
		: mData(data)
	{
	}

	template <class T> void Node<T>::SetNext(const shared_ptr<Node<T>> next)
	{
		mNext = next;
	}
	template <class T> void Node<T>::SetPrev(const shared_ptr<Node<T>> prev)
	{
		mPrev = prev;
	}

	template <class T> shared_ptr<Node<T>> Node<T>::GetNext() const
	{
		return mNext;
	}
	template <class T> shared_ptr<Node<T>> Node<T>::GetPrev() const
	{
		return mPrev.lock();
	}

	template <class T> T Node<T>::GetData() const
	{
		return mData;
	}
}