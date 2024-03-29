#include <stdlib.h>
#include <stdio.h>
#include "bmp.h"
#include <stdint.h>
#include <ctype.h>
#include <stdbool.h>

//https://elcharolin.wordpress.com/2018/11/28/read-and-write-bmp-files-in-c-c/
//https://stackoverflow.com/questions/11129138/reading-writing-bmp-files-in-c
//https://programmerah.com/read-and-write-bmp-image-with-pure-c-language-24353/
//https://engineering.purdue.edu/ece264/16au/hw/HW13
//

struct bmp_header* read_bmp_header(FILE* stream){

    //rewind(stream);
    if(stream == NULL){
        return NULL;
    }

	
    rewind(stream); // sets the file position to the beginning of the file fpr the stream
    

    struct bmp_header *header = malloc(54);


    if((fread(header, 54, 1, stream) != 1)){
        free(header);
        return NULL;
    }
	

	
    if(header->width == 0 || header -> height == 0){
        free(header);
        return NULL;
    }
	
	if(fseek(stream, 54,SEEK_SET) != 0){
  		free(header);
  		return NULL;
	}

    if(header->type != 0x4d42){
        free(header);
        return NULL;
    }    

	fseek(stream, 0,SEEK_SET);
	if(fread(&header -> type, 2, 1 ,stream) != 1){
   		free(header);
   		return NULL;
    }
	return header;
}


struct pixel* read_data(FILE* stream, const struct bmp_header* header){

  
    if (header == NULL || stream == NULL){
        return NULL;
    }


    int vyska = header -> height;
    int sirka = header -> width;
    struct pixel* pixel = calloc(sirka*vyska, 24);

    fseek(stream,54, SEEK_SET);


    for(int i = 0; i < vyska; i++){
     for(int j = 0; j < sirka; j++){
       fread(&pixel[j+(i*sirka)],3, 1, stream);
       }
       fseek(stream, header->width%4, SEEK_CUR);
     
    }
    return pixel;

}



struct bmp_image* read_bmp(FILE* stream) {
 
	if (stream == NULL){
        return NULL;
    }
	rewind(stream);
    struct bmp_image *image = calloc(1,54);
    image -> header = read_bmp_header(stream);
    if(image -> header == NULL){
        fprintf(stderr,"Error: This is not a BMP file.\n");
        free_bmp_image(image);
        return NULL;
    }
	image -> data = read_data(stream, image -> header);
    if(image -> data == NULL){
        fprintf(stderr,"Error: Corrupted BMP file.\n");
        free_bmp_image(image);
        return NULL;
    }
    return image;

}


bool write_bmp(FILE* stream, const struct bmp_image* image) {

	if (stream == NULL || image == NULL){
        return false;
    } else{
	    fwrite(image -> header, 54 , 1 ,stream);
     	fwrite(image -> data, image -> header -> image_size, 1, stream);
		fwrite(&image->header->type, 2, 1, stream);
    	fwrite(&image->header->size, 4, 1, stream);
     	return true;	
	}

}




void free_bmp_image(struct bmp_image* image) {
    if (image != NULL) {
        if (image->header != NULL) {
            free(image->header);
            
        }

        if (image->data != NULL) {
            free(image->data);
            
        }
        free(image);
    }
}
