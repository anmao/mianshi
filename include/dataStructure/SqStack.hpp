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
    if (NULL == S.elem) 
} 


#endif