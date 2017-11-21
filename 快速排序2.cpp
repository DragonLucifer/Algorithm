void quick_sort(int num[], int left, int right)
{
    if (left < right)
    {
        int i = left;
        int j = right;
        int x = num[i];
        while (i < j)
        {
            while (i < j && num[j] >= x)
            {
                j--;
            }
            if(i < j)
            {
                num[i++] = num[j];
            }

            while (i < j && num[i] < x)
            {
                i++;
            }
            if(i < j)
            {
                num[j--] = num[i];
            }
        }
        num[i] = x;

        quick_sort(num, left, i - 1);
        quick_sort(num, i + 1, right);
    }
}