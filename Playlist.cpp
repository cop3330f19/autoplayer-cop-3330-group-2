#include <string>
#include "Song.h"
#include <iomanip>
#include <iostream>
#include <vector>
#include <fstream>
#include "Playlist.h"

using namespace std;

Playlist::Playlist()
{
    
}

Playlist::Playlist(string title)
{
    this->title = title;
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
//play's one song from the play list starting at first index
// void Playlist::play()
// {
//     vector<Song> s = this ->playlist;

//     for (int i = 0; i < count; i++)
//     {
//         /* code */
//     }
    
// }

int Playlist::mode = 0;
// Keeps tract of the playing mode
void Playlist::setMode(int playingMode)
{
    mode = playingMode;
}



