#include "hash.h"

#include <stdio.h>
#include <stdlib.h>

HashTable *hash_init (int N, int K){
    //N: number of buckets
    //K:number of locks
    //N/M = K
    HashTable* newTable = NULL;
    if(N < 1)
        return NULL;
    if(newTable = malloc(sizeof(HashTable)) == NULL){
        //memory allocation for the newTable itself
        return NULL;
    }
    if((newTable->table = malloc(sizeof(entry*) * N)) == NULL){
        //memory allocation for N bucket's head pointers
        return NULL;
    }
    //If you survived until you reach here we can initialize the buckets as empty linked list
    newTable->size = N;
    for(int i = 0; i < N; i++){
        newTable->table[i] = NULL;
    }
    return newTable;
}

//create a key-value pair for hash table
//returns null if unsuccessful
entry* create_pair(int k, void* v){
    entry* newPair;
    if((newPair = malloc(sizeof(entry))) == NULL)
        return NULL; //unsuccessful insert operation
    newPair->key = k;
    newPair->value = v;
    newPair->next = NULL;
    return newPair;
}


int hash_insert (HashTable *hp, int k, void * v){
    int location;
    entry *list_to_insert;
    entry *curr;
    entry* newPair;

    location = simple_hash_function(k);
    list_to_insert = hp->table[location];
    //check if key exists
    curr = list_to_insert;
    while(curr != NULL){
        if(curr->key == k){
            return -1; //key exists
        }
        curr = curr->next;
    }
    //If you are here key does not exist. ie  you can insert this key
    newPair = create_pair(k, v);
    if(newPair == NULL)
        return -1; //unsuccessful creation of pair
    //insert: consider two cases-first item to insert/others
}
