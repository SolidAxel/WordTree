#include <fstream>
#include <iostream>
#include <cctype>
#include <string>
#include "WordTree.hpp"
using namespace std;

int main() {
    int wordcount = 0;
    ifstream fin;
    ofstream fout;
    string filename;
    cout << "Enter name of file with text to analyze: ";
    cin >> filename;
    fin.open(filename.c_str());
    if (fin.fail()) {
        cout << "Error opening file.\n";
        exit(1);
    }
    cout << "\nAnalyzing " << filename << ".\n";
    
    WordTree myTree;
    
    char c;
    
    while (fin.get(c)) {
        string word = "";
        while (isalpha(c) || c == '\'') {
            c = tolower(c);
            word = word + c;
            fin.get(c);
        }
        if (!word.empty()) {
            myTree.Add(word);
            wordcount++;
        }
        
    }
    fin.close();
    fout.open("results.txt");
    cout << "\nWord counts:\n\n";
    cout << myTree;
    fout << myTree;
    cout << "\nTotal number of words in text: " << wordcount << ".\n";
    fout << "\nTotal number of words in text: " << wordcount << ".\n";
    cout << "Number of distinct words appearing in text: "
    << myTree.CountNodes() << ".\n";
    fout << "Number of distinct words appearing in text: "
    << myTree.CountNodes() << ".\n";
    fout.close();
    return 0;
}
// /Users/axelgarcia/Desktop/doi.txt
// /Users/axelgarcia/Desktop/odyssey1.txt
