#ifndef SQLIST_HPP
#define SQLIST_HPP

#include "Status.h"
#include <malloc.h>
#include <iostream>

typedef int ElemType;

typedef struct 
{
    ElemType *elem;
    int length;
    int size;
    int increment;
} SqList;

Status InitList_Sq(SqList &L, int size, int inc)
{
    L.elem = (ElemType*)malloc(size * sizeof(ElemType));
    if (L.elem == NULL) return OVERFLOW;
    L.length = 0;
    L.size = size;
    L.increment = inc;
    return OK;
}

Status DestroyList_Sq(SqList &L)
{
    free(L.elem);
    L.elem = NULL;
    return OK;
}

Status ClearList_Sq(SqList &L)
{
    L.length = 0;
    return OK;
}

bool ListEmpty_Sq(SqList &L)
{
    return L.length == 0;
}

int ListLength_Sq(SqList &L)
{
    return L.length;
}

Status GetElem_Sq(SqList &L, int i, ElemType &e)
{
    e = L.elem[--i];
    return OK;
}

int Search_Sq(SqList &L, ElemType &e)
{
    int i = 0;
    while (i < L.length && L.elem[i] != e) ++i;
    if (i < L.length) return i;
    else return -1;
}

Status visit(ElemType &e) 
{
    std::cout << e << " ";
    return OK;
} 

Status ListTraverse_Sq(SqList &L, Status(*visit)(ElemType &e)) 
{
    if (L.length == 0) return ERROR;
    for (int i = 0; i < L.length; ++i)
    {
        visit(L.elem[i]);
    }

    return OK;
}

Status PutElem_Sq(SqList &L, int i, ElemType e)
{
    if (i > L.length) return ERROR;
    e = L.elem[--i];
    return OK;    
}

Status Append_Sq(SqList &L, ElemType e)
{
    if (L.length >= L.size) return ERROR;
    L.elem[L.length] = e;
    L.length++;
    return OK;
}

Status DeleteLast_Sq(SqList &L, ElemType &e)
{
    if (L.length == 0) return ERROR;
    e = L.elem[--L.length];
    return OK;
}

#endif