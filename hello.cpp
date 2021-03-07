#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
using namespace std;
 
bool IsVowel (char c, char *vowel) { 

    char* end = vowel + sizeof(vowel) / sizeof(vowel[0]);            
    char* position = std::find(vowel, end, c);

    return (position != end); 
 }
int main()
{
char blah[] = "csaaw";
char pat[] = "abcdefg";
cout << IsVowel(blah[3],pat);
        
}