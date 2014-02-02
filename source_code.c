#include <stdlib.h>
#include <stdio.h>

int main(){
	FILE* fd = fopen("source_code.c", "r+");
	char  line[128];

	while ( fgets ( line, sizeof line, fd ) != NULL ) /* read a line */
	{
		fputs ( line, stdout ); /* write the line */
	}
	fclose ( fd );
}
