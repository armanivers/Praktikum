char *stringcat (const char* str1, const char* str2)
{

    // dadurch dass Parameter const sind, werden sie nicht by reference uebergeben
    // das bedeutet "schreibzugriff" auf variablen ist verboten
    // zeiger immernoch veranderbar!

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

char *stringcatAlt(const char* str1, const char* str2)
{
    int size = 1;
    int i = 0;

    while(*(str1+i) != '\0')
    { 
        size++;
        i++;
    }
    i=0;
    while(*(str2+i) != '\0')
    { 
        size++;
        i++;
    }
    i=0;

    char* result = malloc(sizeof(char)*size);

    while(*str1!='\0')
    {
        result[i] = *str1;
        i++;
        str1++;
    }
    while(*str2!='\0')
    {
        result[i] = *str2;
        i++;
        str2++;
    }
    i++;
    result[i] = '\0';
    return result;
}