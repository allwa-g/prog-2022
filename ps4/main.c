#include "bmp.h"
#include "transformations.h"
#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

int main () {    
         FILE * input1 = fopen("square.4x4.bmp", "rb");

     struct bmp_image* image = read_bmp(input1);

     fclose(input1);

     struct bmp_image* horizontal = flip_horizontally(image);
     struct bmp_image* vertical = flip_vertically(image);
     struct bmp_image* right = rotate_right(image);
     struct bmp_image* left = rotate_left(image);


     FILE *input2 = fopen("image.bmp", "wb");
     
     write_bmp(input2, left);

     fclose(input2);

     free_bmp_image(image);
     free_bmp_image(horizontal);
     free_bmp_image(vertical);
     free_bmp_image(right);
     free_bmp_image(left);

    return 0;
}

