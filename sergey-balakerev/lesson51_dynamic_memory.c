#include <stdlib.h>
#include <stdio.h>


short* append(short* arr, size_t* length, short* value)
{
    size_t newArrSize = *length + sizeof(*arr);
    short* newArr = malloc(newArrSize);
    if(newArr == NULL)
    {
        printf("Throwed unexpected exception, in the process of allocating memory");
        return 0;
    }
    size_t i = 0;
    for(; i < *length; i++)
    {
        newArr[i] = arr[i];
    }
    newArr[++i] = *value;
    return newArr;
}

int main(void)
{
    short* numbers[10];
    short newValue = 10;

    size_t numbersSize = sizeof(numbers) / sizeof(*numbers);

    short* newNumbers = append(numbers, &numbersSize, &newValue);

   size_t newNumbersSize = sizeof(newNumbers) / sizeof(*newNumbers);
   for(size_t i = 0; i < newNumbersSize; i++)
   {
        printf("%d. Value is: %d", newNumbers[i], newNumbers[i]);
   }
   return 0;
}