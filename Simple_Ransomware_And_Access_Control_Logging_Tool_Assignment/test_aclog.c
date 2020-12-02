#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

#include <signal.h>
#include <sys/stat.h>


int main() 
{
	int i;
	size_t bytes;
	FILE *file1;
	char filenames1[10][10] = {"file_RW_0", "file_RW_1", 
			"file_RW_2", "file_RW_3", "file_RW_4",
			"file_RW_5", "file_RW_6", "file_RW_7", 		
			"file_RW_8", "file_RW_9"};

	/* example source code */
	//setuid(2000);

	//setreuid(2000, 2000);
	//printf("%d\n", getuid());

	for (i = 0; i < 10; i++) 
	{
		file1 = fopen(filenames1[i], "r");		//this should fail

		file1 = fopen(filenames1[i], "w+");

		if (file1 == NULL) 
		{
			printf("fopen error 1\n");
		}
		else 
		{
			bytes = fwrite(filenames1[i], strlen(filenames1[i]), 1, file1);
			fclose(file1);
		}

	}

	
	/* add your code here */

//CREATE FILE, CHANGE ITS PERMISSIONS AND WRITE TO IT 3 TIMES
/////////////////////////////////////////////////////////////////////////////////////
	
	FILE *file2;

	char filenames2[10][10] = {"file_WO_0", "file_WO_1", 
			"file_WO_2", "file_WO_3", "file_WO_4",
			"file_WO_5", "file_WO_6", "file_WO_7", 		
			"file_WO_8", "file_WO_9"};

	for (i = 0; i < 10; i++) 
	{
		//Create file_WO
		file2 = fopen(filenames2[i], "r");		//this should fail

		file2 = fopen(filenames2[i], "w+");

		if (file2 == NULL)
		{
			file2 = fopen(filenames2[i], "w");
		}

		if (file2 != NULL)
		{
			bytes = fwrite(filenames2[i], strlen(filenames2[i]), 1, file2);	
			fclose(file2);
		}
		
		file2 = fopen(filenames2[i], "r");
		
		//Change permissions to write only for this user
		chmod(filenames2[i], S_IWUSR);			

		file2 = fopen(filenames2[i], "r");	//This should fail

	}

//CREATE FILE, CHANGE ITS PERMISSIONS AND READ IT
/////////////////////////////////////////////////////////////////////////////////////

	FILE *file3;

	char filenames3[10][10] = {"file_RO_0", "file_RO_1", 
			"file_RO_2", "file_RO_3", "file_RO_4",
			"file_RO_5", "file_RO_6", "file_RO_7", 		
			"file_RO_8", "file_RO_9"};

	for (i = 0; i < 10; i++) 
	{
		//Create file_RO
		file3 = fopen(filenames3[i], "r");		//this should fail

		file3 = fopen(filenames3[i], "w+");

		if (file3 == NULL)
		{
			file3 = fopen(filenames3[i], "r");
		}

		if (file3 != NULL)
		{
			bytes = fwrite(filenames3[i], strlen(filenames3[i]), 1, file3);
		}

		//Change permissions to read only for this user
		chmod(filenames3[i], S_IRUSR);

		file3 = fopen(filenames3[i], "r");

		if (file3 != NULL)
		{
			bytes = fwrite(filenames3[i], strlen(filenames3[i]), 1, file3);	//This should fail
		}

	}

//CREATE FILE, CHANGE ITS PERMISSIONS AND WRITE TO IT 3 TIMES
/////////////////////////////////////////////////////////////////////////////////////
	
	FILE *file4;

	char filenames4[10][10] = {"file_AO_0", "file_AO_1", 
			"file_AO_2", "file_AO_3", "file_AO_4",
			"file_AO_5", "file_AO_6", "file_AO_7", 		
			"file_AO_8", "file_AO_9"};

	for (i = 0; i < 10; i++) 
	{
		//Create file_WO
		file4 = fopen(filenames4[i], "r");		//this should fail

		file4 = fopen(filenames4[i], "a+");

		if (file4 == NULL)
		{
			file4 = fopen(filenames4[i], "a");
		}

		if (file4 != NULL)
		{
			bytes = fwrite(filenames4[i], strlen(filenames4[i]), 1, file4);	
			fclose(file4);
		}

		file4 = fopen(filenames4[i], "r");
		
		//Change permissions to write only for this user
		chmod(filenames4[i], S_IWUSR);			

		file4 = fopen(filenames4[i], "r");	//This should fail
	}
	

	return 0;
}

