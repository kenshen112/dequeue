#pragma once

template <class T>
class deque
{
private:
	int iFront;
	int iBack;
	int numCapacity;
	bool isEmpty;
	T data;

public:
	/*************************
	* Default Constructor
	**************************/
	deque()
	{
		iFront = 0;
		iBack = 0;
		numCapacity = 0;
		isEmpty = true;
		data = new T[numCapacity];
	}

	/*******************************
	* Non Default Constrctor
	********************************/	  
	deque(int amount)
	{
		iFront = 0;
		iBack = 0;
		numCapacity = amount;
		data = new T[numCapacity];
		isEmpty = true;

	}

	/***********************
	* Copy Constructor
	************************/
	deque(const deque<T> &rhs)
	{
		assert(rhs.numCapacity >= 0);

		numPush = 0;
		numPop = 0;

		if (numCapacity < rhs.size())
		{
			resize(rhs.size());
		}

		try
		{
			data = new T[rhs.numCapacity];
		}
		catch (std::bad_alloc) {
			throw "ERROR: Unable to allocate buffer";
		}
		numCapacity = rhs.numCapacity;
		int tempPop = rhs.numPop;

		for (int i = rhs.numPop; i < rhs.numPush; i++)
		{
			push(rhs.data[i % rhs.numCapacity]);
		}
	}

	deque operator=(deque rhs);



	/************************************************
	* The Below functions do the same thing from 
	*different ends of the deque
	************************************************/
	void pushBack(T& item);
	void pushFront(T& item);
	void popBack();
	void popFront();

	/**************************
	* resizes the deque
	*************************/
	void resize(int numCapacity);

	/********************
	* Returns Size
	********************/
	int size();
	int capacity();

    /*****************
	Is it empty?
	****************/
	bool empty();

	void clear();


	/************************
	* Are we at the front?
	***********************/
	T front();

	/************************
	* Are we at the back?
	************************/
	T back();

	int iFrontNormalized();

	int iBackNormalized();
};

template<class T>
inline deque deque<T>::operator=(deque rhs)
{
	return deque();
}

template<class T>
void deque<T>::pushBack(T & item)
{
	if (numCapacity == 0)
	{
		resize(1);
	}
	else if (numPush == numCapacity)
	{

		resize(numCapacity *= 2);
	}
	numPush++;
	data[iBack] = element;

}

template<class T>
void deque<T>::pushFront(T & item)
{
	if (numCapacity == 0)
	{
		resize(1);
	}
	else if (numPush == numCapacity)
	{

		resize(numCapacity *= 2);
	}
	numPush++;
	data[iFront] = element;


}

template<class T>
void deque<T>::popBack()
{
	if (numCapacity == 0)
	{
		throw "ERROR: unable to pop from the back of empty deque";
	}

	iBack--;

	if (iBack < 0)
	{
		iBack = numCapacity - 1;
	}
}

template<class T>
void deque<T>::popFront()
{
	if (numCapacity == 0)
	{
		throw "ERROR: unable to pop from the front of empty deque";
	}

	iFront--;
	iFront = (iFront + 1) % numCapacity;
}

template<class T>
void deque<T>::resize(int numCapacity)
{
}

/********************
* Returns Size
********************/
template<class T>
int deque<T>::size()
{
	return 0;
}

/********************
* Returns Size
********************/
template<class T>
int deque<T>::capacity()
{
	return numCapacity;
}

/*****************
Is it empty?
****************/
template<class T>
bool deque<T>::empty()
{
	return false;
}

/**************************
* Clears the entire deque
**************************/
template<class T>
void deque<T>::clear()
{
}

/************************
* Are we at the front?
***********************/
template<class T>
T deque<T>::front()
{
	
}

/************************
* Are we at the back?
***********************/
template<class T>
T deque<T>::back()
{
	
}

/*************************
* Returns index Front
*************************/
template<class T>
int deque<T>::iFrontNormalized()
{
	return 0;
}

/**********************
* Returns index Back
**********************/

template<class T>
int deque<T>::iBackNormalized()
{
	return 0;
}
