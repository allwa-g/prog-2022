#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "k.h"

// A B C  D  E  F  G   H   I   J    K
// 2 4 8 16 32 64 128 256 512 1028 2048


//board[row][column]

void add_random_tile(struct game *game){
    int i;
	int j;

    do{
        i = rand() % SIZE;
        j = rand() % SIZE;
    }while(game->board[i][j] != ' ');

    if(rand() % SIZE-2 == 0){
        game->board[i][j] = 'A';
    }else {
        game->board[i][j] = 'B';
    }
	

}



bool update(struct game *game, int dy, int dx){
  	if((dy != 0  && dx != 0) || ( dx==0 && dy == 0)){
    	return false;
  	}

	if(!is_move_possible(*game)){
		return false;
	}

	if(is_game_won(*game)){
		return false;
	}

	bool is_changed = false;

	int j, i ;
		if (dy==-1)
			{
				for (int j = 0; j < SIZE; j++){
					
					int i=SIZE-1;
					while(i>0){
						if ((game->board[i][j]!=' ') && (game->board[i-1][j]== ' ')){      // aktualne pole je plne, pole nad nim je praznde
							game->board[i-1][j]=game->board[i][j];
							game->board[i][j]=' ';
							is_changed = true;
							if(is_changed == true){
								i=SIZE-1;
							}
						} else if ((game->board[i][j] ==' ') || (game->board[i-1][j] != ' ')){
							i--;
						}
					}

					for ( i = 0; i < SIZE-1; i++){
					
						if ((game->board[i][j]==game->board[i+1][j]) && (game->board[i][j]!=' ')){   // aktualne pole je plne, pole nad nim je plne
						
							game->board[i][j]++;
							game->score=game->score+(int)pow(2,game->board[i][j]-(int)pow(2,6));
							
							is_changed = true;
							if(is_changed == true){
								game->board[i+1][j]=' ';
							}

						}
					}
						
				}
					
			} else if (dy == 1)
			{
				
				for ( j = 0; j < SIZE; ++j)
				{
						
					i=0;
					while(i<SIZE-1){
					if (game->board[i][j]!=' '&& game->board[i+1][j]== ' '){
						
							game->board[i+1][j]=game->board[i][j];
							game->board[i][j]=' ';
							i=0;

							is_changed = true;
						} else if(game->board[i][j] == ' ' || game->board[i+1][j] != ' '){
							i++;
						}
					}

					for ( i = SIZE-1; i > 0; i--){
					
						if (game->board[i][j]==game->board[i-1][j] && game->board[i][j]!=' '){
						
							game->board[i][j]++;
							game->score=game->score+(int)pow(2,game->board[i][j]-(int)pow(2,6));
							

							is_changed = true;
							if(is_changed == true){
								game->board[i-1][j]=' ';
							}
						}
					}
											
				}
			} else if (dx == -1){   //VLAVO
			
				for ( i = 0; i < SIZE; ++i){
				
						
					j=3;
					while(j>0){
						if (game->board[i][j]!=' '&& game->board[i][j-1]== ' '){
						
							game->board[i][j-1]=game->board[i][j];
							game->board[i][j]=' ';
							j=SIZE-1;
							is_changed = true;
						} else if(game->board[i][j]==' '|| game->board[i][j-1]!= ' '){
							j--;
						}
					}

					for ( j = 0; j < SIZE-1; j++)
					{
						if (game->board[i][j]==game->board[i][j+1] && game->board[i][j]!=' '){
							game->board[i][j]++;
							game->score=game->score+(int)pow(2,game->board[i][j]-(int)pow(2,6));
							
							is_changed = true;
							if(is_changed == true){
								game->board[i][j+1]=' ';
							}
						}
					}

						
						
				}
			} else if (dx ==1){    //VPRAVO
			
				
				for ( i = 0; i < SIZE; i++){
				
						

					for ( j = 0; j <SIZE-1; j++){
						
								
						for ( j = SIZE-1; j > 0; j--){
								
							if (game->board[i][j]==game->board[i][j-1] && game->board[i][j]!=' '){
									
								game->board[i][j]++;
								game->score=game->score+(int)pow(2,game->board[i][j]-(int)pow(2,6));
								
								is_changed = true;	
								if(is_changed == true){
									game->board[i][j-1]=' ';
								}								
							}
						}

						j=0;
						while(j<3){
							if (game->board[i][j]!=' '&& game->board[i][j+1]== ' '){
									
								game->board[i][j+1]=game->board[i][j];
								game->board[i][j]=' ';
							
								is_changed = true;
								if(is_changed == true){
									j=0;
								}
							} else if (game->board[i][j] == ' ' || game->board[i][j+1] != ' '){
								j++;
							} 

						}								

								
					}
					
						
				}
			}




		//return zmena;
		return is_changed;
	//}



	


}







//-----------------------------------------------------------------------
bool is_move_possible(const struct game game){
    
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){

			if(((game.board[i][j] == game.board[i+1][j]) && (i < SIZE -1)) || ((game.board[i][j] == game.board[i][j+1]) && (j < SIZE - 1))){
				return true;

			} else if(game.board[i][j]==' '){
				return true;
			}

        }
    }

    return false;
}


bool is_game_won(const struct game game){
	for (int i = 0; i < SIZE; i++){
		for (int j = 0; j < SIZE; j++){
			if (game.board[i][j] == 'K'){
				return true;
			}
		}
	}
	return false;
}
