#ifndef LINKLIST_HPP
#define LINKLIST_HPP

#include "Status.h"
#include <iostream>
#include <malloc.h>

typedef int ElemType;

typedef struct LNode
{
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;

Status create(LinkList &L, ElemType *data, int n)
{
    LNode *p, *q;
    int i;
    if (n < 0) return ERROR;
    L = NULL;
    p = NULL;
    for (int i = 0; i < n; ++i)
    {
        q = (LNode*)malloc(sizeof(LNode));
        if (q == NULL) return OVERFLOW;
        q->data = data[i];
        q->next = NULL;
        if (p == NULL) L = q;
        else p->next = q;
        p = q;
    }
    return OK;
}

Status EnQueue_LQ(LinkList &L, ElemType &e)
{
    LNode *p, *q;
    if ((q = (LNode*)malloc(sizeof(LNode))) == NULL) return OVERFLOW;
    q->data = e;
    q->next = NULL;
    if (L == NULL) L = q;
    else 
    {
        p = L;
        while (p->next != NULL) p = p->next;
        p->next = q;
    }

    return OK;
}

Status DeQueue_LQ(LinkList &L, ElemType &e)
{
    if (L == NULL) return ERROR;
    LinkList p;
    p = L;
    e = p->data;
    L = L->next;
    free(p);
    return OK;
}

Status visit(const ElemType &e)
{
    std::cout << e << " ";
    return OK;
}

void ListTraverse_L(LinkList L, Status(*visit)(const ElemType &e))
{
    if (L == NULL) return;
    for (LinkList p = L; p != NULL; p = p->next)
    {
        visit(p->data);
    }
}

#endif