#include <stdio.h>
#include <stdbool.h>

void filterArray(int *dest, size_t sizeDest, 
                int *src, size_t sizeSrc,
                bool(*filters[])(int), size_t filtersSize)
{
    size_t destCount = 0;
    bool isValidValue;

    for(size_t i = 0; i < sizeSrc; i++)
    {
        isValidValue = true;
        if(destCount > sizeDest) return;

        for(size_t j = 0; j < filtersSize; j++)
        {
            if(!filters[j](src[i])) 
            {
                isValidValue = false;
                break;
            }
        }
        if(isValidValue)
        {
            dest[destCount] = src[i];
            destCount++;
        }
    }
}


bool isCorrectInt(int value)
{
    return true ? value % 2 == 0 : false;
}

bool isPositive(int value)
{
    return true ? value > 0 : false;
}

int main(void)
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int filteredArray[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    bool (*filters[])(int) = {isCorrectInt, isPositive};

    size_t arrSize = sizeof(arr) / sizeof(*arr);
    size_t filteredArraySize = sizeof(filteredArray) / sizeof(int);
    size_t filtersSize = sizeof(filters) / sizeof(*filters);

    filterArray(filteredArray, filteredArraySize,
                arr, arrSize,
                filters, filtersSize);

    for(size_t i = 0; i < sizeof(filteredArray) / sizeof(*filteredArray); i++)
    {
        printf("%d\n", filteredArray[i]);
    }
}