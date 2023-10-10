#include<stdio.h>
#define INPUT "BFS1.txt"
#define MAX 20 // so dinh toi da cua do thi

//khai bao bien
int sodinh; 
int mtk[MAX][MAX];
FILE* fp;

void inmatran(int mt[][MAX], int size)
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

void readfile() 
{
    fp = fopen(INPUT,"r");
    if(fp==NULL)
    {
        printf("FILE NOT FOUND!\n");
    }
    else 
    {
        //doc so dinh cua do thi
        fscanf(fp,"%d",&sodinh);
        printf("So dinh cua do thi: %d",sodinh);
        //doc mtk cua ma tran 
        for (int i=0; i<sodinh; i++)
        {
            for(int j=0; j<sodinh; j++)
            {
                fscanf(fp,"%d",&mtk[i][j]);
            }
        }
        //in ra ma tran ke cua do thi
        printf("\nMTK:\n");
        inmatran(mtk,sodinh);
        fclose(fp);
    }
}

void init(int mang[], int size, int value)//khoi tao gia tri cho mang
{
    for(int i = 0; i < size; i++)
    {
        mang[i] = value;
    }
}

void inmang(int mang[], int size)
{
    for(int i = 0; i < size; i++) {
        printf("%d ",mang[i]);
    }
}
void BreathFirstSearch(int start,int goal)
{
    int OPEN[MAX];//tap cac dinh can duyet
    int CLOSE[MAX];//tap cac dinh da xet
    int n;//Dinh dang xet
    int dem=0;//so luong dinh con lai trong
    int Tn[MAX];//tap cac dinh tiem nang (ke voi dinh dang xet) => co the dua vao OPEN
    int CHA[MAX];
    OPEN[dem]=start;
    //thay vì duyệt đỉnh => cho các đỉnh bằng 0, khi nào lấy đỉnh xét rồi cho bằng -1. 
    init(CLOSE,sodinh,0);//CLOSE[0, 0, 0, 0, 0, 0]
    init(Tn,sodinh,0);
    init(CHA,sodinh,-1);
    while(dem >= 0)//đếm bằng 0 có nghĩa là còn 1 ptu
    {
      n=OPEN[0]; //luôn luôn lấy phần tử ở đầu danh sách OPEN => Đồng nghĩa việc phải xóa ptu đó đi. 
      //xoa phan tu. 
      CLOSE[n]=-1; // gan dinh da xet bang -1
      printf("Dinh dang xet: %d", n);
      for(int i = 0; i < dem; i++)
      {
        //dem = số lượng phần tử của ds OPEN
        OPEN[i] = OPEN[i+1];
      }
      if(n == goal)
      {
        printf("\nTim thay dương di tu %d den %d", start, goal);
        //in ra lo trinh di tu start den goal 
        int duongdi[MAX]; 
        int len=0;//So phan tu cua duongdi[]
        //Luu cha cua cac dinh vao duong di
        for(int i = goal; i!=-1; i=CHA[i])
        {
            duongdi[len++]=i;
        }
        printf("\nduongdi: "); 
        inmang(duongdi, len);
        printf("\nLo trinh tu start = %d den goal = %d: ", start,goal);
        for(int i = len-1; i>=0; i--)
        {
            printf("%d -> ", duongdi[i]);
        }
        return;
      }
      else 
      {
        //đưa các đỉnh lân cận của n vào cuối danh sách OPEN
        for(int j = 0; j < sodinh; j++)
        {
            //Đỉnh chưa từng được xét mới đc cho vào dsach
            if(mtk[n][j]==1 && CLOSE[j]!=-1 && Tn[j]!=-1)
            {
                OPEN[dem++] = j;//j = dinh ke cua n
                Tn[j]=-1;//dinh da duoc dua vao OPEN
                CHA[j]=n;//Cha cua dinh tiem nang = n
            }
        }
      }
      printf("\nOPEN: ");
      inmang(OPEN,dem);
      printf("\nCLOSE: ");
      inmang(CLOSE,sodinh);
      printf("\nTn: "); 
      inmang(Tn, sodinh);
      printf("\nCHA: ");
      inmang(CHA,sodinh);
      dem--; 
    }
}

//DFS
void DFSearch(int start,int goal){
	int open[MAX];//tap cac dinh can duyet
	int close[MAX];//tap cac dinh da xet
	int n;//dinh dang xet
	int dem=0;//so luong dinh con lai trong open
	int Tn[MAX];//ke voi dinh dang xet
	int cha[MAX];//cha cua dinh dang xet
	
	open[dem++]=start;
	init(close,sodinh,0);
	init(Tn,sodinh,0);
	init(cha,sodinh,-1);//cha[]
	
	while(dem>=0){
		n=open[--dem];//luon lay dau phan tu danh sach open
		close[n]=-1;
		printf("\nDinh danh xet: %d",n);
		dem--;
		if(n==goal)
		{
			printf("\nTim thay duong di tu %d den %d",start,goal);
			//in ra lo trinh duong di tu start den goal
			int duongdi[MAX];
			int len=0;//so phan tu cua duongdi
			//luu cha cua cac dinh
			for(int i=goal; i!=-1;i=cha[i]){
				duongdi[len++]=i;
			}
			printf("\nduongdi:");
			inmang(duongdi,len);
			printf("lo trinh tu start= %d den goal= %d: ",start,goal);
			for(int i=len-1;i>=0;i--)
			{
				printf("%d ->",duongdi[i]);
			}
			return;
		}
		else{
			for(int j=0;j<sodinh;j++)
			{
				if(mtk[n][j]==1&&close[j]!=-1&&Tn[j]!=-1){
					
					open[dem++]=j;//j la dinh ke cua n;						
					Tn[j]=-1;
					cha[j]=n;
				}
			
			}
		}
		
		printf("\nopen: ");
		inmang(open, dem);
		printf("\nclose: ");
		inmang(close, sodinh);
		printf("\nTn: ");
		inmang(Tn, sodinh);
		printf("\nCha:");
		inmang(cha, sodinh);

	}
}

int main()
{
    readfile(); 
    DFSearch(0,5);
    return 0;
}