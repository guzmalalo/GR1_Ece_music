#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "music.h"

int main() {
    Song * liked_songs = NULL;

    addLast(&liked_songs,"Waka waka", "Shakira", 1);
    addFirst(&liked_songs, "Back in black", "ACDC", 1);
    addFirst(&liked_songs,"No surprises", "RadioHead", 1);
    addFirst(&liked_songs, "TNT", "Tortoise", 1);
    addLast(&liked_songs,"Baby ...", "Britney",1);
    addFirst(&liked_songs,"Toxic","Britney",1);
    addLast(&liked_songs,"Oye como va", "Santana", 1);
    addLast(&liked_songs,"Oops i dit ..", "Britney",1);

    // premier affichage
    nowPlaying(liked_songs);

    // delete all britney songs
    //deleteByArtist(&liked_songs, "Britney");
    //deleteByArtist(&liked_songs, "Shakira");

    // second print
    //nowPlaying(liked_songs);

    deletePlaylist(&liked_songs);

    return 0;
}
