
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[]) {


	if (argc != 4) {
		printf("wrong argument count\n");
		return 0;
	}
	freopen(argv[3], "w", stdout);
	int a = 0 , b = 0;
	a = atoi(argv[1]);
	b = atoi(argv[2]);
	printf("%d\n %s", a + b, argv[3]);
	return 0;
}
