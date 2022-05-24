#include <stdio.h>
#include <stdlib.h>

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++){
		int size;
		scanf("%d", &size);
		int max = 0;
		for (int j = 0; j < size; j++){
			int k;
			scanf("%d", &k);
			if (max == 0) max = k;
			else if (k > max) {
				printf("No");
				return 0;
			}
            max = k;
		}
	}
	puts("Yes");
}