// CS303_Lecture6aStarter.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Iterator.h"
#include <iostream>
#include <list>

using namespace myIterator;

int main() {
    //using the iterator with STL list
    std::list<std::string> li = { "A","B","C","D","E" };
    std::list<std::string>::iterator iter = li.begin();

    while (iter != li.end()) {
        std::cout << *iter;
        iter++;
        if (iter != li.end())
            std::cout << " ===> ";
    }
    std::cout << '\n';


    // create a doubly linked list
    // setup the initial nodes of Harry & Sam
    DNode<std::string>* harryD = new DNode<std::string>("Harry");
    DNode<std::string>* samD = new DNode<std::string>("Sam");
    harryD->next = samD;
    samD->prev = harryD;

    // Start example from page 4 in notes
    DNode<std::string>* sharonD = new DNode<std::string>("Sharon");

    sharonD->next = samD;       // step 1 - set nextPtr in new node
    sharonD->prev = samD->prev; // step 2 - set prevPtr in new node

    //link old predecessor
    samD->prev->next = sharonD; // step 3 - set nextPtr in previous node
    //link to new predecessor
    samD->prev = sharonD;       // step 4 - set prevPtr in next node

    //completing doubly linked list from slide 6 in notes 
    DNode<std::string>* johnD = new DNode<std::string>("John");
    DNode<std::string>* tomD = new DNode<std::string>("Tom");
    johnD->next = harryD;
    harryD->prev = johnD;
    tomD->next = johnD;
    johnD->prev = tomD;

    try {
        myIterator::iterator<std::string> newListIter(tomD);

        std::cout << "\nPRINTING CURRENT LIST USING POSTFIX\n";
        while (!(newListIter == nullptr)) {
            std::cout << *newListIter << "\n";
            newListIter++;
        }

        std::cout << "\nPRINTING CURRENT LIST USING PREFIX\n";
        newListIter = tomD;
        while (!(newListIter == nullptr)) {
            std::cout << *newListIter << "\n";
            ++newListIter;
        }

        std::cout << "\nCHANGING 2ND NAME TO BUBBA WUBBA\n";
        newListIter = tomD;
        ++newListIter;

        std::string* newData = newListIter.operator->();
        *newData = "Bubba Wubba";

        std::cout << "\nPRINTING CURRENT LIST WITH UPDATED NAME\n";
        newListIter = tomD;
        while (!(newListIter == nullptr)) {
            std::cout << *newListIter << "\n";
            ++newListIter;
        }

        std::cout << "\nDEMONSTRATING PRE & POSTFIX OPERATORS\n";
        newListIter = tomD;
        std::cout << *newListIter << "\n";
        ++newListIter;
        std::cout << *newListIter << "\n";
        --newListIter;
        std::cout << *newListIter << "\n";
        newListIter--;
        std::cout << *newListIter << std::endl;

        newListIter = tomD;
        while (!(newListIter == nullptr)) {
            std::cout << *newListIter << "\n";
            newListIter++;
        }


        myIterator::const_iterator<std::string> newListIter2(tomD);

        std::cout << "\nUSING CONST_ITERATOR CLASS\n";
        while (!(newListIter2 == nullptr)) {
            std::cout << *newListIter2 << "\n";
            newListIter2++;
        }
    }
    catch (std::invalid_argument& err) {
        std::cout << err.what() << std::endl;
    }
}