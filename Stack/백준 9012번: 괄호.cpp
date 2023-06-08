#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

void check(const string& x)
{
	stack<char> stk;
	for(int i=0; i<x.length(); i++){
		if(x[i] == '('){
			stk.push(x[i]);
		}
		else{
			if(stk.empty()){ cout << "NO"; return; }
			else if(stk.top() == '('){ stk.pop(); }
			else{ cout << "NO"; return; }
		}
	}

	(stk.empty()) ? cout << "YES" : cout << "NO";
}

int main()
{
	int n;
	cin >> n;
	cin.ignore();

	vector<string> lines;

	for(int i=0; i<n; i++){
		string line;
		getline(cin, line);
		lines.push_back(line);
	}

	for(int i=0; i<n; i++){
		check(lines[i]);
		cout << endl;
	}


	return 0;
}
