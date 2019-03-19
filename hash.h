#ifndef PROJECT2_LIBRARY_H
#define PROJECT2_LIBRARY_H

struct key_value_pair{
    int key;
    void* value;
    struct key_value_pair *next; // this will point to next element in linked list
    //since we are using chaining for collision resolution.
};

struct hash_table{
    int size;
    struct key_value_pair **table;
};

int simple_hash_function(int i){
    int hash_val;
    int N = 100; //will be replaced
    hash_val = i%N;
    return hash_val;
}

typedef struct hash_table HashTable;
typedef struct key_value_pair entry;
HashTable *hash_init (int N, int K);
int hash_insert (HashTable *hp, int k, void * v);
int hash_delete (HashTable *hp, int k);
int hash_update (HashTable *hp, int k, void *v);
int hash_get (HashTable *hp, int k, void **vp);
int hash_destroy (HashTable *hp);

#endif
