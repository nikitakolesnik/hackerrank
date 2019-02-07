// https://www.hackerrank.com/challenges/array-left-rotation/problem

#include <iostream>

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        std::cout << arr[i] << " ";
    std::cout << "\n";
}

void rotateCopy(int arr[], int rotate, int size)
{
    int *copy = new int[size];
    int index;

    for (int i = 0; i < size; i++)
    {
        index = (i + (size-rotate)) % size;
        copy[index] = arr[i];
    }

    for (int i = 0; i < size; i++)
        arr[i] = copy[i];
        
    delete copy;
}

int main()
{
    int size, rotate;
    std::cin >> size >> rotate;
    std::cin.ignore(1000, 10);

    int *arr = new int[size];
    for (int i = 0; i < size; i++)
        std::cin >> arr[i];
    std::cin.ignore(1000, 10);

    rotateCopy(arr, rotate, size);
    printArray(arr, size);
}
