#include <stdio.h>

int main(int argc, char* argv[])
{
    
    if(argc==3)
    {
        printf("%d",atoi(argv[1])+atoi(argv[2]));
    }
    return 0;
}