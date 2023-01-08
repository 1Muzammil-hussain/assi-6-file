#include <fstream>
#include <iostream>
#include <string>
using namespace std;
int main() {
    string file1Name, file2Name;
    int file1WordCount = 0, file2WordCount = 0;
    cout << "Enter the name of the first file: ";
    cin >> file1Name;
    cout << "Enter the name of the second file: ";
    cin >> file2Name;
    ifstream file1(file1Name);
    if (!file1.is_open()) {
        cout << "Error opening " << file1Name << endl;
        return 1;
    }
    string word;
    
    
    while (file1 >> word) {
        file1WordCount++;
    }

    file1.close();
    ifstream file2(file2Name);
    if (!file2.is_open()) {
        cout << "Error opening " << file2Name << endl;
        return 1;
    }
    while (file2 >> word) {
        file2WordCount++;
    }
    file2.close();
    cout << "Number of words in " << file1Name << ": " << file1WordCount << endl;
    cout << "Number of words in " << file2Name << ": " << file2WordCount << endl;
//	compare word by word both files
	int matchedWordCount=0;
	ifstream f1(file1Name);
	ifstream f2(file2Name);
	string secFileWord;
	while (f1 >> word && f2 >> secFileWord) {
        if(word==secFileWord)
		matchedWordCount++;
    }
    float p=0;
    cout<<"Total word matched : "<<matchedWordCount<<endl;
	p=matchedWordCount*100/file1WordCount;
    cout<<"Percentage Similarity: "<<p;
	return 0;
}