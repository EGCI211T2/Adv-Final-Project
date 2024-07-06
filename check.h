#define check_h
using namespace std;
#include <iostream>
#include <string.h>


int checknum (char s[])
{
    int i,n,a;
    n=strlen(s);
    for (i=0; i<n; i++)
    {
        if(s[i]!='0'&&s[i]!='1'&&s[i]!='2'&&s[i]!='3'&&s[i]!='4'&&s[i]!='5'&&s[i]!='6'&&s[i]!='7'&&s[i]!='8'&&s[i]!='9'){
            return 0;
    }
    }
    return 1;

}

int numin(){
    char* x=new char[20];
    do{
    cin>>x;
    if(checknum(x)==0){
        cout<<"Please enter a proper number"<<endl;
    }
    }while(checknum(x)==0);
    
        return atoi(x);
}

void pagebreak(){
    system ("clear"); //for mac use system("clear");
}


   