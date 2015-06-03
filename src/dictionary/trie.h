/** @file
    Interfejs drzewa TRIE.

    @ingroup dictionary
    @author Wojciech Kordalski <wojtek.kordalski@gmail.com>
            
    @copyright Uniwerstet Warszawski
    @date 2015-06-03
 */

#ifndef __TRIE_H__
#define __TRIE_H__

#include "word_list.h"
#include "rule.h"

#include <stdio.h>
#include <stdlib.h>

/**
 * Węzeł drzewa TRIE.
 */
struct trie_node;

/**
 * Tworzy nowy węzeł drzewa TRIE
 * 
 * @return Wskaźnik na drzewo TRIE.
 */
struct trie_node * trie_init();

/**
 * Destrukcja węzła drzewa TRIE wraz z poddrzewami.
 * 
 * @param[in] root Drzewo do usunięcia.
 */
void trie_done(struct trie_node *root);

/**
 * Usuwa wszystkie wyrazy z drzewa.
 * 
 * @param[in,out] root Drzewo do wyczyszczenia.
 */
void trie_clear(struct trie_node *root);

/**
 * Wstawia wyraz do drzewa.
 * 
 * @param[in,out] root Drzewo, do którego wstawić słowo.
 * @param[in] word Słowo do wstawienia.
 * @return 1 jeśli wstawiono słowo, 0 jeśli istniało wcześniej.
 */
int trie_insert(struct trie_node *root, const wchar_t *word);

/**
 * Sprawdza, czy słowo istnieje w drzewie.
 * 
 * @param[in] root Drzewo do przeszukania.
 * @param[in] word Słowo do znalezienia.
 * @return 0 jeśli nie znaleziono słowa, 1 gdy znaleziono.
 */
int trie_find(const struct trie_node *root, const wchar_t *word);

/**
 * Usuwa słowo z drzewa.
 * 
 * @param[in,out] root Drzewo, z którego usunąć słowo.
 * @param[in] word Słowo do usunięcia.
 * @return 1 jeśli usunięto słowo, 0 jeśli takowe słowo nie ustniało.
 */
int trie_delete(struct trie_node *root, const wchar_t *word);

/**
 * Zapisuje drzewo do strumienia.
 * 
 * @param[in] root Drzewo do zapisania.
 * @param[in] file Strumień, gdzie zapisać drzewo.
 */
int trie_serialize(struct trie_node *root, FILE *file);

/**
 * Ładuje drzewo ze strumienia.
 * 
 * @param[in] file Strumień, z którego wczytać drzewo.
 * @return Wczytane drzewo.
 */
struct trie_node * trie_deserialize(FILE *file);

/**
 * Zwraca dziecko o podanej wartości.
 * 
 * @param[in] node Węzeł, którego dziecko zwrócić.
 * @param[in] value Wartość dziecka.
 * @return Węzeł reprezentujący dziecko lub NULL jeśli takowe nie istnieje.
 */
const struct trie_node * trie_get_child(const struct trie_node *node, wchar_t value);

/**
 * Znajduje wyrazy podobne do podanego w drzewie.
 * 
 * @param[in] root Drzewo do przeszukania.
 * @param[in] word Słowo wzorcowe, do którego znaleźć podobne.
 * @param[out] list Lista słów podobnych.
 */
void trie_hints(struct trie_node* root, const wchar_t* word, struct word_list* list, struct hint_rule** rules);

#endif /* __TRIE_H__ */