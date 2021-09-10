#include <iostream>

#include <vector>
#include <string>

using namespace :: std;

void MakePassword(string password, vector<string> words, string rule, int index) {
    if (index == int(rule.length())) {
        cout << password << endl;
        return;
    }

    if (rule[index] == '#'){
        for (int i=0; i<int(words.size()); i++) {
            string copy = password + words[i];
            MakePassword(copy, words, rule, index+1);        
        }
    } else {
        for (int i=0; i<10; i++) {
            string copy = password + to_string(i);
            MakePassword(copy, words, rule, index+1);        
        }
    }
}

int main() {
    int n_dictionaries;
    cin >> n_dictionaries;

    int n_words = n_dictionaries;
    while (n_dictionaries-- > 0) {
        cout << "--" << endl;

        // Read the words
        vector<string> words;
        for (int i=0; i<n_words; i++) {
            string word;    cin >> word;
            words.push_back(word);
        }

        // Read the rules
        int n_rules;    cin >> n_rules;
        for (int i=0; i<n_rules; i++) {
            string rule;    cin >> rule;
            MakePassword("",  words, rule, 0);
        }

        cin >> n_words;
    }

    return 0;    
}