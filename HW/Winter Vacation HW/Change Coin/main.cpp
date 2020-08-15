#include <stdio.h>
#define MAXNV 5
int values[MAXNV];
int numbers[MAXNV];

void show(int nv);
void change(int amount, int smallest, int nv);

int main(void)
{
	int nv, i;
	int money;

	scanf("%d", &nv);
	if (nv>MAXNV || nv<1) return 0;

	for (i=0; i<nv; i++) {
		scanf("%d", &values[i]);
	}

    for(i=0; i<nv; i++){
        numbers[i] = 0;
    }

	scanf("%d", &money);
	change(money, 0, nv);

	return 0;
}

void show(int nv)
{
	int i;
	printf("(%d", numbers[0]);
	for (i=1; i<nv; i++) {
		printf(",%d", numbers[i]);
	}
	printf(")\n");
}

void change(int amount, int smallest, int nv)
{
	if (smallest<nv) {
		if (amount == 0) {
			show(nv);
		} else if (amount > 0) {
		    //first way to change coin
			change(amount, smallest+1, nv);

			//second way to change coin
            numbers[smallest]++;
            change(amount-values[smallest], smallest, nv);
            numbers[smallest]--;
		}
	}
}
