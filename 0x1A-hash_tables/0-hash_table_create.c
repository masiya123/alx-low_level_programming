#include "hash_tables.h"

/**
 * hash_table_create - Creates a new hash table.
 * @size: The size of the array.
 *
 * Return: A pointer to the newly created hash table, or NULL on failure.
 */
hash_table_t *hash_table_create(unsigned long int size)
{
    hash_table_t *ht;
    hash_node_t **array;

    /* Allocate memory for the hash table struct */
    ht = malloc(sizeof(hash_table_t));
    if (ht == NULL)
        return (NULL);

    /* Allocate memory for the array of hash node pointers */
    array = malloc(sizeof(hash_node_t *) * size);
    if (array == NULL)
    {
        free(ht); /* Free previously allocated memory */
        return (NULL);
    }

    /* Initialize array elements to NULL */
    for (unsigned long int i = 0; i < size; i++)
        array[i] = NULL;

    /* Assign values to the hash table struct */
    ht->size = size;
    ht->array = array;

    return (ht);
}
