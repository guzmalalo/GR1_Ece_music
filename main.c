#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "music.h"

int main() {
    Song * liked_songs = NULL;

    addLast(&liked_songs,"Waka waka", "Shakira", 2);
    addFirst(&liked_songs, "Back in black", "ACDC", 3);
    addFirst(&liked_songs,"No surprises", "RadioHead", 2);
    addFirst(&liked_songs, "TNT", "Tortoise", 3);
    addLast(&liked_songs,"Oye como va", "Santana", 2);

    nowPlaying(liked_songs);

    deletePlaylist(&liked_songs);

    nowPlaying(liked_songs);

    return 0;
}
