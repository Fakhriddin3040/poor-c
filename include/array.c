int* copyArray(int* array, int size) {
    int* copy = malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        copy[i] = array[i];
    }
    return copy;
}

long* copyArray(long* array, int size) {
    long* copy = malloc(size * sizeof(long));
    for (int i = 0; i < size; i++) {
        copy[i] = array[i];
    }
    return copy;
}