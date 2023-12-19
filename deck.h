#ifndef DECK_H
#define DECK_H

#include <stdlib.h>

/**
 * struct card_s - cards
 *
 * @value: Value of card
 * From "Ace" to "King"
 * @kind: Kind of card
 */
typedef struct card_s
{
	const char *value;
	const kind_t kind;
} card_t;

/**
 * enum kind_e - card suit's enumeration
 * @SPADE: suit of Spades
 * @HEART: suit of Hearts
 * @CLUB: suit of Clubs
 * @DIAMOND: suit of Diamonds
 */
typedef enum kind_e
{
	SPADE = 0,
	HEART,
	CLUB,
	DIAMOND
} kind_t;

/**
 * struct deck_node_s - card deck
 *
 * @card: Pointer to card of node
 * @prev: Pointer to previous node of list
 * @next: Pointer to next node of list
 */
typedef struct deck_node_s
{
	const card_t *card;
	struct deck_node_s *prev;
s	struct deck_node_s *next;
} deck_node_t;

void sort_deck(deck_node_t **deck);

#endif /* DECK_H */
