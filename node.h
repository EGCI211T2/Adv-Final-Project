#ifndef node_h
#define node_h
class NODE{
     string name;
    NODE *nextPtr;
public:
    NODE(string);
    ~NODE();
    void set_next(NODE*);
    NODE* get_next();
    string get_name();
};
typedef NODE* NodePtr;


NODE::NODE(string n){
    name=n;
    nextPtr=NULL;
    //pPtr =NULL; not using doubly
}
NODE* NODE::get_next(){
    return nextPtr;

}

string NODE::get_name(){
    return name;
}

void NODE::set_next(NODE *t){
     nextPtr=t;

}
NODE::~NODE(){
     //cout<<"deleting "<<data<<endl;

}
#endif