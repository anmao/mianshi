#include <iostream>
#include "dataStructure/SqStack.hpp"

int main(int argc, char** argv) {
    const int LONGTH = 5;

    SqStack S;

    int size, increment, i;
    
    size = LONGTH;
    increment = LONGTH;
    ElemType e, eArray[LONGTH] = {1, 2, 3, 4, 5};

    if (!InitStack_Sq(S, size, increment))
    {
        std::cout << "Init Failed." << std::endl;
        return 1;
    }
    std::cout << "Init Finish." << std::endl;

    for (int i = 0; i < LONGTH; ++i)
    {
        if (!Push_Sq(S, eArray[i]))
        {
            std::cout << "Push Failed." << std::endl;
            return 1;
        }
    }
    std::cout << "Push Finish." << std::endl;

    if (StackEmpty_Sq(S)) std::cout << "Empty Stack." << std::endl;
    else std::cout << "Stack Not Empty." << std::endl;

    GetTop_Sq(S, e);
    std::cout << "Stack Top elem: " << e << "." << std::endl;

    for (int i = 0; i < LONGTH; ++i)
    {
        Pop_Sq(S, e);
        std::cout << "Pop elem: " << e << "." << std::endl;
    }

    ClearStack_Sq(S);
    std::cout << "Clear Finish." << std::endl;

    return 0;
}
