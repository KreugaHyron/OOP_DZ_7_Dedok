#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;
//класс MyString
class MyString {
private:
    char* str;
    int size;
public:
    MyString() : size(80) {
        str = new char[size + 1];
        for (int i = 0; i <= size; ++i) {
            str[i] = '\0';
        }
    }
    MyString(int customSize) : size(customSize) {
        str = new char[size + 1];
        for (int i = 0; i <= size; ++i) {
            str[i] = '\0';
        }
    }
    MyString(const char* initialStr) : size(strlen(initialStr)) {
        str = new char[size + 1];
        strcpy(str, initialStr);
    }
    MyString(const MyString& other) : size(other.size) {
        str = new char[size + 1];
        strcpy(str, other.str);
    }
    ~MyString() {
        delete[] str;
    }
    void inputString() {
        cout << "Введите строку: ";
        cin >> str;
    }
    void outputString() const {
        cout << "String: " << str << "\n";
    }
    static int getCount() {
        static int count = 0;
        return count;
    }
    MyString& operator++() {
        char* temp = new char[size + 2];
        strcpy(temp, str);
        temp[size] = 'x';
        temp[size + 1] = '\0';
        delete[] str;
        str = temp;
        size++;
        return *this;
    }
    MyString& operator--() {
        if (size > 0) {
            str[size - 1] = '\0';
            size--;
        }
        return *this;
    }
    MyString operator+(int count) const {
        MyString result(*this);
        char* temp = new char[result.size + count + 1];
        strcpy(temp, result.str);
        for (int i = 0; i < count; ++i) {
            temp[result.size + i] = 'x';
        }
        temp[result.size + count] = '\0';
        delete[] result.str;
        result.str = temp;
        result.size += count;
        return result;
    }
    MyString operator-(int count) const {
        MyString result(*this);
        if (count >= result.size) {
            delete[] result.str;
            result.str = new char[1];
            result.str[0] = '\0';
            result.size = 0;
        }
        else {
            result.size -= count;
            result.str[result.size] = '\0';
        }
        return result;
    }
};
int main()
{
    MyString s("Amigo");
    ++s;
    s.outputString();
    --s;  
    s.outputString();
    MyString s2 = s + 3;  
    s2.outputString();
    MyString s3 = s2 - 2;  
    s3.outputString();
    MyString s4 = s3 + 8;
    s4.outputString();
    MyString s5 = s4 - 4;
    s5.outputString();
    MyString s6 = s5 - 3;
    s6.outputString();
}