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
void Playlist::addSong(Song & song)
{
    playlist.push_back(song);
}

//will take a Song object as a parameter and delete it from play list and return true/false.
bool Playlist:: deleteSong(Song & song)
{   
    for(int i = 0; i < playlist.size(); i++)
    {
        if(song  == playlist[i])
        {
          playlist.erase(playlist.begin()+i);
          return true;
        }
    }
    return false;
}

// Adds song to playlist current playlist
Playlist Playlist::operator+()
{
    Playlist p; 
    Song s;
    Playlist p2 = p + s;

    
}

