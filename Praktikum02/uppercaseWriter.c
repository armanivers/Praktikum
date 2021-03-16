
//#include <stdio.h>

char to_upper_case(char c)
{
    return c-32;
    // ((int)c)-32; ist nicht notwendig
}

void upper(char text[])
{
    int i = 0;
    while((text[i]) != '\0')
    {
        //If given char is a lowercase letter THEN convert it

        if(text[i] >= 97 && text[i] <= 122){
            //printf("Text = %c \n",text[i]);
            text[i] = to_upper_case(text[i]);
        }

        i++;
    }
}