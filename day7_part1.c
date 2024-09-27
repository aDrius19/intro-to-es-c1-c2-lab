#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_HANDS 10000
#define MAX_ARR_VAL 11
#define HAND_SIZE 6 // 5 cards + 1 space '\0'

typedef struct {
    char hand[HAND_SIZE];
    int bid;
    int rank;
} CardHand;

int cardValue(char card) {
    if (card >= '2' && card <= '9') return card - '2';
    if (card == 'T') return 8; // 10
    if (card == 'J') return 9; // Jack
    if (card == 'Q') return 10; // Queen
    if (card == 'K') return 11; // King
    if (card == 'A') return 12; // Ace
    return -1; // Invalid
}

int handType(char *hand) {
    int count[13] = {0}; // For cards 2-9, T, J, Q, K, A
    for (int i = 0; i < 5; i++) {
        count[cardValue(hand[i])]++;
    }

    int threeOfAKind = 0;
    int pair = 0;
    int fourOfAKind = 0;
    int fiveOfAKind = 0;
    for (int i = 0; i < 13; i++) {
        if (count[i] == 5) fiveOfAKind++;
        if (count[i] == 4) fourOfAKind++;
        if (count[i] == 3) threeOfAKind++;
        if (count[i] == 2) pair++;
    }

    if (fiveOfAKind) return 7; // Five of a kind
    if (fourOfAKind) return 6; // Four of a kind
    if (threeOfAKind && pair) return 5; // Full house
    if (threeOfAKind) return 4; // Three of a kind
    if (pair == 2) return 3; // Two pair
    if (pair == 1) return 2; // One pair
    return 1; // High card
}

int compareHands(const void *a, const void *b) {
    CardHand *hand1 = (CardHand *)a;
    CardHand *hand2 = (CardHand *)b;

    int type1 = handType(hand1->hand);
    int type2 = handType(hand2->hand);
    if (type1 != type2) return type1 - type2; // Higher type wins

    // Compare card values for ranking
    int value1[5], value2[5];
    for (int i = 0; i < 5; i++) {
        value1[i] = cardValue(hand1->hand[i]);
        value2[i] = cardValue(hand2->hand[i]);
    }

    for (int i = 0; i < 5; i++) {
        if (value1[i] != value2[i]) return value1[i] - value2[i];
    }

    return 0;
}

int main() {
    CardHand hands[MAX_HANDS];
    int handCount = 0;
    FILE *inputFile;
    inputFile = fopen("day7_part1.txt", "r"); // Put the input into a file

    if (inputFile != NULL)
    {
        char oneFileLine[MAX_ARR_VAL];

        while (fgets(oneFileLine, sizeof(oneFileLine), inputFile)) // Loops until the last line from the file
        {
            char *res;
            res = strtok(oneFileLine, " ");
            char hand[HAND_SIZE] = "";
            int bid = 0;

            while(res != NULL) 
            {
                if (strlen(res) == 5) memcpy(hand, res, HAND_SIZE);
                else bid = atoi(res);

                res = strtok(NULL, " ");
                
            }
           if (strlen(hand) > 0 && bid > 0) 
           {
                memcpy(hands[handCount].hand, hand, HAND_SIZE);
                hands[handCount].bid = bid;
                hands[handCount].rank = 0;
                handCount++;
            }
            
        }
        
        fclose(inputFile);
    }
    else
    {
        printf("Couldn't open file\n");
    }

    // Sort hands
    qsort(hands, handCount, sizeof(CardHand), compareHands);

    for (int i = 0; i < handCount; i++) {
        hands[i].rank = i + 1;
    }

    // Calculate total winnings
    long long int totalWinnings = 0;
    for (int i = 0; i < handCount; i++) {
        //printf("hand: %s bid: %d\n", hands[i].hand, hands[i].bid);
        totalWinnings += hands[i].bid * hands[i].rank;
    }

    printf("Total Winnings: %I64d\n", totalWinnings);
    
    return 0;
}