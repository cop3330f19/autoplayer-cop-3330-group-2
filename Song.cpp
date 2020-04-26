/* Group 2
 * Last Updated: 25 Apr 20 
 * COP 3330
 * Group Members:
 * Amani Muller
 * Eric Lampley
 * Zahir Cooper
 * Claressa Wilson 
 * */

#include <iostream>
#include <string>
#include <fstream>
#include <string>
#include "Song.h"
#include <iomanip>
#include <math.h>

using namespace std;

Song::Song()
{
    
}
Song::Song(string title, string artist)
{
    this->title = title;
    this->artist = artist;
}

Song::Song(string title, string artist, string album, int length, int year)
{
    this->title = title;
    this->artist = artist;
    this->album = album;
    this->length = length;
    this->year = year;
}

void Song::set(string title, string artist, string album, int length, int year)
{
    this->title = title;
    this->artist = artist;
    this->album = album;
    this->length = length;
    this->year = year;
}

bool operator==(const Song& lhs, const Song& rhs)
{
    return (lhs.title == rhs.title) && (lhs.artist == rhs.artist);
}

ostream& operator<<(ostream& os, const Song& song)
{
    
    os << song.title << '\n' << song.artist << '\n'
        << song.album << ' ' << "(" << song.year << ")\n" << "Play Time: " <<  song.length / 60 
        << showpoint << fixed << ':' <<  setw(2) << (song.length % 60) <<  endl;
    
    return os;
}

ofstream& operator<<(ofstream& os, const Song& song)
{
     os << song.title << "," << song.artist << ',' 
     << song.album << ',' << song.year << ',' << song.length << endl; 

    return os;
}

istream& operator>>(istream& is, Song& song)
{
    cout << "Song Details" << endl;
    cout << "Title: ";
    is >> song.title; 
    cout << "Artist: ";
    is >> song.artist;
    cout << "Album: ";
    is >> song.album;
    cout << "Year";
    is >> song.year;
    cout << "Length (in seconds): ";
    is >> song.length;
    
    return is;
}

fstream& operator>>(fstream& is, Song& song)
{
    is >> song.title >> song.artist >> song.album >> song.year >> song.length;

    return is;
}
