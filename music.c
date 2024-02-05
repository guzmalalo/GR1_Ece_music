#include "music.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>


void nowPlaying(Song * toPlay){
    while(toPlay!=NULL) {
        printf("Now playing \n");
        printf("%s \n", toPlay->title);
        printf("%s \n\n", toPlay->artist);
        sleep(toPlay->duration);
        toPlay= toPlay->next;
    }
}

Song * createSong(char* title, char* artist, unsigned int duration){
    //  Allocation
    Song * newSong  = (Song *) malloc(sizeof(Song));

    // Initialisation
    newSong->duration = duration;
    strcpy(newSong->artist, artist);
    strcpy(newSong->title, title);
    newSong->next = NULL;

    return newSong;

}

void addFirst(Song ** playlist,char* title, char* artist, unsigned int duration ){
    // create a new song
    Song * newSong = createSong(title,artist,duration);

    newSong->next = *playlist;
    *playlist = newSong;

}


void deletePlaylist(Song ** playlist){
    Song * temp = NULL;

    while(*playlist!=NULL){
        temp= (*playlist)->next;
        free(*playlist);
        *playlist = temp;
    }

}


void addLast(Song ** playlist,char* title, char* artist, unsigned int duration ){
    // create a new song
    Song * newSong = createSong(title, artist, duration);

    if(*playlist ==NULL){
        // if we have no songs yet
        *playlist = newSong;
    }else {

        // We assume that the las song is the head.
        Song *lastSong = *playlist;

        // while last song has a neighbor
        while (lastSong->next != NULL) {
            lastSong = lastSong->next;
        }

        // if we are here, lastsong is pointing to the las element
        lastSong->next = newSong;
        //lastSong = newSong;
    }

}


