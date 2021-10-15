#include <iostream>
using namespace std;
class Foo {
	int M;
public:
	Foo() {
		M = 1;
		Foo(M + 2);

	}
	Foo(int f) {
		M = f;
	}
	~Foo() {
		cout << M;
	}
};

int main() {
	Foo F;
	return 0;
}