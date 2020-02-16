#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// when `monarch` is used as type, it is referring to the structure monarch
typedef struct monarch monarch;

// the structure monarch is defined as follows
struct monarch{
	char name[100];
	int number, birth, reign;
};

// declaration of the functions used
monarch ** getmonarchs(int);
monarch * get_monarch();
char* roman(int);
void free_monarchs(monarch **, int);

int main(){
    monarch ** monarchs;
	int num_monarchs;
	scanf("%d\n", &num_monarchs);
	monarchs = getmonarchs(num_monarchs);
	for(int i=0; i<num_monarchs; i++){
		printf("%s %s, born %d, rule began in %d.\n", monarchs[i]->name, roman(monarchs[i]->number), monarchs[i]->birth, monarchs[i]->reign);
	}
	free_monarchs(monarchs, num_monarchs);
	return(0);
}

monarch **getmonarchs(int num_monarchs){
    /*
        this function reads num_monarchs lines,
        each line representing information about a monarch.
        From the obtained information, the function creates
        and fills up an array of variables of type monarch
        then returns a monarch **
    */

	// Write your code here
    monarch **monarchs = malloc(sizeof(monarch *) * num_monarchs);
    for (int i = 0; i < num_monarchs; i++) {
        monarchs[i] = get_monarch();
    }

    return monarchs;
}

monarch *get_monarch() {
    /*
        scans input and returns a monarch *
    */
    monarch *m = malloc(sizeof(monarch));
    scanf(" %s %d %d %d", m->name, &(m->number), &(m->birth), &(m->reign));
    return m;
}

char *roman(int num){
    /*
        converts num to its corresponding Roman numeral
        equivalent and returns a char *
    */

	// Write your code here
    char *sym[] = {"X", "IX", "V", "IV", "I"};
    int i = 0, val[] = {10, 9, 5, 4, 1};

    char arr[10];
    memset(arr, '\0', sizeof(char) * 10);
    while(num > 0)
    {
        int sig = num/val[i];
        num %= val[i];
        while(sig--)
        {
            strcat(arr, sym[i]);
        }
        i++;
    }

    /*
        causes memory leak
    */
    char *rom = malloc(sizeof(char) * strlen(arr) + 1);
    memset(rom, '\0', strlen(arr) + 1);
    strcpy(rom, arr);

    return rom;
}

void free_monarchs(monarch **monarchs, int num_monarchs){
	for(int i=0; i<num_monarchs; i++){
		free(monarchs[i]);
	}
	free(monarchs);
}