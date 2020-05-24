#include <iostream>
#include "dataStructure/SqList.hpp"

int main(int argc, char** argv) {
    const int LONGTH = 5;

    SqList L;

    int size, increment, i;
    
    size = LONGTH;
    increment = LONGTH;
    ElemType e, eArray[LONGTH] = {1, 2, 3, 4, 5};

    if (!InitList_Sq(L, size, increment))
    {
        std::cout << "Init Failed." << std::endl;
        return 1;
    }
    std::cout << "Init Finish." << std::endl;

    for (int i = 0; i < LONGTH; ++i)
    {
        if (!Append_Sq(L, eArray[i]))
        {
            std::cout << "Push Failed." << std::endl;
            return 1;
        }
    }
    std::cout << "Push Finish." << std::endl;

    if (ListEmpty_Sq(L)) std::cout << "Empty Stack." << std::endl;
    else std::cout << "Stack Not Empty." << std::endl;

    std::cout << "Full Item In the Container: " << std::endl;
    ListTraverse_Sq(L, visit);

    ClearList_Sq(L);
    std::cout << "Clear Finish." << std::endl;

    return 0;
}
