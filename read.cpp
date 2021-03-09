#include <iostream>
#include <fstream>
#include <stdlib.h> 

using namespace std;

//A function that will convert a hexadecimal into decimal and returns the integer back to main.
//The Parameters is the array of chars.
int  hexToDecimal(const char* hex);

const int MAX_SIZE = 999;

void playa(char *txt){

    cout << txt[2];
}

int main()
{
		ifstream hexa;
		hexa.open("example.txt");
					
			char* hexarray = new char[MAX_SIZE];
						
			while (!hexa.eof())
			{	
				for (int i = 0; i <= MAX_SIZE; i++)
				{

						hexa >> hexarray[i];
						
				}
			}
			  
        playa(hexarray);
		
		return 0;
}