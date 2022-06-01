#include <stdio.h>
#include <stdlib.h>
#include <math.h>
  


//int mighty_metod(int number);

int mighty_metod(int num){

	int sucet = 0;
    int max = 10;
	while (num != 0){
		sucet = sucet + num % max;
		num = num / max;
	}
	return sucet;
}

int main(){
	int sucet = 0;
	char cislo;
	while(1){						//infinite loop
	
		scanf("%c", &cislo);
		if (cislo >= '0' && cislo <= '9'){
		
			sucet = sucet + (int)(cislo - '0');
		}
		else if (cislo < '0' || cislo > '9'){
		
			break;
		}

	} 


	while (sucet > 9){
	
		sucet = mighty_metod(sucet);
	}
	printf("%d\n", sucet);
	return 0;
}
