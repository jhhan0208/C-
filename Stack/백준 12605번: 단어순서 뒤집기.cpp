#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

void print_reverse(const string& a){
	stack<string> word;
	string temp;
	int i = 0;

	while(a[i] != NULL){
		if(a[i] == ' '){
			word.push(temp);
			temp = "";
		}
		else temp.push_back(a[i]);
		i++;
	}
	word.push(temp);

	while(!word.empty()){
		cout << word.top() << ' '; 
		word.pop();
	}
}

int main()
{
	int n;
	cin >> n;
	cin.ignore();
	vector<string> words;
	string word;
	for(int i=0; i<n; i++) {
		getline(cin, word);
		words.push_back(word);
	}

	for(int i=0; i<n; i++) {
		cout << "Case #" << i+1 << ": ";
		print_reverse(words[i]);
		cout << endl;
	}
	
}
