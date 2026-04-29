#include <iostream>
#include <string>
#include <stack>
#include "playlist.h"
#include "musicApp.h"
#include "admin.h"
#include "user.h"
using namespace std ;
typedef node* position ;
typedef string s ;

int main(){
    srand(time(0));
    int role_choice ;

    cout<<"===== ROLE CHOICE =====";
    cout<<"1: Admin"<<endl;
    cout<<"2:User"<<endl;
cin>>role_choice ;
    musicApp* m = nullptr ;
    if(role_choice==1){
       s password ;
       cout<<"Enter password :"<<endl ;
       cin >> password ;
       if(password == "123"){ m = new admin() ;}
    else { cout<<"wrong password" ;}
    
}
else { m = new user() ;}

if (m != nullptr)
m->show_menu();

delete m ;
}