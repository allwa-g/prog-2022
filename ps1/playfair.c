#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include "playfair.h"


char* playfair_encrypt(const char* key, const char* text);
char* playfair_decrypt(const char* key, const char* text);
