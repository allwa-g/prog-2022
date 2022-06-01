#include "hof.h"
#include "ui.h"
#include <stdio.h>
#include <stdlib.h>
#include "k.h"
//#include <ncurses.h>

bool move(struct game *game, char key);

int main(){
    int hrac = 10;
    struct player player;
    char pismeno;
    int hra;
    printf("Your name: ");
    scanf("%s", player.name );
    //scanf();
    
    struct game game = {
        .board = {
            {' ', ' ', ' ', ' '},
            {' ', ' ', ' ', ' '},
            {' ', ' ', ' ', ' '},
            {' ', ' ', ' ', ' '}
        },

    };
    player.score = 0;
    game.score = 0;

    while (is_move_possible(game)){
        if(!is_game_won(game)){
            add_random_tile(&game);
            render(game);
            do{
                printf("Enter a direction: ");
                scanf("%c", &pismeno);
                //while (getchar() != '\n');
                hra = 0;
                if (!is_move_possible(game)){
            
                    printf("Move is not possible!\n");
                    hra = 0;
                }else if (!move(&game, pismeno)){
            
            
                    printf("You can enter only w,a,s,d !\n");
                    hra = 1;
                }
            } while (hra);

        }else if (is_game_won(game)){
            struct player list[hrac];
            int lst_size = load(list);
            player.score = game.score;
            if (add_player(list, &lst_size, player)){
                save(list, lst_size);
            }else{
                printf("You are not in the TOP 10\n");
            }
        }


    } 
    if(!is_move_possible(game)){
        struct player list[hrac];  
        int lst_size = load(list);
        
        player.score = game.score;
        if (add_player(list, &lst_size, player)){
            save(list, lst_size);
        }else{
            printf("You are not in the TOP 10\n");
        }        
    }

    return 0;
}


bool move(struct game *game, char key){
    int dx,dy;
    switch (key){
    
    case ('a'): 
    case ('A'):
    //case (KEY_LEFT):
        dx = -1;
        dy = 0;
        if (!update(game, dy, dx)){
        
            return false;
        }
        break;

    case ('s'):
    case ('S'):
    //case(KEY_DOWN):
        dx = 0;
        dy = 1;
        if (!update(game, dy, dx)){
        
            return false;
        }
        break;

    case ('w'):
    case ('W'):
    //case (KEY_UP):
        dx = 0;
        dy = -1;
        if (!update(game, dy, dx)){
        
            return false;
        }
        break;


    case ('d'):
    case ('D'):
    //case (KEY_RIGHT):
        dx = 1;
        dy = 0;
        if (!update(game, dy, dx)){
        
            return false;
        }
        break;
    default:
        return false;
    }
    return true;
}
