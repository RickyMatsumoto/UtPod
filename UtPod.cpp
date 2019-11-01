//UtPod.cpp

#include "UtPod.h"
#include <random>
#include <ctime>
using namespace std;

UtPod::UtPod(){
    this->memSize = MAX_MEMORY;
    this->songs = NULL;
}

UtPod::UtPod(int size){
    if((size > 0) && (size <= MAX_MEMORY)){
        this->memSize = size;
    }
    else{
        this->memSize = MAX_MEMORY;
    }
    this->songs = NULL;
}

int UtPod::addSong(Song const &s){
    if(getRemainingMemory() < s.getSize()){
        return(NO_MEMORY);
    }
    else{
        SongNode *temp = new SongNode {s, songs};
        this->songs = temp;
        return (SUCCESS);
    }
}

int UtPod::removeSong(Song const &s){
    if(this->songs->s == s){
        SongNode *temp = this->songs;
        this->songs = this->songs->next;
        delete(temp);
        return (SUCCESS);
    }

    SongNode *scan = this->songs->next;
    SongNode *prev = this->songs;
    while((scan != NULL) && (scan->s != s)){
        scan = scan->next;
        prev = prev->next;
    }
    if(scan == NULL){
        return (NOT_FOUND);
    }
    else{
        prev->next = scan->next;
        delete(scan);
        return (SUCCESS);
    }
}

void UtPod::showSongList() {
    SongNode *scan = this->songs;
    while(scan != NULL){
        cout << scan->s.getArtist() << ", " << scan->s.getTitle() << ", " << scan->s.getSize() << endl;
        scan = scan->next;
    }
}

int UtPod::getRemainingMemory() {
    SongNode *scan = this->songs;
    int memoryUsed = 0;
    while (scan != NULL) {
        memoryUsed += scan->s.getSize();
        scan = scan->next;
    }
    return(this->memSize - memoryUsed);
}

void UtPod::clearMemory(){
    while(this->songs != NULL){
        SongNode *temp = this->songs;
        this->songs = this->songs->next;
        delete(temp);
    }
}

void UtPod::sortSongList() {
    SongNode *comparee = this->songs;
    while(comparee->next != NULL){
        SongNode *comparer = comparee->next;
        while(comparer != NULL){
            if(comparee->s > comparer->s){
                Song temp = comparer->s;
                comparer->s = comparee->s;
                comparee->s = temp;
            }
            comparer = comparer->next;
        }
        comparee = comparee->next;
    }
}

void UtPod::shuffle() {
    srand(time(NULL));
    SongNode *comparee = this->songs;
    int numSongs = 0;
    while(comparee != NULL){
        comparee = comparee->next;
        numSongs++;
    }

    comparee = this->songs;

    while(comparee != NULL){

        int i = rand() % numSongs;

        SongNode *comparer = this->songs;
        for(; i--; i != 0){
            comparer = comparer->next;
        }

        Song temp = comparer->s;
        comparer->s = comparee->s;
        comparee->s = temp;

        comparee = comparee->next;
    }

}

UtPod::~UtPod() {
    clearMemory();
}