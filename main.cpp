#include <iostream>
#include "dataStructure/LinkList.hpp"

int main(int argc, char** argv) {
    const int LONGTH = 5;

    LinkList L;

    int size, increment, i;
    
    size = LONGTH;
    increment = LONGTH;
    ElemType e, eArray[LONGTH] = {1, 2, 3, 4, 5};

    std::cout << "origin elements:";
    for (int i = 0; i < LONGTH; ++i)
    {
        std::cout << " " << eArray[i];
    }
    std::cout << std::endl;

    if (create(L, eArray, LONGTH) == ERROR)
        std::cout << "init fail." << std::endl;
    std::cout << "init finish." << std::endl;

    ListTraverse_L(L, visit);

    DeQueue_LQ(L, e);
    std::cout << "dequeue item: " << e << std::endl;

    ListTraverse_L(L, visit);

    EnQueue_LQ(L, e);

    ListTraverse_L(L, visit);
    return 0;
}
