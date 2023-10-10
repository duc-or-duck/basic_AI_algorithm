#include<stdio.h>
#define MTK "Greedy_leodoi_mtk.txt"
#define H "Greedy_leodoi.h"
#define MAX 100

FILE *fp; 
int sodinh; 
int mtk[MAX][MAX]; 
int h[MAX];

void inmatran(int mt[MAX][MAX], int size)
{
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            printf("%d ", mt[i][j]);
        }
        printf("\n");
    }
}

void inmang(int m[], int size)
{
    for(int i = 0; i < size; i++)
    {
        printf("%d ", m[i]); 
    }
}
void readfile_mtk() 
{
    fp = fopen(MTK, "r"); 
    if(fp == NULL)
    {
        printf("Couldn't open"); 
        return; 
    }
    else{
        //doc dong dau tien
        fscanf(fp, "%d", &sodinh);
        //doc cac gia tri cua ma tran ke
        for(int i=0; i<sodinh; i++)
        {
            for(int j=0; j<sodinh; j++)
             {fscanf(fp, "%d",&mtk[i][j]);}
        }
        fclose(fp);
    }
    //in ra cac gia tri 
    printf("%d\n",sodinh);
    inmatran(mtk,sodinh);
}

void readfile_h() 
{
    fp = fopen(H, "r"); 
    if(fp == NULL)
    {
        printf("Couldn't open"); 
        return; 
    }
    else{
        //doc dong dau tien
        fscanf(fp, "%d", &sodinh);
        //doc cac gia tri cua ma tran ke
        for(int i=0; i<sodinh; i++)
        {
         fscanf(fp, "%d",&h[i]);
        }
        fclose(fp);
    }
    //in ra cac gia tri
    printf("%d\n",sodinh);
    inmang(h, sodinh); 
}

void init1(int m[], int size, int value)
{
  for(int i=0; i<size; i++)
  {
    m[i] = value; 
  }
}

void init2(int m[], int size)
{
  for(int i = 0; i < size; i++)
  {
    m[i] = i; 
  }
}

void swap(int &x, int &y){
    int tmp = x;
    x = y;
    y = tmp;
}

void Leodoi(int start, int goal) 
{
    int OPEN[MAX];//tap cac dinh cho xet
    int CLOSE[MAX];//tap cac dinh da xet
    int OPENED[MAX];//tap cac dinh da dua vao OPEN
    int PARENT[MAX];//nếu đinh i có cha đc xét thì gán # 0 

    int n; //dinh dang xet
    int dem = 0;//so luong dinh da duoc dua vao OPEN
    
    //khoi tao cac gia tri
    init2(CLOSE,sodinh); 
    init2(OPENED,sodinh);
    init1(PARENT,sodinh,-1);
    OPEN[dem++]=start; // dua start vao open de xet lan dau tien, 
    //OPEN[0] = start va dem = 1
    //duyet cac dinh
    while (dem >= 0)
    {//OPEN van con phan tu de xet, OPEN < 0 la het phan tu
        n=OPEN[--dem];//dem = dem-1=0, n=OPEN[0]=start
        printf("\nDinh dang xet: %d", n); 
        CLOSE[n]=-1;//dinh thu n da duoc duyet
        printf("\nCLOSE[]: "); inmang(CLOSE,sodinh);
        OPENED[n]=-1;
        printf("\nOPENED[]: "); inmang(OPENED,sodinh);
        if(n==goal)
        {
            printf("\nTim thay duong di tu %d den %d", start, goal);
            printf("\nPARENT[]: "); inmang(PARENT,sodinh);
            //duyen cac phan tu trong Parent tu vi tri cua cac goal
            int PATH[MAX]; 
            int dem_path = 0; 
            for(int i = goal; i!=-1; i=PARENT[i])
            {
              PATH[dem_path++] = i;
            }
            //in ra day PATH 
            printf("\nPATH[]: "); 
            for(int i = dem_path-1; i>=0; i--)
            {
                printf("%d -> ", PATH[i]);
            }
            return;
        }
        else 
        {
            int mang_tam[MAX];//chua cac dinh ke voi n dang xet.  
            int dem_tam = 0;//so Luong cac dinh ke voi n dang xet. reset sau moi lan thay doi n
            //xet cac dinh ke cua n
            for(int i = 0; i<sodinh; i++)
            {
                if(mtk[n][i]==1 && CLOSE[i]!=-1 && OPENED[i]!=-1)
                {//n ke voi i, dinh i chua tung duyet, i chua tung dua vao OPEN
                   mang_tam[dem_tam++] = i;
                   OPENED[i]=-1;//cac dinh se duoc dua vao OPEN
                   PARENT[i]=n;                }
            }
            //sap xep mang_tam tang dan theo luong gia h: phan tu min = nam cuoi cung
        for(int i = 0; i < dem_tam-1; i++)
        {
             for(int j = i+1; j < dem_tam; j++)
            {
              if(h[mang_tam[i]]<h[mang_tam[j]])
               {
               swap(mang_tam[i], mang_tam[j]);
               }
            }
        }
        //chen cac dinh cua mang_tam vao cuoi OPEN 
        for(int i = 0; i < dem_tam; i++)
        {
            OPEN[dem++] = mang_tam[i];// vi n = OPEN[dem--], sau lenh nay thi dem = 0; 
        } 
        //in ra cac dinh cua OPEN
        printf("\nOPEN[]: "); inmang(OPEN, dem);
    }
}
//het while thi dem < 0 
printf("\nKhong tim thay duong di tu %d den %d",start,goal);
    
}

int main()
{
    readfile_mtk(); 
    printf("\n----------------------------\n");
    readfile_h(); 
    printf("\n----------------------------\n");
    Leodoi(0,13);

}

