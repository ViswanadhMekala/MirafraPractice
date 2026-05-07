#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>

int main(){
	int pid;
	pid = fork();
	if(pid > 0){
	int a = 10;
	int b = 20;

	int c = a+b;

	printf("Value is %d.\n",c);
	wait(NULL);
	exit(0);
	}
	else if(pid == 0){
	 printf("Hello from child\n");
	}
	
}
