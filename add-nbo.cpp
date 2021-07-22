#include <stdint.h>
#include <netinet/in.h>
#include <cstdio>

int main(int arg1, char *arg2[]) {
	if(arg1 != 3) {
		printf("syntax : add-nbo <file1> <file2>\n");
		printf("sample : add-nbo a.bin b.bin\n");
		return -1;
	}

	FILE * file1 = fopen(arg2[1], "rb");
	FILE * file2 = fopen(arg2[2], "rb");

	uint32_t File_1, File_2;

	fread(&File_1, sizeof(uint32_t), 1, file1);
	fread(&File_2, sizeof(uint32_t), 1, file2);

	File_1 = ntohl(File_1);
	File_2 = ntohl(File_2);

	uint32_t result = File_1 + File_2;
	printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", File_1, File_1, File_2, File_2, result, result);

	fclose(file1);
	fclose(file2);
}
