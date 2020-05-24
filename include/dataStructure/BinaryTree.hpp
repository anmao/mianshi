#ifndef BINARYTREE_HPP
#define BINARYTREE_HPP

#include "Status.h"
#include <iostream>
#include <malloc.h>

typedef char TElemType;

typedef struct BiTNode 
{
    TElemType data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

Status InitBiTree(BiTree &T)
{
    T = NULL;
    return OK;
}

BiTree MakeBiTree(TElemType &e, BiTree &L, BiTree &R)
{
    BiTree T;
    T = (BiTree)malloc(sizeof(BiTree));
    if (T == NULL) return NULL;
    T->data = e;
    T->lchild = L;
    T->rchild = R;
    return T;
}

Status visit(TElemType &e)
{
    std::cout << e;
    return OK;
}

int Leaves(BiTree &T)
{
    int l = 0, r = 0;
    if (T == NULL) return 0;
    if (T->lchild == NULL && T->rchild == NULL) return 1;
    l = Leaves(T->lchild);
    r = Leaves(T->rchild);

    return r + l;
}

int depTraverse(BiTree &T)
{
    if (T == NULL) return ERROR;
    dep = (depTraverse(T->lchild) > depTraverse(T->rchild) ? depTraverse(T->lchild) : depTraverse(T->rchild));
    
    return dep + 1;
}

void levTraverse(BiTree &T, Status(*visit)(TElemType &e), int lev)
{
    if (T == NULL) return;
    visit(T->data);
    std::cout << "level: " << lev << std::endl;

    lev += 1;
    levTraverse(T->lchild, visit, lev);
    levTraverse(T->rchild, visit, lev);
}

void InOrderTraverse(BiTree &T, Status(*visit)(TElemType &e), int &num)
{
    if (T == NULL) return;
    visit(T->data);
    if (T->lchild == NULL && T->rchild == NULL) 
    {
        std::cout << "is a leaf." << std::endl;
        num++;
    }
    else 
        std::cout << "is not a leaf." << std::endl;

    InOrderTraverse(T->lchild, visit, num);
    InOrderTraverse(T->rchild, visit, num);
}

bool BiTreeEmpty(BiTree &T)
{
    return T == NULL;
}

// 打断二叉树 两端置空
Status BreakBiTree(BiTree &T, BiTree)

// 替换左子树

// 替换右子树

// 合并二叉树


#endiw