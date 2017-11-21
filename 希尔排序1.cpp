void shell_sort(int num[], int len)
{
    int i, j, k, group, temp;
    for (group = len / 2; group > 0; group /= 2)
    {
        //��ÿ��������в�������
        for (i = 0; i < group; i++)
        {
            for (j = i + group; j < len; j += group)
            {
                if (num[j - group] > num[j])
                {
                    temp = num[j];
                    k = j - group;
                    while(k >= 0 && num[k] > temp)
                    {
                        num[k + group] = num[k];
                        k -= group;
                    }
                    num[k + group] = temp;
                }
            }
        }
    }
}