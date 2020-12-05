char *stringcat (const char* str1, const char* str2)
{
    int str1Size = 0;
    int str2Size = 0;

    const char *temp = str1;
    
    // alterntive: str1[str1Size] != '\0' statt temp variable
    while( (*temp++) != '\0')
    {
        str1Size++;
    }
    
    temp = str2;

    while( (*temp++) != '\0')
    {
        str2Size++;
    }

    // 1 Zeichen schon fuer stringende
    int concatSize = str1Size+str2Size+1;
    
    char* concat = malloc(sizeof(char)*concatSize);
    
    int i = 0;
    for(; i < str1Size; i++)
    {
        concat[i] = str1[i];
    }
    int j = 0;
    for(; i < concatSize; i++)
    {
        concat[i] = str2[j++];
    }

    concat[concatSize] = "\0";

    return concat;
}