#include "../header/int_list.hpp"

IntList::IntList() {
  this->head = nullptr;
}

void IntList::pushBack(string name, int ID) {
  NameNode* newNode = new NameNode(name, ID);

  if ( this->head == nullptr) {
    this->head = newNode;
  } else {
    NameNode* currNode = this->head;

    // get the last Node
    while (currNode->nextNode != this->head) {
      currNode = currNode->nextNode;
    }
    currNode->nextNode = newNode; 
  }

  newNode->nextNode = this->head;
}

NameNode* IntList::setHead(int start) {
  if(!this->head || start < 1) {
    return nullptr;
  }

  NameNode* curr = this->head;
  while(curr->ID < start) {
    curr = curr->nextNode;
  }

  return curr;
}

void IntList::removeNode(int k, int s) {
  NameNode* currNode = this->setHead(s);
  NameNode* prevNode = currNode;

  while( !(currNode == this->head && currNode->nextNode == this->head) ) {
    
    // get the Node to remove, check the point start **** 
    for(unsigned i = 0; i < k; ++i) {
      prevNode = currNode; 
      currNode = currNode->nextNode;
    } 

    // remove the Node
    prevNode->nextNode = currNode->nextNode; 

    // move the head if current node is the head 
    if(currNode == this->head) {
      this->head = currNode->nextNode;  
    }

    // delete Node to avoid memory leaks
    delete currNode; 

    // update current Node 
    currNode = prevNode->nextNode; 
  } 
}

void IntList::display() {
  NameNode* currNode; 

  if(this->head != nullptr) {
    currNode = this->head ;
    do {
      cout << currNode->ID << " " << currNode->name << endl ;
      currNode = currNode->nextNode ; 
    } while(currNode != this->head) ;
  }
}