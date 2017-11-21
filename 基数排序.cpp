//获取最大位数
int max_bit(int num[], int len)
{
    int bit = 1;
    int radix = 10;
    for (int i = 0; i < len; i++)
    {
        while (num[i] >= radix)
        {
            radix *= 10;
            bit++;
        }
    }

    return bit;
}

void radix_sort(int num[], int len)
{
    int bitCount = max_bit(num, len);
    int *tmp = new int[len];
    int *count = new int[10];  //计数器

    int radix = 1;
    int i, j, k;
    for(i = 0; i < bitCount; i++)  //进行bitCount次排序
    {
        for(j = 0; j < 10; j++)
        {
            count[j] = 0;
        }

        for(j = 0; j < len; j++)  //统计每个桶中的记录数
        {
            k = (num[j] / radix) % 10;
            count[k]++;
        }

        for (j = 1; j < 10; j++)  //将tmp中的位置一次分配给每个桶
        {
            count[j] = count[j] + count[j - 1];
        }

        for (j = len - 1; j >= 0; j--)  //将所有桶中记录收集到tmp中
        {
            k = (num[j] / radix) % 10;
            tmp[count[k] - 1] = num[j];
            count[k]--;
        }

        for (j = 0; j < len; j++)  //复制临时数组的内容到data
        {
            num[j] = tmp[j];
        }

        radix *= 10;
    }
    delete [] tmp;
    delete [] count;
}