#include "Stack.h"
#include <stdlib.h>

// 스택 생성
Stack* StkCreate()
{
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->list = LstCreate();
    return stack;
}

// 스택이 비어 있다면 1을 반환. 스택에 데이터가 있다면 0 반환
int StkEmpty(const Stack* stack)
{
    return LstEmpty(stack->list);
}

// 스택에 e 추가
int StkPush(Stack* stack, const StkElement* e)
{
    if (stack) {
    LstPushFront(stack->list, e);
    return 1;
    }
    return 0;
}

// 스택의 가장 윗부분에 있는 데이터를 pe로 저장해서 반환
// 스택의 가장 윗부분에 있는 데이터는 제거
int StkPop(Stack* stack, StkElement* e)
{
    if (stack) {
    LstGetEntry(stack->list, 0, e);
    LstDeleteFront(stack->list);
    return 1;
    }
    return 0;
}

// 스택의 가장 윗부분에 있는 데이터를 pe로 저장해서 반환
// 스택의 가장 윗부분에 있는 데이터는 제거 안함
int StkTop(const Stack* stack, StkElement* e)
{   
    if (stack) {
    LstGetEntry(stack->list, 0, e);
    return 1;
    }
    return 0;
}

// 스택의 가장 윗부분에 있는 데이터부터 순서대로 화면에 출력
void StkPrint(const Stack* stack, StkPrintFunc print)
{
    LstPrint(stack->list, print);
}

// 스택 제거
void StkDestroy(Stack* stack)
{
    LstDestroy(stack->list);
    free(stack);
}