#pragma once

template <class T>
class deque
{
private:
	int iFront;
	int iBack;
	T data;

public:
	/*************************
	* Default Constructor
	**************************/
	deque()
	{

	}

	/*******************************
	* Non Default Constrctor
	********************************/	  
	deque(int amount)
	{

	}

	/***********************
	* Copy Constructor
	************************/
	deque(const deque rhs&)
	{

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
}

template<class T>
void deque<T>::pushFront(T & item)
{
}

template<class T>
void deque<T>::popBack()
{
}

template<class T>
void deque<T>::popFront()
{
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
	return 0;
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
