#include <stdlib.h>
#include <string.h>
#include "hash_tables.h"

/**
 * hash_table_create - creates a hash table
 * @size: the size of the array
 *
 * Return: a pointer to the newly created hash table, or NULL if something went wrong
 */
hash_table_t *hash_table_create(unsigned long int size)
{
    hash_table_t *ht;

    ht = malloc(sizeof(hash_table_t));
    if (!ht)
        return (NULL);
    ht->size = size;
    ht->array = calloc(size, sizeof(hash_node_t *));
    if (!ht->array)
    {
        free(ht);
        return (NULL);
    }
    return (ht);
}

/**
 * hash_table_destroy - frees the memory allocated for a hash table
 * @ht: a pointer to the hash table to be destroyed
 */
void hash_table_destroy(hash_table_t *ht)
{
    unsigned long int i;

    for (i = 0; i < ht->size; i++)
    {
        hash_node_t *node = ht->array[i];
        hash_node_t *next;

        while (node)
        {
            next = node->next;
            free(node->key);
            free(node->value);
            free(node);
            node = next;
        }
    }
    free(ht->array);
    free(ht);
}
