#include <iostream>
#include <algorithm>
#include <cstring>

#define TAM 260010

using namespace std;

void kmpPreProcess(int *edge, string pat){
	int lenp = pat.length();
	int i = 0, j = -1; edge[0] = -1;

	while (i < lenp){
		while (j>=0 && pat[i] != pat[j])	j = edge[j]; 

		i++; j++;
		edge[i] = j;
	}
}

bool isSubStr(string text, string pattern) {
	int edge[1010];
	kmpPreProcess(edge, pattern);

	int lent = text.length();
	int lenp = pattern.length();
	int i = 0, j = 0;

	while (i < lent) {
		while (j >= 0 &&  text[i] != pattern[j])	j = edge[j];

		i++; j++;
		if (j == lenp)	return true;
	}

	return false;
}

int main(int argc, char const *argv[]) {
	int n_texts;	cin >> n_texts;
	while (n_texts-- > 0) {
		string text;	cin >> text;
		int n_patterns;	cin >> n_patterns;

		while (n_patterns-- > 0) {
			string pattern;	cin >> pattern;
			if (isSubStr(text, pattern)) {
				cout << 'y' << endl;
			} else {
				cout << 'n' << endl;
			}
		}
	}

	return 0;
}