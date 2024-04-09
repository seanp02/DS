#include "Stack.h"

Stack* StkCreate()
{
    Stack* stk = (Stack*)malloc(sizeof(Stack));
    if (stk){
        stk->darr = DACreate();
        stk->top = -1;
        return stk;
    }
    return NULL;
}

int StkEmpty(const Stack* stack)
{
    if(stack->top == -1) return 1;
    else return 0;
}

int StkPush(Stack* stack, Element e)
{
    if (DAAdd(stack->darr, e)) {
        stack->top++;
        return 1;
    }
    return 0;
}

int StkPop(Stack* stack, Element* pe)
{
    if (StkEmpty(stack)) return 0;

    DAGet(stack->darr, stack->top, pe);
    stack->top--;
    return 1;
}

int StkTop(const Stack* stack, Element* pe)
{
    if (StkEmpty(stack)) return 0;

    DAGet(stack->darr, stack->top, pe);
    return 1;
}

void StkPrint(const Stack* stack, PrintFunc func)
{
    if (stack->darr && stack->darr->arr) {
        for (int i = stack->top; -1 < i ; i--) {
            func(stack->darr->arr[i]);
        }
        return;
    }
    return;
}

void StkDestroy(Stack* stack)
{
    DADestroy(stack->darr);
    free(stack);
}