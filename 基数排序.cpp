//��ȡ���λ��
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
    int *count = new int[10];  //������

    int radix = 1;
    int i, j, k;
    for(i = 0; i < bitCount; i++)  //����bitCount������
    {
        for(j = 0; j < 10; j++)
        {
            count[j] = 0;
        }

        for(j = 0; j < len; j++)  //ͳ��ÿ��Ͱ�еļ�¼��
        {
            k = (num[j] / radix) % 10;
            count[k]++;
        }

        for (j = 1; j < 10; j++)  //��tmp�е�λ��һ�η����ÿ��Ͱ
        {
            count[j] = count[j] + count[j - 1];
        }

        for (j = len - 1; j >= 0; j--)  //������Ͱ�м�¼�ռ���tmp��
        {
            k = (num[j] / radix) % 10;
            tmp[count[k] - 1] = num[j];
            count[k]--;
        }

        for (j = 0; j < len; j++)  //������ʱ��������ݵ�data
        {
            num[j] = tmp[j];
        }

        radix *= 10;
    }
    delete [] tmp;
    delete [] count;
}