/***********************************************************************
* Header:
*    DEQUE
* Summary:
*    A custom DEQUE class
* Author
*    Kenyon Bunker and Tim O'Barr
************************************************************************/
#ifndef DEQUE_H
#define DEQUE_H
#include <iostream>
#include <assert.h>

namespace custom {
template <class T>
class deque {
private:
	int iFront;
	int iBack;
	int numCapacity;
	bool isEmpty;
	T *data;

public:
	
   deque();
   deque(int amount);
   deque(deque<T> & rhs);
   ~deque() { clear(); }

   /********************************************
   * ASSIGNMENT OPERATOR
   *******************************************/
   deque<T> & operator=(deque<T> & rhs)
   {
      //clear();
      iBack = -1;
      iFront = 0;

      if (capacity() < rhs.size())
      {
         resize(rhs.size());
      }
      try
      {
         data = new T[rhs.numCapacity];
      }
      catch (std::bad_alloc)
      {
         throw "ERROR: Unable to allocate buffer";
      }
      numCapacity = rhs.numCapacity;
      int tempiFront = rhs.iFront;
      for (int i = rhs.iFront; i < rhs.iBack + 1; i++)
      {
         push_back(rhs.data[rhs.iNormalize(i)]); //What on earth is iNormalize?
      }
      return *this;
   }

   /************************************************
   * The Below functions do the same thing from
   *different ends of the deque
   ************************************************/
   void push_back(const T & item);
   void push_front(const T & item);
   void pop_back();
   void pop_front();

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

   /************************
   * Circular deque
   ************************/
   int iFrontNormalized();
   int iBackNormalized();
   int iNormalize(int i);
};

/*************************
* Default Constructor
**************************/
template<class T>
deque<T>::deque()
{
   iFront = 0;
   iBack = -1;
   numCapacity = 0;
   isEmpty = true;
   data = new T[numCapacity];
}

/*******************************
* Non Default Constrctor
********************************/
template<class T>
deque<T>::deque(int amount)
{
   iFront = 0;
   iBack = -1;
   numCapacity = amount;
   data = new T[numCapacity];
   isEmpty = true;
}

/***********************
* Copy Constructor
************************/
template<class T>
deque<T>::deque(deque<T>& rhs)
{
   assert(rhs.numCapacity >= 0);
   iBack = -1;
   iFront = 0;

   if (capacity() == rhs.size())
   {
      resize(rhs.size());
   }

   try
   {
      data = new T[rhs.numCapacity];
   }
   catch (std::bad_alloc)
   {
      throw "ERROR: Unable to allocate buffer";
   }
   numCapacity = rhs.numCapacity;
   int tempFront = rhs.iFront;

   for (int i = rhs.iFront; i < rhs.iBack + 1; i++)
   {
      push_back(rhs.data[rhs.iNormalize(i)]);
   }
}

/***********************************************
* DEQUE : PUSH_BACK
* adds element to the back of the deque
***********************************************/
template<class T>
void deque<T>::push_back(const T & element)
{
	if (numCapacity == 0)
	{
		resize(1);
	}
	else if (size() == capacity())
	{

		resize(numCapacity *= 2);
	}
	iBack++;
	data[iBackNormalized()] = element;

}

/***********************************************
* DEQUE : PUSH_FRONT
* adds an element to the front of the deque
***********************************************/
template<class T>
void deque<T>::push_front(const T & element)
{
	if (numCapacity == 0)
	{
		resize(1);
	}
	else if (size() == capacity())
	{

		resize(numCapacity *= 2);
	}
	iFront--;
	data[iFrontNormalized()] = element;
}

/***********************************************
* DEQUE : POP_BACK
* removes an element from the back of the deque
***********************************************/
template<class T>
void deque<T>::pop_back()
{
	if (numCapacity == 0)
	{
		throw "ERROR: unable to pop from the back of empty deque";
	}

	iBack--;
}

/***********************************************
* DEQUE : POP_FRONT
* removes an element from the back of the deque
***********************************************/
template<class T>
void deque<T>::pop_front()
{
	if (numCapacity == 0)
	{
		throw "ERROR: unable to pop from the front of empty deque";
	}

	iFront++;
}

/********************************************
 * deque : RESIZE
 * resizes the deque buffer
 *******************************************/
template<class T>
void deque<T>::resize(int capacityNew)
{
   bool full = false;
   // do nothing if there is nothing to do
   if (capacityNew < numCapacity)
   {
      return;
   }
   T x;
   int s;
   try
   {
      //Create new deque  
      T *dataNew = new T[capacityNew];

      for (int i = 0; i < size(); i++)
      {
         dataNew[i] = data[i];

         x = dataNew[i];
      }

      //copy deque
      data = dataNew;
      //set new capacity
      numCapacity = capacityNew;
      
   }
   catch (std::bad_alloc) {
      throw "ERROR: Unable to allocate new buffer for deque";
   }
}

/***********************************************
* DEQUE : SIZE
* return the size of the deque
***********************************************/
template<class T>
int deque<T>::size()
{
   if (iBack == -1 && iFront == 0)
   {
      return 0;
   }
   else
   {
      return iBack - iFront + 1;
   }
}

/***********************************************
* DEQUE : CAPACITY
* returns the capacity of the deque
***********************************************/
template<class T>
int deque<T>::capacity()
{
   return numCapacity;
}

/***********************************************
* DEQUE : EMPTY
* determines if the queue is empty
***********************************************/
template<class T>
bool deque<T>::empty()
{
   if (size() <= 0)
   {
      return true;
   }
   else
   {
      return false;
   }
}

/***********************************************
* DEQUE : CLEAR
* Clears and the deque
***********************************************/
template<class T>
void deque<T>::clear()
{
   data = NULL;
   delete[] data;
   numCapacity = 0;
   iFront = 0;
   iBack = -1;
}

/***********************************************
* DEQUE : FRONT
* returns the value of the front element
***********************************************/
template<class T>
T deque<T>::front()
{
   if (empty() == true)
   {
      throw "ERROR: attempting to access an element in an empty queue";
   }
   else
   {
      return data[iFrontNormalized()];
   }
}

/***********************************************
* DEQUE : BACK
* returns the value of the back element
***********************************************/
template<class T>
T deque<T>::back()
{
   if (empty() == true)
   {
      throw "ERROR: attempting to access an element in an empty queue";
   }
   else
   {
      return data[iBackNormalized()];
   }
}

/***********************************************
* DEQUE : iFrontNormalized
* Returns index Front
***********************************************/
template<class T>
int deque<T>::iFrontNormalized()
{
   return iNormalize(iFront);
}

/***********************************************
* DEQUE : iBackNormalized
* Returns index back
***********************************************/
template<class T>
int deque<T>::iBackNormalized()
{
   
   return iNormalize(iBack);
}

/***********************************************
* DEQUE : iNormalize
* Assists in making deque circular
***********************************************/
template<class T>
int deque<T>::iNormalize(int num)
{
   return (num % numCapacity + numCapacity) % numCapacity;
}
} //end namespace custom
#endif /* DEQUE_H */
