#define combat_h
#include <iostream>
using namespace std;
#include <time.h>
#include <stdlib.h>
#include <string.h>

class monster{
private:
    string name;
    int hp,atk,def,sta,spd,lvl=1,exp=0,upoint;
public:
    void statt();
    int gethp();
    int getsta();
    int getlvl();
    int getspd();
    void upgrade();
    void level(int x);
    int nattack(monster x);
    int sattack(monster x);
    int cattack(monster x,int s);
    void battle(monster a,monster b);
    int ndefend();
    int defend();
    void heal();
    monster(string,int = 20,int = 1,int = 1,int=10,int=1);
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
    cout<<name<<" is a monster"<<endl;
}
void monster::statt(){
    cout<<"Name: "<<name<<endl;
    cout<<"Level: "<<lvl<<endl;
    cout<<"HP: "<<hp<<endl;
    cout<<"Stamina: "<<sta<<endl;
    cout<<"Speed: "<<spd<<endl;
    cout<<"Attack: "<<atk<<endl;
    cout<<"Defense: "<<def<<endl;
}
void monster::level(int x){
    int l=lvl,req=250;
    exp+=x;
    while(exp>=(req*lvl)){
    exp-=(req*lvl);
    lvl++;
    }
upoint+=(lvl-l)*3;
}

 int monster::gethp(){
    return hp;
 }
 int monster::getsta(){
        return sta;
    }
    int monster::getlvl(){
        return lvl;
    }
int monster::getspd(){
    return spd;
}
void monster::upgrade(){
    int c;
    if(upoint<=0){
        cout<<"You don't have any upgrade point!!"<<endl;
    }
    else {
        while(upoint>0&&c!=0){
            cout<<"Upgrade Point: "<<upoint<<endl;
            cout<<"Stats lists:"<<endl;
            cout<<"1.HP: "<<hp<<endl;
            cout<<"2.Stamina: "<<sta<<endl;
            cout<<"3.Speed: "<<spd<<endl;
            cout<<"4.Attack: "<<atk<<endl;
            cout<<"5.Defense: "<<def<<endl;
            cout<<"0.Back"<<endl;
            cout<<"Choose stats to upgrade: ";
            c=numin();
            if(c<0||c>5){
                cout<<"Please choose number in the list."<<endl;
                continue;
            }
            else{
                switch (c){
                case 0:
                        break;
                
                case 1:
                    hp+=5;
                
                case 2:
                    sta+=2;
                
                case 3:
                    spd++;
                
                case 4:
                    atk++;
                
                case 5:
                    def++;
                
            }
            }
            
        }
    }
}
int monster::sattack(monster x){
    int p=rand()%4;
    if(p==0){
        cout<<name<<" miss the special attack."<<endl;
        return 0;
    }
    else if(p<3){
        cout<<name<<" attacks "<<x.name<<" "<<atk*3<<" damage."<<endl;
        return atk*3;
    }
    else{
        cout<<"Critical hit!!!"<<endl;
        cout<<name<<" attacks "<<x.name<<" "<<atk*5<<" damage."<<endl;
        return atk*5;
    }

}
int monster::nattack(monster x){
    int p=rand()%4;
    if(p==0){
        cout<<name<<" miss the attack."<<endl;
        return 0;
    }
    else if(p<3){
        cout<<name<<" attacks "<<x.name<<" "<<atk<<" damage."<<endl;
        return atk;
    }
    else{
       cout<<"Critical hit!!!"<<endl;
        cout<<name<<" attacks "<<x.name<<" "<<atk*2<<" damage."<<endl;
        return atk*2;
    }
}
int monster::cattack(monster x,int s){
    int p=rand()%4;
    if(p==0){
        cout<<name<<" miss the charge attack."<<endl;
        return 0;
    }
    else {
        cout<<name<<" attacks "<<x.name<<" "<<atk*s<<" damage."<<endl;
        return atk*s;
    }

}
int monster::ndefend(){
    int x =(def/10)*(rand()%10+1);
    cout<<name<<" defends "<<x<<" damage."<<endl;
    return x;
}
int monster::defend(){
    int x =def*2;
    cout<<name<<" use protection for "<<x<<" damage."<<endl;
    return x;
}
monster::~monster()
{
    //cout<<name<<" is dead."<<endl;
}

void monster::battle(monster a, monster b){
 int ahp=a.gethp(),asta=a.getsta(),alvl=a.getlvl(),aspd=a.getspd(),bhp=b.gethp(),blvl=b.getlvl(),bspd=b.getspd();
    int ea=asta/2, c;
    int turn=0;
    int heal;
do{
    if(turn>0){
        ea+=2;
        if(ea>=asta){
            ea=asta;
        }
    }
    turn++;
    int bc=rand()%3+1;
    int aatk=0,adef,batk=0,bdef,af,bf;
    cout<<"----------------------------------"<<endl;
    cout<<a.name<<endl;
    cout<<"HP: "<<ahp<<"  Level: "<<alvl<<"  Speed: "<<aspd<<endl;
    cout<<"Energy: "<<ea<<endl;
    cout<<"----------------------------------"<<endl;
    cout<<b.name<<endl;
    cout<<"HP: "<<bhp<<"  Level: "<<blvl<<"  Speed: "<<bspd<<endl;
    cout<<"----------------------------------"<<endl;
    cout<<"Choose the action: "<<endl;
    cout<<"1.Normal Attack"<<endl;
    cout<<"2.Super Attack"<<endl;
    cout<<"3.Charge Attack"<<endl;
    cout<<"4.Protect"<<endl;
    cout<<"5.Restore"<<endl;
    do{
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
                    if(ahp<0)
                    {
                    ahp=0;
                    }
                    if(ahp>0){
                    cout<<a.name<<" has "<<ahp<<" left."<<endl;
                    }
                    else{
                        cout<<a.name<<" is dead."<<endl;
                        break;
                    }
                    
                }
                else if(bf==0&&batk!=0) {
                    cout<<b.name<<" can't penetrate "<<a.name<<" defend."<<endl;
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
                    if(bhp<0)
                    {
                    bhp=0;
                    }
                    if(bhp>0){
                    cout<<b.name<<" has "<<bhp<<" left."<<endl;
                    }
                    else{
                        cout<<b.name<<" is dead."<<endl;
                        break;
                    }
                    
                }
                  else if(af==0&&aatk!=0) {
                    cout<<a.name<<" can't penetrate "<<b.name<<" defend."<<endl;
                }
            break;
            case 2:
                heal=b.gethp()/10;
                bhp+=heal;
                if(bhp>=b.gethp())
                {
                    bhp=b.gethp();
                }
                cout<<b.name<<" heals 10 percent of its HP."<<endl;
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
                    if(bhp<0)
                    {
                    bhp=0;
                    }
                    if(bhp>0){
                    cout<<b.name<<" has "<<bhp<<" left."<<endl;
                    }
                    else{
                        cout<<b.name<<" is dead."<<endl;
                        break;
                    }
                    
                }
                else if(af==0&&aatk!=0) {
                    cout<<a.name<<" can't penetrate "<<b.name<<" defend."<<endl;
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
                    if(bhp<0)
                    {
                    bhp=0;
                    }
                    if(bhp>0){
                    cout<<b.name<<" has "<<bhp<<" left."<<endl;
                    }
                    else{
                        cout<<b.name<<" is dead."<<endl;
                        break;
                    }  
                }
                else if(af==0&&aatk!=0) {
                    cout<<a.name<<" can't penetrate "<<b.name<<" defend."<<endl;
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
                    if(bhp<0)
                    {
                    bhp=0;
                    }
                    if(bhp>0){
                    cout<<b.name<<" has "<<bhp<<" left."<<endl;
                    }
                    else{
                        cout<<b.name<<" is dead."<<endl;
                        break;
                    }
                }
                else if(af==0&&aatk!=0) {
                    cout<<a.name<<" can't penetrate "<<b.name<<" defend."<<endl;
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
                    if(ahp<0)
                    {
                    ahp=0;
                    }
                    if(ahp>0){
                    cout<<a.name<<" has "<<ahp<<" left."<<endl;
                    }
                    else{
                        cout<<a.name<<" is dead."<<endl;
                        break;
                    }
                    
                }
                else if(bf==0&&batk!=0) {
                    cout<<b.name<<" can't penetrate "<<a.name<<" defend."<<endl;
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
                    if(bhp<0)
                    {
                    bhp=0;
                    }
                    if(bhp>0){
                    cout<<b.name<<" has "<<bhp<<" left."<<endl;
                    }
                    else{
                        cout<<b.name<<" is dead."<<endl;
                        break;
                    }
                }
                else if(af==0&&aatk!=0) {
                    cout<<a.name<<" can't penetrate "<<b.name<<" defend."<<endl;
                }
                heal=b.gethp()/10;
                bhp+=heal;
                if(bhp>=b.gethp())
                {
                    bhp=b.gethp();
                }
                cout<<b.name<<" heals 10 percent of its HP."<<endl;
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
                    if(bhp<0)
                    {
                    bhp=0;
                    }
                    if(bhp>0){
                    cout<<b.name<<" has "<<bhp<<" left."<<endl;
                    }
                    else{
                        cout<<b.name<<" is dead."<<endl;
                        break;
                    }  
                }
                else if(af==0&&aatk!=0) {
                    cout<<a.name<<" can't penetrate "<<b.name<<" defend."<<endl;
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
                    if(ahp<0)
                    {
                    ahp=0;
                    }
                    if(ahp>0){
                    cout<<a.name<<" has "<<ahp<<" left."<<endl;
                    }
                    else{
                        cout<<a.name<<" is dead."<<endl;
                        break;
                    }
                    
                }
                else if(bf==0&&batk!=0) {
                    cout<<b.name<<" can't penetrate "<<a.name<<" defend."<<endl;
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
                    if(bhp<0)
                    {
                    bhp=0;
                    }
                    if(bhp>0){
                    cout<<b.name<<" has "<<bhp<<" left."<<endl;
                    }
                    else{
                        cout<<b.name<<" is dead."<<endl;
                        break;
                    }
                    
                }
                  else if(af==0&&aatk!=0) {
                    cout<<a.name<<" can't penetrate "<<b.name<<" defend."<<endl;
                }
            break;
            case 2:
                heal=b.gethp()/10;
                bhp+=heal;
                if(bhp>=b.gethp())
                {
                    bhp=b.gethp();
                }
                cout<<b.name<<" heals 10 percent of its HP."<<endl;
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
                    if(bhp<0)
                    {
                    bhp=0;
                    }
                    if(bhp>0){
                    cout<<b.name<<" has "<<bhp<<" left."<<endl;
                    }
                    else{
                        cout<<b.name<<" is dead."<<endl;
                        break;
                    }
                    
                }
                else if(af==0&&aatk!=0) {
                    cout<<a.name<<" can't penetrate "<<b.name<<" defend."<<endl;
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
                    if(bhp<0)
                    {
                    bhp=0;
                    }
                    if(bhp>0){
                    cout<<b.name<<" has "<<bhp<<" left."<<endl;
                    }
                    else{
                        cout<<b.name<<" is dead."<<endl;
                        break;
                    }  
                }
                else if(af==0&&aatk!=0) {
                    cout<<a.name<<" can't penetrate "<<b.name<<" defend."<<endl;
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
                    if(bhp<0)
                    {
                    bhp=0;
                    }
                    if(bhp>0){
                    cout<<b.name<<" has "<<bhp<<" left."<<endl;
                    }
                    else{
                        cout<<b.name<<" is dead."<<endl;
                        break;
                    }
                }
                else if(af==0&&aatk!=0) {
                    cout<<a.name<<" can't penetrate "<<b.name<<" defend."<<endl;
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
                    if(ahp<0)
                    {
                    ahp=0;
                    }
                    if(ahp>0){
                    cout<<a.name<<" has "<<ahp<<" left."<<endl;
                    }
                    else{
                        cout<<a.name<<" is dead."<<endl;
                        break;
                    }
                    
                }
                else if(bf==0&&batk!=0) {
                    cout<<b.name<<" can't penetrate "<<a.name<<" defend."<<endl;
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
                    if(bhp<0)
                    {
                    bhp=0;
                    }
                    if(bhp>0){
                    cout<<b.name<<" has "<<bhp<<" left."<<endl;
                    }
                    else{
                        cout<<b.name<<" is dead."<<endl;
                        break;
                    }
                }
                else if(af==0&&aatk!=0) {
                    cout<<a.name<<" can't penetrate "<<b.name<<" defend."<<endl;
                }
                heal=b.gethp()/10;
                bhp+=heal;
                if(bhp>=b.gethp())
                {
                    bhp=b.gethp();
                }
                cout<<b.name<<" heals 10 percent of its HP."<<endl;
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
                    if(bhp<0)
                    {
                    bhp=0;
                    }
                    if(bhp>0){
                    cout<<b.name<<" has "<<bhp<<" left."<<endl;
                    }
                    else{
                        cout<<b.name<<" is dead."<<endl;
                        break;
                    }  
                }
                else if(af==0&&aatk!=0) {
                    cout<<a.name<<" can't penetrate "<<b.name<<" defend."<<endl;
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
                    if(ahp<0)
                    {
                    ahp=0;
                    }
                    if(ahp>0){
                    cout<<a.name<<" has "<<ahp<<" left."<<endl;
                    }
                    else{
                        cout<<a.name<<" is dead."<<endl;
                        break;
                    }
                    
                }
                else if(bf==0&&batk!=0) {
                    cout<<b.name<<" can't penetrate "<<a.name<<" defend."<<endl;
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
                    if(bhp<0)
                    {
                    bhp=0;
                    }
                    if(bhp>0){
                    cout<<b.name<<" has "<<bhp<<" left."<<endl;
                    }
                    else{
                        cout<<b.name<<" is dead."<<endl;
                        break;
                    }
                    
                }
                  else if(af==0&&aatk!=0) {
                    cout<<a.name<<" can't penetrate "<<b.name<<" defend."<<endl;
                }
            break;
            case 2:
                heal=b.gethp()/10;
                bhp+=heal;
                if(bhp>=b.gethp())
                {
                    bhp=b.gethp();
                }
                cout<<b.name<<" heals 10 percent of its HP."<<endl;
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
                    if(bhp<0)
                    {
                    bhp=0;
                    }
                    if(bhp>0){
                    cout<<b.name<<" has "<<bhp<<" left."<<endl;
                    }
                    else{
                        cout<<b.name<<" is dead."<<endl;
                        break;
                    }
                    
                }
                else if(af==0&&aatk!=0) {
                    cout<<a.name<<" can't penetrate "<<b.name<<" defend."<<endl;
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
                    if(bhp<0)
                    {
                    bhp=0;
                    }
                    if(bhp>0){
                    cout<<b.name<<" has "<<bhp<<" left."<<endl;
                    }
                    else{
                        cout<<b.name<<" is dead."<<endl;
                        break;
                    }  
                }
                else if(af==0&&aatk!=0) {
                    cout<<a.name<<" can't penetrate "<<b.name<<" defend."<<endl;
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
                    if(bhp<0)
                    {
                    bhp=0;
                    }
                    if(bhp>0){
                    cout<<b.name<<" has "<<bhp<<" left."<<endl;
                    }
                    else{
                        cout<<b.name<<" is dead."<<endl;
                        break;
                    }
                }
                else if(af==0&&aatk!=0) {
                    cout<<a.name<<" can't penetrate "<<b.name<<" defend."<<endl;
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
                    if(ahp<0)
                    {
                    ahp=0;
                    }
                    if(ahp>0){
                    cout<<a.name<<" has "<<ahp<<" left."<<endl;
                    }
                    else{
                        cout<<a.name<<" is dead."<<endl;
                        break;
                    }
                    
                }
                else if(bf==0&&batk!=0) {
                    cout<<b.name<<" can't penetrate "<<a.name<<" defend."<<endl;
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
                    if(bhp<0)
                    {
                    bhp=0;;
                    }
                    if(bhp>0){
                    cout<<b.name<<" has "<<bhp<<" left."<<endl;
                    }
                    else{
                        cout<<b.name<<" is dead."<<endl;
                        break;
                    }
                }
                else if(af==0&&aatk!=0) {
                    cout<<a.name<<" can't penetrate "<<b.name<<" defend."<<endl;
                }
                heal=b.gethp()/10;
                bhp+=heal;
                if(bhp>=b.gethp())
                {
                    bhp=b.gethp();
                }
                cout<<b.name<<" heals 10 percent of its HP."<<endl;
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
                    if(bhp<0)
                    {
                    bhp=0;
                    }
                    if(bhp>0){
                    cout<<b.name<<" has "<<bhp<<" left."<<endl;
                    }
                    else{
                        cout<<b.name<<" is dead."<<endl;
                        break;
                    }  
                }
                else if(af==0&&aatk!=0) {
                    cout<<a.name<<" can't penetrate "<<b.name<<" defend."<<endl;
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
                    if(ahp<0)
                    {
                    ahp=0;
                    }
                    if(ahp>0){
                    cout<<a.name<<" has "<<ahp<<" left."<<endl;
                    }
                    else{
                        cout<<a.name<<" is dead."<<endl;
                        break;
                    }
                    
                }
                else if(bf==0&&batk!=0) {
                    cout<<b.name<<" can't penetrate "<<a.name<<" defend."<<endl;
                }
                break;
            case 2:
            heal=b.gethp()/10;
                bhp+=heal;
                if(bhp>=b.gethp())
                {
                    bhp=b.gethp();
                }
                cout<<b.name<<" heals 10 percent of its HP."<<endl;
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
                    if(ahp<0)
                    {
                    ahp=0;
                    }
                    if(ahp>0){
                    cout<<a.name<<" has "<<ahp<<" left."<<endl;
                    }
                    else{
                        cout<<a.name<<" is dead."<<endl;
                        break;
                    }
                    
                }
                else if(bf==0&&batk!=0) {
                    cout<<b.name<<" can't penetrate "<<a.name<<" defend."<<endl;
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
                cout<<b.name<<" heals 10 percent of its HP."<<endl;
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
                    if(ahp<0)
                    {
                    ahp=0;
                    }
                    if(ahp>0){
                    cout<<a.name<<" has "<<ahp<<" left."<<endl;
                    }
                    else{
                        cout<<a.name<<" is dead."<<endl;
                        break;
                    }
                    
                }
                else if(bf==0&&batk!=0) {
                    cout<<b.name<<" can't penetrate "<<a.name<<" defend."<<endl;
                }
                heal=a.gethp()/10;
                ahp+=heal;
                if(ahp>=a.gethp())
                {
                    ahp=a.gethp();
                }
                 if(ahp==a.gethp()){
                    cout<<a.name<<"now has a full HP."<<endl;
                }
                else{
                cout<<a.name<<" heals 10 percent of its HP."<<endl;
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
                    cout<<b.name<<"now has a full HP."<<endl;
                }
                else{
                cout<<b.name<<" heals 10 percent of its HP."<<endl;
                }
                heal=a.gethp()/10;
                ahp+=heal;
                if(ahp>=a.gethp())
                {
                    ahp=a.gethp();
                }
                 if(ahp==a.gethp()){
                    cout<<a.name<<"now has a full HP."<<endl;
                }
                else{
                cout<<a.name<<" heals 10 percent of its HP."<<endl;
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
                    cout<<a.name<<"now has a full HP."<<endl;
                }
                else{
                cout<<a.name<<" heals 10 percent of its HP."<<endl;
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
                    cout<<a.name<<"now has a full HP."<<endl;
                }
                else{
                cout<<a.name<<" heals 10 percent of its HP."<<endl;
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
                    if(ahp<0)
                    {
                    ahp=0;
                    }
                    if(ahp>0){
                    cout<<a.name<<" has "<<ahp<<" left."<<endl;
                    }
                    else{
                        cout<<a.name<<" is dead."<<endl;
                        break;
                    }
                    
                }
                else if(bf==0&&batk!=0) {
                    cout<<b.name<<" can't penetrate "<<a.name<<" defend."<<endl;
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
                    cout<<b.name<<"now has a full HP."<<endl;
                }
                else{
                cout<<b.name<<" heals 10 percent of its HP."<<endl;
                }

            break;
            case 3:
            bdef=b.defend();
             
            }
    }
    }
    }


    

}while(ahp>0&&bhp>0);
}
