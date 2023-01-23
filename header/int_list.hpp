#ifndef __INT_LIST_HPP__
#define __INT_LIST_HPP__

#include <string>
#include <iostream>
using namespace std ;

// build a node using a struct
struct NameNode {
  string name ;            // holds the name of each person in the list 
  int ID ;                 // holds the position of the name in the namelist
  NameNode* nextNode ;
  NameNode(string name, int ID) : name(name), ID(ID), nextNode(nullptr) {}
};

class IntList {
  private:
    NameNode* head ;          // NameNode pointer to the start of the list         

  public:
    // constructor                       
    IntList() ;
    
    // put the names in the IntList
    void pushBack(string name, int ID) ;

    // remove the node after the k(th) count starting from node s 
    void removeNode(int k, int s) ;

    // set the head, the start point for counting 
    NameNode* setHead(int start) ; 

    // display the list 
    void display() ;
};

#endif  // __INT_LIST_HPP__