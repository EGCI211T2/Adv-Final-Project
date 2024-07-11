#ifndef score_h
#define score_h
class SCORE{
     string name;
     int data;
    SCORE *nextPtr;
    SCORE *pPtr;
public:
    SCORE(string,int);
    ~SCORE();
    void set_next(SCORE*);
    SCORE* get_next();
    string get_name();
    int get_score();
    SCORE * get_prev(); 
    void set_prev(SCORE* t); 
    void print();
};
typedef SCORE* SCOREPtr;


SCORE::SCORE(string n,int s){
    name=n;
    data=s;
    nextPtr=NULL;
    pPtr =NULL;
}
void SCORE::set_prev(SCOREPtr t)
{
  this->pPtr = t; 
}
SCOREPtr SCORE::get_prev() { 
    return pPtr; }
SCOREPtr SCORE::get_next() { 
        return nextPtr;}

int SCORE::get_score(){
    return data;
}
string SCORE::get_name(){
    return name;
}

void SCORE::set_next(SCORE *t){
     this->nextPtr = t; 
       if (t!=NULL) t->pPtr=this;

}
void SCORE::print(){
    cout<<name<<" "<<data<<endl;
}
SCORE::~SCORE(){
     //cout<<"deleting "<<data<<endl;

}
#endif