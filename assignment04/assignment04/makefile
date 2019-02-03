###############################################################
# Program:
#     Assignment 04, DEQUE
#     Brother Kirby, CS235
# Author:
#     Kenyon Bunker
#     Tim O'Barr
# Summary:
#     A Now Serving application using a custom deque class
# Time:
#     Kenyon 10
#	  Tim    10
#     Together 5
# The most difficult part:
#     Kenyon
#     Getting the deque to be circular. Any pointers you have
#     would be great. We narrowed it down
#     to how resize was putting data onto the new deque.
#     Tim
#     	Designing nowserving. How it would all fit together.
#       
###############################################################

##############################################################
# The main rule
##############################################################
a.out: deque.h assignment04.o nowServing.o serviceRequest.o
	g++ -o a.out assignment04.o nowServing.o serviceRequest.o -std=c++11
	tar -cf assignment04.tar *.h *.cpp makefile

##############################################################
# The individual components
#      assignment04.o : the driver program
#      nowServing.o   : the logic for the now serving program
##############################################################
assignment04.o: deque.h assignment04.cpp
	g++ -c assignment04.cpp -std=c++11

nowServing.o: nowServing.h nowServing.cpp deque.h
	g++ -c nowServing.cpp -std=c++11
	
serviceRequest.o: ServiceRequest.h serviceRequest.cpp nowServing.h
	g++ -c serviceRequest.cpp -std=c++11
