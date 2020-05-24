#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <malloc.h>
#include "Status.h"

typedef int ElemType;

typedef struct 
{
    ElemType *elem;
    int front;
    int rear;
    int size;
} Queue;

Status InitQueue(Queue &Q, int size)
{
    Q.elem = (ElemType*)malloc(size * sizeof(ElemType));
    if (NULL == Q.elem) return OVERFLOW;
    Q.front = 0;
    Q.rear = 0;
    return OK;
}

Status DestroyQueue(Queue &Q)
{
    free(Q.elem);
    Q.elem = NULL;
    return OK;
}

bool QueueEmpty(Queue &Q)
{
    return Q.front == Q.rear;
}

Status ClearQueue(Queue &q)
{
    if (q.front == 0) return OK;
    q.front = 0;
    q.rear = 0;
    return OK;
}

Status GetFront_queue(Queue &Q, ElemType &e)
{
    if (QueueEmpty(Q)) return ERROR;
    e = Q.elem[Q.front];
    return OK;
}

Status Push_queue(Queue &Q, ElemType &e)
{
    if (Q.rear == Q.size) return ERROR;
    Q.elem[Q.rear++] = e;
    return OK;
}

Status Delete_Queue(Queue &Q, ElemType &e)
{
    if (Q.front == Q.rear) return ERROR;
    e = Q.elem[Q.front++];
    return OK;
}

#endif