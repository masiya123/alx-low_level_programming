#include "hash_tables.h"

shash_table_t *shash_table_create(unsigned long int size)
{
    shash_table_t *sht;
    unsigned long int i;

    sht = malloc(sizeof(shash_table_t));
    if (sht == NULL)
        return (NULL);
    sht->size = size;
    sht->shead = NULL;
    sht->stail = NULL;
    sht->array = malloc(sizeof(shash_node_t *) * size);
    if (sht->array == NULL)
    {
        free(sht);
        return (NULL);
    }
    for (i = 0; i < size; i++)
        sht->array[i] = NULL;
    return (sht);
}

shash_node_t *make_shash_node(const char *key, const char *value)
{
    shash_node_t *node;

    node = malloc(sizeof(shash_node_t));
    if (node == NULL)
        return (NULL);
    node->key = strdup(key);
    node->value = strdup(value);
    if (node->key == NULL || node->value == NULL)
    {
        free(node);
        return (NULL);
    }
    node->next = NULL;
    node->sprev = NULL;
    node->snext = NULL;
    return (node);
}

void add_to_sorted_list(shash_table_t *ht, shash_node_t *node)
{
    shash_node_t *tmp;

    if (ht->shead == NULL)
    {
        ht->shead = node;
        ht->stail = node;
        return;
    }
    tmp = ht->shead;
    while (tmp && strcmp(node->key, tmp->key) > 0)
        tmp = tmp->snext;
    if (tmp == NULL)
    {
        node->sprev = ht->stail;
        ht->stail->snext = node;
        ht->stail = node;
    }
    else
    {
        node->sprev = tmp->sprev;
        node->snext = tmp;
        if (tmp->sprev)
            tmp->sprev->snext = node;
        else
            ht->shead = node;
        tmp->sprev = node;
    }
}

int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
    unsigned long int idx;
    shash_node_t *node, *new_node;

    if (!key || !value || !ht)
        return (0);
    idx = key_index((const unsigned char *)key, ht->size);
    node = ht->array[idx];
    while (node)
    {
        if (strcmp(node->key, key) == 0)
        {
            free(node->value);
            node->value = strdup(value);
            return (1);
        }
        node = node->next;
    }
    new_node = make_shash_node(key, value);
    if (!new_node)
        return (0);
    new_node->next = ht->array[idx];
    ht->array[idx] = new_node;
    add_to_sorted_list(ht, new_node);
    return (1);
}

char *shash_table_get(const shash_table_t *ht, const char *key)
{
    unsigned long int idx;
    shash_node_t *node;

    if (!ht || !key)
        return (NULL);
    idx = key_index((const unsigned char *)key, ht->size);
    node = ht->array[idx];
    while (node)
    {
        if (strcmp(node->key, key) == 0)
            return (node->value);
        node = node->next;
    }
    return (NULL);
}

void shash_table_print(const shash_table_t *ht)
{
    shash_node_t *node;

    if (!ht)
        return;
    node = ht->shead;
    printf("{");
    while (node)
    {
        printf("'%s': '%s'", node->key, node->value);
        node = node->snext;
        if (node)
            printf(", ");
    }
    printf("}\n");
}

void shash_table_print_rev(const shash_table_t *ht)
{
    shash_node_t *node;

    if (!ht)
        return;
    node = ht->stail;
    printf("{");
    while (node)
    {
        printf("'%s': '%s'", node->key, node->value);
        node = node->sprev;
        if (node)
            printf(", ");
    }
    printf("}\n");
}

void shash_table_delete(shash_table_t *ht)
{
    shash_node_t *node, *tmp;
    unsigned long int i;

    if (!ht)
        return;
    for (i = 0; i < ht->size; i++)
    {
        node = ht->array[i];
        while (node)
        {
            tmp = node->next;
            free(node->key);
            free(node->value);
            free(node);
            node = tmp;
        }
    }
    free(ht->array);
    free(ht);
}
