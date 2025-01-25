#include <stdio.h>

int globalVar = 42;

void printAddresses(){
	int localVar = 10;
	printf("Address of globalVar: %p\n",(void *)&globalVar);
	printf("Address of localVar: %p\n",(void *) &localVar);
	printf("Address of printAddresses(): %p\n",(void *)&printAddresses);
}
int main(){
	printf("Address of main():%p\n",(void *)&main);
	printAddresses();
	return 0;
}
