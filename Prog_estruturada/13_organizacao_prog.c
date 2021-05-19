#include <stdio.h>

#define NUM_RANKS 13
#define NUM_SUITS 4
#define NUM_CARDS 5

int num_in_rank[NUM_RANKS];  //Quantidade de valores nas cartas, 13 diferentes valores.
int num_in_suit[NUM_SUITS];  //Quantidade de nipes, que são 4.
int flush, straight, four, three, pairs;
char ranks_array[NUM_RANKS] = {'2','3','4','5','6','7','8','9','t','q','j','k','a'};
char suits_array[NUM_CARDS] = {'c','d','h','s'};

void read_cards(void);
void analyze_cards(void);
void print_result(void);
int validade_rank(char a);
int validade_suit(char a);

int main(){

    read_cards();
    analyze_cards();
    print_result();

    return 0;
}
//Checking if the rank is valid.
int validade_rank(char a){
    int cont = 0;

    for (int i=0; i<NUM_RANKS; i++){
        if (a == ranks_array[i])
            cont++;}

        if (cont > 0)
            return 1;
        else
            return 0;
}
//Checking if the suit is valid.
int validade_suit(char a){
    int cont = 0;

    for (int i=0; i<NUM_SUITS; i++)
        if (a == suits_array[i]){
            cont++;}

        if (cont > 0)
            return 1;
        else
            return 0;
}

/*************************************************
*Reads the cards into global variables num_in_rank
* and num_in_suit. It also checks for invalid cards.
**************************************************/
void read_cards(void){

    int cards_read = 0;
    int rank, suit;
    char rank_ch, suit_ch;

    for (int i=0; i<NUM_RANKS; i++)
        num_in_rank[i] = 0;

    for (int i=0; i<NUM_SUITS; i++)
        num_in_suit[i] = 0;

    while (cards_read < NUM_CARDS){
        printf("Digite uma carta: ");

        rank_ch = getchar();
        switch (rank_ch){
            case '2': rank = 0; break;
            case '3': rank = 1; break;
            case '4': rank = 2; break;
            case '5': rank = 3; break;
            case '6': rank = 4; break;
            case '7': rank = 5; break;
            case '8': rank = 6; break;
            case '9': rank = 7; break;
            case 't': rank = 8; break;
            case 'q': rank = 9; break;
            case 'j': rank = 10; break;
            case 'k': rank = 11; break;
            case 'a': rank = 12; break;}

        suit_ch = getchar();
        switch (suit_ch){
            case 'c': suit = 0; break;
            case 'd': suit = 1; break;
            case 'h': suit = 2; break;
            case 's': suit = 3; break;}

        getchar(); //Get the \n character.

        if (validade_rank(rank_ch) && validade_suit(suit_ch)){

        num_in_rank[rank]++;
        num_in_suit[suit]++;
        cards_read++;
        }

        else
            if (validade_rank(rank_ch) != 1 || validade_suit(suit_ch) != 1)
                printf("\nValor inválido, digite outra carta!\n");
    }
}

/*****************************************************
* Determines if the hand contains a straight, a flush,
* four-of-a-kind, three-of-a-kind, and how many pairs.
******************************************************/
void analyze_cards(void){

    int rank;
    int num_consec = 0;
    flush = 0;
    straight = 0;
    four = 0;
    three = 0;
    pairs = 0;

    // check for flush
    for(int i=0; i<NUM_SUITS; i++){
        if(num_in_suit[i] == NUM_CARDS)
            flush = 1;
    }
    //check for straight
    rank = 0;
    while (num_in_rank[rank] == 0)
        rank++;

    for(; rank<NUM_RANKS && num_in_rank[rank]>0; rank++)
        num_consec++;

    if (num_consec == NUM_CARDS){
        straight = 1;
        return;
    }
    for(int i=0; i<NUM_RANKS; i++){
        if(num_in_rank[i] == 4) four = 1;
        if(num_in_rank[i] == 3) three = 1;
        if(num_in_rank[i] == 2) pairs++;
    }
}

/*********************************************
*Print the result based on the last function.
*********************************************/
void print_result(void){

    if(straight && flush)
        printf("\nStraight Flush\n");
    else if (four)
        printf("\nFour of a kind\n");
    else if (three && pairs == 1)
        printf("\nFull house\n");
    else if (flush)
        printf("\nFlush\n");
    else if (straight)
        printf("\nStraight\n");
    else if (three)
        printf("\nThree of a kind\n");
    else if (pairs == 2)
        printf("\nDois pares\n");
    else if (pairs == 1)
        printf("\nPar\n");
    else
        printf("\nCarta mais alta\n");
}
