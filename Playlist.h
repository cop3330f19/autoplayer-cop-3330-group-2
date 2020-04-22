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
   static int mode;

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
   void addSong(Song song);
   //will take a Song object as a parameter and delete it from play list and return true/false.
   bool deleteSong(Song & song);
   // Adds song to playlist current playlist
   Playlist friend operator+(Playlist &p ,Song &s);
   // concatenation of the two playlist objects 
   Playlist friend operator+(Playlist & playlist , Playlist & p2);
   //removing a song(s) from a playlist
   Playlist friend operator-(Playlist &p , Song & song);

   /*return a new playlist that is the intersection of the songs in the playlist argument and 
   the songs contained within the playlist object. This will contain no duplicates*/
   Playlist intersect(Playlist & Playlist);
   /* return a new playlist that merges the songs in the playlist argument
   and the songs contained within the playlist object which match been called. 
   This playlist will contain all songs, including duplicates.*/
   Playlist merge(Playlist & Playlist);
   //play's one song from the play list starting at first index
   void play();
   // Keeps tract of the playing mode
   static void setMode(int);

   std::vector<Song> getPlaylist();

};

int Playlist::mode = 0;

#endif
