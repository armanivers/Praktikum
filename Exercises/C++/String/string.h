#include <ostream>
#include <cstring>
using namespace std;

namespace fhdo_pk2{
    class String{
        private:
        
        char* str;
        int size;

        public:
        String();
        String(const char* s);
        String(const String& s);
        ~String();
        int length();

        // zugriff darauf fur << operator ohne getter?? <<operator  nur als friend definieren?
        inline int getLength() const
        {
            return size;
        }
        inline char getChar(int index) const
        {
            return str[index];
        }

        friend ostream& operator<< (ostream& ausgabe, const String& s)
        {
            for(int i = 0 ; i < s.size ; i++)
            {
                ausgabe << s.str[i];
            }
            return ausgabe;
        }

        /* Memberfunktiom heist funktion die hier "erstellt" wird? (also in .h?)
        // friend bedeutet es hat zugriff auf private attribute??
        friend ostream& operator<<(ostream& ausgabe, const String& s);
        */
    };
    
}