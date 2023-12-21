#include "backsubst.h"
/**
 * Zwraca 0 - wsteczne podstawienie zakonczone sukcesem
 * Zwraca 1 - błąd dzielenia przez 0 (element na diagonali = 0)
 * Zwraca 2 - błąd nieprawidłowych rozmiarów macierzy
 */
int  backsubst(Matrix *x, Matrix *mat, Matrix *b) {
				if(mat->r != mat->c || x->c!=1 || b->c!=1 || x->r!=b->r || x->r!=mat->r) return 2;
				for(int i=0;i<mat->r;i++)
				{
					double sum=0;
					for(int j=0;j<i;j++)
					{
						sum+=mat->data[mat->r-1-i][mat->c-1-j]*x->data[x->r-1-j][0];
					}
					if(mat->data[mat->r-1-i][mat->c-1-i]==0) return 1;
					x->data[x->r-1-i][0]=(b->data[b->r-1-i][0]-sum)/mat->data[mat->r-1-i][mat->c-1-i];
				}
				
				return 0;
}


