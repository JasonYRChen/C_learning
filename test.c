#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <pthread.h>

int BEERS = 100000;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void error(char *msg)
{
    fprintf(stderr, "%s: %s\n", msg, strerror(errno));
    exit(1);
}

void* drink(void *upper_limit)
{
    for (int i=0; i<(long)upper_limit; i++) {
        pthread_mutex_lock(&lock);
        BEERS--;
        pthread_mutex_unlock(&lock);
    }
    return NULL;
}

int main()
{
    int persons = 10;
    long upper_limit = BEERS / persons;
    pthread_t threads[persons];
    
    for (int i=0; i<persons; i++) {
        if (pthread_create(&threads[i], NULL, drink, (void*)upper_limit) == -1)
            error("Cannot create thread");
    }

    void *result;
    for (int i=0; i<10; i++) {
        if (pthread_join(threads[i], result) == -1)
            error("Cannot join thread");
    }
    
    printf("%i beers left\n", BEERS);

    return 0;
}

