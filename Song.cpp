//Song.cpp

#include "Song.h"

Song::Song(string artist, string title, int size) {
    if((title != "\0") && (artist != "\0") && (size > 0)){
        this->title = title;
        this->artist = artist;
        this->size = size;
    }
    else{
        cout << "Incorrect input." << endl;
    }
}

string Song::getTitle() const{
    return (this->title);
}

string Song::getArtist() const{
    return (this->artist);
}

int Song::getSize() const{
    return (this->size);
}

bool Song::operator==(const Song& song){
    return (this->title == song.getTitle()) && (this->artist == song.getArtist()) && (this->size == song.getSize());
}

bool Song::operator!=(const Song& song) {
    return (!operator==(song));
}

bool Song::operator>(const Song& song){
    if(this->getArtist() > song.getArtist()){
        return(true);
    }
    else if(this->getArtist() == song.getArtist()){
        if(this->getTitle() > song.getTitle()){
            return (true);
        }
        else if (this->getTitle() == song.getTitle()){
            if (this->getSize() > song.getSize()){
                return (true);
            }
        }
    }
    return(false);
}

bool Song::operator<(const Song& song){
    return (!operator>(song));
}