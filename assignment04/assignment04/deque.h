namespace custom
{
template <class T>
class deque
{
private:
   int iFront;
   int iBack;
   T data;
   int numCapacity;

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

   /********************************************
   * ASSIGNMENT OPERATOR
   *******************************************/
   deque<T> & operator=(deque<T>& rhs)
   {
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

/********************************************
 * Queue : RESIZE
 * resizes the deque buffer
 *******************************************/
template<class T>
void deque<T>::resize(int numCapacity)
{
   // do nothing if there is nothing to do
   if (capacityNew < numCapacity)
   {
      return;
   }
   try
   {
      T *dataNew = new T[capacityNew];

      for (int i = numPop; i < numPush; i++) {
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
   if (numPush == numPop)
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
   if (empty())
   {

   }
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

} //end namespace custom
