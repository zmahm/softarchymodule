#include <stdio.h>

void funcLast(int z){
	int localVarLast = 20;
	printf("In funcLast:\n");
	printf("Address of argument z: %p\n", (void *)&z);
	printf("Address of local variable localVarLast: %p\n", (void *)&localVarLast);
}

void funcX(int a, int b, int c){
	int localVarX= 10;
	printf("In funcX:\n");
	printf("Address of argument a: %p\n", (void*)&a);
	printf("Address of argument b: %p\n", (void*)&b);
	printf("Address of argument c: %p\n", (void*)&c);
	printf("Address of local variable localVarX: %p\n", (void*)&localVarX);
}

void func1(int x, int y){
	int localVar1= 5;
	printf("In func1:\n");
	printf("Address of argument x: %p\n", (void*)&x);
	printf("Address of argument y: %p\n", (void*)&y);
	printf("Address of local variable localVar1: %p\n", (void*)&localVar1);
	funcX(x,y,localVar1);
}


int main(){
	int x=1, y=2, z=3;

	printf("In main:\n");
	printf("Address of variable x: %p\n", (void*)&x);
	printf("Address of variable y: %p\n", (void*)&y);
	printf("Address of variable z: %p\n", (void*)&z);
	func1(x,y);
	funcLast(z);
	
	return 0;
}

