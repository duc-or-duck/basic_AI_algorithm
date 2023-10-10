#include<stdio.h>
#define INPUT "balo.txt"
#define MAX 50//so do toi da

//bien toan cuc
FILE* fp;
int sodovat,Pmax;
int vw[MAX];
int v[MAX];//gia tri cac do vat
int w[MAX];//trong luong do vat
float cs[MAX];
int dem=0;
int vet[MAX];

void inmang(int m[MAX],int size)
{
	for(int i=0; i<size; i++)
	{
		printf("%d ",m[i]);
	}
	
}

void readfile()
{
	fp=fopen(INPUT,"r");
	if(fp==NULL)
	{
		printf("Khong tim thay file");
	}
	else{
		fscanf(fp,"%d",&sodovat);
		fscanf(fp,"%d",&Pmax);
		for(int i=0;i<sodovat*2;i++)
		{
			fscanf(fp,"%d",&vw[i]);		
		}
		//tach vw thanh v va w
		
		for(int i=0;i<sodovat*2;i=i+2)
		{
			if(dem>=sodovat)
			{
				break;	
			}
			w[dem]=vw[i];
			v[dem]=vw[i+1];
			cs[dem]=(float)(v[dem]/w[dem]);
			dem++;
		}
		
		fclose(fp);
	}
	//in ra ca gia tri
	printf("\nSo do vat cho truoc la: %d",sodovat);
	printf("\nTrong luong toi da: %d",Pmax);
	printf("\nGia tri cac do vat:");
	inmang(v,sodovat);
	printf("\nTrong luong cac do vat:");
	inmang(w,sodovat);
	printf("\nv/w: ");
	for(int i=0;i<dem;i++)
	{
		printf("%.1f ",cs[i]);
	}
}

void iswap(int *x,int *y)
{
	int tam=*x;
	*x=*y;
	*y=tam;
}

void fswap(float *x,float *y)
{
	float tam=*x;
	*x=*y;
	*y=tam;
}

void init(int m[MAX],int size,int value)
{
    for(int i=0; i<size-1; i++)
    {
    	m[i]=value;
	}
	
}

void Greedy_CaiTui()
{
	for(int i=0;i<sodovat-1;i++)
	{
		for(int j=i+1;j<sodovat;j++)
		{
			fswap(&cs[i],&cs[j]);
			iswap(&v[i],&v[j]);
			iswap(&w[i],&w[j]);		
		}
	}
	printf("\nGia tri cac do vat sau khi sap xep:");
	inmang(v,sodovat);
	printf("\nTrong luong cac do vat sau khi sap xep:");
	inmang(w,sodovat);
	printf("\nv/w sau khi sap xep: ");
	for(int i=0;i<dem;i++)
	{
		printf("%.1f ",cs[i]);
	}
	
	int bestvalue=0;
	int bestweight=0;
	init(vet,sodovat,0);
	
	for(int i=0; i<sodovat; i++)
	{
		if(Pmax>=w[i])
		{
			Pmax-=w[i];
			bestvalue+=v[i];
			bestweight+=w[i];
			vet[i]=1;
		}
	}
	printf("\nTrong luong toi da co the mang theo: %d",bestweight);
	printf("\nGia tri toi da co the mang theo: %d",bestvalue);
	printf("\nDo vat mang theo: ");
	for(int i=0;i<sodovat;i++)
	{
		if(vet[i]==1)
		{
			printf("%5d %5d",v[i],w[i]);
		}
		printf("\n");
	}
}
int main()
{
	readfile();
	Greedy_CaiTui();
	return 0;
}
