#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
	FILE *misc;
	if(argc == 3) {
		misc = fopen(argv[1], "r+b");
	} else {
		goto quit;
	}
	
	if(NULL == misc) {
		printf("File could not be opened.\n");
		return 1;
	}
	
	if(fseek(misc, 224L, SEEK_SET) != 0) {
		printf("Could not find offset in file.\n");
		fclose(misc);
		return 1;
	}
	
	if(argc == 3 && strcmp(argv[2], "unlock") == 0) {
		fwrite("HTCU", 4, 1, misc);
	} else if(argc == 3 && strcmp(argv[2], "relock") == 0) {
		fwrite("HTCL", 4, 1, misc);
	} else if(argc == 3 && strcmp(argv[2], "lock") == 0) {
		fwrite("\0\0\0\0", 4, 1, misc);
	} else if(argc == 3 && strcmp(argv[2], "superversion") == 0) {
		if(fseek(misc, 160L, SEEK_SET) != 0) {
			printf("Could not find offset in file.\n");
			fclose(misc);
			return 1;
		}
		fwrite("0.0.0.0\0\0\0\0\0\0\0\0\0", 16, 1, misc);
	} else {
		fclose(misc);
		quit:
		printf("usage:\bltool <file> <option>\nOptions: unlock|relock|lock|superversion\n");
		return 1;
	}
	
	fflush(misc);
	fclose(misc);
	return 0;
}
