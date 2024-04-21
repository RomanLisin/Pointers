#include<iostream>
using namespace std;

int string_length(unsigned char arr[]);
int string_length(char arr[]);
void to_lower(unsigned char arr[]);
void to_upper(unsigned char arr[]);
void shrink(unsigned char arr[]);
bool is_palindrome(char arr[]);
bool is_int_number(char arr[]);
int to_int_number(char arr[]);

void main()
{
	setlocale(LC_ALL, "");
    unsigned char chArr[] = "Хорошо          живет    на   свете      Винни    Пух";
    unsigned char charrEng[] = "GOOD           LIVE   BY            VINNY    PUH   ";
    char strArr[] = "зимаамиз";
    char intStrArr[] = "-3335656";
	
	cout << endl << "The string on " << string_length(chArr) << " symbols." << endl;
    cout << chArr << endl;
    shrink(chArr);
    cout << chArr << endl;
    to_lower(charrEng);
    cout << charrEng << endl;
    to_upper(charrEng);
    cout << charrEng << endl;
    shrink(charrEng);
    cout << charrEng << endl;
    cout << "String " << strArr << " " << (is_palindrome(strArr)? "is palindrom ": "is not palindrom ") << endl;
    cout << "String " << intStrArr << " " << (is_int_number(intStrArr) ? "is integer number" : "isn't integer number") << endl;
    cout << "String " << intStrArr << " is " << to_int_number(intStrArr) << " number" << endl;
}

int string_length(unsigned char arr[])
{
	int i = 0;
	while (arr[i++]); // while (arr[i] != '\0')i++;
	return i;
}
int string_length(char arr[])
{
    int i = 0;
    while (arr[i] != '\0')i++;
    return i;
}
void to_lower(unsigned char arr[])
{
    int i = 0;
    while (arr[i])
    {
        if (arr[i] >= 'А' && arr[i] <= 'Я') {
            arr[i] += ('а' - 'А');
        }
        else if (arr[i] >= 'A' && arr[i] <= 'Z') {
            arr[i] += ('a' - 'A');
        }
        i++;
    }
}
void to_upper(unsigned char arr[])
{
    int i = 0;
    while (arr[i])
    {
        if (arr[i] >= 'а' && arr[i] <= 'я') {
            arr[i] += ('А' - 'а');
        }
        else if (arr[i] >= 'a' && arr[i] <= 'z') {
            arr[i] += ('А' - 'а');
        }
        i++;
    }


}

    void shrink(unsigned char str[]) {  
    int i = 0;
    while (str[i] == 0x20)i++; // remove begin space , 0x20 - space - ' '
   /* int j = 0;
    while (str[i]) str[j++] = str[i++];
    str[j] = '\0';*/
    int len = string_length(str); //j;
    while (len > 0 && str[len - 1] == 0x20) str[--len] = '\0';  // remove end space
    // remove middle space
    i = 0;
    while (str[i]) {
        if (str[i] == 0x20 && str[i + 1] == 0x20) {
            int k = i;
            while (str[k]) {
                str[k] = str[k + 1];
                ++k;
            }
            continue;
        }
        ++i;
    }
}
    bool is_palindrome(char arr[])
    {
       /* int i = 0;
        int j = 0;
        while (arr[i]) arr[j++] = arr[i++];
        arr[j] = '\0';*/
        int j = string_length(arr);
        int len = j;
        int i = 0;
        while (i < (j / 2)) if (arr[i++] != arr[--len]) return 0;
        return 1;
    }
    bool is_int_number( char arr[])
    {
        while (*arr) {
            if (*arr == '-');
            else if (*arr < '0' || *arr > '9') return false;

            ++arr;
        }
        return true;
    }
    int to_int_number(char arr[])
    {
        int sign = 1;
        int number = 0;

        if (*arr == '-') {
            sign = -1;
            ++arr;
        }
        if (is_int_number(arr))
        {   
            while (*arr != '\0') {
                number = number * 10+ (*arr - '0');
                ++arr;
            }
            return number*sign;
        }
        else return 0;
    }