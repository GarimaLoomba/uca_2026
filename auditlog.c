#include <unistd.h>    
#include <fcntl.h>     
#include <string.h>    
#include <stdlib.h>    
#include <stdio.h>  


# define BUFF_SIZE 1024 
int main(int argc , char *argv[]){
	if(argc<2){
		printf("Argumets less than required ");
		return (-1);

	}

	if(strcmp(argv[1],"--add")==0){
		if(argc<3){
			printf("Message is not entered ");
			return (-1);
		}
		int fd = open(argv[1] , O_WRONLY | O_CREAT | O_APPEND , 0644);
		if(fd==-1){
			printf("Problen opening file ");
			return -1;
		}

		write(fd , argv[2] , strlen(argv[2]));
		write(fd , "\n" , 1);

		close(fd);

		printf("Log added succesfully\n");
		return 0 ;



		
	}

	else if (strcmp(argv[1], "--view") == 0){
		int fd = open(argv[1] , O_RDONLY);
		if(fd==-1){
			printf("Problem opening file ");
			return -1 ;

		}
                 char buffer[BUFF_SIZE];
		ssize_t bytesRead ;


		while((bytesRead = read(fd,buffer , BUFF_SIZE-1))>0){
			buffer[butesRead] = '\0';
			printf("%s" , buffer);
		}
	}
}

