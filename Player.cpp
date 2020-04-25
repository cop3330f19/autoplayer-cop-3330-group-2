#include "Song.h"
#include <iomanip>
#include <iostream>
#include <string>
#include "Playlist.h"
#include <fstream>
#include <vector>
#include "StringHelper.h"
#include <cstdlib>  

using namespace std;

// Counts number of playlist in file
const int countLinesInFile(string filename);

// Adds song from file to song vector
void openPlaylistFile(string filename, vector<string> & v);

// Searchs for playlist
int searchForPlaylist(int selection, vector<string> & v);

// Static controlling playing mode
int Playlist::mode = 0;
int main()
{
    int index = 0;
    int new_playlist = 0;
    Song song;
    bool check;
    string title, artist, album, tempPlaylist;
    int year, song_in_seconds;
    
    string newPlaylist;

    // Controls switch choices
    int selection, selection1;
    char selection2;
    char control, control2;

    vector<string> play;

    openPlaylistFile("Playlist.list", play);
    start:
    cout << "----------WELCOME to the AutoPlayer----------" << endl << endl;
    cout << "You currently have " << play.size() << " playlist(s)." << endl;
    cout << "1 - Open an exisiting playlist" << endl;
    cout << "2 - Create new list" << endl;
    cout << "3 - Exit" << endl;
    cout << "Selection: "; 
    cin >> selection;
    cout << endl;
do
{
    if (selection == 1)
    {
            cout << "Please select a playlist from below:" << endl;
            for (int i = 0; i < play.size() ; i++)
            {
            cout << i + 1 << " " << play[i] << endl;
            }
            cout << "Selection: ";
            cin >> selection1;
            cout << endl;
                
            
            index = searchForPlaylist(selection1,play);
            Playlist p(play[index]);
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
            if(toupper(control)== 'A')
            {
                cout << "Song Details" << endl;
                cout << "Title: ";
                cin >> title; //needs to be a getline
                cout << "Artist: ";
                cin >> artist;   
                cout << "Album: ";
                cin >> album;                         
                cout << "Year: ";
                cin >> year;
                cout << "Length (in seconds): ";
                cin >> song_in_seconds;
                song.set(title,artist,album,song_in_seconds,year);
                p.addSong(song);
            }
            else if(toupper(control)== 'D')
            {
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
            }
            else if(toupper(control)== 'M')
            {
                cout << "Enter mode: " << endl;
                cout << setw(9) << right << "N - Normal " << endl;
                cout << setw(9) << "R - Repeat " <<endl;
                cout << setw(9) << "L - Loop " << endl;
                cout << "Selection: ";
                cin >> control2;
                p.setMode(toupper(control2));
                goto label;
            }
            else if(toupper(control)== 'P')
            {
                cout << "NOW PLAYING:" << endl;
                p.play();
                goto label;
            }
            else if(toupper(control)== 'S')
            {
                p.printPlaylist();
                goto label;
            }
            else if(toupper(control)== 'Q')
                goto start;
            else
            {
               cout << "Invalid selection " << endl; 
                goto label;
            }    
    }    
    if (selection == 2)
     {
        cout << "1 - Create new empty list" << endl;
        cout << "2 - Merge 2 exisitng playlists" << endl;
        cout << "3 - Intersect 2 exisinting playlists" << endl;
        cout << "Selection: ";
        cin >> selection1;
        if(selection1 == 1)
        {
            cout << "Name of new playlist (cannot contain underscores):";
            cin.ignore();
            getline(cin,newPlaylist);
            Playlist p(newPlaylist);    
        }
     }
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


int searchForPlaylist(int selection, vector<string> & v)
{
    string playlist;
    if(selection == 1)
        playlist = "Country";
    else if(selection == 2)
        playlist = "90s_RnB";
    else if(selection == 3)
        playlist = "Country_RnB_Mix";
    else if(selection == 4)
        playlist = "Intersected_List";
    else if(selection == 5)
        playlist = "Rock_Anthems";
    else
       return playlist.size();
    

    for(int i = 0; i < v.size() ; i++)
    {
        if (playlist == v[i])
        {
            return i;
        }
        
    }
    return -1;
    
    
}

void openPlaylistFile(string filename, vector <string> & v)
{
    string line;
    ifstream file;
    file.open(filename.c_str());
    while(file >> line)
        v.push_back(line);
}
