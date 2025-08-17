#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Seed the random number generator with current time
    srand(time(0));

    // Generate random number between 1 and 100
    int randomNumber = (rand() % 100) + 1;
    int guess = 0;
    int attempts = 0;
    
    printf("Welcome to the Guess the Number game!\n");
    printf("I have selected a number between 1 and 100.\n");
    printf("Try to guess it!\n");

    while (guess != randomNumber)
    {
        printf("Enter your guess: ");
        scanf("%d", &guess);

        if (guess < 1 || guess > 100)
        {
            printf("Please enter a number between 1 and 100.\n");
        }
        if (guess < randomNumber)
        {
            printf("Too low! Try again.\n");
        }
        else
        {
            printf("Too high! Try again.\n");
        }
        attempts++;

    }
    printf("Congratulations! You've guessed the number %d in %d attempts.\n", randomNumber, attempts);
    printf("Thanks for playing!\n");
    return 0;
}