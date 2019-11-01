#ifndef SONG_H
#define SONG_H

#include <iostream>
#include <string>
using namespace std;

class Song{
    private:
        string artist;
        string title;
        int size;

    public:
        Song(string artist, string title, int size);
        string getTitle() const;
        string getArtist() const;
        int getSize() const;
        bool operator==(const Song& song);
        bool operator!=(const Song& song);
        bool operator>(const Song& song);
        bool operator<(const Song& song);
};

#endif