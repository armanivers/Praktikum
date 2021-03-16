#ifndef _STRING_H_
#define _STRING_H_

#include <string.h>
#include <ostream>

class String
{
    private:
    int size;
    char* buffer;

    public:
    String();
    String(const char* c);
    String(const String& o);
    ~String();

    char operator[](int i);
    
    friend std::ostream& operator<<(std::ostream& out,const String& s);

    inline const char* c_str() const
    {
        return buffer;
    }
    
    inline char at(int p) const
    {

        return buffer[p];
    }

    inline int length() const
    {
        return size;
        
        //Alternative: mit strln();
        //return strlen(buffer);
        
        //Alternative: Implementierung ohne size
        //int i = 0;
        //while(buffer[i] != '\o') {i++;}
        //return i;
    }
};
#endif