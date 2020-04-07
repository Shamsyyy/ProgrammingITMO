#include <stdio.h>
#include <string.h>
#define MAX_FILES 100
void Extract(char* nameoffile) {
  /*  ������ ������ ������: < a.txt : 10 >< b.bin : 10 >< c.bmp : 567656 >
     ������ ���� ����� �������� 10, 10, 567656  */
  FILE* fp = fopen(nameoffile, "rb+");
  FILE* newfile;
  char filenames[MAX_FILES][128]; // �������� ������ � ������
  unsigned long long int filesizes[MAX_FILES]; // ������� ������ � ������
  int count = 0; // ���������� ������ � ������
  while (fscanf(fp, "|  %s  -  %llu  |", filenames[count], &filesizes[count]) != 0) {
    count++;
  }
  int symbol;
  unsigned long long int sizefile;
  char filename[128];
  for (int i = 0; i < count; i++) {
    sizefile = filesizes[i]; // ������ i-��� �����
    strcpy(filename, filenames[i]); // �������� i-��� �����
    newfile = fopen(filename, "wb"); // ������� i-�� ����
    while (sizefile-- > 0) { // ���� � ������ �������� ����� i-��� �����
      putc((symbol = getc(fp)), newfile); // ������ �� � ����� � ����� ����
    }
    fclose(newfile);
  }
  printf("\tEXTRACT DONE\n");
}

void List(char* nameoffile) {
	FILE* fp = fopen(nameoffile, "rb");
	char filen[256]; // ����� ������
	unsigned long long int  sizefile;
	printf("FILE IN ARCHIVE:\n");
	while (fscanf(fp, "|  %s  -  %llu  |", filen, &sizefile) != 0) {
		printf("\t%s\n", filen);
	}
	fclose(fp);
}

void Create(char* nameoffile, int argc, char* argv[]) {
	char tmp;
	FILE* fp = fopen(nameoffile, "wb");
	FILE* fl; // ���� �����
	unsigned long long int file_size[128]; // ���-�� ���� � �����
	for (int i = 4; i < argc; i++) {
  	fl = fopen(argv[i], "rb");
		if (fl == NULL)
			continue;
		fseek(fl, 0, SEEK_END); //������ ��������� �� ����� �����
		file_size[i - 4] = ftell(fl); //����� � ��������� � ����� ������ �����
		fseek(fl, 0, SEEK_SET); //������������ � ������ �����
    //fprintf(fp, "< %s : %llu >", argv[i], file_size[i-4]);
		fclose(fl);
	}
	for (int i = 0; i < argc - 4; i++)
		fprintf(fp, "|  %s  -  %llu  |", argv[i + 4], file_size[i]);
	for (int i = 4; i < argc; i++) {
		fl = fopen(argv[i], "rb");
		if (fl == NULL) {
			printf("FILE %s NO FOUND\n", argv[i]);
			continue;
		}
		else {
			printf("FILE %s ADD\n", argv[i]);
		}
		while ((tmp = getc(fl)) != EOF)
			putc(tmp, fp);
		fclose(fl);
	}
	printf("\tARCHIVING DONE\n");
}

int main(int argc, char* argv[]) {
	FILE* fp;
	char* nameoffile;
  // ���������� �� ���� ���������� � ������ ��������������� �������
	for (int i = 0; i < argc; i++) {
		if (!strcmp("--file", argv[i])) {
			nameoffile = argv[i + 1];
		}
		if (!strcmp("--create", argv[i])) {
			Create(nameoffile, argc, argv);
			break;
		}
		if (!strcmp("--extract", argv[i])) {
			Extract(nameoffile);
		}
		if (!strcmp("--list", argv[i])) {
			List(nameoffile);
		}
	}
	return 0;
}

