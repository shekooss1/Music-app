#include <iostream>
#include <string>
#include <stack>
#include "playlist.h"
#include "musicApp.h"
#include "admin.h"
using namespace std ;
typedef node* position ;
typedef string s ;

    void admin::show_menu() {
    int choice;
    do {
        cout << "=== My Playlist ===";
        cout << "1. Add song"<<endl;
        cout << "2. Delete song"<<endl;
    cout << "3. Next song"<<endl;
        cout << "4. Previous song"<<endl;
        cout << "5. Show playlist"<<endl;
         cout << "0. Exit"<<endl;
        cout << "Choice: "<<endl;
        cin >> choice;

        if (choice == 1) {
              s song;
            string artist ;
            string genre ;
            int duration_seconds ;

            cout << "Enter song name: ";
            getline(cin >> ws, song);
           
            cout << "Enter artist name: ";
            getline(cin >> ws, artist);
           
            cout << "Enter genre : ";
            getline(cin >> ws, genre);
           
            cout << "Enter duration in seconds : ";
            cin >>  duration_seconds ;
           
          
            add_song(song, artist,genre,duration_seconds);     // calls MusicApp::add_song()
                                          // which calls playlist.insert_song()
        }
        else if (choice == 2) {
        string song;
            cout << "Song to delete: "; getline(std::cin >> std::ws, song);
            delete_song(song);           // calls MusicApp::delete_song()
                                          // which calls playlist.delete_song()
        }
        else if (choice == 3) play_next();         // MusicApp::play_next() → playlist.play_next()
        else if (choice == 4)  play_previous();     // MusicApp — same idea
        else if (choice == 5)  display_list(); // MusicApp::display_playlist() → playlist.display()
        
    } while (choice != 0);
}
