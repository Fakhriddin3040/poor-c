#include <stdio.h>
#include <pthread.h>

void* print_count() {
    long long count = 0;
    while(1)
    {
        printf("%lld. The dig is big is: %lld\n,", count, (long long)1e12 * 10 + count);
        count++;
    }
    return NULL;
}

int main(int argc, char const *argv[]) {
    pthread_t thread_id;
    while (1) {
        pthread_create(&thread_id, NULL, print_count, NULL);
    }

    return 0;
}