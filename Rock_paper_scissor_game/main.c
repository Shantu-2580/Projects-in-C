#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(0));
    int player, computer = rand() % 3; // Random number between 0 and 2

    // 0 --> Snake
    // 1 --> Water
    // 2 --> Gun
    printf("Welcome to the Snake Water Gun Game!\n");
    printf("Rules:\n");
    printf("0: Rock\n");
    printf("1: Paper\n");
    printf("2: Scissor\n");
    printf("To exit the game, enter a number outside the range (0-2).\n");

    while (1)
    {

        printf("Enter your choice (0, 1, or 2): ");
        scanf("%d", &player);

        if (player == computer)
        {
            printf("It's a tie! You both chose %d.\n", player);
        }
        else if ((player == 0 && computer == 1) ||
                 (player == 1 && computer == 2) ||
                 (player == 2 && computer == 0))
        {
            printf("You Lose! You chose %d and the computer chose %d.\n", player, computer);
        }
        else
        {
            printf("You Won! You chose %d and the computer chose %d.\n", player, computer);
        }

        if(player != 0 && player != 1 && player != 2) {
            printf("Exiting the game.\n");
            break;
        }
    }
    return 0;
}
