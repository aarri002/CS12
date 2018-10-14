//  =============== BEGIN ASSESSMENT HEADER ================
/// @file assignment07/Makefile
/// @brief Assignment 7 for CS 12 Fall 2014
///
/// @author Alberto Arriaga Felix [aarri002@ucr.edu]
/// @date 12/06/2014
///
/// @par Enrollment Notes 
///     Lecture Section: 001
/// @par
///     Lab Section: 021
/// @par
///     TA: Leo P. Vu
///
/// @par Plagiarism Section
/// I hereby certify that the code in this file
/// is ENTIRELY my own original work.
//  ================== END ASSESSMENT HEADER ===============

#variables
COMPILE = g++
FLAGS = -W -Wall -Werror -ansi -pedantic
DEBUG = -g -W -Wall -Werror -ansi -pedantic
OBJS = BBoard.o Message.o Reply.o Topic.o User.o

#Targets

all: main.cpp $(OBJS)
	$(COMPILE) $(FLAGS) -o a.out main.cpp $(OBJS)

BBoard.o: BBoard.cpp BBoard.h
	$(COMPILE) $(FLAGS) -c BBoard.cpp

Message.o: Message.cpp Message.h
	$(COMPILE) $(FLAGS) -c Message.cpp

Reply.o: Reply.cpp Reply.h
	$(COMPILE) $(FLAGS) -c Reply.cpp
    
Topic.o: Topic.cpp Topic.h
	$(COMPILE) $(FLAGS) -c Topic.cpp
    
User.o: User.cpp User.h
	$(COMPILE) $(FLAGS) -c User.cpp

clean:
	rm -rf *~ *.o a.out

tar:
	tar -czvf assn6.tgz *.cpp *.h Makefile

debug: main.cpp $(OBJS)
	$(COMPILE) $(DEBUG) -o a.out main.cpp $(OBJS)