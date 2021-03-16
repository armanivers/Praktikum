#include "mystring.h"

String::String() : size{1}, buffer{new char[size]} 
{
    buffer[0] = '\0';
}

String::String(const char* s) : size{strlen(s)+1}, buffer{new char[size]} 
{
    strcpy(buffer,s);
}

String::String(const String& o)
{
    size = o.size;
    buffer = new char[size];

    for(int i = 0 ; i < o.size; i++)
    {
        buffer[i] = o.buffer[i];
    }
}

String::~String() { delete[] buffer; }

char String::operator[](int i)
{
    if(i < 0 || i > size) return ' ';

    return buffer[i];
}

std::ostream& operator<<(std::ostream& out, const String& s)
{
    for(int i = 0; i < s.size; i++)
    {
        out << s.buffer[i];
    }
    return out;
}


