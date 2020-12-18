int countIndex(char s[]) 
{
    int i = 0;
    int counter = 0;
    while(s[i] != '\0')
    {
        if(s[i] == ' ')
        {
            counter++;
        }
        i++;
    }
    return counter;
}

int countPointer(char s[])
{
    int i = 0;
    int counter = 0;
    while(*(s+i) != '\0')
    {
        if(*(s+i) == ' ')
        {
            counter++;
        }
        i++;
        // ALTERNATIV: s++; statt index
    }
    return counter;
}