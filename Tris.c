#include <stdio.h>
#include <stdlib.h>
#define MAX 3
#define MAX_INPUT 1

int** creaMatrice() {
	int **a;
	int valore, contatore, controllOrizzontale = 0, colonna0 = 0, colonna1 = 0, colonna2 = 0, nPrimo = 1, nSecondo = 2, diagonale = 0;

  	a = (int **)malloc(MAX * sizeof(int *)); //doppio puntatore per la matrice 
  		for (int i = 0; i < MAX; i++) { //for per le righe da creare
    		a[i] = (int *)malloc(MAX * sizeof(int));
   }	
   
  	for (int i = 0; i < MAX; i++) {
    	for (int j = 0; j < MAX; j++) { //for che setta la matrice con le posizioni e i valori da aggiungere
     		while(contatore < MAX*MAX){
     			printf("Inserisci posizione\n");
     				scanf("%d %d", &i, &j);
						printf("Inserisci valore 1 o 2:\n");
     						scanf("%d", &valore);
     				if((i >= MAX || j >= MAX) || (valore != 1 && valore != 2)){
     					 goto errore;
					 }
     					printf("\n");
     					a[i][j] = valore;
     					contatore++;
			 }
    	}
 	}
 	contatore = 0;
 	for (int i = 0; i < MAX; i++)  // for che stampa la tabella di tris(matrice)
	 {
 		printf("\n");
    	for (int j = 0; j < MAX; j++) 
		{
    		printf("%d\t", a[i][j]);
    	}
    		printf("\n");
	}
	
	for (int i = 0; i < MAX; i++) 
	{
    	for (int j = 0; j < MAX; j++) // for che fa controlli per tris orizzontale,verticale,diagonale
		{
			
    		if(nPrimo == a[i][j]){
				controllOrizzontale++;
			}
			if(controllOrizzontale >= 2){
				printf("tris orizzontale");
				goto exit_loops; 
			}
			while(contatore <= 1) {
			colonna0 = a[i][j];
			colonna1 = a[i][j+1];
			colonna2 = a[i][j+2];
				if((colonna0 ==  a[i + 1][j] && colonna0 == a[i + 2][j]) || (colonna1 ==  a[i + 1][j] && colonna1 == a[i + 2][j]) 
				|| (colonna2 ==  a[i + 1][j] && colonna2 == a[i + 2][j])){
					printf("Tris verticale\n");
					goto exit_loops; 
				}
				contatore++;
			}
			contatore = 0;
			while(contatore <= 1){
				diagonale = a[i][j]; 
					if(diagonale == a[i][j+2] && diagonale == a[i+1][j+1] && diagonale == a[i+2][j] && diagonale == a[i+2][j+2]) {
						printf("Tris diagonale\n");
						goto exit_loops; 
					}
					contatore++;
			}
    	}
	}
	
	exit_loops: //metodi che fanno uscire dai loop uno per la fine del gioco e uno per eventuali errori
		if (1) {
  			printf(" Fine Gioco.\n");
  			system("pause");
		}
		return 0;
	
	errore:
		if(1) {
			printf("Errore \n");
			system("pause");
		}
		return 0;
}

int main(void) {
  int** a = creaMatrice();
  for (int i = 0; i < MAX; i++) {
  	free(a[i]);
  }
  free(a);
}
