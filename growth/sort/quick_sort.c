#include <stdio.h>


void quick_sort (int nums[], int i, int j)
{
    if (nums == NULL || i > j)
        return;

    int left = i;   // 左哨兵
    int right = j;  // 右哨兵

    int base = nums[i];
    int temp;
    while (left != right)
    {
        // 由于最后要和基准(即base元素)进行交换, 目的为，在基准的右侧，都比基准大.
        // 同时, 要右侧优先, 也是为了避免，出现左侧出现比基准大的元素
        // PS: 可以尝试将, while循环，交换位置, 会得到错误的结果....
        while (nums[right] > base && left < right)
            right--;
        while (nums[left] <= base && left < right)
            left++;

        if (left < right)
        {
            temp = nums[left];
            nums[left] = nums[right];
            nums[right] = temp;
        }
    }

    temp = nums[i];
    nums[i] = nums[left];
    nums[left] = temp;
    quick_sort (nums, i, right - 1);
    quick_sort (nums, left + 1, j);
}

int main()
{
    int a_1[] = {8, 100, 50, 22, 8, 6, 1, 1000, 999, 0};

    quick_sort (a_1, 0, 9);
    int i;
    for (i = 0; i < 10; i++)
    {
        printf("%d\t", a_1[i]);
    }
    return 0;
}
