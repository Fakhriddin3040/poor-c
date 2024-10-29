#include <stdio.h>
#include <sys/types.h>

#define TAM_MAX 50

typedef struct client_t {
    pid_t pid;
    char password[TAM_MAX]; // Хранит пароль до 50 символов
    struct client_t *next; // Указатель на следующего клиента

    struct client_t *(*add_client)(struct client_t *);
} client_t;

// Функция добавления клиента
client_t *add_client(client_t *self) {
    // Реализация добавления клиента
    return self;
}

// Инициализация структуры клиента
void init_client(client_t *client) {
    client->add_client = add_client;
    client->next = NULL;
}

int main() {
    client_t client;
    init_client(&client);

    // Проверяем и вызываем функцию add_client
    if (client.add_client) {
        client.add_client(&client);
    } else {
        printf("add_client не инициализирована.\n");
    }

    return 0;
}