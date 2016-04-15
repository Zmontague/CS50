/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    int low = 0;
    int high = n - 1;
    if (n < 0)
    {
        return false;
    }
    while (low <= high) 
    {
        int mid = (low + high) / 2;
        if (values[mid] == value)
        {
            return true;
        }
        else if (values[mid] < value)
        {
            low = mid + 1;
        }
        else if (values[mid] > value) 
        {
            high = mid - 1;
        }
    }
    return false;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // TODO: implement an O(n^2) sorting algorithm
 int swaps = 0;
    do
    {
        swaps = 0;
        for(int i = 0; i < n - 1; i++)
        {
            if(values[i] > values[i + 1])
            {
                int temp = values[i];
                values[i] = values[i + 1];
                values[i + 1] = temp;
                swaps++;
            }
        }
    } while(swaps != 0);
    
    
    return;
}