#include "types.h"
#include "stat.h"
#include "fcntl.h"
#include "user.h"

int main(int argc, char *argv[]){
	if(argc<2){
		printf(1,"Error: Invalid number of arguments\n");
		exit();
	}
	int n = atoi(argv[1]);
	int i;
	for(i=0; i<n; i++){
		if(fork()==0){
			printf(1,"Child PID: %d\n", getpid());
			exit();
		}
	}
	for(i=0; i<n; i++){
		wait();
	}
	printf(1,"Parent PID: %d\n", getpid());
	exit();
}
