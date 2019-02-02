/***********************************************************************
 * Implementation:
 *    NOW SERVING
 * Summary:
 *    This will contain the implementation for nowServing() as well as any
 *    other function or class implementations you may need
 * Author
 *    <your names here>
 **********************************************************************/

#include <iostream>     // for ISTREAM, OSTREAM, CIN, and COUT
#include <string>       // for STRING
#include <cassert> // for ASSERT  
#include <sstream>
#include "nowServing.h" // for nowServing() prototype
#include "deque.h"      // for DEQUE
using namespace std; // Dear CS teachers, https://stackoverflow.com/questions/1452721/why-is-using-namespace-std-considered-bad-practice

/************************************************
 * NOW SERVING
 * The interactive function allowing the user to
 * handle help requests in the Linux lab
 ***********************************************/
void nowServing()
{
   // instructions
   cout << "Every prompt is one minute.  The following input is accepted:\n";
   cout << "\t<class> <name> <#minutes>    : a normal help request\n";
   cout << "\t!! <class> <name> <#minutes> : an emergency help request\n";
   cout << "\tnone                         : no new request this minute\n";
   cout << "\tfinished                     : end simulation\n";

   // your code here
   ServiceRequest request;
   int time = 0;
   int numRequest = 0;
   requestData rData;
   std::string data;
   std::string token;
   std::string inputArr[4];  //array for input tokens

   std::cout << "<" << numRequest << ">";

   std::getline(std::cin, data);

   std::istringstream ss(data);

   int i = 0;
   while (ss >> token)
   {
	   inputArr[i] = token;
	   i++;
   }

   if (inputArr[0] == "!!")
   {
	   rData.urgent = true;
	   rData.sClass = inputArr[1];
	   rData.name = inputArr[2];
	   rData.minutesRequired = stoi(inputArr[3]);
   }

   else
   {
	   rData.sClass = inputArr[0];
	   rData.name = inputArr[1];
	   rData.minutesRequired = stoi(inputArr[2]);
   }

   //Example function calls for service request. We can move them later.
   request.setRequest(rData);
   request.getRequest();
   request.incrementTime(time);
   request.removeRequest();
   request.display();

   // end
   cout << "End of simulation\n";
}


