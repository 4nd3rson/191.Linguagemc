#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int played, computer, playerpoints = 0, pcpoints = 0, times;
    printf("ROCK, PAPER AND SCISSORS\n");
    printf("--------Welcome---------\n");
    printf("\n");

    printf("How many times you want play? ");
    scanf("%d", &times);
    printf("\n");
    printf(":::::::::::I:N:I:C:I:O:::::::::::");

    for(int c = 1; times >= c; c++){

        printf("\n");
        printf("-----------------------\n");
        printf("[1] - ROCK\n");
        printf("[2] - PAPER\n");
        printf("[3] - SCISSORS\n");
        printf("-----------------------\n");
        printf("\n");

        printf("Enter an option above: ");
        scanf("%d", &played);
        printf("\n");

        srand(time(NULL));
        computer = rand() % 3;

        switch(played){
            case 1:
                if(computer == 0){
                    printf("You played *ROCK* and the computer played *ROCK*");
                }else if(computer == 1){
                    printf("You played *ROCK* and the computer played *PAPER*");
                    pcpoints++;
                }else{
                    printf("You played *ROCK* and the computer played *SCISSORS*");
                    playerpoints++;
                }
                break;
            case 2:
                if(computer == 0){
                    printf("You played *PAPER* and the computer played *ROCK*");
                    playerpoints++;
                }else if(computer == 1){
                    printf("You played *PAPER* and the computer played *PAPER*");
                }else{
                    printf("You played *PAPER* and the computer played *SCISSORS*");
                    pcpoints++;
                }
                break;
            case 3:
                if(computer == 0){
                    printf("You played *SCISSORS* and the computer played *ROCK*");
                    pcpoints++;
                }else if(computer == 1){
                    printf("You played *SCISSORS* and the computer played *PAPER*");
                    playerpoints++;
                }else{
                    printf("You played *SCISSORS* and the computer played *SCISSORS*");
                }
                break;
        }
        printf("\n\n");
    }
    printf("\n");
    printf(":::::::::::P:L:A:C:A:R::::::::::::");
    printf("\n");
    printf("\n####### YOU %d x %d COMPUTER #######", playerpoints, pcpoints);

    getch();

    return 0;
}
