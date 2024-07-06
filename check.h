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
            a=0;
        return a;}
        else a=1;
    }
    return a;
}

int numin(){
    char* x;
    cin>>x;
    if(checknum(x)==0){
        cout<<"Please enter a proper number"<<endl;
        return 0;
    }
    else{
        return atoi(x);
    }
}

void pagebreak(){
    system ("clear"); //for mac use system("clear");
}