#ifndef stack_h
#define stack_h
#include "node.h"
class Stack {
	NodePtr top;
	int size;
public:
    void push(string);
    void pop();
    Stack();
    ~Stack();
    bool isEmpty();
};


void Stack::push(string n){
  NodePtr new_node=new NODE(n);
  if(new_node){
            new_node->set_next(top);
            top=new_node;
            ++size;
   }
 
    else{
        cout<<"No more memory left"<<endl;
    }
    
}

void Stack::pop(){
    if (isEmpty()) {
        cout << "Stack Underflow" << endl;
    }
        NodePtr t=top;
        string name;
        name=t->get_name();
        cout<<name<<endl;
        top = t->get_next();
        size--;
        delete t;
    }
Stack::Stack(){
    top=NULL;
    size=0;
    
}
Stack::~Stack(){
   //cout<<"start clearing the stack."<<endl;
}
bool Stack::isEmpty() {
    return top == nullptr;
}


#endif