void bubble_sort(int num[], int len)
{
    bool exchange;
    for (int i = 0; i < len - 1; i++)
    {
       exchange = false;
       for (int j = 0; j < len - i - 1; j++)
       {
           if (num[j] > num[j + 1])
           {
               int temp = num[j];
               num[j] = num[j + 1];
               num[j + 1] = temp;
               exchange = true;
           }
       }
       if (!exchange)
       {
           return;
       }
    }
}