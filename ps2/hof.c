#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"hof.h"
#include"k.h"
#include<math.h>

int load(struct player list[]){
    FILE *file = fopen(HOF_FILE, "rb");

    if(file == NULL){
        return -1;
    }
    int i = 0;
    int players = 10;
    while(fscanf(file, "%s %i", list[i].name, &list[i].score) != EOF && i < players){
        i++;
    }  
    fclose(file);
    return i;
}



bool add_player(struct player list[], int* size, const struct player player){

    if(list[*size-1].score > player.score && *size == 10){
        return false;
    }


	if(*size > 10 || *size < 0){
        return false;

    } else if (*size < 10 && *size > 0){
        strcpy(list[*size].name, player.name);
        list[*size].score = player.score;
        *size = *size + 1;
        return true;
    } else if (*size == 10){
        strcpy(list[*size-1].name, player.name);
        list[*size-1].score = player.score;
        return true;
    } else if (*size == 0){
        strcpy(list[*size+1].name, player.name);
        list[*size+1].score = player.score;

        return true;
    } else {
        return false;
    }

	return 0;
	
}





bool save(const struct player list[], const int size){
    FILE *save = fopen(HOF_FILE, "wb");


    if(save == NULL){
        return false;
    } else {

        for( int i = 0; i < size; i++){
    	    fprintf(save, "%29s %d\n", list[i].name, list[i].score);
        }

    }

    fclose(save);
	return true;
}

