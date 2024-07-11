#define combat_h
#include <iostream>
using namespace std;
#include <iomanip>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

class monster{
private:
    string name;
    int hp,atk,def,sta,spd,upoint;
public:
    void statt();
    int gethp();
    int getsta();
    int getspd();
    int getatk();
    int getdef();
    void upgrade();
    int nattack(monster x);
    int sattack(monster x);
    int cattack(monster x,int s);
    int battle(monster a,monster b,int round);
    int ndefend();
    int defend();
    void heal();
    monster(string,int = 10,int = 1,int = 1,int=8,int=1);
    ~monster();
};

monster::monster (string n, int h, int a, int d,int st, int sp)
{
    name=n;
    hp=h;
    atk=a;
    def=d;
    sta=st;
    spd=sp;
}
void monster::statt(){
    cout<<"Name: "<<name<<endl;
    cout<<"HP: "<<hp<<endl;
    cout<<"Stamina: "<<sta<<endl;
    cout<<"Speed: "<<spd<<endl;
    cout<<"Attack: "<<atk<<endl;
    cout<<"Defense: "<<def<<endl;
}

 int monster::gethp(){
    return hp;
 }
 int monster::getsta(){
        return sta;
    }
int monster::getspd(){
    return spd;
}
int monster::getatk(){
    return atk;
}
int monster::getdef(){
    return def;
}
void monster::upgrade(){
  int c;
  upoint=5;
        do{
            system("clear");
            cout<<"Name: "<<name<<endl;
            cout<<"Upgrade Point: "<<upoint<<endl;
            cout<<"Stats lists:"<<endl;
            cout<<"1.HP: "<<hp<<endl;
            cout<<"2.Stamina: "<<sta<<endl;
            cout<<"3.Speed: "<<spd<<endl;
            cout<<"4.Attack: "<<atk<<endl;
            cout<<"5.Defense: "<<def<<endl;
            cout<<"Choose stats to upgrade: ";
            c=numin();
            if(c<1||c>5){
                cout<<"Please choose number in the list."<<endl;
                continue;
            }
            else{
                switch (c){
                case 1:
                    hp+=5;
                    upoint--;
                    break;
                case 2:
                    sta+=2;
                    upoint--;
                    break;
                case 3:
                    spd++;
                    upoint--;
                    break;
                case 4:
                    atk++;
                    upoint--;
                break;
                case 5:
                    def++;
                    upoint--;
                    break;
            }
            }
            
        }while(upoint!=0);
    }
    

int monster::sattack(monster x){
    int p=rand()%7;
    if(p==0){
        cout<<name<<" miss the special attack."<<endl;
        sleep(2);
        return 0;
    }
    else if(p<6){
        cout<<name<<" attacks "<<x.name<<" "<<atk*3<<" damage."<<endl;
         sleep(2);
        return atk*3;
    }
    else{
        cout<<"Critical hit!!!"<<endl;
        sleep(2);
        cout<<name<<" attacks "<<x.name<<" "<<atk*5<<" damage."<<endl;
         sleep(2);
        return atk*5;
    }
}
int monster::nattack(monster x){
    int p=rand()%7;
    if(p==0){
        cout<<name<<" miss the attack."<<endl;
         sleep(2);
        return 0;
    }
    else if(p<6){
        cout<<name<<" attacks "<<x.name<<" "<<atk<<" damage."<<endl;
         sleep(2);
        return atk;
    }
    else{
       cout<<"Critical hit!!!"<<endl;
        sleep(2);
        cout<<name<<" attacks "<<x.name<<" "<<atk*2<<" damage."<<endl;
         sleep(2);
        return atk*2;
    }

}
int monster::cattack(monster x,int s){
    int p=rand()%7;
    if(p==0){
        cout<<name<<" miss the charge attack."<<endl;
         sleep(2);
        return 0;
    }
    else {
        cout<<name<<" attacks "<<x.name<<" "<<atk*s<<" damage."<<endl;
         sleep(2);
        return atk*s;
    }
}
int monster::ndefend(){
    int x =(def/10)*(rand()%7+4);
    cout<<name<<" defends "<<x<<" damage."<<endl;
     sleep(2);
    return x;
}
int monster::defend(){
    int x =def*2;
    cout<<name<<" use protection for "<<x<<" damage."<<endl;
     sleep(2);
    return x;
}
monster::~monster()
{
    //cout<<name<<" is dead."<<endl;
}

int monster::battle(monster a, monster b,int round){
 int ahp=a.gethp(),asta=a.getsta(),aspd=a.getspd(),bhp=b.gethp(),bspd=b.getspd(),ba=b.getatk(),bd=b.getdef();
    int ea=asta/2, c;
    int turn=0;
    int heal;
    
do{
    if(turn>0)
    sleep(2);
    system("clear");
    if(turn>0){
        ea+=2;
        if(ea>=asta){
            ea=asta;
        }
    }
    turn++;
    int bb=rand()%10+1;
    int bc;
    if(bb<6)
    {
    bc=1;
    }
    else if(bb<9)
    {
        bc=2;
    }
    else{
        bc=3;
    }
    int aatk=0,adef,batk=0,bdef,af,bf;
    cout<<"----------------------------------"<<endl;
    cout<<a.name<<endl;
    cout<<"HP  : "<<setw(5)<<ahp<<"  Speed : "<<setw(5)<<spd<<endl;
    cout<<"Atk : "<<setw(5)<<atk<<"  Defend: "<<setw(5)<<def<<endl;
    cout<<"Energy: "<<ea<<endl;
    cout<<"----------------------------------"<<endl;
    cout<<b.name<<endl;
    cout<<"HP. : "<<setw(5)<<bhp<<"  Speed : "<<setw(5)<<bspd<<endl;
    cout<<"Atk : "<<setw(5)<<ba<<"  Defend: "<<setw(5)<<bd<<endl;
    cout<<"----------------------------------"<<endl;
    cout<<"Score: "<<round<<endl;
    cout<<"----------------------------------"<<endl;
    cout<<"Choose the action: "<<endl;
    cout<<"1.Normal Attack"<<endl;
    cout<<"2.Super Attack"<<endl;
    cout<<"3.Charge Attack"<<endl;
    cout<<"4.Protect"<<endl;
    cout<<"5.Restore"<<endl;
    do{
    cout<<":";
    c=numin();
    if(c<1||c>5)
    {
        cout<<"Please choose action on the list"<<endl;
    }
    }while(c<1||c>5);
    switch (c){
    case 1:
    if(ea<1)
    {
        cout<<name<<" has not enough energy!"<<endl;
        ea-=2;
        break;
    }
    else{
        ea-=1;
        if(bspd>aspd){
            switch (bc)
            {
            case 1:
                batk=b.nattack(a);
                adef=a.ndefend();
                bf=batk-adef;
                if(bf<0){
                    bf=0;
                }
                if(bf>0&&batk!=0)
                {
                    ahp-=bf;
                    cout<<b.name<<" deals "<<bf<<" damage."<<endl;   
                    sleep(2);                
                    if(ahp<0)
                    {
                    ahp=0;
                    }
                    if(ahp>0){
                    cout<<a.name<<" has "<<ahp<<" hp left."<<endl;
                    sleep(2);
                    }
                    else{

                        cout<<a.name<<" is dead."<<endl;
                        sleep(2);
                        break;
                    }
                    
                }
                else if(bf==0&&batk!=0) {
                    cout<<b.name<<" can't penetrate "<<a.name<<" defend."<<endl;
                    sleep(2);
                }
                aatk=a.nattack(b);
                bdef=b.ndefend();
                af=aatk-bdef;
                if(af<0){
                    af=0;
                }
                if(af>0&&aatk!=0)
                {
                    bhp-=af;
                    cout<<a.name<<" deals "<<af<<" damage."<<endl; 
                    sleep(2);                  
                    if(bhp<0)
                    {
                    bhp=0;
                    }
                    if(bhp>0){
                    cout<<b.name<<" has "<<bhp<<" left."<<endl;
                    sleep(2);
                    }
                    else{
                        cout<<b.name<<" is dead."<<endl;
                        sleep(2);
                        break;
                    }
                    
                }
                  else if(af==0&&aatk!=0) {
                    cout<<a.name<<" can't penetrate "<<b.name<<" defend."<<endl;
                    sleep(2);
                }
            break;
            case 2:
                heal=b.gethp()/10;
                bhp+=heal;
                if(bhp>=b.gethp())
                {
                    bhp=b.gethp();
                }
                  if(bhp==b.gethp()){
                    cout<<b.name<<" heals."<<endl;
                    sleep(2);
                    cout<<b.name<<" now has a full HP."<<endl;
                    sleep(2);
                }
                else{
                cout<<b.name<<" heals 10 percent of its HP."<<endl;
                sleep(2);
                }
                aatk=a.nattack(b);
                bdef=b.ndefend();
                af=aatk-bdef;
                if(af<0){
                    af=0;
                }
                if(af>0&&aatk!=0)
                {
                    bhp-=af;
                    cout<<a.name<<" deals "<<af<<" damage."<<endl; 
                    sleep(2);                  
                    if(bhp<0)
                    {
                    bhp=0;
                    }
                    if(bhp>0){
                    cout<<b.name<<" has "<<bhp<<" left."<<endl;
                    sleep(2);
                    }
                    else{
                        cout<<b.name<<" is dead."<<endl;
                        sleep(2);
                        break;
                    }
                    
                }
                else if(af==0&&aatk!=0) {
                    cout<<a.name<<" can't penetrate "<<b.name<<" defend."<<endl;
                    sleep(2);
                }
            break;
            case 3:
                bdef=b.defend();
                aatk=a.nattack(b);
                af=aatk-bdef;
                if(af<0){
                    af=0;
                }
                if(af>0&&aatk!=0)
                {
                    bhp-=af;
                    cout<<a.name<<" deals "<<af<<" damage."<<endl; 
                    sleep(2);                 
                    if(bhp<0)
                    {
                    bhp=0;
                    }
                    if(bhp>0){
                    cout<<b.name<<" has "<<bhp<<" left."<<endl;
                    sleep(2);
                    }
                    else{
                        cout<<b.name<<" is dead."<<endl;
                        sleep(2);
                        break;
                    }  
                }
                else if(af==0&&aatk!=0) {
                    cout<<a.name<<" can't penetrate "<<b.name<<" defend."<<endl;
                    sleep(2);
                }
                break;
        }
       }
       else{
        switch (bc){
            case 1:
                aatk=a.nattack(b);
                bdef=b.ndefend();
                af=aatk-bdef;
                if(af<0){
                    af=0;
                }
                if(af>0&&aatk!=0)
                {
                    bhp-=af;
                    cout<<a.name<<" deals "<<af<<" damage."<<endl;
                    sleep(2);                   
                    if(bhp<0)
                    {
                    bhp=0;
                    }
                    if(bhp>0){
                    cout<<b.name<<" has "<<bhp<<" left."<<endl;
                    sleep(2);
                    }
                    else{
                        cout<<b.name<<" is dead."<<endl;
                        sleep(2);
                        break;
                    }
                }
                else if(af==0&&aatk!=0) {
                    cout<<a.name<<" can't penetrate "<<b.name<<" defend."<<endl;
                    sleep(2);
                }
                batk=b.nattack(a);
                adef=a.ndefend();
                bf=batk-adef;
                if(bf<0){
                    bf=0;
                }
                if(bf>0&&batk!=0)
                {
                    ahp-=bf;
                    cout<<b.name<<" deals "<<bf<<" damage."<<endl;    
                    sleep(2);               
                    if(ahp<0)
                    {
                    ahp=0;
                    }
                    if(ahp>0){
                    cout<<a.name<<" has "<<ahp<<" hp left."<<endl;
                    sleep(2);
                    }
                    else{
                        cout<<a.name<<" is dead."<<endl;
                        sleep(2);
                        break;
                    }
                    
                }
                else if(bf==0&&batk!=0) {
                    cout<<b.name<<" can't penetrate "<<a.name<<" defend."<<endl;
                    sleep(2);
                }
            break;
            case 2:
             aatk=a.nattack(b);
                bdef=b.ndefend();
                af=aatk-bdef;
                if(af<0){
                    af=0;
                }
                if(af>0&&aatk!=0)
                {
                    bhp-=af;
                    cout<<a.name<<" deals "<<af<<" damage."<<endl;  
                    sleep(2);                 
                    if(bhp<0)
                    {
                    bhp=0;
                    }
                    if(bhp>0){
                    cout<<b.name<<" has "<<bhp<<" left."<<endl;
                    sleep(2);
                    }
                    else{
                        cout<<b.name<<" is dead."<<endl;
                        sleep(2);
                        break;
                    }
                }
                else if(af==0&&aatk!=0) {
                    cout<<a.name<<" can't penetrate "<<b.name<<" defend."<<endl;
                    sleep(2);
                }
                heal=b.gethp()/10;
                bhp+=heal;
                if(bhp>=b.gethp())
                {
                    bhp=b.gethp();
                }
                  if(bhp==b.gethp()){
                    cout<<b.name<<" heals."<<endl;
                    sleep(2);
                    cout<<b.name<<" now has a full HP."<<endl;
                    sleep(2);
                }
                else{
                cout<<b.name<<" heals 10 percent of its HP."<<endl;
                sleep(2);
                }
                break;
            case 3:   
                aatk=a.nattack(b);
                bdef=b.defend();
                af=aatk-bdef;
                if(af<0){
                    af=0;
                }
                if(af>0&&aatk!=0)
                {
                    bhp-=af;
                    cout<<a.name<<" deals "<<af<<" damage."<<endl;  
                    sleep(2);                 
                    if(bhp<0)
                    {
                    bhp=0;
                    }
                    if(bhp>0){
                    cout<<b.name<<" has "<<bhp<<" left."<<endl;
                    sleep(2);
                    }
                    else{
                        cout<<b.name<<" is dead."<<endl;
                        sleep(2);
                        break;
                    }  
                }
                else if(af==0&&aatk!=0) {
                    cout<<a.name<<" can't penetrate "<<b.name<<" defend."<<endl;
                    sleep(2);
                }
                break;
       }

       } 
    }
    break;
    case 2:
    if(ea<4)
    {
        cout<<name<<" has not enough energy!"<<endl;
        sleep(2);
        ea-=2;
        break;
    }
    else{
        ea-=4;
    if(bspd>aspd){
            switch (bc)
            {
            case 1:
                batk=b.nattack(a);
                adef=a.ndefend();
                bf=batk-adef;
                if(bf<0){
                    bf=0;
                }
                if(bf>0&&batk!=0)
                {
                    ahp-=bf;
                    cout<<b.name<<" deals "<<bf<<" damage."<<endl;  
                    sleep(2);                 
                    if(ahp<0)
                    {
                    ahp=0;
                    }
                    if(ahp>0){
                    cout<<a.name<<" has "<<ahp<<" hp left."<<endl;
                    sleep(2);
                    }
                    else{
                        cout<<a.name<<" is dead."<<endl;
                        sleep(2);
                        break;
                    }
                    
                }
                else if(bf==0&&batk!=0) {
                    cout<<b.name<<" can't penetrate "<<a.name<<" defend."<<endl;
                    sleep(2);
                }
                aatk=a.sattack(b);
                bdef=b.ndefend();
                af=aatk-bdef;
                if(af<0){
                    af=0;
                }
                if(af>0&&aatk!=0)
                {
                    bhp-=af;
                    cout<<a.name<<" deals "<<af<<" damage."<<endl; 
                    sleep(2);                  
                    if(bhp<0)
                    {
                    bhp=0;
                    }
                    if(bhp>0){
                    cout<<b.name<<" has "<<bhp<<" left."<<endl;
                    sleep(2);
                    }
                    else{
                        cout<<b.name<<" is dead."<<endl;
                        sleep(2);
                        break;
                    }
                    
                }
                  else if(af==0&&aatk!=0) {
                    cout<<a.name<<" can't penetrate "<<b.name<<" defend."<<endl;
                    sleep(2);
                }
            break;
            case 2:
                heal=b.gethp()/10;
                bhp+=heal;
                if(bhp>=b.gethp())
                {
                    bhp=b.gethp();
                }
                  if(bhp==b.gethp()){
                    cout<<b.name<<" heals."<<endl;
                    sleep(2);
                    cout<<b.name<<" now has a full HP."<<endl;
                    sleep(2);
                }
                else{
                cout<<b.name<<" heals 10 percent of its HP."<<endl;
                sleep(2);
                }
                aatk=a.sattack(b);
                bdef=b.ndefend();
                af=aatk-bdef;
                if(af<0){
                    af=0;
                }
                if(af>0&&aatk!=0)
                {
                    bhp-=af;
                    cout<<a.name<<" deals "<<af<<" damage."<<endl;  
                    sleep(2);                 
                    if(bhp<0)
                    {
                    bhp=0;
                    }
                    if(bhp>0){
                    cout<<b.name<<" has "<<bhp<<" left."<<endl;
                    sleep(2);
                    }
                    else{
                        cout<<b.name<<" is dead."<<endl;
                        sleep(2);
                        break;
                    }
                    
                }
                else if(af==0&&aatk!=0) {
                    cout<<a.name<<" can't penetrate "<<b.name<<" defend."<<endl;
                    sleep(2);
                }
            break;
            case 3:
                bdef=b.defend();
                aatk=a.sattack(b);
                af=aatk-bdef;
                if(af<0){
                    af=0;
                }
                if(af>0&&aatk!=0)
                {
                    bhp-=af;
                    cout<<a.name<<" deals "<<af<<" damage."<<endl;     
                    sleep(2);              
                    if(bhp<0)
                    {
                    bhp=0;
                    }
                    if(bhp>0){
                    cout<<b.name<<" has "<<bhp<<" left."<<endl;
                    sleep(2);
                    }
                    else{
                        cout<<b.name<<" is dead."<<endl;
                        sleep(2);
                        break;
                    }  
                }
                else if(af==0&&aatk!=0) {
                    cout<<a.name<<" can't penetrate "<<b.name<<" defend."<<endl;
                    sleep(2);
                }
                break;
        }
       }
       else{
        switch (bc){
            case 1:
                aatk=a.sattack(b);
                bdef=b.ndefend();
                af=aatk-bdef;
                if(af<0){
                    af=0;
                }
                if(af>0&&aatk!=0)
                {
                    bhp-=af;
                    cout<<a.name<<" deals "<<af<<" damage."<<endl; 
                    sleep(2);                  
                    if(bhp<0)
                    {
                    bhp=0;
                    }
                    if(bhp>0){
                    cout<<b.name<<" has "<<bhp<<" left."<<endl;
                    sleep(2);
                    }
                    else{
                        cout<<b.name<<" is dead."<<endl;
                        sleep(2);
                        break;
                    }
                }
                else if(af==0&&aatk!=0) {
                    cout<<a.name<<" can't penetrate "<<b.name<<" defend."<<endl;
                    sleep(2);
                }
                batk=b.nattack(a);
                adef=a.ndefend();
                bf=batk-adef;
                if(bf<0){
                    bf=0;
                }
                if(bf>0&&batk!=0)
                {
                    ahp-=bf;
                    cout<<b.name<<" deals "<<bf<<" damage."<<endl;    
                    sleep(2);               
                    if(ahp<0)
                    {
                    ahp=0;
                    }
                    if(ahp>0){
                    cout<<a.name<<" has "<<ahp<<" hp left."<<endl;
                    sleep(2);
                    }
                    else{
                        cout<<a.name<<" is dead."<<endl;
                        sleep(2);
                        break;
                    }
                    
                }
                else if(bf==0&&batk!=0) {
                    cout<<b.name<<" can't penetrate "<<a.name<<" defend."<<endl;
                    sleep(2);
                }
            break;
            case 2:
             aatk=a.sattack(b);
                bdef=b.ndefend();
                af=aatk-bdef;
                if(af<0){
                    af=0;
                }
                if(af>0&&aatk!=0)
                {
                    bhp-=af;
                    cout<<a.name<<" deals "<<af<<" damage."<<endl; 
                    sleep(2);                  
                    if(bhp<0)
                    {
                    bhp=0;
                    }
                    if(bhp>0){
                    cout<<b.name<<" has "<<bhp<<" left."<<endl;
                    sleep(2);
                    }
                    else{
                        cout<<b.name<<" is dead."<<endl;
                        sleep(2);
                        break;
                    }
                }
                else if(af==0&&aatk!=0) {
                    cout<<a.name<<" can't penetrate "<<b.name<<" defend."<<endl;
                    sleep(2);
                }
                heal=b.gethp()/10;
                bhp+=heal;
                if(bhp>=b.gethp())
                {
                    bhp=b.gethp();
                }
                  if(bhp==b.gethp()){
                    cout<<b.name<<" heals."<<endl;
                    sleep(2);
                    cout<<b.name<<" now has a full HP."<<endl;
                    sleep(2);
                }
                else{
                cout<<b.name<<" heals 10 percent of its HP."<<endl;
                sleep(2);
                }
                break;
            case 3:   
                aatk=a.sattack(b);
                bdef=b.defend();
                af=aatk-bdef;
                if(af<0){
                    af=0;
                }
                if(af>0&&aatk!=0)
                {
                    bhp-=af;
                    cout<<a.name<<" deals "<<af<<" damage."<<endl;  
                    sleep(2);                 
                    if(bhp<0)
                    {
                    bhp=0;
                    }
                    if(bhp>0){
                    cout<<b.name<<" has "<<bhp<<" left."<<endl;
                    sleep(2);
                    }
                    else{
                        cout<<b.name<<" is dead."<<endl;
                        sleep(2);
                        break;
                    }  
                }
                else if(af==0&&aatk!=0) {
                    cout<<a.name<<" can't penetrate "<<b.name<<" defend."<<endl;
                    sleep(2);
                }
                break;
       }

       }
    }
    break;
    case 3:
    if(ea==0)
    {
        cout<<name<<" has not enough energy!"<<endl;
        sleep(2);
        ea-=2;
        break;
    }
    else{
       
    if(bspd>aspd){
            switch (bc)
            {
            case 1:
                batk=b.nattack(a);
                adef=a.ndefend();
                bf=batk-adef;
                if(bf<0){
                    bf=0;
                }
                if(bf>0&&batk!=0)
                {
                    ahp-=bf;
                    cout<<b.name<<" deals "<<bf<<" damage."<<endl;   
                    sleep(2);                
                    if(ahp<0)
                    {
                    ahp=0;
                    }
                    if(ahp>0){
                    cout<<a.name<<" has "<<ahp<<" hp left."<<endl;
                    sleep(2);
                    }
                    else{
                        cout<<a.name<<" is dead."<<endl;
                        sleep(2);
                        break;
                    }
                    
                }
                else if(bf==0&&batk!=0) {
                    cout<<b.name<<" can't penetrate "<<a.name<<" defend."<<endl;
                    sleep(2);
                }
                aatk=a.cattack(b,ea); 
                 ea-=ea;
                bdef=b.ndefend();
                af=aatk-bdef;
                if(af<0){
                    af=0;
                }
                if(af>0&&aatk!=0)
                {
                    bhp-=af;
                    cout<<a.name<<" deals "<<af<<" damage."<<endl;  
                    sleep(2);                 
                    if(bhp<0)
                    {
                    bhp=0;
                    }
                    if(bhp>0){
                    cout<<b.name<<" has "<<bhp<<" left."<<endl;
                    sleep(2);
                    }
                    else{
                        cout<<b.name<<" is dead."<<endl;
                        sleep(2);
                        break;
                    }
                    
                }
                  else if(af==0&&aatk!=0) {
                    cout<<a.name<<" can't penetrate "<<b.name<<" defend."<<endl;
                    sleep(2);
                }
            break;
            case 2:
                heal=b.gethp()/10;
                bhp+=heal;
                if(bhp>=b.gethp())
                {
                    bhp=b.gethp();
                }
                  if(bhp==b.gethp()){
                    cout<<b.name<<" heals."<<endl;
                    sleep(2);
                    cout<<b.name<<" now has a full HP."<<endl;
                    sleep(2);
                }
                else{
                cout<<b.name<<" heals 10 percent of its HP."<<endl;
                sleep(2);
                }
                aatk=a.cattack(b,ea);
                 ea-=ea;
                bdef=b.ndefend();
                af=aatk-bdef;
                if(af<0){
                    af=0;
                }
                if(af>0&&aatk!=0)
                {
                    bhp-=af;
                    cout<<a.name<<" deals "<<af<<" damage."<<endl;   
                    sleep(2);                

                    if(bhp<0)
                    {
                    bhp=0;
                    }
                    if(bhp>0){
                    cout<<b.name<<" has "<<bhp<<" left."<<endl;
                    sleep(2);
                    }
                    else{
                        cout<<b.name<<" is dead."<<endl;
                        sleep(2);
                        break;
                    }
                    
                }
                else if(af==0&&aatk!=0) {
                    cout<<a.name<<" can't penetrate "<<b.name<<" defend."<<endl;
                    sleep(2);
                }
            break;
            case 3:
                bdef=b.defend();
                aatk=a.cattack(b,ea);
                 ea-=ea;
                af=aatk-bdef;
                if(af<0){
                    af=0;
                }
                if(af>0&&aatk!=0)
                {
                    bhp-=af;
                    cout<<a.name<<" deals "<<af<<" damage."<<endl; 
                    sleep(2);                  
                    if(bhp<0)
                    {
                    bhp=0;
                    }
                    if(bhp>0){
                    cout<<b.name<<" has "<<bhp<<" left."<<endl;
                    sleep(2);
                    }
                    else{
                        cout<<b.name<<" is dead."<<endl;
                        sleep(2);
                        break;
                    }  
                }
                else if(af==0&&aatk!=0) {
                    cout<<a.name<<" can't penetrate "<<b.name<<" defend."<<endl;
                    sleep(2);
                }
                break;
        }
       }
       else{
        switch (bc){
            case 1:
                aatk=a.cattack(b,ea);
                 ea-=ea;
                bdef=b.ndefend();
                af=aatk-bdef;
                if(af<0){
                    af=0;
                }
                if(af>0&&aatk!=0)
                {
                    bhp-=af;
                    cout<<a.name<<" deals "<<af<<" damage."<<endl; 
                    sleep(2);                  
                    if(bhp<0)
                    {
                    bhp=0;
                    }
                    if(bhp>0){
                    cout<<b.name<<" has "<<bhp<<" left."<<endl;
                    sleep(2);
                    }
                    else{
                        cout<<b.name<<" is dead."<<endl;
                        sleep(2);
                        break;
                    }
                }
                else if(af==0&&aatk!=0) {
                    cout<<a.name<<" can't penetrate "<<b.name<<" defend."<<endl;
                    sleep(2);
                }
                batk=b.nattack(a);
                adef=a.ndefend();
                bf=batk-adef;
                if(bf<0){
                    bf=0;
                }
                if(bf>0&&batk!=0)
                {
                    ahp-=bf;
                    cout<<b.name<<" deals "<<bf<<" damage."<<endl;  
                    sleep(2);                 
                    if(ahp<0)
                    {
                    ahp=0;
                    }
                    if(ahp>0){
                    cout<<a.name<<" has "<<ahp<<" hp left."<<endl;
                    sleep(2);
                    }
                    else{
                        cout<<a.name<<" is dead."<<endl;
                        sleep(2);
                        break;
                    }
                    
                }
                else if(bf==0&&batk!=0) {
                    cout<<b.name<<" can't penetrate "<<a.name<<" defend."<<endl;
                    sleep(2);
                }
            break;
            case 2:
             aatk=a.cattack(b,ea);
              ea-=ea;
                bdef=b.ndefend();
                af=aatk-bdef;
                if(af<0){
                    af=0;
                }
                if(af>0&&aatk!=0)
                {
                    bhp-=af;
                    cout<<a.name<<" deals "<<af<<" damage."<<endl;
                    sleep(2);                   
                    if(bhp<0)
                    {
                    bhp=0;;
                    }
                    if(bhp>0){
                    cout<<b.name<<" has "<<bhp<<" left."<<endl;
                    sleep(2);
                    }
                    else{
                        cout<<b.name<<" is dead."<<endl;
                        sleep(2);
                        break;
                    }
                }
                else if(af==0&&aatk!=0) {
                    cout<<a.name<<" can't penetrate "<<b.name<<" defend."<<endl;
                    sleep(2);
                }
                heal=b.gethp()/10;
                bhp+=heal;
                if(bhp>=b.gethp())
                {
                    bhp=b.gethp();
                }
                cout<<b.name<<" heals 10 percent of its HP."<<endl;
                sleep(2);
                break;
            case 3:   
                aatk=a.cattack(b,ea);
                 ea-=ea;
                bdef=b.defend();
                af=aatk-bdef;
                if(af<0){
                    af=0;
                }
                if(af>0&&aatk!=0)
                {
                    bhp-=af;
                    cout<<a.name<<" deals "<<af<<" damage."<<endl;
                    sleep(2);                   
                    if(bhp<0)
                    {
                    bhp=0;
                    }
                    if(bhp>0){
                    cout<<b.name<<" has "<<bhp<<" left."<<endl;
                    sleep(2);
                    }
                    else{
                        cout<<b.name<<" is dead."<<endl;
                        sleep(2);
                        break;
                    }  
                }
                else if(af==0&&aatk!=0) {
                    cout<<a.name<<" can't penetrate "<<b.name<<" defend."<<endl;
                    sleep(2);
                }
                break;
       }

       }
    }
    break;
    case 4:
    if(ea<2)
    {
        cout<<name<<" has not enough energy!"<<endl;
        sleep(2);
        ea-=2;
        break;
    }
    else{
        ea-=2;
     if(bspd>aspd){
            switch (bc)
            {
            case 1:
                batk=b.nattack(a);
                adef=a.defend();
                bf=batk-adef;
                if(bf<0){
                    bf=0;
                }
                if(bf>0&&batk!=0)
                {
                    ahp-=bf;
                    cout<<b.name<<" deals "<<bf<<" damage."<<endl; 
                    sleep(2);                  
                    if(ahp<0)
                    {
                    ahp=0;
                    }
                    if(ahp>0){
                    cout<<a.name<<" has "<<ahp<<" hp left."<<endl;
                    sleep(2);
                    }
                    else{
                        cout<<a.name<<" is dead."<<endl;
                        sleep(2);
                        break;
                    }
                    
                }
                else if(bf==0&&batk!=0) {
                    cout<<b.name<<" can't penetrate "<<a.name<<" defend."<<endl;
                    sleep(2);
                }
                break;
            case 2:
            heal=b.gethp()/10;
                bhp+=heal;
                if(bhp>=b.gethp())
                {
                    bhp=b.gethp();
                }
                 if(bhp==b.gethp()){
                    cout<<b.name<<" heals."<<endl;
                    sleep(2);
                    cout<<b.name<<" now has a full HP."<<endl;
                    sleep(2);
                }
                else{
                cout<<b.name<<" heals 10 percent of its HP."<<endl;
                sleep(2);
                }
            adef=defend();
            break;
            case 3:
            bdef=b.defend();
            adef=a.defend();
            break;
        
            }
        }
        else{
            switch (bc)
            {
            case 1:
                adef=a.defend();
                batk=b.nattack(a);
                bf=batk-adef;
                if(bf<0){
                    bf=0;
                }
                if(bf>0&&batk!=0)
                {
                    ahp-=bf;
                    cout<<b.name<<" deals "<<bf<<" damage."<<endl;
                    sleep(2);                   
                    if(ahp<0)
                    {
                    ahp=0;
                    }
                    if(ahp>0){
                    cout<<a.name<<" has "<<ahp<<" hp left."<<endl;
                    sleep(2);
                    }
                    else{
                        cout<<a.name<<" is dead."<<endl;
                        sleep(2);
                        break;
                    }
                    
                }
                else if(bf==0&&batk!=0) {
                    cout<<b.name<<" can't penetrate "<<a.name<<" defend."<<endl;
                    sleep(2);
                }
                break;
            case 2:
            adef=defend();
            heal=b.gethp()/10;
                bhp+=heal;
                if(bhp>=b.gethp())
                {
                    bhp=b.gethp();
                }
                if(bhp==b.gethp()){
                    cout<<b.name<<" heals."<<endl;
                    sleep(2);
                    cout<<b.name<<" now has a full HP."<<endl;
                    sleep(2);
                }
                else{
                cout<<b.name<<" heals 10 percent of its HP."<<endl;
                sleep(2);
                }
                break;
            case 3:
            adef=a.defend();
            bdef=b.defend();
            break;
            }
        }
    }
    break;
    case 5:
    if(ea<2)
    {
        cout<<name<<" has not enough energy!"<<endl;
        sleep(2);
        ea-=2;
        break;
    }
    else{
        ea-=2;
    if(bspd>aspd){
            switch (bc)
            {
            case 1:
                batk=b.nattack(a);
                adef=a.ndefend();
                bf=batk-adef;
                if(bf<0){
                    bf=0;
                }
                if(bf>0&&batk!=0)
                {
                    ahp-=bf;
                    cout<<b.name<<" deals "<<bf<<" damage."<<endl;    
                    sleep(2);               
                    if(ahp<0)
                    {
                    ahp=0;
                    }
                    if(ahp>0){
                    cout<<a.name<<" has "<<ahp<<" hp left."<<endl;
                    sleep(2);
                    }
                    else{
                        cout<<a.name<<" is dead."<<endl;
                        sleep(2);
                        break;
                    }
                    
                }
                else if(bf==0&&batk!=0) {
                    cout<<b.name<<" can't penetrate "<<a.name<<" defend."<<endl;
                    sleep(2);
                }
                heal=a.gethp()/10;
                ahp+=heal;
                if(ahp>=a.gethp())
                {
                    ahp=a.gethp();
                }
                 if(ahp==a.gethp()){
                    cout<<a.name<<" heals."<<endl;
                    sleep(2);
                    cout<<a.name<<" now has a full HP."<<endl;
                    sleep(2);
                }
                else{
                cout<<a.name<<" heals 10 percent of its HP."<<endl;
                sleep(2);
                }
                break;
            case 2:
            heal=b.gethp()/10;
                bhp+=heal;
                if(bhp>=b.gethp())
                {
                    bhp=b.gethp();
                }
                if(bhp==b.gethp()){
                    cout<<b.name<<" heals."<<endl;
                    sleep(2);
                    cout<<b.name<<" now has a full HP."<<endl;
                    sleep(2);
                }
                else{
                cout<<b.name<<" heals 10 percent of its HP."<<endl;
                sleep(2);
                }
                heal=a.gethp()/10;
                ahp+=heal;
                if(ahp>=a.gethp())
                {
                    ahp=a.gethp();
                }
                 if(ahp==a.gethp()){
                    cout<<a.name<<" heals."<<endl;
                    sleep(2);
                    cout<<a.name<<" now has a full HP."<<endl;
                    sleep(2);
                }
                else{
                cout<<a.name<<" heals 10 percent of its HP."<<endl;
                sleep(2);
                }
                break;
            case 3:
            bdef=b.defend();
              heal=a.gethp()/10;
                ahp+=heal;
                if(ahp>=a.gethp())
                {
                    ahp=a.gethp();
                }
                 if(ahp==a.gethp()){
                    cout<<a.name<<" now has a full HP."<<endl;
                    sleep(2);
                }
                else{
                cout<<a.name<<" heals 10 percent of its HP."<<endl;
                sleep(2);
                }
                break;
            }

    }
    else{
        heal=a.gethp()/10;
                ahp+=heal;
                if(ahp>=a.gethp())
                {
                    ahp=a.gethp();
                }
                 if(ahp==a.gethp()){
                    cout<<a.name<<" heals."<<endl;
                    sleep(2);
                    cout<<a.name<<" now has a full HP."<<endl;
                    sleep(2);
                }
                else{
                cout<<a.name<<" heals 10 percent of its HP."<<endl;
                sleep(2);
                }
            switch (bc)
            {
            case 1:
                batk=b.nattack(a);
                adef=a.ndefend();
                bf=batk-adef;
                if(bf<0){
                    bf=0;
                }
                if(bf>0&&batk!=0)
                {
                    ahp-=bf;
                    cout<<b.name<<" deals "<<bf<<" damage."<<endl;  
                    sleep(2);                 
                    if(ahp<0)
                    {
                    ahp=0;
                    }
                    if(ahp>0){
                    cout<<a.name<<" has "<<ahp<<" hp left."<<endl;
                    sleep(2);
                    }
                    else{
                        cout<<a.name<<" is dead."<<endl;
                        sleep(2);
                        break;
                    }
                    
                }
                else if(bf==0&&batk!=0) {
                    cout<<b.name<<" can't penetrate "<<a.name<<" defend."<<endl;
                    sleep(2);
                }
            break;
            case 2:
            heal=b.gethp()/10;
                bhp+=heal;
                if(bhp>=b.gethp())
                {
                    bhp=b.gethp();
                }
                if(bhp==b.gethp()){
                    cout<<b.name<<" now has a full HP."<<endl;
                    sleep(2);
                }
                else{
                cout<<b.name<<" heals 10 percent of its HP."<<endl;
                sleep(2);
                }

            break;
            case 3:
            bdef=b.defend();
             
            }
    }
    }
    }

}while(ahp>0&&bhp>0);
    if(ahp>0)
    return 1;
    else 
    return 0;
 }
