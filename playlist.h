#pragma once
#include <iostream>
#include <string>
#include <stack>
#include "struct.h"
using namespace std ;
typedef node* position ;
typedef string s ;
class Play_List{
    private :
    position head ;
    position tail ;
    position current;   
    stack<string> history;

    int counter ;

      public :
      Play_List(){ head = NULL ;
        tail = NULL ;
        current = NULL ;
        counter = 0 ;
     }

      void Clear_PlayList(){
        if (head == NULL) return;
        position p ;
        while(head != NULL){
            p = head ;
            head = head->next ;
            delete p ;
        }
        head = NULL ;
        tail = NULL ;
        current = NULL ;
        counter = 0 ;
      }
      void insert_song(s song , s artist , s genre , int duration ){
 position new_node = new node ;
    new_node->next=NULL ;
 new_node->pre = tail ;
new_node->song = song ;
new_node->artist = artist ;
new_node->genre = genre ;
new_node->duration_seconds = duration ;
new_node->play_count = 0;  
    
if(tail!=NULL)			
tail->next=new_node;
			tail=new_node;
if (head==NULL)head=tail;
			counter++;
        if (current == NULL) current = new_node;

        }

void play_next(){
    if (current == NULL) {
        cout<<"No song is playing" ;
    return ;
    }

    if (current->next == NULL){ 
        cout<<"This is last song" ; 
    return ;     
    }
if (current != NULL) history.push(current->song);

    current = current->next;
   increment_play_count(current) ; 
    cout<<"Now Playing :"<<current->song<<endl;

}
void play_previous(){

    if (current == NULL) {
        cout<<"No song is playing" ;
    return ;    
    }

    if (current == head){ 
        cout<<"This is first song" ; 
    return ; 
    }
if (current != NULL) history.push(current->song);

    current = current->pre;
        cout<<"Now Playing :"<<current->song<<endl;

    }
  void delete_song(s song) {
        position curr = Search(song);
        if (curr == NULL) return;

        // ✅ Move current away BEFORE deleting
        if (curr == current) {
            if (current->next != NULL)      current = current->next;
            else if (current->pre != NULL)  current = current->pre;
            else{                           
             current = NULL;   // playlist becomes empty
            }
            }

        if (curr == tail) tail = curr->pre;
        if (curr == head) head = curr->next;

        if (curr->next != NULL) curr->next->pre = curr->pre;
        if (curr->pre  != NULL) curr->pre->next = curr->next;

        delete curr;
        counter--;
        cout << song << " deleted"<<endl;

        if (current != NULL)
            cout << "Now playing: " << current->song << endl;
        else
            cout << "Playlist is now empty.\n";
    }
void display_Play_List(){
    position p = head ;

    if (p == NULL) {
        cout<<"Playlist is empty";
        return;
    }

    while(p != NULL){
      cout << p->song;
      cout << p->artist;
      cout << p->genre;
      cout << p->play_count ;
      if (p == current) cout << "  <== playing";
      cout << endl;
      p = p->next;
    }
}

position Search(s song){
    position p = head ;
  
    while( p  != nullptr){
        if(p->song == song) 
        {
        return p ;
    }
p = p->next ;    
}
return NULL ;
}

void Play_by_name(s song){
    position p = Search(song);
if(p != nullptr){
if (current != NULL) history.push(current->song);
    current = p ;
 increment_play_count(current) ; 
    cout<<"The song is now playing : " << p ->song ;
}
}
position first(){
    return head;
}
position end(){
    return tail;
}

bool isEmpty(){return counter == 0 ;}
int number_of_songs(){return counter ;}
void show_current_song() {
    if (current == NULL) { cout << "No song is currently playing.\n"; return; }
    cout << "Now playing: \"" << current->song << "\"\n";
}
void loop_mood(){
if (current == NULL) {cout<<"PlayList is Empty"<<endl ; return ;}
if(current->next == NULL){
if (current != NULL) history.push(current->song);
    current = head ;
cout << "Now playing: " << current->song << endl;
}
else{
    history.push(current->song);
    current = current->next ;
cout << "Now playing: " << current->song << endl;    
}
}
void shuffle(){
    if(isEmpty()) {cout<<"The play list is empty"; return ;}
    int index = rand() % counter ;
position p = head ;
for(int i = 0 ; i < index;i++){
    p=p->next ;
}
if (current != NULL) history.push(current->song);
current = p ;
increment_play_count(current) ; 
cout<<"Now playing : "<<current->song;

}

void play_history(){
if(history.empty()){cout<<"No song played"; return ;}

string last = history.top();
history.pop();
position p = Search(last);
if(p!=NULL){ current = p ;
cout<<"Now is playing : "<< current->song << endl ;
}
}

~Play_List(){
    Clear_PlayList();
    cout<<" Destroyed object" << endl ;
}
void increment_play_count(position p){
p->play_count ++ ;
}

void get_most_played() {
    if (head == NULL) { cout << "List is empty\n"; return; }
    position p = head;
    position best = head;           // track the best node, not just a number
    while (p != NULL) {
        if (p->play_count > best->play_count) best = p;
        p = p->next;
    }
    cout << "Most played: " << best->song << " (" << best->play_count << " plays)\n";
}

};
