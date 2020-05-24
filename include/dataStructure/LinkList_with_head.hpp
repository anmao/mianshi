#ifndef LINKLIST_WITH_HEAD_HPP
#define LINKLIST_WITH_HEAD_HPP

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
    if (n < 0) return ERROR;
    p = L = NULL;

    q = (LNode*)malloc(sizeof(LNode));
    if (q == NULL) return OVERFLOW;
    q->next == NULL;
    p = L = q;

    for (int i = 0; i < n; ++i)
    {
        q = (LNode*)malloc(sizeof(LNode));
        if (q == NULL) return OVERFLOW;
        q->data = data[i];
        q->next = NULL;
        p->next = q;
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
    if (L == NULL)
    {
        L = (LNode*)malloc(sizeof(LNode));
        if (L == NULL) return OVERFLOW;
        L->next = NULL;
    }
    else if (L->next == NULL)
    {
        L->next = q;
    }
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
    if (L == NULL || L->next == NULL) return ERROR;
    LNode *p;
    p = L->next;
    e = p->data;
    L->next = p->next;
    free(p);
    return OK;
}

Status visit(ElemType &e)
{
    std::cout << e << " ";
    return OK;
}

void ListTraverse_L(LinkList L, Status(*visit)(ElemType &e))
{
    if (L == NULL || L->next == NULL) return;
    for (auto p = L->next; p != NULL; p = p->next) visit(p->data);
}

#endif