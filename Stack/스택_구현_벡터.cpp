#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class stack
{
private:
	vector<T> v;
public:
	stack(){}

	void push(const T& val){ v.push_back(val); }
	void pop(){ v.pop_back(); }

	const T& top() const { return v.back(); }
	bool empty() const { return v.empty(); }
	T size() const { return v.size(); }
};

int main()
{
	stack<int> stk;
	stk.push(10);
	stk.push(20);
	stk.push(30);
	stk.pop();

	cout << stk.top() << endl;
	stk.push(40);

	while(!stk.empty()){
		cout << stk.top() << ' ';
		stk.pop();
	}
}
