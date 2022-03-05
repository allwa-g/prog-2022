#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "bmp.h"
#include "playfair.h"
#include <math.h>




int main()
{


    char key[] = "computer";
    char text[] = "Hello world!";


    playfair_decrypt(key, text);
    playfair_encrypt(key, text);

//-------------------------------------------------------
// REVERSE FUNCTION
//-------------------------------------------------------

    reverse(text);
    char* reversed = reverse(text);
    printf("Reverse: %s\n", reversed);
    free(reversed);


//-------------------------------------------------------
// VIGENERE ENCRYPT FUNCTION
//-------------------------------------------------------

    vigenere_encrypt(key, text);

    char *vigenere_encrypted, *vigenere_decrypted;
    vigenere_encrypted = vigenere_encrypt(key, text);
    printf("vigenere_encrypt: %s\n", vigenere_encrypted);

//--------------------------------------------------------
// VIGENRE DECRYPT
//-------------------------------------------------------
    
    vigenere_decrypted = vigenere_decrypt(key, vigenere_encrypted);
    vigenere_decrypt(key, text);
    printf("vigenere_decrypt: %s\n", vigenere_decrypted);
    free(vigenere_encrypted);
    free(vigenere_decrypted);

//----------------------------------------------------------
// BIT ENCRYPT FUNCTION
//------------------------------------------------------------
    unsigned char* bit_encrypted;
    bit_encrypted = bit_encrypt(text);
    printf("bit encrypted: ");
    for(int i=0; i < (int)strlen(text);i++) {
        printf("%x ", (unsigned char) bit_encrypted[i]);
    }

//-----------------------------------------------------------
// BIT DECRYPT FUNCTION
//-----------------------------------------------------------

   char* bit_decrypted;
    bit_decrypted = bit_decrypt(bit_encrypted);
    printf("\nbit decrypted: ");
    for(int i=0; i < (int)strlen(text);i++) {
        printf("%c", (unsigned char) bit_decrypted[i]);
    }

    free(bit_decrypted);
    free(bit_encrypted);


//------------------------------------------------------------
// BMP ENCRYPT FUNCTION
//-----------------------------------------------------------

    printf("\nbmp_encrypt: ");
    unsigned char* bmp_encrypted;
    bmp_encrypted = bmp_encrypt(key, text);
    for(int i=0; i<(int)strlen(text);i++) {
        printf("%x ", (unsigned char) bmp_encrypted[i]);
    }

//------------------------------------------------------
// BMP DECRYPT FUNCTION
//--------------------------------------------------------------
    printf("\nbmp_decrypt: ");
    char* bmp_decrypted = bmp_decrypt(key, bmp_encrypted);
    printf("%s\n", bmp_decrypted);

    free(bmp_encrypted);
    free(bmp_decrypted);

    return 0;
}
