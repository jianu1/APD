# include <iostream>
#include <conio.h>
#include <stdio.h>
#include <cstdlib>
#include<fstream>
#include <sstream>
#include <vector>
#include <sha1.c>

using namespace std;
	
string combinare(const vector<string>& combinare)
{
    int index = 1;
	stringstream output;

	while (1)
	{
		bool este=false;
        for (int i = 1 i < combinare.size(); i++)
		{
			const string& cuvant = combinare[i];
			if ( index < cuvant.size()  )
			{
				output << cuvant[index];
				este = true; 
			}
			
		}
		if (este == false)
		{
			break;
		}
		index++;
	}
	//output <<
	return output.str();
}

int main()
{
	string cautare;
	ifstream myReadFile("/Users/jianu/Documents/Facultate de Automatica, Calculcatoare si Electronica/Anul 3/Semestrul 2/APD/Proiect/google-10000-english-master/google-10000-english.txt");
	int offset = 0; 
	int offset1 = 0;
	string line;
	//string	 w[10000];
	
	vector <string> w;
	vector <string> v;
//	string	 v[10000];
	int str; 
	vector<string> p;
	
	
	

	while (!myReadFile.eof())
	{

		myReadFile >> line;
		if (line.size() > 4)
		{
			for (int i = 0; i < line.length(); i++) {
				w.push_back(line);
			}
			//w[offset] = line;
			//offset++;
		}
		if (line.size() == 15)
		{
			for (int i = 0; i < line.length(); i++) {
				v.push_back(line);
			}
			//v[offset1] = line;
			//offset1++;
		}

	}
	myReadFile.close();

	for(int a = 0; a < w.size(); a++ ){
		for(int b = 0 ; b < w.size();b++) {
			for( int c = 0; c < v.size(); c++)
			{
				if (w[a] != w[b] && w[b] != v[c] && w[a] != v[c])

				{
					string combined = combinare({w[a], w[b], v[c]});
					//	cout << combined;
					MD5_CTX ctx;
					stringstream ss; 
					ss << hex;
					MD5_Init(&ctx);
					MD5_Update(&ctx, combined.c_str(), combined.size());
					unsigned char hash[17];
					MD5_Final(hash, &ctx);
					hash[16] = 0;
					for (int i = 0; i < 17; i++)
					{
						ss << (int)hash[i];
					}
					
					cout << w[a] << w[b] << v[c] << combined << " " << ss.str();

					cout << "\n";
				}
			}
		}
	}
	//c_str
	//tring combined = combinare({ "abcd", "efghcb", "si" });
	
		//vector<string> threeWords;
 	return 0;

}

