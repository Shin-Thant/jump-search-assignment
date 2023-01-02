#include <iostream>
#include <math.h>

int minNumber(int first, int second)
{
    if (first > second)
    {
        return second;
    }

    return first;
}

int linearSearch(int data[], int size, int previous, int toFind)
{
    for (int i = previous; i < previous + sqrt(size); i++)
    {
        if (data[i] == toFind)
        {
            return i;
        }
    }

    return -1;
}

int binarySearch(int data[], int size, int previous, int toFind)
{
    int step = sqrt(size);

    int leftInd = previous;
    int rightInd = previous + step;

    while (leftInd <= rightInd)
    {
        int mid = floor((leftInd + rightInd) / 2);

        if (toFind == data[mid])
        {
            return mid;
        }
        else if (toFind > data[mid])
        {
            leftInd = mid + 1;
        }
        else if (toFind < data[mid])
        {
            rightInd = mid - 1;
        }
    }

    return -1;
}

int jumpSearch(int data[], int size, int toFind)
{
    // array don't have any element
    if (size <= 0)
    {
        return -1;
    }

    int step = sqrt(size);
    int previous = 0;

    // search by jumping
    while (data[minNumber(step, size) - 1] < toFind)
    {
        previous = step;

        if (data[step] == toFind)
        {
            return step;
        }

        if (step >= size)
        {
            return -1;
        }

        step = step + sqrt(size);
    }

    // apply linear search
    // return linearSearch(data, size, previous, toFind);

    // apply binary search
    return binarySearch(data, size, previous, toFind);
}

// int myJumpSearch(int data[], int size)
// {
// }

int main()
{
    int data[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = sizeof data / sizeof data[0];
    int toFind = 6;

    int result = jumpSearch(data, size, toFind);
    if (result != -1)
    {
        printf("=> Found at index - %d\n", result);
    }
    else
    {
        printf("=> %d not found!\n", toFind);
    }

    return 0;
}