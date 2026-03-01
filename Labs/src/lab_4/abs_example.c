#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int *data = (int*)malloc(5 * sizeof(int));
    if (!data) return 1;

	for(int i = 0; i < 5; i++) data[i] = i;

    int *temp = (int*)realloc(data, 10 * sizeof(int));
    if (temp != NULL) {
        data = temp;
        for(int i = 5; i < 10; i++) data[i] = i;
    } else {
        free(data);
        return 1;
    }

    for(int i = 0; i < 10; i++) printf("%d ", data[i]);
    
    free(data); 
    return 0;
}
