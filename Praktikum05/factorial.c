int factorial(int n)
{
    if(n == 0)
    {
        return 1;
    }
    return n * factorial(n-1);
}

int binomialCoefficient(int n, int k)
{
    if(k == 0)
    {
        return 1;
    }
    else if(k > n)
    {
        return 0;
    }

    // rekursiv (besser!)
    return binomialCoefficient(n-1,k-1)+binomialCoefficient(n-1,k);
    
    /*
    int nFak = factorial(n);
    int kFak = factorial(k);
    int nkFak = factorial(n-k);
    return nFak/(kFak*nkFak);
    */
}