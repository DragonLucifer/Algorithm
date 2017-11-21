int partition(int num[], int left, int right)
{
    int x = num[right];
    int i = left;
    int j = left - 1;
    for (; i < right; i++)
    {
        if (num[i] < x)
        {
            j++;
            if (j != i)
            {
                swap(num[j], num[i]);
            }
        }
    }
    swap(num[j + 1], num[right]);

    return j + 1;  //·µ»Ø·Ö¸îµã
}

void quick_sort(int num[], int left, int right)
{
    if (left < right)
    {
        int index = partition(num, left, right);
        quick_sort(num, left, index - 1);
        quick_sort(num, index + 1, right);
    }
}