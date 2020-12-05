double min(double a[], int n)
{
    if(n <= 0)
    {
        return 0.0;
    }

    if(n == 1)
    {
        return a[0];
    }

    double temp = a[0];

    for(int i = 1; i < n ; i++)
    {
        if(a[i] < temp)
        {
            temp = a[i];
        }
    }
    return temp;
}