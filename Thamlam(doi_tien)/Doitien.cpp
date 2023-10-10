#include<stdio.h>
#define INPUT "Doitien.txt"
#define MAX 50

//bien toan cuc
FILE* fp;
int sotien,soto;
int money[MAX];

void docmang(int m[MAX],int size)
{
	for(int i=0; i<size; i++)
	{
		fscanf(fp,"%d ",&m[i]);
	}
	
}

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
		return;
	}
	else
	{
		fscanf(fp,"%d",&sotien);
		fscanf(fp,"%d",&soto);
		docmang(money,soto);
		fclose(fp);
	}
	printf("\nSo tien can doi: %d",sotien);
	printf("\nSo to tien: %d",soto);
	printf("\nMenh gia cac to tien: ");
	inmang(money,soto);
}

void swap(int *x,int *y)
{
	int tam=*x;
	*x=*y;
	*y=tam;
}

void sapxepgiam(int m[],int size)
{
	for(int i=0; i<size-1; i++)
	{
		for(int j=i+1; j<size; j++)
		{
			if(m[i]<m[j])
			{
				swap(&m[i],&m[j]);
			}
		}
	}
}

void init(int m[MAX],int size,int value)
{
    for(int i=0; i<size-1; i++)
    {
    	m[i]=value;
	}
	
}

void Greedy_DoiTien()
{
	int vet[MAX];//dung mang vet de luu tru so to tien da doi
	init(vet,soto,0);
	sapxepgiam(money,soto);
	printf("\nMenh gia cac to tien sau khi sap xep giam dan: ");
	inmang(money,soto);
	for(int i=0; i<soto; i++)
	{
		if(sotien>=money[i])
		{
			sotien-=money[i];
			printf("\nSo tien con lai: %d",sotien);
			vet[i]=1;
		}
	}
	if(sotien>0)
	{
		printf("\nKhong doi duoc tien");
		return;
	}
	else{
		printf("\nVet: ");
		inmang(vet,soto);
		printf("\nCac to tien doi duoc: ");
		for(int i=0; i<soto; i++)
		{
			if(vet[i]==1)
				printf("%d ",money[i]);		
		}
	}
}

int main()
{
	readfile();
	Greedy_DoiTien();
	return 0;
}