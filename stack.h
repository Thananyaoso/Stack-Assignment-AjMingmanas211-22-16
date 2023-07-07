#ifndef stack_h
#define  stack_h
#include "node.h"
using namespace std;

class Stack{
private:
	 NodePtr top;
	 int size;
public:
    Stack(NodePtr = NULL);
    char pop();
    bool empt();
    void push(char);
    char get_top();
    ~Stack();
};

Stack::Stack(NodePtr t){
  if(t) {
    top=t;
    size=1;
    
  }
 else{
   top=NULL;
	 size=0;
   }
}
void Stack::push(char x){
   NodePtr newnode=new NODE(x);
  //1
  if(newnode){
      newnode->set_next(top);
      top = newnode;
      size++;
   }
  else cout<<"No memory left for new nodes"<<endl;
		 // Left missing for exercises…
}
char Stack::pop(){
 	  NodePtr t=top;
		int value;		
	 if(t){
     value=t->get_value();
     top=t->get_next();
	   delete t;
     size--;
     return value;
     }
    
	 cout<<"Empty stack"<<endl;
   return 0;
	}
bool Stack::empt(){
  if(top){
    return false;
  }
  return true;
}

char Stack::get_top(){
  return top->get_value();
}

Stack::~Stack(){
   cout<<"Clearing all stacks"<<endl;
  	int i;
  NodePtr t=top;
for(i=0;i<size;i++){
     NodePtr t = top;
     top = top->get_next();
     delete t;
   	
  }
}


#endif