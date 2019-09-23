#include <iostream>

int main() {
	char target[] = "Jung HyeonSu"; //15byte
	long b[72]; // 201602.072   576byte 
	int a = 17; // 4byte
	int i = 612; // 4byte
	int *c = new int[602]; // 8byte
	char * copy = "is no no"; // 8byte
	char name = 'a'; // 1byte


	std::cout << "&name+i    = "<< &name+i  << std::endl;
	//std::cout << "target    = " << &target << std::endl;
	//std::cout << "long b    = " <<&b << std::endl;
	//std::cout << "int a     = " << &a << std::endl;
	//std::cout << "int i     = " <<&i << std::endl;
	//std::cout << "int c     = " <<&c << std::endl;
	//std::cout << "char copy = " << &copy << std::endl;
	//std::cout << "char name = " <<(void*) &name << std::endl;
}
