#include <stdio.h>
#include <stdlib.h>

void teste (int cont){
	static int oi = 100;
	if (cont == 5) return;
	printf("%d\n", oi);
	oi = cont++;
	teste(cont);
}

void main (){
	teste(0);
}