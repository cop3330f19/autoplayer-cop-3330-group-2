#ifndef PLAYLIST_H
#define  PLAYLIST_H

#include <string>
#include "Song.h"
#include <iomanip>
#include <iostream>
#include <vector>
#include <fstream>

class Playlist
{
   private:
   std::string title;
   std::vector<Song> playlist;

   public:
   
   // Constructors
   Playlist();
   Playlist(std::string);

   friend std::ostream& operator<<(std::ostream& os, const Playlist& playlist);
   //output to file
   friend std::ofstream& operator<<(std::ofstream& os, const Playlist& playlist);

   // input the playlist in the format:
   // title
   friend std::istream& operator>>(std::istream& is, Playlist& playlist);
   //input from file
   friend std::fstream& operator>>(std::fstream& is, Playlist& playlist);

   void setTitle(std::string);

   std::string getTitle() const;
   //will take a Song object as a parameter and insert it into the play list.
   void addSong(Song & song);
   //will take a Song object as a parameter and delete it from play list and return true/false.
   bool deleteSong(Song & song);
   // Adds song to playlist current playlist
   //Song operator+(Song & song);

   //Song operator+(<Song> & song);


   

   

};

#endif
