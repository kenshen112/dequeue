namespace custom
{
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

		clear();

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
		int tempFront= rhs.iFront;

		for (int i = rhs.iBack; i < rhs.iFront; i++)
		{
			push(rhs.data[i % rhs.numCapacity]);
		}
	}

   /********************************************
   * ASSIGNMENT OPERATOR
   *******************************************/
   deque<T> & operator=(deque<T>& rhs)
   {
      if (rhs.numCapacity == 0)
      {
		  clear();
         return *this;
      }

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
      for (int i = rhs.iFront; i < rhs.iBack; i++)
      {
         pushBack(rhs.data[iNormalize(i)]); //What on earth is iNormalize?
      }
      return *this;
   }

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
void deque<T>::pushBack(T & element)
{
	if (numCapacity == 0)
	{
		resize(1);
	}
	else if (iBack == numCapacity)
	{

		resize(numCapacity *= 2);
	}
	iBack++;
	data[iBack] = element;

}

template<class T>
void deque<T>::pushFront(T & element)
{
	if (numCapacity == 0)
	{
		resize(1);
	}
	else if (iFront == numCapacity)
	{

		resize(numCapacity *= 2);
	}

	iFront++;
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

/********************************************
 * deque : RESIZE
 * resizes the deque buffer
 *******************************************/
template<class T>
void deque<T>::resize(int numCapacity)
{

	int capacityNew = 0;

   // do nothing if there is nothing to do
   if (capacityNew < numCapacity)
   {
      return;
   }
   try
   {
      T *dataNew = new T[capacityNew];

      for (int i = 0; i < iFront; i++) {
         dataNew[i] = data[i];
      }

      data = dataNew;
      numCapacity = capacityNew;
   }
   catch (std::bad_alloc) {
      throw "ERROR: Unable to allocate new buffer for deque";
   }
}

/********************
* Returns Size
********************/
template<class T>
int deque<T>::size()
{
   return iBack - iFront + 1;
}

/********************
* Returns Capacity
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
   if (iBack == iFront)
   {
      return true;
   }
   else
   {
      return false;
   }
}

/**************************
* Clears the entire deque
**************************/
template<class T>
void deque<T>::clear()
{
   data = NULL;
   delete[] data;
   numCapacity = 0;
   iFront = 0;
   iBack = -1;
}

/************************
* Are we at the front?
***********************/
template<class T>
T deque<T>::front()
{
   if (empty() == true)
   {
      throw "ERROR: attempting to access an element in an empty queue";
   }
   else
   {
      return data[iFrontNormalize()];
   }
}

/************************
* Are we at the back?
***********************/
template<class T>
T deque<T>::back()
{
   if (empty() == true)
   {
      throw "ERROR: attempting to access an element in an empty queue";
   }
   else
   {
      return data[iBackNormalize()];
   }
}

/*************************
* Returns index Front
*************************/
template<class T>
int deque<T>::iFrontNormalized()
{
   return iFront % numCapacity;
}

/**********************
* Returns index Back
**********************/

template<class T>
int deque<T>::iBackNormalized()
{
   return (iBack - 1) % numCapacity;
}

} //end namespace custom
