void shell_sort(int *num, int len)
{
    for (int d = len / 2; d > 0; d /= 2)
    {
        //ÿ��Ԫ���������ڵ�Ԫ�ؽ��в�������
        for (int i = d; i < len; i++)
        {
            int temp = num[i];
            int j = i;
            while (j >= d && num[j - d] > temp)
            {
                num[j] = num[j - d];
                j -= d;
            }
            num[j] = temp;
        }
    }
}