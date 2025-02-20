#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void) {

	int n = 0, count =0, check =0;
	char str[101] = "";

	scanf("%d", &n);

	while (n) {
		scanf("%s", str);


		for (int i = 0; str[i] != '\0'; i++) {

			while (str[i] == str[i + 1]) {
				for (int j = i; str[j] != '\0'; j++) {

					str[j] = str[j + 1];
				}
				//str[i] = str[i + 1];
			}
		}

		//printf("str = %s\n", str);

		for (int i = 0; str[i] != '\0'; i++) {
			for (int j = 0; str[j] != '\0'; j++) {
			
				if (str[i] == str[j] && i != j) {
					check++;
					break;
				}
			}
			if (check) {
				break;
			}
		}

		if (!check) {
			count++;
		}
		else {
			check = 0;
		}
		
		char str[101] = "";
		
		n--;
	}
	printf("%d", count);

	return 0;
}