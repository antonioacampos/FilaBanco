#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>

typedef struct {
    char id;
    char name[30];
} Client;

typedef struct {
    Client clients[100];
    int front;
    int rear;
    int count;
} t_queue;

void initQueue(t_queue *que);
bool isFull(t_queue *que);
bool isEmpty(t_queue *que);
bool enqueue(t_queue *que, Client client);
bool dequeue(t_queue *que, Client *client);

#endif
