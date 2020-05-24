#ifndef SQSTACK_HPP
#define SQSTACK_HPP

#include <malloc.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -1

#define LONGHT 5

typedef int Status;
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

Status StackEmpty_Sq(SqStack &S)
{
    return S.top == 0;
}

void ClearStack_Sq(SqStack &S)
{
    if (S.top == 0) return;
    S.size = 0;
    S.top = 0;
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

Status GetTop_Sq(SqStack S, ElemType &e)
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