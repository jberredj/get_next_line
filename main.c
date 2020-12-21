#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "get_next_line.h"

void	ft_putchar_fd(char c, int fd);

int main(int argc, char **argv)
{
	int file1 = 0;
	char *line1 = NULL;
	int gnlend1 = 1;
	#ifdef FD2
	int file2 = 0;
	char *line2 = NULL;
	int gnlend2 = 1;
	#endif
	int j = 1;

	printf("---- GNL TEST ----\n\n");
	while (j < argc) {
		file1 = open(argv[j], O_RDONLY);
		#ifdef FD2
		file2 = open(argv[j + 1], O_RDONLY);
		#endif
		printf("file1 = %s\nOPEN = %s\n", argv[j], ((file1 < 0) ? "KO" : "OK"));
		#ifdef FD2
		printf("file2 = %s\nOPEN = %s\n", argv[j + 1], ((file2 < 0) ? "KO" : "OK"));
		#endif
		for(; gnlend1 > 0/* || gnlend2 > 0*/;)
		{
			gnlend1 = get_next_line(file1, &line1);
			printf("\n---- MAIN ----\nOUTPUT\t[%d]\n", gnlend1);
			printf("FD = %d\n", file1);
			printf("LINE ADRESS\t%p\nLINE CONTENT\t%s\n", line1, line1);
			printf("\n");
			free(line1);
			line1 = NULL;
			#ifdef FD2
			gnlend2 = get_next_line(file2, &line2);
			printf("\n---- MAIN ----\nOUTPUT\t[%d]\n", gnlend2);
			printf("FD = %d\n", file2);
			printf("LINE ADRESS\t%p\nLINE CONTENT\t%s\n", line2, line2);
			printf("\n");
			free(line2);
			line2 = NULL;
			#endif
		}	
		close(file1);
	#ifdef FD2
		close(file2);
		j+= 2;
	#else
		j++;
	#endif
	}
	return 0;
}
