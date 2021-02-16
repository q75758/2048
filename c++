#include <iostream>
#include <conio.h>
#include <time.h>
#include <iomanip>
#include <string>
#include <stdlib.h>
#include <locale.h>
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_X 120
using namespace std;
int kutular[4][4] = {
{0 , 0 , 0 , 0} ,
{0 , 0 , 0 , 0} ,
{0 , 0 , 0, 0} ,
{0 , 0 , 0 , 0}
};
void kutulari_goster(void)
{
	system("cls");
	for(int i = 0 ; i < 4 ; i++)
 	{
 		cout << "\n";
 		for(int j = 0 ; j < 4 ; j++)
 		{
 			if (kutular[i][j] == 0)
 			{
 				cout << setw(6) << " ";
			}
			else
			{
				cout << setw(6) << kutular[i][j];
			}
 		}
 	}
}
void kutulari_yukari_kaydir(void)
{
	int k = 0;
	int yeni_sutun[4] = {0};
	for(int sutun = 0 ; sutun < 4 ; sutun++)
	{
	k = 0;
	for(int satir = 0 ; satir < 4 ; satir++)
 	{
 		if (kutular[satir][sutun] != 0)
		{
			yeni_sutun[k] = kutular[satir][sutun];
			k++;
		}
	}
	for(int satir = 0 ; satir < 4 ; satir++)
	{
		kutular[satir][sutun] = yeni_sutun[satir];
 		yeni_sutun[satir] = 0;
	}
 	}
}
void kutulari_yukari_topla(void)
{
	for(int f = 0 ; f < 4 ; f++)
 	{
 		for(int t = 0 ; t < 4 ; t++)
 		{
 			if (kutular[f][t] == kutular[f+1][t])
			{
				kutular[f][t] = kutular[f][t]*2;
				kutular[f+1][t] = 0;
			}
		}
	}	
}
void kutulari_asagi_kaydir(void)
{
	int t = 3;
	int yeni_satir[4] = {0};
	for(int b = 0 ; b < 4 ; b++)
 	{
 		t = 3;
 		for(int a = 3 ; a >= 0 ; a--)
 		{
 			if (kutular[a][b] != 0)
			{
				yeni_satir[t] = kutular[a][b];
				t--;
			}
		}
		for(int a = 0 ; a < 4 ; a++)
 		{
 			kutular[a][b] = yeni_satir[a];
 			yeni_satir[a] = 0;
		}
   }
}
void kutulari_asagi_topla (void)
{
	for (int q = 0 ; q < 4 ; q++)
	{
		for (int w = 4 ; w >= 0 ; w--)
		{
			if (kutular[q][w] == kutular[q+1][w])
			{
				kutular[q][w] = kutular[q][w]*2;
				kutular[q+1][w] = 0;
			}
		}
	}
}
void kutulari_saga_kaydir (void)
{
	int v = 0;
	int yeni_satir[4] = {0};
	for (int z = 0 ; z < 4 ; z++)
	{
		v = 0;
		for (int x = 0; x < 4 ; x++)
		{
			if (kutular[z][x] == 0)
			{
				yeni_satir[v] = kutular[z][x];
				v++;
			}
		}
		for (int x = 0; x < 4 ; x++)
		{
			if (kutular[z][x] != 0)
			{
				yeni_satir[v] = kutular[z][x];
				v++;
			}
		}
		for (int x = 0 ; x < 4 ; x++)
		{
			kutular[z][x] = yeni_satir[x];
			yeni_satir[x] = 0;
		}
	}
}
void kutulari_saga_topla (void)
{
	for (int m = 0 ; m < 4 ; m++)
	{
		for (int n = 3 ; n >= 0 ; n--)
		{
			if (kutular [m][n-1] == kutular[m][n])
			{
				kutular[m][n] = kutular[m][n-1]*2;
				kutular[m][n-1] = 0;
			}
		}
	}
}
void kutulari_sola_kaydir (void)
{
	int h = 0;
	int yeni_satir[4] = {0};
	for (int o = 0 ; o < 4 ; o++)
	{
		h = 0;
		for (int p = 0; p < 4 ; p++)
		{	
			if (kutular[o][p] != 0)
			{
				yeni_satir[h] = kutular[o][p];
				h++;
			}
		}
		for (int p = 0; p < 4 ; p++)
		{
			if (kutular[o][p] == 0)
			{
				yeni_satir[h] = kutular[o][p];
				h++;
			}
		}
		for (int p = 0 ; p < 4 ; p++)
		{
			kutular[o][p] = yeni_satir[p];
			yeni_satir[p] = 0;
		}
	}
}
void kutulari_sola_topla (void)
{
	for (int o = 0 ; o < 4 ; o++)
	{
		for (int p = 0 ; p < 4 ; p++)
		{
			if (kutular [o][p-1] == kutular[o][p])
			{
				kutular[o][p] = kutular[o][p-1]*2;
				kutular[o][p-1] = 0;
			}
		}
	}
}
void rastgele_sayi_olustur (void)
{
	int dizi[4] = {0};
	int x , y;
	int random;
	srand(time(NULL));
	random = rand() % 2 + 1;
	random *= 2;
	while(true)
	{
		x = rand() %4;
		y = rand() %4;
 		if (kutular[x][y] == 0)
 		{
 			kutular[x][y] = random;
 			break;
		}
	}
}
void skor_hesapla(void)
{
	int skor = 0;
}
int main()
{
	setlocale(LC_ALL, "Turkish");
	int c;
	int i, j;
	char key;
	kutulari_goster();
	int value = key;
    while (value != KEY_X)
	{	
		key = getch();
		switch(getch())
		{
			case KEY_UP:
 			{
				kutulari_yukari_kaydir();
				kutulari_yukari_topla();
				kutulari_yukari_kaydir();
				rastgele_sayi_olustur();
				kutulari_goster();
				break;
			}
			case KEY_DOWN:
			{
				kutulari_asagi_kaydir();
				kutulari_asagi_topla();
				kutulari_asagi_kaydir();
				rastgele_sayi_olustur();
				kutulari_goster();
				break;
			}
			case KEY_RIGHT:
			{
				kutulari_saga_kaydir();
				kutulari_saga_topla();
				kutulari_saga_kaydir();
				rastgele_sayi_olustur();
				kutulari_goster();
				break;
			}
			case KEY_LEFT:
			{
				kutulari_sola_kaydir();
				kutulari_sola_topla();
				kutulari_sola_kaydir();
				rastgele_sayi_olustur();
				kutulari_goster();
			break;
			}
			key = getch();
			value = key;
		}
 		for (int k = 0 ; k < 4 ; k++)
		{
			for (int l = 0 ; l < 4 ; l++)
			{
				if(kutular[k][l] == 2048)
				{
					cout << "\nTebrikler oyunu kazandın !\n";
					value = KEY_X;
				}
			}
		}
}
return 0;
}
