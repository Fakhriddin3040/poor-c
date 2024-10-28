#include <stdio.h>
#include <stdlib.h>
#include <sys/sysctl.h>

int main() {
    int64_t memory_size;
    size_t len = sizeof(memory_size);

    // Используем sysctl для получения информации о физической памяти
    if (sysctlbyname("hw.memsize", &memory_size, &len, NULL, 0) == -1) {
        perror("sysctl");
        return 1;
    }

    long double total_len = (double)memory_size / 1024.0 / 1024.0;

    printf("Total memory: %llf bytes\n", total_len);
    
    return 0;
}