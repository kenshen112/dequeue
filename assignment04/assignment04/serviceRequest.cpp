/***********************************************************************
 * Implementation:
 *    SERVICEREQUEST
 * Summary:
 *    Holds data and functions related to fulfilling a service request
 * Author
 *    Tim O'Barr and Kenyon Bunker
 **********************************************************************/
#include "ServiceRequest.h"

 /***********************************************
 * Default Constructor
 ***********************************************/
ServiceRequest::ServiceRequest()
{

}

/***********************************************
* SERVICEREQUEST : getRequest
* gets request data
***********************************************/
void ServiceRequest::getRequest()
{
	requestData tempRequest;
}

/***********************************************
* SERVICEREQUEST : setRequest
* sets/updates request data
***********************************************/
void ServiceRequest::setRequest(requestData rData)
{
	request.push_back(rData);
}

/***********************************************
* SERVICEREQUEST : removeRequest
* removes request from deque
***********************************************/
void ServiceRequest::removeRequest()
{
	request.pop_front();
}

/***********************************************
* SERVICEREQUEST : incrementTime
* increments the request time down
***********************************************/
int ServiceRequest::incrementTime(int &time)
{
	for (int i = request.front().minutesRequired; time < i; time++)
	{
		display();
	}

	removeRequest();
   return 0;
}

/***********************************************
* SERVICEREQUEST : display
* displays request data
***********************************************/
void ServiceRequest::display()
{

}
