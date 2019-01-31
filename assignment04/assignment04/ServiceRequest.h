/***********************************************************************
 * Header:
 *    SERVICE REQUEST
 * Summary:
 *    Holds data and functions related to fulfilling a service request
 * Author
 *    Tim O'Barr
 *    Kenyon Bunker
 ************************************************************************/
#ifndef SERVICEREQUEST_H
#define SERVICEREQUEST_H

#include "deque.h"
#include <string.h>
#include <string>
#include <iostream> 


using namespace custom;
/***********************************************
* Structure REQUESTDATA
* holds service request data
***********************************************/
struct requestData
{
   std::string sClass;
   std::string name;
   int minutesRequired;
   int minutesRemaining;
   bool urgent;
};

/***********************************************
* SERVICE REQUEST
* Main Class Body
***********************************************/
class ServiceRequest
{
private:
   deque <requestData> request;     //deque object

public:
   //default Constructor
   ServiceRequest();

   //prototype functions
   void getRequest();
   void setRequest(deque request);
   void removeRequest();
   int incrementTime(int time);
   void display();
};


#endif // SERVICEREQUEST_H
