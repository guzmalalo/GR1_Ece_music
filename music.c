#include "music.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>


void nowPlaying(Song * toPlay){
    int choix;
    while(toPlay!=NULL) {
        printf("Now playing \n");
        printf("%s \n", toPlay->title);
        printf("%s \n\n", toPlay->artist);
        //sleep(toPlay->duration);
        printf("1: next , 2: previous, 3:exit \n");
        scanf("%d",&choix);
        switch (choix) {
            case 1:
                toPlay=toPlay->next;
                break;
            case 2:
                toPlay=toPlay->prev;
                break;
            case 3:
                return;
            default:
                break;
        }
    }

    printf("End playlist \n\n");
    printf("==============================\n");
}

Song * createSong(char* title, char* artist, unsigned int duration){
    //  Allocation
    Song * newSong  = (Song *) malloc(sizeof(Song));

    // Initialisation data
    newSong->duration = duration;
    strcpy(newSong->artist, artist);
    strcpy(newSong->title, title);

    // initialisation des liens / links
    newSong->next = NULL;
    newSong->prev = NULL;

    return newSong;
}

void addFirst(Song ** playlist,char* title, char* artist, unsigned int duration ){
    // create a new song
    Song * newSong = createSong(title,artist,duration);

    if(*playlist == NULL){
        // new HEAD
        *playlist = newSong;
        newSong->next = newSong;
        newSong->prev = newSong;
    }else{
        // au moins une chanson
        newSong->next = *playlist;
        newSong->prev = (*playlist)->prev;

        newSong->next->prev = newSong;
        newSong->prev->next = newSong;

        *playlist = newSong;
    }
}


void deletePlaylist(Song ** playlist){

    if(*playlist == NULL){
        return;
    }

    Song * toDelete = NULL;
    Song * current = (*playlist)->next;

    // delete all the songs after the HEAD
    while(current!=*playlist){
        toDelete = current;
        current = current->next;

        free(toDelete);
    }

    // delete the first song
    free(*playlist);
    *playlist = NULL;
}


void addLast(Song ** playlist,char* title, char* artist, unsigned int duration ){
    // create a new song
    Song * newSong = createSong(title, artist, duration);

    if(*playlist ==NULL){
        // if we have no songs yet
        *playlist = newSong;
        newSong->next = newSong;
        newSong->prev = newSong;
    }else {
        // au moins une chanson
        newSong->next = *playlist;
        newSong->prev = (*playlist)->prev;

        newSong->next->prev = newSong;
        newSong->prev->next = newSong;
    }

}

// delete by artist
void deleteByArtist(Song ** playlist, char * artistName){
    // we do something if we have at least one song
    if(*playlist !=NULL){
        Song * prev = *playlist;
        Song * current = (*playlist)->next;

        while (current!=NULL){
            if(strcmp(current->artist, artistName)==0){
                prev->next = current->next;
                free(current);
                current=prev->next;
            }else{
                prev= current;
                current= current->next;
            }
        }

        // if the artist is in the first position
        if(strcmp((*playlist)->artist, artistName)==0){
            current = *playlist;
            *playlist= (*playlist)->next;
            free(current);
        }
    }
}













