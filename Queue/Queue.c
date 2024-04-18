#include <stdlib.h>
#include "Queue.h"

Queue* QueCreate() {
    Queue* que = (Queue*)malloc(sizeof(Queue));
    que -> list = LstCreate();
    return que;
}

int QueEmpty(const Queue* queue) {
    if(LstEmpty(queue -> list))
        return 1;
    return 0;
}

int QueEnqueue(Queue* queue, const QueElement* e) {
    if(queue) {
        return LstPushBack(queue -> list, e);
    }
    return 0;
}

int QueDequeue(Queue* queue, QueElement* e) {
    if(queue && !LstEmpty(queue -> list)) {
        LstGetEntry(queue -> list, 0, e);
        return LstDeleteFront(queue -> list);
    }
    return 0;
}

int QueFront(const Queue* queue, QueElement* e) {
    if(queue && !LstEmpty(queue -> list)) {
        LstGetEntry(queue -> list, 0, e);
        return 1;
    }
    return 0;
}

void QuePrint(const Queue* queue, QuePrintFunc func) {
    LstPrint(queue -> list, func);
}

void QueDestroy(Queue* queue) {
    LstDestroy(queue -> list);
    free(queue);
}