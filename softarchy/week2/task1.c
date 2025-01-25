#include <stdio.h>

int globalVar = 42;
static int staticVar;

void simpleFunction(){
	printf("yoyo\n");
}

int main(){
	printf("yoyo main\n");
	simpleFunction();
	return 0;
}
