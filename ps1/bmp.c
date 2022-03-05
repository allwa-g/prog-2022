#include <memory.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include "bmp.h"


//----------------------------------------------
// reverse function - COMPLETE
//----------------------------------------------

char* reverse(const char* text){
	if (text == NULL ){   
		return NULL;
	}

	int lenght = strlen(text);	
	int size = sizeof(char*);
	char *reversed = (char*)calloc(lenght+1, size);
	
	int i = lenght-1;
	
	for (int j = 0; j < lenght; j++)
	{
		reversed[j] = toupper(text[i]);
		i--;
	}
	return reversed;
}


//------------------------------------------------------
// vigenere encrypt function
//------------------------------------------------------


char* vigenere_encrypt(const char* key, const char* text) 
{
    if((key==NULL || text==NULL) || (strlen(text)==0 && key[0] =='\0') || strlen(key)==0
     || text[0] == '\0'){
        return NULL;
    }

    if((text == NULL || key == NULL) || (strlen(key) == 1 && key[0] == ' ')){
        return NULL;
    }
        
    int key_lenght = 0;
    key_lenght = strlen(key);
    char* kluc=(char*)malloc(key_lenght+1);    
    int i=0;
    while (i<key_lenght){
        kluc[i]=toupper(key[i]);
        i++;
    }

    int text_lenght = 0;
    text_lenght = strlen(text);

    char* slovo=(char*)malloc(text_lenght+1);



    char* encrypt=(char*)malloc(text_lenght+1);

    for (int i=1;i<key_lenght;i++){

        if(!(isalpha(kluc[i]))){

            free(slovo);
            free(kluc);
            free(encrypt);
            return NULL;
        }
    }


    
    for (int i=0; i<=text_lenght;i++){

        slovo[i]=toupper(text[i]);
        
    }


    int j = 0;
    for (int i=0;i<=text_lenght;i++){
        
        if (isupper(slovo[i])){
            
            //encrypt[i]=(slovo[i]+kluc[j])%26+'A';
            encrypt[i]='A' + (((slovo[i]-'A'+ (kluc[j]-'A')) )%26)+0;

            j++;

            if (j>=key_lenght){
                j=0;
            }
                
        }
        else encrypt[i]=slovo[i];
    }

    free(slovo);
    free(kluc);
    return encrypt;
}



//--------------------------------------------------------
// vigenre decrypt function
//----------------------------------------------------------

char* vigenere_decrypt(const char* key, const char* text) 
{
    if(key==NULL || text==NULL || strlen(text)==0 || strlen(key)== 0
    || key[0] =='\0' || text[0] == '\0'){
        return NULL;
    }
        
    if((text == NULL || key == NULL) || (strlen(key) == 1 && key[0] == ' ')){
        return NULL;
    }
        

    int key_lenght = 0;
    key_lenght = strlen(key);
    char* kluc=(char*)malloc(key_lenght+1);    
    int i=0;
    while (i<key_lenght){
        kluc[i]=toupper(key[i]);
        i++;
    }

    int text_lenght = 0;
    text_lenght = strlen(text);

    char* slovo=(char*)malloc(text_lenght+1);



    char* decrypt=(char*)malloc(text_lenght+1);

    for (int i=1;i<key_lenght;i++){

        if(!(isalpha(kluc[i]))){

            free(slovo);
            free(kluc);
            free(decrypt);
            return NULL;
        }
    }

    
    for (int i=0; i<=text_lenght;i++){

        slovo[i]=toupper(text[i]);
        
    }


    int j = 0;
    for (int i=0;i<=text_lenght;i++){
        
        if (isupper(slovo[i])){

            decrypt[i] = 'Z' - (('Z'-(slovo[i]) + ((kluc[j])-'A')) % 26);

            j++;

            if (j>=key_lenght){
                j=0;
            }
                
        }
        else decrypt[i]=slovo[i];
    }

    free(slovo);
    free(kluc);
    return decrypt;
}





//-----------------------------------------------------------
/*
char* caesar_encrypt(const char* text, const int step){

	if(text == NULL || step < 0){
		return NULL;
	}

	int len = strlen(text);
	char* result = (char*)calloc(len + 1, sizeof(text));

	for (int index = 0; index < len; index++){
		result[index] = (text[index] - 'A' + step) % 26 + 'A';

	}
	result[len] = '\0';
	return result;
}
*/

//-------------------------------------------------------------------------
// BIT ENCRYPT
//-------------------------------------------------------

unsigned char* bit_encrypt(const char* text){

    int lenght = strlen(text);

	if(text==NULL || text[0]=='\0' || lenght==0 ){
        return NULL;
    }



        

    int size = sizeof(text);


    unsigned char* sifra = ((unsigned char*)calloc((2*lenght)+1,size));

    for (int c=0; c<lenght; c++){

	    int bin_num[8]={0};

		char bin_char,  character=text[c];

        
        for (int i = 0; character!=0; i++){
            int zvysok = character%2; // 0 alebo 1
            int podiel = character/2;
            bin_char = zvysok;   // modulus
            bin_num[i] = bin_char;
            character=podiel;

        }

	    for (int i=0; i<4; i++){
            int reverse = 7-i;
		    int first = bin_num[i];
		    bin_num[i]=bin_num[reverse];
		    bin_num[reverse]= first;
	    }


	    int first =bin_num[0];
	    bin_num[0]=bin_num[1];
    	bin_num[1]= first;

	    int second=bin_num[2];
	    bin_num[2]=bin_num[3];
	    bin_num[3]=second;

        int bit = 8;
        int l=4, k=0;
	    while (l<bit){
            
		    if(bin_num[l]==bin_num[k]){
                bin_num[l]=0;
            } else{
			    bin_num[l]=1;
		    }
		    k++;
            l++;
	    }

	    int binary =0, i=0;
 

	    while (i<8){
            int exponent = 7-i;
		    int mocnina=pow(2, exponent);	
		    binary=binary+bin_num[i]*mocnina;
            i++;
           
	    }   

	    sifra[c]=binary;
	}

	return sifra;
}

//---------------------------------------------------------
// BMP ENCRYPT FUNCTION
//--------------------------------------------------------------


unsigned char* bmp_encrypt(const char* key, const char* text){
    if(key == NULL || key[0] == '\0' || strlen(key) == 0 
    || text == NULL || strlen(text) == 0 || text[0]==0) {
        return NULL;
    }

    int len_text = strlen(text);
    int len_key = strlen(key);
    int size = sizeof(char);
    
    for(int i = 0; i < len_key; i++){
        if(!isalpha(key[i])){
            return NULL;
        }
    }
    int slovo = len_text;
    char* reverz = calloc(slovo+1, size)+1;
    char* vigenere = calloc(slovo+1, size)+1;
    int vig = strlen(vigenere);    
    reverz = reverse(text);
    vigenere = vigenere_encrypt(key, reverz);
    free(reverz);    

    unsigned char* bit = calloc(vig+1, sizeof(unsigned char));

    bit = bit_encrypt(vigenere);
    free(vigenere); 

    return bit;
 
    free (bit);
    free (reverz);
    free (vigenere);

}


//-----------------------------------------------------------------
// BIT DECRYPT FUNCTION
//-----------------------------------------------------------------

char* bit_decrypt(const unsigned char* text){


	if(text==NULL || text[0]=='\0'){
        return NULL;
    }

	unsigned char* slovo = (unsigned char*)calloc(strlen((char*)text)+1, sizeof(char));
	char *decrypted = (char*)calloc(strlen((char*)text)+1, sizeof(char));
	strcpy((char*)slovo, (char*)text);


    int j;
	for (j = 0; slovo[j]!='\0'; j++){

		int cislo = slovo[j];

	
		int binary[8];	

		for (int i = 0; i < 8; i++){
			binary[i] = 0;
		}

		int reverse = 7;
		while(cislo>0){
			binary[reverse] = cislo % 2;
			cislo = cislo / 2;
			reverse--;
		}
	
       
		for (int i =0; i < 4; i++){
			if (binary[i] == binary[i+4]){
				binary[i+4] = 0;
			}else {
                binary[i+4] = 1;
            }
            
		}
		
		int bin_num = 0;
        
		for (int j = 0; j < 3; j=j+2){
			bin_num = binary[j]; binary[j] = binary[j+1];
			binary[j+1] = bin_num;
		}

		int sifra = 0;
		int exponent = 0;
        int k = 7;
		while ( k >= 0){
            int mocnina = pow(2,exponent);
            sifra = sifra + binary[k]*mocnina;
			exponent++;
            k--;
		}
		decrypted[j] = sifra;

	}
 
	free(slovo);
	return decrypted;
}


//-----------------------------------------------------------------
// BMP DECRYPT FUNCTION
//---------------------------------------------------------

char* bmp_decrypt(const char* key, const unsigned char* text){
    if(key == NULL || key[0] == '\0' || strlen(key) == 0 
    || text == NULL || text[0]==0) {
        return NULL;
    }

    for(int i = 0; i < strlen(key); i++){
        if(!isalpha(key[i])){
            return NULL;
        }
    }

  
  
    char* bit_decr;
    bit_decr = bit_decrypt(text);
    char* vigenere;
    vigenere= vigenere_decrypt(key,bit_decr);
    char* reverz;
    reverz= reverse(vigenere);

free(bit_decr);
free(vigenere);

return reverz;
free(reverz);

}
