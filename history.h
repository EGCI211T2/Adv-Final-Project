#define history_h
#include "score.h"
#include <fstream>

class LL {
  SCOREPtr hol; 
  int size;

public:
  LL();
  int deletes(int value);
  int isEmpty();
  void insert(string name, int score);
  void printList();
  ~LL();
 void printListR();
 void shigh();
 void vhigh();

};

LL::LL() {
  this->hol = NULL;
  size = 0;
}

LL::~LL() {
  /*cout << "deleting all nodes" << endl;
  SCOREPtr t;
  t = hol;
  int i;
  for (i = 0; i < size; i++) {
    t = hol->get_next();
    delete hol;
    hol = t;
  }*/
}
void LL::insert(string name, int score) 
{
  SCOREPtr newPtr;      
  SCOREPtr previousPtr; 
  SCOREPtr currentPtr; 

  newPtr = new SCORE(name,score); 

  if (newPtr != NULL) { // is space available

    previousPtr = NULL;
    currentPtr = hol;
    // loop to find the correct location in the list
    while (currentPtr != NULL && score > currentPtr->get_score()) {
      previousPtr = currentPtr;          
      currentPtr = currentPtr->get_next();                             
    } 

    // insert new node at beginning of list
    if (previousPtr == NULL) {
        newPtr->set_next(hol);
        hol = newPtr;
       
      }
    else { 
      // insert new node between previousPtr and currentPtr
      previousPtr->set_next(newPtr);
      
      newPtr->set_next(currentPtr);
        } // end else
    ++size;
  } 
  else {
    cout << score << " not inserted. No memory available." << endl;
  } 
}


int LL::isEmpty() { return hol == NULL; } 


void LL::printListR() 
{
  SCOREPtr currentPtr = hol;
  SCOREPtr tempPtr;

  if (size != 0)  {
    cout << "Top score: " << endl;

    int i;
    for (i=0; i<size-1; i++) 
      currentPtr = currentPtr->get_next();
    for (i = 1 ;i <=size; i++)
     {
      if(i<=5){
      cout<<i<<". ";
      currentPtr->print();
      }
      currentPtr = currentPtr->get_prev();
    } 
    

    //puts(" NULL\n");
  } 
} 
void shigh(LL h){
    ifstream inputFile("score.txt");
     if (!inputFile.is_open()) { 
        cout << "Error opening the file!" << endl; 
    }
    else{
    while(!inputFile.eof()){
        string n; 
        int s;
        inputFile>>n;
        inputFile>>s;
        h.insert(n,s);
    }
    h.printListR();
     inputFile.close();
    }
}
void vhigh(string n,int s){
    ofstream log;
     log.open("score.txt", fstream::app);
     log<<endl;
     log<< n << " " <<s;
     log.close();
}