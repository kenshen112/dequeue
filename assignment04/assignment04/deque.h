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
	void pushFrot(T& item);
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

	/************************
	* Are we at the front?
	***********************/
	T front();

	/************************
	* Are we at the back?
	************************/
	T back();

	T iFrontNormalized();

	T iBackNormalized();
};

