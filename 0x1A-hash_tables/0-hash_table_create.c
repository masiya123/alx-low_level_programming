#include "hash_tables.h"

/**
 * hash_table_create - Creates a hash table.
 * @size: Size of the array in the hash table
 *
 * Return: Pointer to the newly created hash table, or NULL on failure
 */
hash_table_t *hash_table_create(unsigned long int size)
{
    hash_table_t *ht = malloc(sizeof(hash_table_t));

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
