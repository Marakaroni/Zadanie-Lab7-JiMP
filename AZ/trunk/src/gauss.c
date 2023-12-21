#include "gauss.h"
#include "mat_io.h"
/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */
void swap(Matrix *mat, int co, int czym)
{
	double *wsk=mat->data[co];
	mat->data[co]=mat->data[czym];
	mat->data[czym]=wsk;
}
double absol(double wart)
{
	if(wart>-wart) return wart;
	else return -wart;
}
int eliminate(Matrix *mat, Matrix *b){
		Matrix *jo = createMatrix(mat->r, mat->c+1);
		for(int i=0;i<mat->r;i++) // przepisanie macierzy mat do x
		{
			for(int j=0;j<mat->c;j++)
			{
				jo->data[i][j]=mat->data[i][j];
			}
		}
		for(int i=0;i<mat->r;i++) //przepisanie macierzy b na koniec x
		{
			jo->data[i][mat->c]=b->data[i][0];
		}
		
		for(int k=0;k<jo->c-2;k++)
		{
			double maxx=0;
			int nr=k;
			
			for(int j=k;j<jo->r;j++)
			{
				if(absol(jo->data[j][k])>maxx)
				{
					maxx=absol(jo->data[j][k]);
					nr=j;
				}
			}
			if(maxx==0) return 1;
			
			swap(jo,k,nr);
			for(int i=1+k;i<jo->r;i++) //normalizacja
			{
				
	
				double wsp=jo->data[i][k]/jo->data[k][k];
				
				for(int j=0;j<jo->c;j++)
				{
					jo->data[i][j]=jo->data[i][j]-wsp*jo->data[k][j];
				}
			}
		}
		
		for(int i=0;i<mat->r;i++)
		{
			for(int j=0;j<mat->c;j++)
			{
				mat->data[i][j]=jo->data[i][j];
			}
		}
		
		for(int i=0;i<b->r;i++)
		{
			
			b->data[i][0]=jo->data[i][jo->c-1];
		}
		
		return 0;
}

