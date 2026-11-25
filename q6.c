#include <stdio.h>
void grow(int heights[], int n)
{
    if (n == 0)
    {
        return;
    }
    heights[n - 1] = heights[n - 1] + (int)(heights[n - 1] * 0.10);
    grow(heights, n - 1);
}

int tallest(int heights[], int n)
{
    int maxPos;

    if (n == 1)
    {
        return 0;
    }
    maxPos = tallest(heights, n - 1);
    if (heights[n - 1] > heights[maxPos])
    {
        return n - 1;
    }
    return maxPos;
}

int search(int heights[], int n, int target)
{
    if (n == 0)
    {
        return -1;
    }
    if (heights[n - 1] == target)
    {
        return n - 1;
    }
    return search(heights, n - 1, target);
}

int main()
{
    int ids[6] = {101, 102, 103, 104, 105, 106};
    int heights[6] = {45, 120, 78, 200, 95, 150};
    int i, maxIndex, target, foundIndex;
    grow(heights, 6);

    printf("New heights:");
    for (i = 0; i < 6; i++)
    {
        printf(" %d", heights[i]);
    }
    printf("\n");

    maxIndex = tallest(heights, 6);
    printf("Tallest: tower %d (%d m)\n", ids[maxIndex], heights[maxIndex]);
    printf("Height to search: ");
    scanf("%d", &target);
    foundIndex = search(heights, 6, target);
    if (foundIndex != -1)
    {
        printf("Tower %d is %d m\n", ids[foundIndex], heights[foundIndex]);
    }
    else
    {
        printf("No tower found with height %d m\n", target);
    }

    return 0;
}