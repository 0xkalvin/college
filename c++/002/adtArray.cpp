#include <stdlib.h>
#include <iostream>
#include "adtArray-header.h"

adtArray::adtArray()
{
    for (int i = 0; i < SIZE; i++)
    {
        numbers[i] = 0;
    }
}

void adtArray::print()
{
    cout << "[";
    for (int i = 0; i < SIZE; i++)
    {
        cout << numbers[i] << " ";
    }
    cout << "]";
}

string adtArray::addElement(int n, int position)
{
    position--;
    if (position < 1 || position > SIZE)
    {
        return "Ouf of range! ";
    }
    if (numbers[position] > 0)
    {
        return "This position is already occupied! ";
    }

    numbers[position] = n;
    return "Added it successfully! ";
}

string adtArray::deleteElement(int position)
{
    position--;
    if (position < 1 || position > SIZE)
    {
        return "Out of range! ";
    }
    else if (numbers[position] == 0)
    {
        return "This position value is already zero! ";
    }
    numbers[position] = 0;
    return "Number deleted successfully! ";
}

string adtArray::exchangeElementsPosition(int pos1, int pos2)
{
    pos1--;
    pos2--;
    if (numbers[pos1] == 0 || numbers[pos2] == 0)
    {
        return "You cannot exchange the position of a zero! ";
    }
    if (pos1 < 1 || pos1 > SIZE || pos2 < 1 || pos2 > SIZE)
    {
        return "Out of range! ";
    }

    int temp = numbers[pos1];
    numbers[pos1] = numbers[pos2];
    numbers[pos2] = temp;

    return "elements position exchanged successfully! ";
}

string adtArray::findMaxAndMin()
{
    int max, min;
    max = numbers[0];
    min = numbers[0];

    for (int i = 1; i < SIZE; i++)
    {
        if (numbers[i] > max)
        {
            max = numbers[i];
        }
        else if (numbers[i] < min)
        {
            min = numbers[i];
        }
    }

    return "Max is " + to_string(max) + " and min is " + to_string(min);
}

void adtArray::selection_sort()
{
    for (int i = 0; i < SIZE; i++)
    {
        int min = i;
        for (int j = i + 1; j < SIZE; j++)
        {
            if (numbers[min] > numbers[j])
            {
                min = j;
            }
        }
        int temp = numbers[min];
        numbers[min] = numbers[i];
        numbers[i] = temp;
    }

    cout << "\nArray successfully sorted ";
}

void adtArray::invert_array(int arr[]) 
{ 
    int start = 0;
    int end = SIZE-1;
    while (start < end) 
    { 
        int temp = arr[start];  
        arr[start] = arr[end]; 
        arr[end] = temp; 
        start++; 
        end--; 
    }  
} 

int* adtArray::new_sorted_array()
{
    for (int i = 0; i < SIZE; i++)
    {
        int min = i;
        for (int j = i + 1; j < SIZE; j++)
        {
            if (numbers[min] > numbers[j])
            {
                min = j;
            }
        }
        int temp = numbers[min];
        numbers[min] = numbers[i];
        numbers[i] = temp;
    }

    return numbers;
}

int* adtArray::get_numbers(){
    return numbers;
}