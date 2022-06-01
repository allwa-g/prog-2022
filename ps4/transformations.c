#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "bmp.h"
#include <string.h>
#include "transformations.h"

#include "transformations.h"
#include "bmp.h"
#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>


//https://github.com/yunghsianglu/IntermediateCProgramming/blob/master/Ch23/main.c

//https://cboard.cprogramming.com/c-programming/142074-how-flipping-image-horizontally.html

//https://stackoverflow.com/questions/56424386/crop-bmp-file-image-in-c-program

//https://social.msdn.microsoft.com/Forums/windowsdesktop/en-US/134bbcad-b48e-42a0-99c5-7513dbbd1671/how-to-calculate-padding-and-create-a-bitmap-header-and-save-a-bitmap-in-vc?forum=vcgeneral

//https://stackoverflow.com/questions/34465329/bitmap-color-c

//https://stackoverflow.com/questions/48065528/color-changing-bmp-in-c




struct bmp_image* flip_horizontally(const struct bmp_image* image){


    if(image == NULL){
        return NULL;
    }

    if(image->header->height < 0 || image->header->width < 0){
        return NULL;
    }

    if(image->header == NULL || image->data == NULL){
        return NULL;
    }



	struct bmp_image* f_horizontal = malloc(sizeof(struct bmp_header));
	f_horizontal->header = malloc(sizeof(struct bmp_header));
	*f_horizontal->header = *image->header;
	uint32_t sirka = f_horizontal->header->width;
	uint32_t vyska = f_horizontal->header->height;
	struct pixel* pixel = calloc(sirka*vyska,24);

    f_horizontal -> header -> size = image -> header -> size;
    f_horizontal -> header -> type = image -> header -> type;
    f_horizontal -> header -> reserved1 = image -> header -> reserved1;
    f_horizontal -> header -> reserved2 = image -> header -> reserved2;
    f_horizontal -> header -> offset = image -> header -> offset;
    f_horizontal -> header -> dib_size = image -> header -> dib_size;
    f_horizontal -> header -> width = image -> header -> width;
    f_horizontal -> header -> height = image -> header -> height;
    f_horizontal -> header -> planes = image -> header -> planes;
    f_horizontal -> header -> bpp = image -> header -> bpp;
    f_horizontal -> header -> compression = image -> header -> compression;
    f_horizontal -> header -> image_size = image -> header -> image_size;
    f_horizontal -> header -> x_ppm = image -> header -> x_ppm;
    f_horizontal -> header -> y_ppm = image -> header -> y_ppm;
    f_horizontal -> header -> num_colors = image -> header -> num_colors;
    f_horizontal -> header -> important_colors = image -> header -> important_colors;



	for(uint32_t i = 0; i< vyska;i++){
		for(uint32_t j = 0; j<sirka; j++){
			pixel[sirka*i+j].red = image->data[sirka*i+(sirka-j-1)].red;
			pixel[sirka*i+j].green = image->data[sirka*i+(sirka-j-1)].green;
			pixel[sirka*i+j].blue = image->data[sirka*i+(sirka-j-1)].blue;
		}
	}
	f_horizontal->data = pixel;
	return f_horizontal;
}



struct bmp_image* flip_vertically(const struct bmp_image* image){


    if(image == NULL){
        return NULL;
    }

    if(image->header->height < 0 || image->header->width < 0){
        return NULL;
    }

    if(image->header == NULL || image->data == NULL){
        return NULL;
    }




	struct bmp_image* f_vertical = malloc(54);
	f_vertical->header = malloc(54);
	*f_vertical->header = *image->header;
	uint32_t sirka = f_vertical->header->width;
	uint32_t vyska = f_vertical->header->height;
	struct pixel* pixel = calloc(sirka*vyska,24);

    f_vertical -> header -> size = image -> header -> size;
    f_vertical -> header -> type = image -> header -> type;
    f_vertical -> header -> reserved1 = image -> header -> reserved1;
    f_vertical -> header -> reserved2 = image -> header -> reserved2;
    f_vertical -> header -> offset = image -> header -> offset;
    f_vertical -> header -> dib_size = image -> header -> dib_size;
    f_vertical -> header -> width = image -> header -> width;
    f_vertical -> header -> height = image -> header -> height;
    f_vertical -> header -> planes = image -> header -> planes;
    f_vertical -> header -> bpp = image -> header -> bpp;
    f_vertical -> header -> compression = image -> header -> compression;
    f_vertical -> header -> image_size = image -> header -> image_size;
    f_vertical -> header -> x_ppm = image -> header -> x_ppm;
    f_vertical -> header -> y_ppm = image -> header -> y_ppm;
    f_vertical -> header -> num_colors = image -> header -> num_colors;
    f_vertical -> header -> important_colors = image -> header -> important_colors;



	for(uint32_t i = 0; i< vyska;i++){
		for(uint32_t j = 0; j<sirka; j++){
			pixel[sirka*i+j].red = image->data[sirka*(vyska-i-1)+j].red;
			pixel[sirka*i+j].green = image->data[sirka*(vyska-i-1)+j].green;
			pixel[sirka*i+j].blue = image->data[sirka*(vyska-i-1)+j].blue;
		}
	}
	f_vertical->data = pixel;
	return f_vertical;
}



struct bmp_image* rotate_right(const struct bmp_image* image){


    if(image == NULL){
        return NULL;
    }

    if(image->header->height < 0 || image->header->width < 0){
        return NULL;
    }

    if(image->header == NULL || image->data == NULL){
        return NULL;
    }




	struct bmp_image* right = calloc(1, sizeof(struct bmp_image));
	right->header = calloc(1, sizeof(struct bmp_header));
	*right->header = *image->header;
	int sirka = right->header->width;
	int vyska = right->header->height;
	struct pixel* pixel = calloc(sirka*vyska,24);

    right -> header -> size = image -> header -> size;
    right -> header -> type = image -> header -> type;
    right -> header -> reserved1 = image -> header -> reserved1;
    right -> header -> reserved2 = image -> header -> reserved2;
    right -> header -> offset = image -> header -> offset;
    right -> header -> dib_size = image -> header -> dib_size;
    right -> header -> width = image -> header -> width;
    right -> header -> height = image -> header -> height;
    right -> header -> planes = image -> header -> planes;
    right -> header -> bpp = image -> header -> bpp;
    right -> header -> compression = image -> header -> compression;
    right -> header -> image_size = image -> header -> image_size;
    right -> header -> x_ppm = image -> header -> x_ppm;
    right -> header -> y_ppm = image -> header -> y_ppm;
    right -> header -> num_colors = image -> header -> num_colors;
    right -> header -> important_colors = image -> header -> important_colors;



	for(int i = 0; i< vyska;i++){
		for(int j = 0; j<sirka; j++){
			pixel[sirka*i+j].red = image->data[(vyska-i-1)+j*vyska].red;
			pixel[sirka*i+j].green = image->data[(vyska-i-1)+j*vyska].green;
			pixel[sirka*i+j].blue = image->data[(vyska-i-1)+j*vyska].blue;
		}
	}


	right->header->width = image->header->height;
    right->header->height = image->header->width;


    int padding = (right->header->width*3);
    if(padding % 4 == 3){
        padding = 1;
    } if(padding % 4 == 0){
        padding = 0;
    } if (padding % 4 == 2){
        padding = 2;
    } if (padding % 4 == 1){
        padding = 3;
    }

    //printf("padding: %d\n",padding);
    //printf("offset %d\n", right->header->offset);



    right -> header -> image_size = (( right->header->width * 3 + padding))*right->header->height;
    right -> header -> size = right->header->image_size + right->header->offset ;
    //printf("sirka: %d\n", right->header->width);
    //printf("vyska: %d\n", right->header->height);


    //printf("size: %d %d \n", right->header->size, right->header->image_size );
    
    //printf("vysledok: %d\n", 9%4);
	right->data = pixel;
	return right;
}


struct bmp_image* rotate_left(const struct bmp_image* image){


    if(image == NULL){
        return NULL;
    }

    if(image->header->height < 0 || image->header->width < 0){
        return NULL;
    }

    if(image->header == NULL || image->data == NULL){
        return NULL;
    }




	struct bmp_image* left = calloc(1, sizeof(struct bmp_image));
	left->header = calloc(1, sizeof(struct bmp_header));



	*left->header = *image->header;
	uint32_t sirka = left->header->width;
	uint32_t vyska = left->header->height;
	struct pixel* pixel = calloc(sirka*vyska,sizeof(struct pixel));

    //left -> header -> size = image -> header -> size;
    
 


    left -> header -> type = image -> header -> type;
    left -> header -> reserved1 = image -> header -> reserved1;
    left -> header -> reserved2 = image -> header -> reserved2;
    left -> header -> offset = image -> header -> offset;
    left -> header -> dib_size = image -> header -> dib_size;
    left -> header -> width = image -> header -> width;
    left -> header -> height = image -> header -> height;
    left -> header -> planes = image -> header -> planes;
    left -> header -> bpp = image -> header -> bpp;
    left -> header -> compression = image -> header -> compression;
    
    left -> header -> x_ppm = image -> header -> x_ppm;
    left -> header -> y_ppm = image -> header -> y_ppm;
    left -> header -> num_colors = image -> header -> num_colors;
    left -> header -> important_colors = image -> header -> important_colors;
    left->header->size = image->header->size;
    left->header->image_size = image->header->image_size;

    //printf("image size: %ld\n",left->header->height*left->header->width*3+ sizeof(struct bmp_header));
    	for(int i = 0; i< vyska;i++){
		for(int j = 0; j<sirka; j++){
			pixel[sirka*i+j].red = image->data[(vyska-i-1)+j*vyska].red;
			pixel[sirka*i+j].green = image->data[(vyska-i-1)+j*vyska].green;
			pixel[sirka*i+j].blue = image->data[(vyska-i-1)+j*vyska].blue;
		}
	}


	left->header->width = image->header->height;
    left->header->height = image->header->width;


    int padding = (left->header->width*3);
    if(padding % 4 == 3){
        padding = 1;
    } if(padding % 4 == 0){
        padding = 0;
    } if (padding % 4 == 2){
        padding = 2;
    } if (padding % 4 == 1){
        padding = 3;
    }

    //printf("padding: %d\n",padding);
    //printf("offset %d\n", right->header->offset);



    left -> header -> image_size = (( left->header->width * 3 + padding))*left->header->height;
    left -> header -> size = left->header->image_size + left->header->offset ;
    
	left->data = pixel;    
	return left;
}


