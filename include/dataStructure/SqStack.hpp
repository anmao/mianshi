#ifndef SQSTACK_HPP
#define SQSTACK_HPP

#include <malloc.h>
#include "Status.h"

typedef int ElemType;

typedef struct 
{
    ElemType *elem;
    int top;
    int size;
    int increment;
} SqStack; 

Status InitStack_Sq(SqStack &S, int size, int inc)
{
    S.elem = (ElemType*)malloc(size * sizeof(ElemType));
    if (NULL == S.elem) return OVERFLOW;
    S.top = 0;
    S.size = size;
    S.increment = inc;
    return OK;
} 

Status DestroyStack_Sq(SqStack &S)
{
    free(S.elem);
    S.elem = NULL;
    return OK;
}

bool StackEmpty_Sq(SqStack &S)
{
    return S.top == 0;
}

Status ClearStack_Sq(SqStack &S)
{
    if (S.top == 0) return OK;
    S.size = 0;
    S.top = 0;
    return OK;  
}

Status Push_Sq(SqStack &S, ElemType e)
{
    ElemType *newbase;
    if (S.top >= S.size)
    {
        newbase = (ElemType*)realloc(S.elem, (S.size + S.increment) * sizeof(ElemType));
        if (newbase == NULL) return OVERFLOW;
        S.elem = newbase;
        S.size += S.increment;
    }
    S.elem[S.top++] = e;
    return OK;
}

Status GetTop_Sq(SqStack &S, ElemType &e)
{
    if (S.top == 0) return ERROR;
    e = S.elem[S.top - 1];
    return OK;
}

Status Pop_Sq(SqStack &S, ElemType &e)
{
    if (S.top == 0) return ERROR;
    e = S.elem[--S.top];
    return OK;
}

#endif