#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Simple Betting Game
// Jack Queen King - computer shuffles these cards
// player has to guess the position of Queen.
// if he wins, he takes 3*bet
// if he looses, he looses the bet amount.
// player starts with $100.

void play(int bet);

int cash = 100;

int main()
{
    int bet;
    printf("What's to the Betting Game\n");
    printf("Total cash = $%d\n", cash);
    while (cash > 0) {
        printf("What's your bet? $");
        scanf("%d", &bet);
        if (bet == 0 || bet > cash)
            break;
        play(bet);
    }

    return 0;
}

void play(int bet)
{
    char C[3] = {'J', 'Q', 'K'};
    printf("Shuffling..");
    srand(time(NULL)); // seeding random number generator

    int i;
    for (i = 0; i < 5; i++) {
        int x = rand() % 3;
        int y = rand() % 3;
        int tmp = C[x];
        C[x] = C[y];
        C[y] = tmp;
    }
    int playersGuess;
    printf("What's the positon of queen - 1, 2, 3?:\t");
    scanf("%d", &playersGuess);

    if (C[playersGuess - 1] == 'Q') {
        cash += 3*bet;
        printf("You win! Result = { %c %c %c } Total Cash = %d\n", C[0], C[1], C[2], cash);
    } else {
        cash -= bet;
        printf("You lost! Result = { %c %c %c } Total Cash = %d\n", C[0], C[1], C[2], cash);
    }

}