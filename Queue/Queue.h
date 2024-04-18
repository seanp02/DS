#pragma once

#include "List.h"
#include "QueElementType.h"

typedef struct {
    List* list;
} Queue;

typedef void (*QuePrintFunc)(const QueElement* e);

Queue* QueCreate();
int QueEmpty(const Queue* queue);
int QueEnqueue(Queue* queue, const QueElement* e);
int QueDequeue(Queue* queue, QueElement* e);
int QueFront(const Queue* queue, QueElement* e);
void QuePrint(const Queue* queue, QuePrintFunc func);
void QueDestroy(Queue* queue);
