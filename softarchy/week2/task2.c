#include <stdio.h>
#include <stdlib.h>

int globalVar=42;

int main(int argc, char *argv[]){

	if(argc!=2) {
		printf("usage %s<memory address>\n", argv[0]);
		printf("Address of globalVar %p\n", (void *)&globalVar);
		return 1;
	}

	unsigned long addr = strtoul(argv[1], NULL, 16);
	char *ptr = (char *)addr;
	printf("Accessing memory at address: %p: %x\n",(void *) ptr, *ptr);

	return 0;
}
/*
	usage for this is  first "./task2" that'll give you the address of globalVar
	then you can use "./task2 <address>"
	
	I'm guessing Lee's distro has Address Space Layout Ranomization (ASLR) disabled but 
	this is enabled by default on many others so if you notice the memory addresses changing
	on print, do the following


	(you cant do this on uni computers for obvious reasons lol)

	echo 0 | sudo tee /proc/sys/kernel/randomize_va_space
 	
	this disables ASLR so you can use the address printed on no arg usage 
 	
	to renable use same command but do echo 2 lol 

	this task could've been made 10 times more simple if he just said to print the 
	byte directly with the pointer instead of input from command line :(
*/

