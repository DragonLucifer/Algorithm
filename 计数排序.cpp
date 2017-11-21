//假定数组中元素的取值范围是[0,k]，因此需分配k+1个内存空间
void counting_sort(int num[], int len, int k)
{
    int *count = new int[k + 1];
    int *tmp = new int[len];
    for (int i = 0; i < k; i++)
    {
        count[i] = 0;
    }
    for (int i = 0; i < len; i++)
    {
        count[num[i]]++;
    }
    for (int i = 1; i < k; i++)
    {
        count[i] += count[i - 1];
    }

    int index;
    for (int i = 0; i < len; i++)
    {
        index = count[num[i]];
        tmp[index - 1] = num[i];
        count[num[i]]--;
    }

    for (int i = 0; i < len; i++)
    {
        num[i] = tmp[i];
    }
}