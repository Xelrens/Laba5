#include <iostream>
#include <cstring>
using namespace std;

class String
{
public:
    String()
    {
        str = nullptr;
        length = 0;
    }

    String(const char* line)
    {
        length = strlen(line) + 1;
        str = new char[length];

        strcpy(str, line);
    }

    // конструктор копирования
    String(const String& other)
    {
        length = other.length;
        str = new char[length];

        strcpy(str, other.str);
    }

    ~String()
    {
        delete[] str;
    }

    String operator=(const String& other)
    {
        if (str != nullptr)
        {
            delete[] str;
        }

        length = other.length;
        str = new char[length];

        strcpy(str, other.str);

        return *this;
    }

    String operator=(string& other)
    {
        if (str != nullptr)
        {
            delete[] str;
        }

        length = other.length();
        str = new char[length];

        const char* other_str;
        other_str = other.c_str();

        strcpy(str, other_str);

        return *this;
    }

    //Конкатенация двух строк
    String operator+(const String& other)
    {
        char* newStr = new char[length + other.length + 1];

        strcpy(newStr, str);
        strcat(newStr, other.str);

        String returnObj(newStr);
        delete[] newStr;

        return returnObj;
    }

    String operator+=(const String& other)
    {
        strcat(str, other.str);

        String returnObj(str);

        return returnObj;
    }


    bool operator ==(const String& other)
    {
        return(strcmp(str, other.str) == 0) ? true : false;
    }

    bool operator ==(const int& other)
    {
        if (length == other)
            return true;
        else
            return false;
    }

    bool operator >(const String& other)
    {
        if (length > other.length)
            return true;
        else
            return false;
    }

    bool operator >(const int& other)
    {
        if (length > other)
            return true;
        else
            return false;
    }

    bool operator <(const String& other)
    {
        if (length > other.length)
            return false;
        else
            return true;
    }

    bool operator <(const int& other)
    {
        if (length > other)
            return false;
        else
            return true;
    }



    bool operator !=(const String& other)
    {
        return !(operator==(other));
    }

    char& operator [](int index)
    {
        return str[index];
    }


    void display()
    {
        cout << str;
    }

    //Определение размера строки
    void Size()
    {
        cout << length - 1;
    }

    //Возвращение i-того символа строки
    char Symbol(int index)
    {
        if (index<0 || index>length - 2)
            cout << "Error";
        else
        {
            char Symbol = str[index];
            return Symbol;
        }
    }


    friend istream& operator >> (istream& s, String& t);
   

    friend ostream& operator <<(ostream& s, String& t);
    

private:
    char* str;
    int length;
};



istream& operator >> (istream& s, String& t)
{
    t.length = 0;
    auto pos = s.tellg();
    while (!s.eof()) {
        if (s.get() == ' ' || s.peek() == '\n' || s.peek() == '\r')
            break;
        t.length++;
    }
    t.str = new char[t.length];
    s.seekg(pos);
    s.read(t.str, t.length);
    s.seekg(1, std::ios::cur);
    return s;
}

ostream& operator<<(ostream& s, String& t)
{
    s << t.str;
    return s;
}
