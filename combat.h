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
    void charge();
    void upgrade();
    void level();
    void describe();
    int nattack(monster);
    int sattack(monster);
    int cattack(monster);
    void ndefend();
    void heal();
    bool alive();
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
                switch c
                case 0{
                        break;
                }
                case 1{
                    hp+=5
                }
                case 2{
                    sta+=2
                }
                case 3{
                    spd++;
                }
                case 4{
                    atk++;
                }
                case 5{
                    def++;
                }
            }

            
        }
    }
}
void monster::charge(){
    sta+=2;
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
bool monster::alive ()
{
    if (hp<=0) return false;
    else return true;

}
monster::~monster()
{
    cout<<name<<" is dead."<<endl;
}
void monster::describe(){

    
}
void combat(monster a, monster b){
do{
    int bc=rand()%3+1;
    int a.hp=a.gethp(),a.sta=a.getsta(),a.lvl=a.getlvl(),a.getspd(),b.hp=b.gethp(),b.lvl=b.getlvl(),b.spd=b.getspd();
    int ea=a.sta/2, c;
    int a.atk=0,a.def,b.atk=0,b.def;
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
    case 1{
        if(b.spd>a.spd&&bc!=3){
            
        }
        
    }


    

}while(a.alive()==1&&b.alive()==1);
}