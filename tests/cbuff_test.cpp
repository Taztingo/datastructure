#include <iostream>
#include "../my_cbuff.hpp"
using namespace std;


int main() {
	MyCBuff buff(3);
	
	//Initial trace
	cout << "The size is: " << buff.size() << "\n";
	cout << "Is it empty: " << buff.empty() << "\n";
	cout << "The top is: " << buff.top() << "\n";

	cout << "------------------\n";

	//Empty pop
	buff.pop();
	cout << "The size is: " << buff.size() << "\n";
	cout << "Is it empty: " << buff.empty() << "\n";
	cout << "The top is: " << buff.top() << "\n";

	cout << "------------------\n";

	//First push
	buff.push(1);
	cout << "The size is: " << buff.size() << "\n";
	cout << "Is it empty: " << buff.empty() << "\n";
	cout << "The top is: " << buff.top() << "\n";

	cout << "------------------\n";

	//Second push
	buff.push(2);
	cout << "The size is: " << buff.size() << "\n";
	cout << "Is it empty: " << buff.empty() << "\n";
	cout << "The top is: " << buff.top() << "\n";

	cout << "------------------\n";
	
	//Third push
	buff.push(3);
	cout << "The size is: " << buff.size() << "\n";
	cout << "Is it empty: " << buff.empty() << "\n";
	cout << "The top is: " << buff.top() << "\n";

	cout << "------------------\n";
	
	//Fourth push
	buff.push(4);
	cout << "The size is: " << buff.size() << "\n";
	cout << "Is it empty: " << buff.empty() << "\n";
	cout << "The top is: " << buff.top() << "\n";
	
	cout << "------------------\n";

	//Pop 1/3
	buff.pop();
	cout << "The size is: " << buff.size() << "\n";
	cout << "Is it empty: " << buff.empty() << "\n";
	cout << "The top is: " << buff.top() << "\n";
	
	cout << "------------------\n";

	//Pop 2/3
	buff.pop();
	cout << "The size is: " << buff.size() << "\n";
	cout << "Is it empty: " << buff.empty() << "\n";
	cout << "The top is: " << buff.top() << "\n";
	
	cout << "------------------\n";

	//Pop 3/3
	buff.pop();
	cout << "The size is: " << buff.size() << "\n";
	cout << "Is it empty: " << buff.empty() << "\n";
	cout << "The top is: " << buff.top() << "\n";
	return 0;
}
