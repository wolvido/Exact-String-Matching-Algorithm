# include <string.h>
#include <iostream>
#include <string>
#include <stdlib.h> 
#include <fstream>
#include <chrono>
using namespace std;

int  hexToDecimal(const char* hex);
const int MAX_SIZE = 10000000;
# define NO_OF_CHARS 256

void search(char *txt, char *pat)
{
    int m = strlen(pat);
    int n = strlen(txt);

    int s = 0; // s is shift of the pattern with respect to text
    int j = 0; // counter

    while (s <= n )
    {
        while (pat[j] == txt[s])
            j++;

        if (j > m)
        {
            printf("\n pattern occurs at shift = %d", s);
            s += n;
 
        }
        else
        s += m;

    }
}

/* Driver code to test above funtion */
int main()
{
    ifstream read;
		read.open("example.txt");
					
			char* txt = new char[MAX_SIZE];
						
			while (!read.eof())
			{	
				for (int i = 0; i <= MAX_SIZE; i++)
				{

						read >> txt[i];
						
				}
			}
			  
    char pat[] = "pattern";

    auto start = chrono::steady_clock::now();

    search(txt, pat);

    auto end = chrono::steady_clock::now();

    cout << " " << endl;
    cout << "simplified BMH execution:" << endl;
    cout << "Elapsed time in nanoseconds : "
        << chrono::duration_cast<chrono::nanoseconds>(end - start).count()
        << " ns" << endl;
 
    cout << "Elapsed time in microseconds : "
        << chrono::duration_cast<chrono::microseconds>(end - start).count()
        << " µs" << endl;
 
    cout << "Elapsed time in milliseconds : "
        << chrono::duration_cast<chrono::milliseconds>(end - start).count()
        << " ms" << endl;
 
    cout << "Elapsed time in seconds : "
        << chrono::duration_cast<chrono::seconds>(end - start).count()
        << " sec";
    return 0;
}