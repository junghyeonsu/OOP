#include <iostream>

int fibo(int i){
	if(i == 1)
		return 0;
	else if(i==2)
		return 1;
	else
		return fibo(i-1) + fibo(i-2);
}

int main(){
	int i;
	std::cin >> i;
	int val = fibo(i);

	std::cout << "입력값=" << i << "출력값=" << val   << std::endl;
	return 0;
}
