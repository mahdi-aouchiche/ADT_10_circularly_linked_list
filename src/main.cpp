#include <iostream>
#include <string>
#include <fstream>
#include "int_list.cpp"
using namespace std;

int main() {
  string filename;             // file holding strings in a newline. 
  string name;                 // holds names from the filename.
  int ID = 0;                  // position of the person from the list.
  int k;                       // number of people to skip.  
  IntList namelist;            // pointer to the circularly linked list.
  int file_num;                // used in the selection of a file. 
  
  cout 
    << "1 - file_1" << "\t" 
    << "2 - file_2" << "\t" 
    << "3 - file_3" << "\n"
    << "Select a file: ";
  cin >> file_num;

  if(file_num == 1) {
    filename = "./input_files/file_1.txt";
  } else if (file_num == 2) {
    filename = "./input_files/file_2.txt";
  } else if (file_num == 3) {
    filename = "./input_files/file_3.txt"; 
  } else {
    cout << "Wrong input." << endl;
    exit(1);
  } 

  // open the file 
  ifstream inFS(filename);

  // check if the file is open
  if(!inFS.is_open()) {
    cout << "File could not open" << endl;
    exit(1);
  }

  // fill up the list  
  while(getline(inFS, name)){
    ID++; 
    namelist.pushBack(name, ID);    // push back names to create a circle
  }

  // Get the number to start count from
  cout << "Enter the number between (1 and " << ID 
    << ") of a person to start counting from: "; 
  cin >> ID;

  // Get the amount of ppl to skip 
  cout << "Enter the number of people to skip: "; 
  cin >> k;

  // remove the people from the list 
  namelist.removeNode(k, ID);

  cout << endl << "The lucky survivor is: ";
  namelist.display();  
}