#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main()
{
	queue<int> q;
	vector<int> answer;
	int n;
	cin >> n;

	for(int i=1; i<=n; i++) q.push(i);

	for(int i=0; i<n; i++){
		answer.push_back(q.front());
		q.pop();
		q.push(q.front());
		q.pop();
	}

	for(auto elem : answer) cout << elem << ' ';
	return 0;
}
