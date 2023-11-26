
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the number of cards in a deck and the number of suits
#define NUM_CARDS 52
#define NUM_SUITS 4

// Enum to represent card suits
typedef enum {
    CLUBS,
    DIAMONDS,
    HEARTS,
    SPADES
} Suit;

// Array of suit names
const char* suitNames[] = { "Clubs", "Diamonds", "Hearts", "Spades" };

// Array of card ranks' names
const char* rankNames[] = { "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace" };

// Function to shuffle an array of integers
void shuffle(int array[], int size) {
    for (int i = size - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}

int main() {
    // Create an array to represent a deck of cards
    int deck[NUM_CARDS];
    for (int i = 0; i < NUM_CARDS; i++) {
        deck[i] = i;
    }

    // Shuffle the deck
    srand(time(NULL));
    shuffle(deck, NUM_CARDS);

    // Split the deck into two hands for each player
    int player1[NUM_CARDS / 2];
    int player2[NUM_CARDS / 2];
    for (int i = 0; i < NUM_CARDS / 2; i++) {
        player1[i] = deck[i];
        player2[i] = deck[i + NUM_CARDS / 2];
    }

    // Play the game
    int rounds = 0;
    int player1Score = 0, player2Score = 0;

    while (rounds < NUM_CARDS / 2) {
        int card1 = player1[rounds];
        int card2 = player2[rounds];

        Suit suit1 = (Suit)(card1 / 13);
        Suit suit2 = (Suit)(card2 / 13);

        int rank1 = card1 % 13;
        int rank2 = card2 % 13;

        printf("Round %d: Player 1 plays card %s (%s), Player 2 plays card %s (%s)\n", rounds + 1, rankNames[rank1], suitNames[suit1], rankNames[rank2], suitNames[suit2]);

        if (rank1 == 12 && rank2 != 12) {
            printf("Player 1 wins the round!\n");
            player1Score++;
        }
        else if (rank2 == 12 && rank1 != 12) {
            printf("Player 2 wins the round!\n");
            player2Score++;
        }
        else if (rank1 > rank2) {
            printf("Player 1 wins the round!\n");
            player1Score++;
        }
        else if (rank2 > rank1) {
            printf("Player 2 wins the round!\n");
            player2Score++;
        }
        else {
            printf("It's a tie! War is declared.\n");
        }

        rounds++;

        // Ask the user to continue or quit
        char choice;
        printf("Continue playing? (Y/N): ");
        scanf(" %c", &choice);

        if (choice != 'Y' && choice != 'y') {
            break;
        }
    }

    printf("\nGame Over!\n");
    printf("Player 1's score: %d\n", player1Score);
    printf("Player 2's score: %d\n", player2Score);

    return 0;
}