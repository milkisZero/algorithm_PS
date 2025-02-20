
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {

	char str[1000001]="";
	int check[30] = {0};
	int max = 0, n= -1;

	scanf("%s", str);

	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] < 'A' || str[i] > 'Z') {

			str[i] = str[i] + ('A' - 'a');
		}
		
		check[str[i] - 65]++;
		
	}

	for (int i = 0; i < 30; i++) {
		if (check[i] > check[max]) {
			max = i;
		}
		else if (check[i] == check[max] && max != i) {
			n = check[i];
		}
	}

	if (check[max] == n) {
		printf("?");
	}
	else {
		printf("%c", 65 + max);
	}

	return 0;
}