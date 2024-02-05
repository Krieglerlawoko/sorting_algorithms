#include "deck.h"

int _strcmp(const char *s1, const char *s2);
void insertion_sort_deck_value(deck_node_t **deck);
void sort_deck(deck_node_t **deck);
char get_value(deck_node_t *card);
void insertion_sort_deck_kind(deck_node_t **deck);

/**
 * _strcmp - Compares two strings.
 * @s1: The first string to be compared.
 * @s2: The second string to be compared.
 *
 * Return: Positive byte difference if s1 > s2
 *         0 if s1 == s2
 *         Negative byte difference if s1 < s2
 */
int _strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}

	if (*s1 != *s2)
		return (*s1 - *s2);
	return (0);
}

/**
 * get_value - Numerical value of a card got.
 * @card: Points to a deck_node_t card.
 *
 * Return: card numerical value.
 */
char get_value(deck_node_t *card)
{
	if (_strcmp(card->card->value, "Ace") == 0)
		return (0);
	if (_strcmp(card->card->value, "1") == 0)
		return (1);
	if (_strcmp(card->card->value, "2") == 0)
		return (2);
	if (_strcmp(card->card->value, "3") == 0)
		return (3);
	if (_strcmp(card->card->value, "4") == 0)
		return (4);
	if (_strcmp(card->card->value, "5") == 0)
		return (5);
	if (_strcmp(card->card->value, "6") == 0)
		return (6);
	if (_strcmp(card->card->value, "7") == 0)
		return (7);
	if (_strcmp(card->card->value, "8") == 0)
		return (8);
	if (_strcmp(card->card->value, "9") == 0)
		return (9);
	if (_strcmp(card->card->value, "10") == 0)
		return (10);
	if (_strcmp(card->card->value, "Jack") == 0)
		return (11);
	if (_strcmp(card->card->value, "Queen") == 0)
		return (12);
	return (13);
}

/**
 * insertion_sort_deck_kind - Sort a deck of cards from spades to diamonds.
 * @deck: A pointer to the head of a deck_node_t doubly-linked list.
 */
void insertion_sort_deck_kind(deck_node_t **deck)
{
	deck_node_t *itr, *insert, *tmp;

	for (itr = (*deck)->next; itr != NULL; itr = tmp)
	{
		tmp = itr->next;
		insert = itr->prev;
		while (insert != NULL && insert->card->kind > itr->card->kind)
		{
			insert->next = itr->next;
			if (itr->next != NULL)
				itr->next->prev = insert;
			itr->prev = insert->prev;
			itr->next = insert;
			if (insert->prev != NULL)
				insert->prev->next = itr;
			else
				*deck = itr;
			insert->prev = itr;
			insert = itr->prev;
		}
	}
}

/**
 * insertion_sort_deck_value - Deck of cards sorted from
 *                             spades to diamonds from ace to king.
 * @deck: A pointer to the head of a deck_node_t doubly-linked list.
 */
void insertion_sort_deck_value(deck_node_t **deck)
{
	deck_node_t *itr, *insert, *tmp;

	for (itr = (*deck)->next; itr != NULL; itr = tmp)
	{
		tmp = itr->next;
		insert = itr->prev;
		while (insert != NULL &&
		       insert->card->kind == itr->card->kind &&
		       get_value(insert) > get_value(itr))
		{
			insert->next = itr->next;
			if (itr->next != NULL)
				itr->next->prev = insert;
			itr->prev = insert->prev;
			itr->next = insert;
			if (insert->prev != NULL)
				insert->prev->next = itr;
			else
				*deck = itr;
			insert->prev = itr;
			insert = itr->prev;
		}
	}
}

/**
 * sort_deck - Cards deck sortd from ace to king and
 *             from spades to diamonds.
 * @deck: Pointer to the head of a deck_node_t doubly-linked list.
 */
void sort_deck(deck_node_t **deck)
{
	if (deck == NULL || (*deck)->next == NULL || *deck == NULL)
		return;

	insertion_sort_deck_kind(deck);
	insertion_sort_deck_value(deck);
}
