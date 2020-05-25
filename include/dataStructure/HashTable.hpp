#ifndef HASHTABLE_HPP
#define HASHTABLE_HPP

#include "Status.h"
#include <malloc.h>
#include <iostream>

#define MAXNUM 9999

typedef int KeyType;

typedef struct 
{
    KeyType key;
} RcdType;

typedef struct 
{
    RcdType *rcd;
    int size;
    int count;
    int *tag;
} HashTable;

const int hashsize[] = {11, 31, 61, 127, 251, 503};
int index = 0;

Status InitHashTable(HashTable &H, int size)
{
    H.rcd = (RcdType*)malloc(sizeof(RcdType) * size);
    H.tag = (int*)malloc(size * sizeof(int));
    if (H.rcd == NULL || H.tag == NULL) return OVERFLOW;
    KeyType maxNum = MAXNUM;
    for (int i = 0; i < size; ++i)
    {
        H.tag[i] = 0;
        H.rcd[i].key = maxNum;
    }
    H.size = size;
    H.count = 0;
    return OK;
}

int Hash(KeyType key, int m)
{
    return (3 * key) % m;
}

void collision(int &p, int m)
{
    p = (p + 1) % m;
}

Status SearchHash(HashTable &H, KeyType &key, int &p, int &c)
{
    p = Hash(key, H.size);
    int h = p;
    c = 0;
    while ((H.tag[p] == 1 && H.rcd[p].key != key) || H.tag[p] == -1) 
    {
        collision(p, H.size);
        c++;
    }

    if (H.tag[p] == 1 && H.rcd[p].key == key) return OK;
    return ERROR;
}

void printHash(HashTable &H)
{
    std::cout << "key:";
    for (int i = 0; i < H.size; ++i)
    {
        std::cout << " " << H.rcd[i].key;
    }
    std::cout << std::endl;

    std::cout << "tag:";
    for (int i = 0; i < H.size; ++i)
    {
        std::cout << " " << H.tag[i];
    }
    std::cout << std::endl;
    std::cout << std::endl;
}

Status InsertHash(HashTable &H, KeyType &key);

Status recreateHash(HashTable &H)
{
    RcdType *orcd;
    int *otag, osize;
    orcd = H.rcd;
    otag = H.tag;
    osize = H.size;

    InitHashTable(H, hashsize[index++]);
    for (int i = 0; i < osize; ++i)
    {
        if (otag[i] == 1)
        {
            InsertHash(H, orcd[i].key);
        }
    }

    return OK;
}

Status InsertHash(HashTable &H, KeyType &key)
{
    int p, c;
    if (SearchHash(H, key, p, c) == ERROR)
    {
        if (c * 1.0 / H.size < 0.5)
        {
            H.rcd[p].key = key;
            H.tag[p] = 1;
            H.count++;
            return OK;
        }
        else
        {
            recreateHash(H);
        }
    }

    return ERROR;
}

Status DeleteHash(HashTable &H, KeyType &key)
{
    int p, c;
    if (SearchHash(H, key, p, c) == OK)
    {
        H.tag[p] = -1;
        H.count--;
        return OK;
    }

    return ERROR;
}

#endif