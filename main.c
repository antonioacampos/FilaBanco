#include <stdio.h>
#include <string.h>
#include "queue.h"

int main() {
    t_queue gQueue, pQueue;
    initQueue(&gQueue);
    initQueue(&pQueue);
    char ordem;
    int pCount = 0;
    Client cliente;
    char ordemClients[1000][30];
    int servedIndex = 0;

    while (scanf(" %c", &ordem) && ordem != 'f') {
        if (ordem == 'p' || ordem == 'g') {
            scanf(" %s", cliente.name);
            cliente.id = ordem;
            if (ordem == 'p') {
                enqueue(&pQueue, cliente);
            } else {
                enqueue(&gQueue, cliente);
            }
        } else if (ordem == 's') {
            if (!isEmpty(&pQueue) && (pCount < 3 || isEmpty(&gQueue))) {
                dequeue(&pQueue, &cliente);
                pCount++;
            } else if (!isEmpty(&gQueue)) {
                dequeue(&gQueue, &cliente);
                pCount = 0;
            }
            strcpy(ordemClients[servedIndex++], cliente.name);
        }
    }

    for (int i = 0; i < servedIndex; i++) {
        printf("%s\n", ordemClients[i]);
    }

    return 0;
}
