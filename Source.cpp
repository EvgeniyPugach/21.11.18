# include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <clocale>

using namespace std;

const int N = 256;

int GetLength(char*);
void CompareInLength(char* line1,char* line2);
bool equalline(char* line1, char* line2);
int FindSubstringIndex(char* line, char* substring);

int main()
{
	char myString1[N]; char myString2[N];
	char substring[N];
	cin >> myString1; cin >> myString2;
    
	CompareInLength (myString1 , myString2);
	

	equalline(myString1, myString2);

	cout << "Enter a substring : ";
	cin >> substring;
	int k = FindSubstringIndex(myString1, substring);
	cout << k << endl;


	system("pause");
	return 0;

 }

int GetLength(char* line)
{
	int length = 0;

	while (line[length]) // == line[length] != '/0' - default
	{
		length++;
	}

	return length;
}

void CompareInLength(char* line1, char* line2) 
{

	if (GetLength(line1) > GetLength(line2))
	{
		cout << "Max lenght = " << GetLength(line1) << endl;
	}
	else if (GetLength(line2) < GetLength(line1))
	{
		cout << "Max lenght = " << GetLength(line2) << endl;

	}
	else {
		cout << "equal" << endl;
	}

}

bool equalline(char* line1, char* line2)
{
	int k = 0;

	if (GetLength(line1) == GetLength(line2))
	{
		for (int i = 0; i < GetLength(line1); i++)
		{
			if (line1[i] == line2[i])
			{
				k++;
			}
			else { return false; break; }
		}
	}
	else return false;
	if (k == GetLength(line1))
	{
		return true;
	}
}

int FindSubstringIndex(char* line, char* substring)
{
	int n = GetLength(line),
		m = GetLength(substring);

	if (m > n)
	{
		return -1;
	}
	int j = 0;
	for (int i = 0;  i < n && j < m; i++)
	{
		if (line[i] == substring[j])
		{
			return i;
		}
	}
	
}