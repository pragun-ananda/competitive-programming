#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

string extendSeq(char p[], int len, char income[], char outgo[]) {
	int i = 0;
	while (i < len) {
		if (p[i] == 'Y')
			if (income[i+1] == 'Y' && outgo[i] == 'Y') {
				p[i+1] = 'Y';
			}
		i++;
	}
	i = len-1;
	while (i > 0) {
		if (p[i] == 'Y')
			if (income[i-1] == 'Y' && outgo[i] == 'Y') {
				p[i-1] = 'Y';
			}
		i--;
	}
	string possible(p);
	return possible;
}

void test_case() {
	ifstream file("travel_restrictions_input.txt");
	if (file.is_open()) {
		string line;
		getline(file, line);

		int airlines = stoi(line);
		int counter = 1;

		string flights;
		// for each case:
		while (getline(file, flights) && counter < airlines+1){
			vector<string> paths;

			// read in information
			int numflights = stoi(flights);

			string incoming;
			getline(file, incoming);

			char in[incoming.length()];

			for (int i = 0; i < sizeof(in); ++i) {
				in[i] = incoming[i];
			}

			string outgoing;
			getline(file, outgoing);

			char out[outgoing.length()];
			for (int i = 0; i < sizeof(out); ++i) {
				out[i] = outgoing[i];
			}

			for (int i = 0; i < numflights; i++) {
				char path[numflights];

				bool first = false;
				bool last = false;
				if (i == 0)
					first = true;
				if (i == numflights-1)
					last = true;

				if (first){
					if (in[i+1] == 'Y') {
						path[i+1] = 'Y';
					}
					else {
						path[i+1] = 'N';
					}
				}
				if (last) {
					if (in[i-1] == 'Y') {
						path[i-1] = 'Y';
						
					}
					else {
						path[i-1] = 'N';
					}
				}
				if (!first && !last) {
					if (in[i-1] == 'Y') {
						path[i-1] = 'Y';
					}
					else {
						path[i-1] = 'N';
					}
					if (in[i+1] == 'Y') {
						path[i+1] = 'Y';
					}
					else {
						path[i+1] ='N';
					}
				}

				if (out[i] == 'N') {
					if (first)
						path[i+1] = 'N';
						
					if (last) 
						path[i-1] = 'N';
						
					else {
						path[i+1] = 'N';
						path[i-1] = 'N';
					}
				}

				for (int j = 0; j < numflights; j++) {
					if (i - j > 1 || j - i > 1) {
						path[j] = 'N';
						continue;
					}
					if (i == j) {
						path[j] = 'Y';
					}			
				}
				string oldpath(path);
				string newpath = extendSeq(path, numflights, in, out);
				paths.push_back(newpath.substr(0,numflights));		
			}
			cout << "Case #" << counter << ": " << endl;
			for (int i = 0; i < paths.size(); i++) {
				cout << paths[i] << endl;
			}
			counter++;
		}
	}
	else{
		cout << "file didn't read" << endl;
	}
	file.close();
}


int main() {
    test_case();
   	return 0;
}


