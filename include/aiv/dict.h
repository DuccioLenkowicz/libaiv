#include <string.h>
#include <stdlib.h>

// Non ci sono funzioni di destroy
// Liberare la memoria nei test
// Cancellazione record in un dizionario
// Lunghezza di un dizionario
// Iteratore sulle chiavi
// Trasformazione delle chiavi in una aiv_list

typedef struct aiv_dict_item
{
    struct aiv_dict_item *prev;
    struct aiv_dict_item *next;
    void *key;
    unsigned int key_len;
    void *data;
}aiv_dict_item_t;

typedef struct aiv_dict
{
    struct aiv_dict_item **hash_map;
    unsigned int hash_map_size;
    unsigned int current_cost;
} aiv_dict_t;

// create a new dictionary
aiv_dict_t *aiv_dict_new(unsigned int, int *);
// destroy a dict instance
void aiv_dict_destroy(aiv_dict_t  *);
// add an item to a dictionary
int aiv_dict_add(aiv_dict_t *, void *, unsigned int, void *);
// retrieve a value given a key
void *aiv_dict_get(aiv_dict_t *, void *, unsigned int);
// remove item from the dict
void *aiv_dict_remove(aiv_dict_t *, void *, unsigned int);

void aiv_dict_destroy(aiv_dict_t *);

int aiv_dict_len(aiv_dict_t *);




