#define combat_h
#include <iostream>
using namespace std;
#include <time.h>
#include <stdlib.h>
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
    void level();
    int nattack(monster);
    int sattack(monster);
    int cattack(monster);
    void combat(monster a,monster b);
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
void monster::level(){
    int l=lvl,req=250;
    while(exp>=(req*lvl))
    lvl++;
upoint+=(lvl-l)*3;
}

 int gethp(){
    return hp;
 }
 int getsta(){
        return sta;
    }
    int getlvl(){
        return lvl;
    }
int getspd(){
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
                cout<<"Please choose number in the list.">>endl;
                continue;
            }
            else{
                switch (c){
                case 0:
                        break;
                
                case 1:
                    hp+=5
                
                case 2:
                    sta+=2
                
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
    int x =def*rand()%10+1;
    cout<<name<<" defends "<<x<<" damage."<<endl;
    return x;
}
int monster::defend(){
    int x =def*2
    cout<<name<<"use protection for "<<x<<" damage."<<endl;
    return x;
}
monster::~monster()
{
    cout<<name<<" is dead."<<endl;
}
void monster::describe(){

    
}
void monster::combat(monster a, monster b){
 int a.hp=a.gethp(),a.sta=a.getsta(),a.lvl=a.getlvl(),a.getspd(),b.hp=b.gethp(),b.lvl=b.getlvl(),b.spd=b.getspd();
    int ea=a.sta/2, c;
    int turn=0;
do{
    if(turn>0){
        ea+=2;
        if(ea>=a.sta){
            ea=a.sta;
        }
    }
    turn++;
    int bc=rand()%3+1;
    int a.atk=0,a.def,b.atk=0,b.def,af,bf;
    cout<<"----------------------------------"<<endl;
    cout<<a.name<<endl;
    cout<<"HP: "<<a.hp<<"  Level: "<<a.lvl<<"  Speed: "<<a.spd<<endl;
    cout<<"Energy: "<<ea<<endl;
    cout<<"----------------------------------"<<endl;
    cout<<b.name<<endl;
    cout<<"HP: "<<b.hp<<"  Level: "<<b.lvl<<"  Speed: "<<b.spd<<endl;
    cout<<"----------------------------------"<<endl;
    cout<<"Choose the action: "<<endl;
    cout<<"1.Normal Attack"<<endl;
    cout<<"2.Super Attack"<<endl;
    cout<<"3.Charge Attack"<<endl;
    cout<<"4.Protect"<<endl;
    cout<<"5.Restore"<<endl;
    do{
    c=numin();
    if(c<1||c<5)
    {
        cout<<"Please choose action on the list"<<endl;
    }
    }while(c<1||c>5);
    switch c
    case 1:
        if(b.spd>a.spd){
            switch (bc)
            {
            case 1:
                b.atk=b.nattack();
                a.def=a.ndefend();
                bf=b.atk-a.def;
                if(bf<0){
                    bf=0;
                }
                if(bf>0&&b.atk!=0)
                {
                    a.hp-=bf;
                    cout<<b.name<<" deals "<<bf<<" damage."<<endl;                   
                    if(a.hp<0)
                    {
                    a.hp=0
                    }
                    if(a.hp>0){
                    cout<<a.name<<" has "<<a.hp<<" left."<<endl;
                    }
                    else{
                        cout<<a.name<<" is dead."<<endl;
                        break;
                    }
                    
                }
                else if(bf==0&&b.atk!=0) {
                    cout<<b.name<<" can't penetrate "<<a.name<<" defend."<<endl;
                }
                a.atk=a.nattack();
                b.def=b.ndefend();
                af=a.atk-b.def;
                if(af<0){
                    af=0;
                }
                if(af>0&&a.atk!=0)
                {
                    b.hp-=af;
                    cout<<a.name<<" deals "<<af<<" damage."<<endl;                   
                    if(b.hp<0)
                    {
                    b.hp=0
                    }
                    if(b.hp>0){
                    cout<<a.name<<" has "<<b.hp<<" left."<<endl;
                    }
                    else{
                        cout<<b.name<<" is dead."<<endl;
                        break;
                    }
                    
                }
                  else if(af==0&&a.atk!=0) {
                    cout<<a.name<<" can't penetrate "<<b.name<<" defend."<<endl;
                }
            
            case 2:
                int heal=b.gethp()/10;
                b.hp+=heal;
                if(b.hp>=b.gethp())
                {
                    b.hp=b.gethp();
                }
                cout<<b.name<<" heals 10 percent of its HP."<<endl;
                a.atk=a.nattack();
                b.def=b.ndefend();
                af=a.atk-b.def;
                if(af<0){
                    af=0;
                }
                if(af>0&&a.atk!=0)
                {
                    b.hp-=af;
                    cout<<a.name<<" deals "<<af<<" damage."<<endl;                   
                    if(b.hp<0)
                    {
                    b.hp=0
                    }
                    if(b.hp>0){
                    cout<<a.name<<" has "<<b.hp<<" left."<<endl;
                    }
                    else{
                        cout<<b.name<<" is dead."<<endl;
                        break;
                    }
                    
                }
                else if(af==0&&a.atk!=0) {
                    cout<<a.name<<" can't penetrate "<<b.name<<" defend."<<endl;
                }
            
            case 3:
                b.def=b.defend();
                a.atk=a.nattack();
                af=a.atk-b.def;
                if(af<0){
                    af=0;
                }
                if(af>0&&a.atk!=0)
                {
                    b.hp-=af;
                    cout<<a.name<<" deals "<<af<<" damage."<<endl;                   
                    if(b.hp<0)
                    {
                    b.hp=0
                    }
                    if(b.hp>0){
                    cout<<a.name<<" has "<<b.hp<<" left."<<endl;
                    }
                    else{
                        cout<<b.name<<" is dead."<<endl;
                        break;
                    }  
                }
                else if(af==0&&a.atk!=0) {
                    cout<<a.name<<" can't penetrate "<<b.name<<" defend."<<endl;
                }
        }
       }
       else{
        switch (bc){
            case 1:
                a.atk=a.nattack();
                b.def=b.ndefend();
                af=a.atk-b.def;
                if(af<0){
                    af=0;
                }
                if(af>0&&a.atk!=0)
                {
                    b.hp-=af;
                    cout<<a.name<<" deals "<<af<<" damage."<<endl;                   
                    if(b.hp<0)
                    {
                    b.hp=0
                    }
                    if(b.hp>0){
                    cout<<a.name<<" has "<<b.hp<<" left."<<endl;
                    }
                    else{
                        cout<<b.name<<" is dead."<<endl;
                        break;
                    }
                }
                else if(af==0&&a.atk!=0) {
                    cout<<a.name<<" can't penetrate "<<b.name<<" defend."<<endl;
                }
                b.atk=b.nattack();
                a.def=a.ndefend();
                bf=b.atk-a.def;
                if(bf<0){
                    bf=0;
                }
                if(bf>0&&b.atk!=0)
                {
                    a.hp-=bf;
                    cout<<b.name<<" deals "<<bf<<" damage."<<endl;                   
                    if(a.hp<0)
                    {
                    a.hp=0
                    }
                    if(a.hp>0){
                    cout<<a.name<<" has "<<a.hp<<" left."<<endl;
                    }
                    else{
                        cout<<a.name<<" is dead."<<endl;
                        break;
                    }
                    
                }
                else if(bf==0&&b.atk!=0) {
                    cout<<b.name<<" can't penetrate "<<a.name<<" defend."<<endl;
                }

            case 2:
             a.atk=a.nattack();
                b.def=b.ndefend();
                af=a.atk-b.def;
                if(af<0){
                    af=0;
                }
                if(af>0&&a.atk!=0)
                {
                    b.hp-=af;
                    cout<<a.name<<" deals "<<af<<" damage."<<endl;                   
                    if(b.hp<0)
                    {
                    b.hp=0
                    }
                    if(b.hp>0){
                    cout<<a.name<<" has "<<b.hp<<" left."<<endl;
                    }
                    else{
                        cout<<b.name<<" is dead."<<endl;
                        break;
                    }
                }
                else if(af==0&&a.atk!=0) {
                    cout<<a.name<<" can't penetrate "<<b.name<<" defend."<<endl;
                }
                int heal=b.gethp()/10;
                b.hp+=heal;
                if(b.hp>=b.gethp())
                {
                    b.hp=b.gethp();
                }
                cout<<b.name<<" heals 10 percent of its HP."<<endl;
            case 3:   
                a.atk=a.nattack();
                b.def=b.defend();
                af=a.atk-b.def;
                if(af<0){
                    af=0;
                }
                if(af>0&&a.atk!=0)
                {
                    b.hp-=af;
                    cout<<a.name<<" deals "<<af<<" damage."<<endl;                   
                    if(b.hp<0)
                    {
                    b.hp=0
                    }
                    if(b.hp>0){
                    cout<<a.name<<" has "<<b.hp<<" left."<<endl;
                    }
                    else{
                        cout<<b.name<<" is dead."<<endl;
                        break;
                    }  
                }
                else if(af==0&&a.atk!=0) {
                    cout<<a.name<<" can't penetrate "<<b.name<<" defend."<<endl;
                }
       }

       } 
    case 2:
    if(b.spd>a.spd){
            switch (bc)
            {
            case 1:
                b.atk=b.nattack();
                a.def=a.ndefend();
                bf=b.atk-a.def;
                if(bf<0){
                    bf=0;
                }
                if(bf>0&&b.atk!=0)
                {
                    a.hp-=bf;
                    cout<<b.name<<" deals "<<bf<<" damage."<<endl;                   
                    if(a.hp<0)
                    {
                    a.hp=0
                    }
                    if(a.hp>0){
                    cout<<a.name<<" has "<<a.hp<<" left."<<endl;
                    }
                    else{
                        cout<<a.name<<" is dead."<<endl;
                        break;
                    }
                    
                }
                else if(bf==0&&b.atk!=0) {
                    cout<<b.name<<" can't penetrate "<<a.name<<" defend."<<endl;
                }
                a.atk=a.sattack();
                b.def=b.ndefend();
                af=a.atk-b.def;
                if(af<0){
                    af=0;
                }
                if(af>0&&a.atk!=0)
                {
                    b.hp-=af;
                    cout<<a.name<<" deals "<<af<<" damage."<<endl;                   
                    if(b.hp<0)
                    {
                    b.hp=0
                    }
                    if(b.hp>0){
                    cout<<a.name<<" has "<<b.hp<<" left."<<endl;
                    }
                    else{
                        cout<<b.name<<" is dead."<<endl;
                        break;
                    }
                    
                }
                  else if(af==0&&a.atk!=0) {
                    cout<<a.name<<" can't penetrate "<<b.name<<" defend."<<endl;
                }
            
            case 2:
                int heal=b.gethp()/10;
                b.hp+=heal;
                if(b.hp>=b.gethp())
                {
                    b.hp=b.gethp();
                }
                cout<<b.name<<" heals 10 percent of its HP."<<endl;
                a.atk=a.sattack();
                b.def=b.ndefend();
                af=a.atk-b.def;
                if(af<0){
                    af=0;
                }
                if(af>0&&a.atk!=0)
                {
                    b.hp-=af;
                    cout<<a.name<<" deals "<<af<<" damage."<<endl;                   
                    if(b.hp<0)
                    {
                    b.hp=0
                    }
                    if(b.hp>0){
                    cout<<a.name<<" has "<<b.hp<<" left."<<endl;
                    }
                    else{
                        cout<<b.name<<" is dead."<<endl;
                        break;
                    }
                    
                }
                else if(af==0&&a.atk!=0) {
                    cout<<a.name<<" can't penetrate "<<b.name<<" defend."<<endl;
                }
            
            case 3:
                b.def=b.defend();
                a.atk=a.sattack();
                af=a.atk-b.def;
                if(af<0){
                    af=0;
                }
                if(af>0&&a.atk!=0)
                {
                    b.hp-=af;
                    cout<<a.name<<" deals "<<af<<" damage."<<endl;                   
                    if(b.hp<0)
                    {
                    b.hp=0
                    }
                    if(b.hp>0){
                    cout<<a.name<<" has "<<b.hp<<" left."<<endl;
                    }
                    else{
                        cout<<b.name<<" is dead."<<endl;
                        break;
                    }  
                }
                else if(af==0&&a.atk!=0) {
                    cout<<a.name<<" can't penetrate "<<b.name<<" defend."<<endl;
                }
        }
       }
       else{
        switch (bc){
            case 1:
                a.atk=a.sattack();
                b.def=b.ndefend();
                af=a.atk-b.def;
                if(af<0){
                    af=0;
                }
                if(af>0&&a.atk!=0)
                {
                    b.hp-=af;
                    cout<<a.name<<" deals "<<af<<" damage."<<endl;                   
                    if(b.hp<0)
                    {
                    b.hp=0
                    }
                    if(b.hp>0){
                    cout<<a.name<<" has "<<b.hp<<" left."<<endl;
                    }
                    else{
                        cout<<b.name<<" is dead."<<endl;
                        break;
                    }
                }
                else if(af==0&&a.atk!=0) {
                    cout<<a.name<<" can't penetrate "<<b.name<<" defend."<<endl;
                }
                b.atk=b.nattack();
                a.def=a.ndefend();
                bf=b.atk-a.def;
                if(bf<0){
                    bf=0;
                }
                if(bf>0&&b.atk!=0)
                {
                    a.hp-=bf;
                    cout<<b.name<<" deals "<<bf<<" damage."<<endl;                   
                    if(a.hp<0)
                    {
                    a.hp=0
                    }
                    if(a.hp>0){
                    cout<<a.name<<" has "<<a.hp<<" left."<<endl;
                    }
                    else{
                        cout<<a.name<<" is dead."<<endl;
                        break;
                    }
                    
                }
                else if(bf==0&&b.atk!=0) {
                    cout<<b.name<<" can't penetrate "<<a.name<<" defend."<<endl;
                }

            case 2:
             a.atk=a.sattack();
                b.def=b.ndefend();
                af=a.atk-b.def;
                if(af<0){
                    af=0;
                }
                if(af>0&&a.atk!=0)
                {
                    b.hp-=af;
                    cout<<a.name<<" deals "<<af<<" damage."<<endl;                   
                    if(b.hp<0)
                    {
                    b.hp=0
                    }
                    if(b.hp>0){
                    cout<<a.name<<" has "<<b.hp<<" left."<<endl;
                    }
                    else{
                        cout<<b.name<<" is dead."<<endl;
                        break;
                    }
                }
                else if(af==0&&a.atk!=0) {
                    cout<<a.name<<" can't penetrate "<<b.name<<" defend."<<endl;
                }
                int heal=b.gethp()/10;
                b.hp+=heal;
                if(b.hp>=b.gethp())
                {
                    b.hp=b.gethp();
                }
                cout<<b.name<<" heals 10 percent of its HP."<<endl;
            case 3:   
                a.atk=a.sattack();
                b.def=b.defend();
                af=a.atk-b.def;
                if(af<0){
                    af=0;
                }
                if(af>0&&a.atk!=0)
                {
                    b.hp-=af;
                    cout<<a.name<<" deals "<<af<<" damage."<<endl;                   
                    if(b.hp<0)
                    {
                    b.hp=0
                    }
                    if(b.hp>0){
                    cout<<a.name<<" has "<<b.hp<<" left."<<endl;
                    }
                    else{
                        cout<<b.name<<" is dead."<<endl;
                        break;
                    }  
                }
                else if(af==0&&a.atk!=0) {
                    cout<<a.name<<" can't penetrate "<<b.name<<" defend."<<endl;
                }
       }

       }
    case 3:
    if(b.spd>a.spd){
            switch (bc)
            {
            case 1:
                b.atk=b.nattack();
                a.def=a.ndefend();
                bf=b.atk-a.def;
                if(bf<0){
                    bf=0;
                }
                if(bf>0&&b.atk!=0)
                {
                    a.hp-=bf;
                    cout<<b.name<<" deals "<<bf<<" damage."<<endl;                   
                    if(a.hp<0)
                    {
                    a.hp=0
                    }
                    if(a.hp>0){
                    cout<<a.name<<" has "<<a.hp<<" left."<<endl;
                    }
                    else{
                        cout<<a.name<<" is dead."<<endl;
                        break;
                    }
                    
                }
                else if(bf==0&&b.atk!=0) {
                    cout<<b.name<<" can't penetrate "<<a.name<<" defend."<<endl;
                }
                a.atk=a.cattack();
                b.def=b.ndefend();
                af=a.atk-b.def;
                if(af<0){
                    af=0;
                }
                if(af>0&&a.atk!=0)
                {
                    b.hp-=af;
                    cout<<a.name<<" deals "<<af<<" damage."<<endl;                   
                    if(b.hp<0)
                    {
                    b.hp=0
                    }
                    if(b.hp>0){
                    cout<<a.name<<" has "<<b.hp<<" left."<<endl;
                    }
                    else{
                        cout<<b.name<<" is dead."<<endl;
                        break;
                    }
                    
                }
                  else if(af==0&&a.atk!=0) {
                    cout<<a.name<<" can't penetrate "<<b.name<<" defend."<<endl;
                }
            
            case 2:
                int heal=b.gethp()/10;
                b.hp+=heal;
                if(b.hp>=b.gethp())
                {
                    b.hp=b.gethp();
                }
                cout<<b.name<<" heals 10 percent of its HP."<<endl;
                a.atk=a.cattack();
                b.def=b.ndefend();
                af=a.atk-b.def;
                if(af<0){
                    af=0;
                }
                if(af>0&&a.atk!=0)
                {
                    b.hp-=af;
                    cout<<a.name<<" deals "<<af<<" damage."<<endl;                   
                    if(b.hp<0)
                    {
                    b.hp=0
                    }
                    if(b.hp>0){
                    cout<<a.name<<" has "<<b.hp<<" left."<<endl;
                    }
                    else{
                        cout<<b.name<<" is dead."<<endl;
                        break;
                    }
                    
                }
                else if(af==0&&a.atk!=0) {
                    cout<<a.name<<" can't penetrate "<<b.name<<" defend."<<endl;
                }
            
            case 3:
                b.def=b.defend();
                a.atk=a.cattack();
                af=a.atk-b.def;
                if(af<0){
                    af=0;
                }
                if(af>0&&a.atk!=0)
                {
                    b.hp-=af;
                    cout<<a.name<<" deals "<<af<<" damage."<<endl;                   
                    if(b.hp<0)
                    {
                    b.hp=0
                    }
                    if(b.hp>0){
                    cout<<a.name<<" has "<<b.hp<<" left."<<endl;
                    }
                    else{
                        cout<<b.name<<" is dead."<<endl;
                        break;
                    }  
                }
                else if(af==0&&a.atk!=0) {
                    cout<<a.name<<" can't penetrate "<<b.name<<" defend."<<endl;
                }
        }
       }
       else{
        switch (bc){
            case 1:
                a.atk=a.cattack();
                b.def=b.ndefend();
                af=a.atk-b.def;
                if(af<0){
                    af=0;
                }
                if(af>0&&a.atk!=0)
                {
                    b.hp-=af;
                    cout<<a.name<<" deals "<<af<<" damage."<<endl;                   
                    if(b.hp<0)
                    {
                    b.hp=0
                    }
                    if(b.hp>0){
                    cout<<a.name<<" has "<<b.hp<<" left."<<endl;
                    }
                    else{
                        cout<<b.name<<" is dead."<<endl;
                        break;
                    }
                }
                else if(af==0&&a.atk!=0) {
                    cout<<a.name<<" can't penetrate "<<b.name<<" defend."<<endl;
                }
                b.atk=b.cattack();
                a.def=a.ndefend();
                bf=b.atk-a.def;
                if(bf<0){
                    bf=0;
                }
                if(bf>0&&b.atk!=0)
                {
                    a.hp-=bf;
                    cout<<b.name<<" deals "<<bf<<" damage."<<endl;                   
                    if(a.hp<0)
                    {
                    a.hp=0
                    }
                    if(a.hp>0){
                    cout<<a.name<<" has "<<a.hp<<" left."<<endl;
                    }
                    else{
                        cout<<a.name<<" is dead."<<endl;
                        break;
                    }
                    
                }
                else if(bf==0&&b.atk!=0) {
                    cout<<b.name<<" can't penetrate "<<a.name<<" defend."<<endl;
                }

            case 2:
             a.atk=a.cattack();
                b.def=b.ndefend();
                af=a.atk-b.def;
                if(af<0){
                    af=0;
                }
                if(af>0&&a.atk!=0)
                {
                    b.hp-=af;
                    cout<<a.name<<" deals "<<af<<" damage."<<endl;                   
                    if(b.hp<0)
                    {
                    b.hp=0
                    }
                    if(b.hp>0){
                    cout<<a.name<<" has "<<b.hp<<" left."<<endl;
                    }
                    else{
                        cout<<b.name<<" is dead."<<endl;
                        break;
                    }
                }
                else if(af==0&&a.atk!=0) {
                    cout<<a.name<<" can't penetrate "<<b.name<<" defend."<<endl;
                }
                int heal=b.gethp()/10;
                b.hp+=heal;
                if(b.hp>=b.gethp())
                {
                    b.hp=b.gethp();
                }
                cout<<b.name<<" heals 10 percent of its HP."<<endl;
            case 3:   
                a.atk=a.cattack();
                b.def=b.defend();
                af=a.atk-b.def;
                if(af<0){
                    af=0;
                }
                if(af>0&&a.atk!=0)
                {
                    b.hp-=af;
                    cout<<a.name<<" deals "<<af<<" damage."<<endl;                   
                    if(b.hp<0)
                    {
                    b.hp=0
                    }
                    if(b.hp>0){
                    cout<<a.name<<" has "<<b.hp<<" left."<<endl;
                    }
                    else{
                        cout<<b.name<<" is dead."<<endl;
                        break;
                    }  
                }
                else if(af==0&&a.atk!=0) {
                    cout<<a.name<<" can't penetrate "<<b.name<<" defend."<<endl;
                }
       }

       }


    

}while(a.hp>0&&b.hp>0);
}
