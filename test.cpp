#include <iostream>
#include <set>

using namespace std;

int main()
{
	set<char> setTest;

	setTest.insert('b');
	setTest.insert('i');
	setTest.insert('g');
	setTest.insert('b');
	setTest.insert('i');
	setTest.insert('n');
	setTest.insert('g');

	string s = "";
	while(!setTest.empty())
	{
		s += *setTest.begin();
		setTest.erase(setTest.begin());

	}
	cout << s << endl;
}