#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string lastline;
string firstPart;
string total;
const char SPACER = ',';

int main (int argc, char const *argv[]) {

	string line;
	ifstream myfile (argv[1]);
	if (myfile.is_open())
	{
		while ( getline (myfile,line) )
		{

			if (!line.find("LOCK")) {
				firstPart = lastline.substr(lastline.find_last_of(":") + 1,10);
				firstPart.resize(firstPart.length() - 1);
				total = firstPart + SPACER;
				line = line.substr(line.find("(") + 1,100);
				line.resize(line.length() - 1);
				total.append(line);

				int i = 0;
				while(i < total.length()) {
					if (total.at(i) == ' ') {
						total.at(i) = SPACER;
					}
					i = i + 1;
				}

				int j = 0;
				while (j < total.length()) {
					if ( !isdigit(total.at(j)) && total.at(j) != SPACER ){
						total.erase(j, 1);
					}
					else {
						j++;
					}
				}

				cout << total << endl;
			}
			else {
				lastline = line;
			}
			
		}
		myfile.close();
	}

	else cout << "Error, could not open file. Does it exist?" << endl; 

	return 0;
}