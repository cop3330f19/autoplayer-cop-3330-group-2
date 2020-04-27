/* Group 2
 * Last Updated: 25 Apr 20 
 * COP 3330
 * Group Members:
 * Amani Muller
 * Eric Lampley
 * Zahir Cooper
 * Claressa Wilson 
 * */

#include "Song.h"
#include <iomanip>
#include <iostream>
#include <string>
#include "Playlist.h"
#include <fstream>
#include <vector>
#include "StringHelper.h"
#include <cstdlib>  
#include <algorithm>

using namespace std;

// Counts number of playlist in file
const int countLinesInFile(string filename);

// Adds song from file to song vector
void openPlaylistFile(string filename, vector<string> & v);

void writeNewPlaylistfile(string file, string playlist);

void eraseDuplicates(vector<string> &v);


// Static controlling playing mode
int Playlist::mode = 0;
int main()
{
    Song song;
    // checking if song is deleted
    bool check;
    
    // Playlist important info
    string title, artist, album, choice, choice2;
    int year, song_in_seconds;
    
    string newPlaylist;

    // Controls switch choices
    int selection, selection1, selection2;
    char control, control2;
    
    vector<string> play;
    
do
{
      // adds playlist from file to vector
    openPlaylistFile("Playlist.list", play);
    eraseDuplicates(play);

    cout << "----------WELCOME to the AutoPlayer----------" << endl << endl;
    cout << "You currently have " << play.size() << " playlist(s)." << endl;
    cout << "1 - Open an exisiting playlist" << endl;
    cout << "2 - Create new list" << endl;
    cout << "3 - Exit" << endl;
    cout << "Selection: "; 
    cin >> selection;
    cout << endl;

    switch (selection)
    {
    
        case 1:
        {
            cout << "Please select a playlist from below:" << endl;
            for (int i = 0; i < play.size() ; i++)
            {
            cout << i + 1 << " " << play[i] << endl;
            }
            cout << "Selection: ";
            cin >> selection1;
            choice = play[selection1-1];
            cout << endl;
            Playlist p(choice);
            label:
            cout << "You are now playing: " << p.getTitle() << endl;
            cout << setw(22) << right << "A - Add a song" << endl;
            cout << setw(25) << right << "D - Delete a song" << endl;
            cout << setw(23) << right << "P - Play a song" << endl;
            cout << setw(24) << right << "M - Set the mode" << endl;
            cout << setw(26) << right << "S - Show all songs" << endl;
            cout << setw(16) << right << "Q - Quit" << endl;
            cout << "Selection: ";
            cin >> control;
            cout << endl;
            switch(toupper(control))
                {
                case 'A': 
                cout << "Song Details" << endl;
                cout << "Title: ";
                cin.ignore();
                getline(cin,title); //needs to be a getline
                cout << "Artist: ";
                getline(cin,artist);   
                cout << "Album: ";
                getline(cin,album);                         
                cout << "Year: ";
                cin >> year;
                cout << "Length (in seconds): ";
                cin >> song_in_seconds;
                song.set(title,artist,album,song_in_seconds,year);
                p.appendToFile(song);
                p.addSong(song);
                break;
                case 'D':
                cout << "Enter to delete: " << endl;
                cout << "Title: ";
                cin >> song;
                cout << "Artist: ";
                cin >> song;    
                check = p.deleteSong(song);
                if(check == true)
                    cout << "Song successfully deleted " << endl;
                else
                    cout << "Song not found in playlist" << endl;
                break;
                case 'M':
                cout << "Enter mode: " << endl;
                cout << setw(9) << right << "N - Normal " << endl;
                cout << setw(9) << "R - Repeat " <<endl;
                cout << setw(9) << "L - Loop " << endl;
                cout << "Selection: ";
                cin >> control2;
                p.setMode(toupper(control2));
                break;
                case 'P':
                        p.play();
                        goto label;
                        break;
                case 'S':
                    p.printPlaylist();
                        break;
                case 'Q':
                        break;
                default: 
                    cout << "Invalid selection " << endl; 
                    break;
                } // inner switch end
    } // case 1 end
    break;
            
    case 2:
    {
        cout << "1 - Create new empty list" << endl;
        cout << "2 - Merge 2 exisitng playlists" << endl;
        cout << "3 - Intersect 2 exisinting playlists" << endl;
        cout << "Selection: ";
        cin >> selection1;
        cout << "Name of new playlist (cannot contain underscores): ";
        cin.ignore();
        getline(cin,newPlaylist);
        cout << endl;
         if(selection1 == 1)
        {
            writeNewPlaylistfile("Playlist.list", newPlaylist);
        }
        if(selection1 == 2)
       {
           cout << " Which of the following playlists would you like to merge? " << endl;
           for(int i = 0; i < play.size(); i++)
           {
               cout <<  i + 1 << " " << play[i] << endl;
           }
           Playlist p3(newPlaylist);
           writeNewPlaylistfile("Playlist.list", newPlaylist);
           cout << "Playlist 1: ";
           cin >> selection1;
           cout << endl;
           choice = play[selection1-1];
           Playlist p(choice);
           p3.merge(p);
           cout << "Playlist 2: ";
           cin >> selection2;
           cout << endl;
           choice2 = play[selection2-1];
           Playlist p1(choice2);
           p3.merge(p1);
           p3.merge(p);
       }
       if(selection1 == 3)
       {
           cout << "Which of the following playlists would you like to intersect? " << endl; 
           for(int i = 0; i < play.size(); i++)
           {
               cout <<  i + 1 << " " << play[i] << endl;
           }
           Playlist p3(newPlaylist);
           writeNewPlaylistfile("Playlist.list", newPlaylist);
           cout << "Playlist 1: ";
           cin >> selection1;
           cout << endl;
           choice = play[selection1-1];
           Playlist p(choice);
           p3  = p;
           cout << "Playlist 2: ";
           cin >> selection2;
           cout << endl;
           choice2 = play[selection2-1];
           Playlist p1(choice2);
           p3.intersect(p1);
       }
    }// case 2 end
    break;

    default:
    break;
    } // end of entire switch
}
while (selection != 3);
    
cout << endl;    return 0;
}// end of main


const int countLinesInFile(string filename) 
{
    int count = 0;
    string line;
 
    /* Creating input filestream */ 
    ifstream file;
    file.open(filename.c_str());

    while (getline(file, line))
        count++;

    return count;
}


void openPlaylistFile(string filename, vector <string> & v)
{
    string line;
    ifstream file;
    file.open(filename.c_str());
    while(file >> line)
    {
        v.push_back(line);
       
    }

       
}

void writeNewPlaylistfile(string file, string playlist)
{

    ofstream f;
    f.open(file.c_str(),ios::app);
    f << '\n' << playlist;
}

void eraseDuplicates(vector<string> & v)
{
   sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());
}
