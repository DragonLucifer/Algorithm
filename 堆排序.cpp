void heap_build(int num[], int root, int len)
{
    int lchild = root * 2 + 1;
    if (lchild < len)
    {
        int largest = lchild;
        int rchild = lchild + 1;
        if (rchild < len)
        {
            if (num[rchild] > num[largest])
            {
                largest = rchild;
            }
        }
        if (num[root] < num[largest])
        {
            swap(num[root], num[largest]);
            heap_build(num, largest, len);
        }
    }
}

void heap_sort(int num[], int len)
{
    for (int i = len / 2; i >= 0; i--)
    {
        heap_build(num, i, len);
    }

    for (int j = len - 1; j >= 1; j--)
    {
        swap(num[0], num[j]);
        heap_build(num, 0, --len);
    }
}