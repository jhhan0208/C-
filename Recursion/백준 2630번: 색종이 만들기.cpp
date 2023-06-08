#include <iostream>
#include <vector>
using namespace std;

int w;
int b;

void color(const vector<vector<int>>& paper, int n, int x, int y){

	bool white = false;
	bool blue = false;
	for(int i=x; i<x+n; i++){
		for(int j=y; j<y+n; j++){
			if(paper[i][j]==0) white = true;
			else blue = true;
		}
	}

	if(white == true && blue == false) w++;
	else if(blue == true && white == false) b++;
	else{
		color(paper, n/2, x, y);
		color(paper, n/2, x+n/2, y);
		color(paper, n/2, x, y+n/2);
		color(paper, n/2, x+n/2, y+n/2);
	}
}

int main()
{
	int n;
	cin >> n;
	vector<vector<int>> paper(n, vector<int>(n, 0));

	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){ cin >> paper[i][j]; }
	}

	color(paper, n, 0, 0);

	cout << w << endl << b;

	return 0;
}
