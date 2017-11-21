void selection_sort(int num[], int len)
{
    for (int i = 0; i < len - 1; i ++)
    {
        int j = i;
        for (int k = i + 1; k < len; k++)
        {
            if (num[k] < num[j])
            {
                j = k;
            }
        }

        if (j != i)
        {
            int temp = num[j];
            num[j] = num[i];
            num[i] = temp;
        }
    }
}