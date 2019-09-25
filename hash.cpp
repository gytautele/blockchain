
#include <string>
#include <iomanip>
#include <iostream>
#include<fstream>
#include<sstream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iterator> 

using std::string;
using std::cout;
using std::endl;
using std::cin;
using std::vector;

void read (vector<string> &userstring, string input, int &size)
{
	int i=0;
	cout << "Please write your input, when You want to stop, press ENTER, ESC and ENTER again:" << endl;
	while (cin >> input)
	{	
		if (int(input[0])== 27) break;
		userstring.push_back(input);
		size+=input.size();		
		i++;
	}

	/*for (int i=0; i<naujas.size(); i++)
	{
		cout << naujas[i];
	}*/

	/*for(int i=0; i<userstring.size(); i++)
    {
        cout<<userstring[i];
    }*/
}
//-------------------------------
void read1(vector<string> &userstring, string input, int &size)
{
	std::ifstream in("text.txt");

	if (!in) {
    cout << "Unable to open file text.txt";
    exit(1);   // call system to stop
	}

	while (in >> input)
	{
		userstring.push_back(input);
	}

	/*for(int i=0; i<userstring.size(); i++)
    {
        cout<<userstring[i];
        cout<<size<<endl;
    }*/

}
//-------------------------------
void hash_fun(vector<string> &userstring, string hash[], int size, std::vector<string> foo)
{
	int nul=0; //amount of zero symbol in the end of hash
	nul=size/6;

	//std::reverse(userstring.begin(), userstring.end()); 

	/*for (int i=0; i<nul; i++)
	{
		hash[i]='0';

	}

	for (int i=0; i<nul; i++)
	{
		cout << hash[i];
	}*/

}


int main(int argc, char const *argv[])
{
	vector<string> userstring; //string for saving data
	string input; //temporary 
	int size=0; //amount of letters
	string hash[32];

	bool a; //for choice
	cout << "If You want to read from file press 1, otherwise press 0:" << endl;
	cin >> a;
	if (a==0) read(userstring, input, size);
	else read1(userstring, input, size);

	std::vector<string> foo ={"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "q", "l", "m", "n", "o", "p", "u" 
	"ab", "bc", "cd", "de", "ef", "fg", "gh", "hi", "ij", "jk", "kl", "lm", "mn", "no", "op", "pq", "qr", "rs", "st", "tu", "uv", "vw", "wx", "xy", "yz", "za"};

	hash_fun(userstring, hash, size, foo);
	
	return 0;
}
