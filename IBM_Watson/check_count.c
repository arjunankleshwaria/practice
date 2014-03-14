#include <stdio.h>
#include <stdint.h>
#include "utils.h"
#include "mynode.h"

//#define	READ_FILE
#ifdef	READ_FILE

/* Read lines from a file */
int main()
{
	/* create an array to store all the root pointers of all the BSTs */
	struct node *arr[ALPHABET_COUNT + 1] = {0};

	/* Open the file to read */
	FILE *file = fopen("input.txt", "r");

	if(file != NULL)
	{
		/* buffer to read a line */
		char line[MAX_LINE_LENGTH] = {0};

		/* read the file line by line */
		while(fgets(line, MAX_LINE_LENGTH, file) != NULL)
		{
			/* if EOF reached, break out of the loop */
			if(feof(file))
				break;

			/* calculate the index in the array to which the newly
			 * read line should belong to
			 */
			int8_t index;
			if(line[0] < LOWER_CASE_START)
				index = line[0] - UPPER_CASE_START;
			else
				index = line[0] - LOWER_CASE_START;

			if(!(index >= 0 && index < ALPHABET_COUNT))
				index = ALPHABET_COUNT;

			/* check if the line read has been read before
			 * and update its count accordingly
			 */
			updateCount(&(arr[index]), line);
		}

		/* close the file */
		fclose(file);

		/* print all the lines read and their count */
		printf("\nOutput:\n\n");
		printCounts(arr);

		/* free all the memory allocated to store the data */
		freeAllData(arr);
	}
	else
	{
		perror("Could not open the file.\n");
		exit(-1);
	}
	return 0;
}

#else

/* Keep reading input from user through STDIN */
int main()
{
	/* create an array to store all the root pointers of all the BSTs */
	struct node *arr[ALPHABET_COUNT + 1] = {0};

	while(1)
	{
		printf("\nInput:\n");

		/* buffer to read a line of input from STDIN */
		char line[MAX_LINE_LENGTH] = {0};

		/* read a line of input from STDIN */
		int r = read(STDIN, line, MAX_LINE_LENGTH);
		if(r < 0)
		{
			perror("Error reading from STDIN.\n");
			exit(-1);
		}
		if(r == 0)
			continue;

		printf("\nOutput:\n");

		/* NULL terminate the line just read into the buffer */
		line[r - 1] = '\0';

		/* calculate the index in the array to which the newly
		 * read line should belong to
		 */
		int8_t index;
		if(line[0] < LOWER_CASE_START)
			index = line[0] - UPPER_CASE_START;
		else
			index = line[0] - LOWER_CASE_START;

		if(!(index >= 0 && index < ALPHABET_COUNT))
			index = ALPHABET_COUNT;

		/* check if the line read has been read before
		 * and update its count accordingly
		*/
		updateCount(&(arr[index]), line);

		/* print all the lines read and their count */
		printCounts(arr);
	}
	return 0;
}

#endif
