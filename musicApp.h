#pragma once
#include <iostream>
#include <string>
#include <stack>
#include "playlist.h"
using namespace std ;


class musicApp{
protected : 
Play_List p ;

        public :
    virtual void add_song(string song ,string artist ,string genre , int duration_seconds ){
    p.insert_song(song,artist,genre,duration_seconds);
            
}
virtual void delete_song(string song){ 
                   p.delete_song(song);  
}

    void play_next(){ p.play_next();}
    void play_previous(){ p.play_previous();}
    void  display_list(){ p.display_Play_List();}
virtual ~musicApp(){}
virtual void show_menu() = 0 ;
// in musicApp.h — add these
void shuffle()        { p.shuffle(); }
void loop_mood()      { p.loop_mood(); }
void play_history()   { p.play_history(); }
void play_by_name(string song) { p.Play_by_name(song); }
void show_current()   { p.show_current_song(); }
int  song_count()     { return p.number_of_songs(); }
};