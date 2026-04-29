#include <iostream>
#include <string>
#include <stack>
#include "playlist.h"
#include "musicApp.h"
#include "user.h"
using namespace std ;
typedef node* position ;
typedef string s ;


void user::show_menu() {
    int choice;
    do {
    cout << "\n==== Music Playlist ====\n";
        cout << "1. Add Song\n";
        cout << "2. Delete Song\n";
        cout << "3. Next Song\n";
        cout << "4. Previous Song\n";
        cout << "5. Shuffle Playlist\n";
        cout << "6. Display Playlist\n";
        cout << "7. Play by Name\n";
        cout << "8. Number of songs\n";
        cout << "9. Show current song\n";
        cout << "10. Shuffle Play 🔀\n";
        cout << "11. Repeat Play 🔁\n";
        cout << "12. Play History ⏮\n";
        cout << "0. Exit\n";
    cout << "Choice: ";
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
        else if (choice == 3)  play_next();         // MusicApp::play_next() → playlist.play_next()
        else if (choice == 4)  play_previous();     // MusicApp — same idea
        else if (choice == 5)  shuffle();  // directly on playlist object
        else if (choice == 6)  display_list(); // MusicApp::display_playlist() → playlist.display()
        else if (choice == 7) {
            s song;
            cout << "Enter song name: ";
            getline(cin >> ws, song);
            play_by_name(song);
        }
            else if (choice == 8)    cout << "Number of songs: " << song_count() << endl;
          else if (choice == 9)    show_current();
            else if (choice == 10)  shuffle();
        else if (choice == 11) loop_mood(); 
         else if (choice == 12)   play_history(); // ⏮
           
    } while (choice != 0);
        cout<<"Thank you for using app";   

}

