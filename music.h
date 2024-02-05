#ifndef GR1_ECE_MUSIC_MUSIC_H
#define GR1_ECE_MUSIC_MUSIC_H

struct song {
    // data
    char title[30];
    char artist[20];
    unsigned int duration;

    // lien/link
    struct song* next;
};

typedef struct song Song;
typedef char* String;

// creation chanson
Song * createSong(String title, char* artist, unsigned int duration);

//affichage
void nowPlaying(Song * toPlay);

//ajouter en tete
void addFirst(Song ** playlist,char* title, char* artist, unsigned int duration );

// ajout à la fin
void addLast(Song ** playlist,char* title, char* artist, unsigned int duration );

// free
void deletePlaylist(Song ** playlist);


#endif
