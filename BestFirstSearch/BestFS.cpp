#include<stdio.h>
#define MTK "BestFS.txt"
#define H "BestFSh.txt"
#define MAX 100


//khai báo biến
FILE *fp; 
int sodinh; 
int mtk[MAX][MAX]; 
int h[MAX];

void inmang(int m[], int size)
{
    for(int i = 0; i < size; i++)
    {
        printf("%d ", m[i]); 
    }
}
void inmatran(int mt[MAX][MAX], int size){
    for(int i=0;i<size;i++){
        for(int j=0; j<size; j++){
            printf("%d  ",mt[i][j]);
        }
        printf("\n");
    }
}

void init(int m[], int size, int value){
    for(int i=0; i<size; i++){
        m[i]=value;
    }
}

void readfile_mtk() 
{
    fp = fopen(MTK, "r"); 
    if(fp == NULL)
    {
        printf("File MTK not found"); 
        return; 
    }
    else{
        //doc dong dau tien
        fscanf(fp, "%d", &sodinh);
        //doc cac gia tri cua ma tran ke
        for(int i=0; i<sodinh; i++){
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

void swap(int *x, int *y){
    int tam = *x;
    *x = *y;
    *y = tam;
}

void BestFirstSearch(int start, int goal){
    int n;
    int OPEN[MAX];
    int OPENED[MAX];
    int CLOSE[MAX];//[0 1 2 3 4 5 6 7 8 9]
    int CHA[MAX];
    //khoi tao cho OPENED va CLOSE
    for(int i=0; i<sodinh; i++){
        CLOSE[i]=i;
        OPENED[i]=i;
    }
    int Tn[MAX];
    init(CHA, sodinh,-1); 
    int dem=0;//kiem tra so luong con lai trong OPEN
    OPEN[dem++]=start;//dem=1

    while(dem>=0){
        //lan lap dau tioen
        n=OPEN[--dem];//dem=0 -> n=start
        CLOSE[n]=-1;
        OPENED[n]=-1;
        printf("\nDinh dang xet: %d", n);
        if(n==goal){
            printf("\nTim thay duong di tu %d den %d", start, goal);
            //in ra duong di tu start den goal
            printf("\nCHA[]: "); inmang(CHA, sodinh);
            int duongdi[MAX]; 
            int len = 0; 
            for(int i = goal; i!=-1; i=CHA[i])
            {// xuat phat tu goal tro ve dau
                duongdi[len++]=i;
            }
            printf("\nDuong di[]: "); 
            for(int i = len-1; i>=0; i--)
            {
                printf("%d -> ", duongdi[i]);
            }
            return;
        }
        else{
            //tim cac dinh ke cua n
            for(int i=0; i<sodinh; i++){
                if(mtk[n][i]==1 && OPENED[i]!=-1 && CLOSE[i]!=-1){
                    OPEN[dem++]=i;//dem=0
                    OPENED[i]=-1;
                    CHA[i] = n;
                }
            }
            //in ra gia tri mang OPEN, CLOSE, OPENED
            printf("\nOPENED[]: " );inmang(OPENED,sodinh);
            printf("\nCLOSE[]: " );inmang(CLOSE,sodinh);
            printf("\nOPEN truoc SX[]: " );inmang(OPEN,dem);
            //tim h min cua OPEN[] == sap xep OPEN theo tt giam
            for(int i=0; i<dem-1;i++){
                for(int j=i+1; j<dem; j++){
                    if(h[OPEN[i]]<h[OPEN[j]]){
                        swap(&OPEN[i],&OPEN[j]);

                    }
                }
            }
        }
        printf("\nOPEN sau SX[]: " );inmang(OPEN,dem);
    }
    //thoat khoi while => khong co duong di 
    printf("Khong tim thay duong di tu %d den %d", start, goal);
}

int main(){
    readfile_mtk();
    printf("\n");
    readfile_h();
    BestFirstSearch(0,6);
    return 0;
}