#include "queue.h"

void initQueue(t_queue *que) {
    que->front = 0;
    que->rear = -1;
    que->count = 0;
}

bool isFull(t_queue *que) {
    return que->count == 100;
}

bool isEmpty(t_queue *que) {
    return que->count == 0;
}

bool enqueue(t_queue *que, Client client) {
    if (!isFull(que)) {
        que->rear = (que->rear + 1) % 100;
        que->clients[que->rear] = client;
        que->count++;
        return true;
    }
    return false;
}

bool dequeue(t_queue *que, Client *client) {
    if (!isEmpty(que)) {
        *client = que->clients[que->front];
        que->front = (que->front + 1) % 100;
        que->count--;
        return true;
    }
    return false;
}
