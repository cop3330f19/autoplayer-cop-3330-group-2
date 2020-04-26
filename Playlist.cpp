/* Group 2
 * Last Updated: 25 Apr 20 
 * COP 3330
 * Group Members:
 * Amani Muller
 * Eric Lampley
 * Zahir Cooper
 * Claressa Wilson 
 * */

#include <string>
#include "Song.h"
#include <iomanip>
#include <iostream>
#include <vector>
#include <fstream>
#include "Playlist.h"
#include "StringHelper.h"
#include <stdlib.h>  

using namespace std;

Playlist::Playlist()
{
    songnumber = 0;
}

Playlist::Playlist(string title)
{
    songnumber = 0;

    this->title = title;
    string song, artist,album, line;
    int year, song_length;

    ifstream file;
    file.open((StringHelper::stou(title) + ".playlist").c_str());
    while(getline(file,line))
    {
        Song s;
        song = StringHelper::parse(line,',')[0];
        artist = StringHelper::parse(line,',')[1];
        album = StringHelper::parse(line,',')[2];
        year = atoi(StringHelper::parse(line,',')[3].c_str());
        song_length = atoi(StringHelper::parse(line,',')[4].c_str());

        s.set(song,artist,album,song_length,year);
        addSong(s);
    }
    writeToFile();
}

void Playlist::setTitle(string title)
{
    this->title = title;
}

string Playlist::getTitle() const
{
    return title;
}

//will take a Song object as a parameter and insert it into the play list.
void Playlist::addSong(Song song)
{
    playlist.push_back(song);
}

//will take a Song object as a parameter and delete it from play list and return true/false.
bool Playlist:: deleteSong(Song & song)
{   
    for(int i = 0; i < playlist.size(); i++)
    {
        if(song == playlist[i])
        {
          playlist.erase(playlist.begin()+i);
          return true;
        }
    }
    return false;
}

// Adds song to playlist current playlist
Playlist operator+(Playlist & p ,Song & s)
{
    p.addSong(s);
    return p;  
}

  // concatenation of the two playlist objects 
Playlist operator+(Playlist & playlist, Playlist & p2)
{
    vector<Song> s = playlist.getPlaylist();
    Playlist p3 = p2;

    for (int i = 0; i < s.size(); i++)
    {
        p3.addSong(s[i]);
    }  
    return p3;
}
//removing a song(s) from a playlist
Playlist operator-(Playlist & p , Song & song)
{
    p.deleteSong(song);
    return p;  
}

vector<Song> Playlist:: getPlaylist()
{
    return playlist;
}

/*return a new playlist that is the intersection of the songs in the playlist argument and 
the songs contained within the playlist object. This will contain no duplicates*/
Playlist Playlist::intersect(Playlist & p)
{
    vector<Song> s = this ->playlist;
    vector <Song> s1 = p.getPlaylist();
    Playlist p1;


    for (int i = 0; i < playlist.size(); i++)
    {
       if(s[i] == s1[i])
       p1.addSong(s[i]);
    }
    return p1;  
}

/* return a new playlist that merges the songs in the playlist argument
and the songs contained within the playlist object which match been called. 
This playlist will contain all songs, including duplicates.*/
Playlist Playlist::merge(Playlist & p)
{
    Playlist p1;  
    p1 = *this + p;

    return p1;
}

int Playlist::getPlayingMode()
{
    int count = 0;
    if(mode == 0)
    {
        return count;
        count++;
    }
    if(mode == 1)
    {
        return count;
    }
    if(mode == 2)
    {
        return count;
    }

    return count;
}

// play's one song from the play list starting at first index
void Playlist::play()
{
    if(mode == 0 || mode == 2)
    {
        cout << playlist[songnumber] << endl;
        songnumber++;
    }
    if(mode == 1)
         cout << playlist[songnumber] << endl;
    if (mode == 2 && songnumber == playlist.size())
    {
        songnumber = 0;
    }
    if (mode == 0 && songnumber == playlist.size())
    {
        cout << " END OF PLAYLIST" << endl;
        return;
    }
   
}


// Keeps tract of the playing mode
void Playlist::setMode(char playingMode)
{
    if(playingMode == 'N')
        mode = 0;
    if(playingMode == 'R')
        mode = 1;
    if(playingMode == 'L')
        mode = 2;
}

void Playlist::appendToFile(Song song)
{
    ofstream file;
    file.open((StringHelper::stou(title) + ".playlist").c_str(), ios::app);
    file << song;
    
}
void Playlist::writeToFile()
{
    ofstream file;
    file.open((StringHelper::stou(title) + ".playlist").c_str());
    for (int i = 0; i < playlist.size(); i++)
    {
       file << playlist[i];
    }
}

ostream& operator<<(ostream& os, const Playlist& playlist)
{
    for(int i = 0; i < playlist.playlist.size(); i++)
   {
    os << playlist.playlist[i] << endl;
      
       return os;
   }
   
}

void Playlist::printPlaylist()
{
    for(int i = 0; i < playlist.size(); i++)
        cout << playlist[i] << endl;

}

