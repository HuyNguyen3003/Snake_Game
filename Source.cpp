#define _CRT_SECURE_NO_WARNINGS
#include "mylib.h"
/// /////////////////////////////////////////////////////
FILE* f; FILE* d;
int tdx[100] = { 0 }, tdy[100] = { 0 };
int sl = 4;
int speed = 150;
int xq = -1, yq = -1;
int ag;
char name[30];
int cl1 = -1; int cl2 = -1;
///////////////
void gifile();
void intro();
void edit();
void in4();
void vetuong();
void play();
void ktran();
void veran();
void dcran(int x, int y);
bool kttuong();
void ktqua();
void vequa();
void rananqua();
void vetuong1();
bool kttuong1();
void endgame();

//
int main() {
	//srand(time(NULL));
	ShowCur(0);
	do
	{
		intro();
		edit();
		play();
		endgame();
		gifile();
		system("cls");
		
	} while (ag);
	textcolor(0);
}
void intro() {

	int i = 2, u = 10; int z = 0;
	while (true)
	{
		vetuong();
		textcolor(u); gotoXY(49, 5);  printf("--------------");
		textcolor(u); gotoXY(49, 7);  printf("--------------");
		textcolor(u); gotoXY(49, 6);  printf("|");
		textcolor(u); gotoXY(62, 6);  printf("|");
		textcolor(i-1); gotoXY(50, 6);  printf("Game con ran");
		textcolor(2); gotoXY(88, 20); printf("CODE BY: ");
		textcolor(2); gotoXY(97, 20); printf("6251071040");
		textcolor(6); gotoXY(97, 21); printf("6251071105");
		textcolor(4); gotoXY(97, 22); printf("6251071038");
		textcolor(5); gotoXY(97, 23); printf("6251Abcxyz");
		i++; if (i == 10) i = 2;  u--; if (u == 2) u = 10; z++; Sleep(11);
		textcolor(7); gotoXY(30, 10); printf("loading %d ",z);
		if (z == 100) break;
	}
	in4();
	system("cls");
}
void in4() {
	textcolor(7); gotoXY(30, 12); printf("Nhap ten: "); fgets(name, sizeof(name), stdin);
}
void vetuong(){
	textcolor(cl2);
	for (int x = 6; x < 110; x++)
	{
		gotoXY(x, 2); printf("_");
		gotoXY(x, 25); printf("_");
	}
	for (int y = 3; y < 26; y++)
	{
		gotoXY(5, y); printf("|");
		gotoXY(110, y); printf("|");
	}
}
void play() {
	vetuong();
	vetuong1();
	ktran();
	int check = 2;
	int x = tdx[0], y = tdy[0];
	ktqua();
	vequa();
	while (true)
	{
		gotoXY(tdx[sl], tdy[sl]); printf(" ");
		veran();
		textcolor(15); gotoXY(50, 1); printf("Diem: %d", sl - 4);
		if (_kbhit())
		{
			char c = _getch();
			if (c == -32)
			{
				c = _getch();
				if (c == 80 && check != 0)
				{
					check = 1;
				}
				else if (c == 72 && check != 1)
				{
					check = 0;
				}
				else if (c == 75 && check != 2)
				{
					check = 3;
				}
				else if (c == 77 && check != 3)
				{
					check = 2;
				}
			}
		}

		if (check == 1)
		{
			y++;
		}
		else if (check == 0) {
			y--;
		}
		else if (check == 3) {
			x--;
		}
		else if (check == 2) {
			x++;
		}
	

		
		if (kttuong())break;
		if (kttuong1())break;

		rananqua();
		dcran(x,y);
		Sleep(speed);
	}
	gifile();
	system("cls");
}
void ktran() {
	int x = 56; int y = 12;
	for (int i = 0; i < sl; i++)
	{
		tdx[i] = x--; tdy[i] = y;
	}
}
void veran() {
	textcolor(cl1);
	for (int i = 0; i < sl; i++)
	{
		if (i == 0) {
			gotoXY(tdx[i], tdy[i]); printf("0");
		}
		else {
			gotoXY(tdx[i], tdy[i]); printf("o");
		}

	}
}
void dcran(int x,int y) {
	for (int i = sl; i > 0; i--)
	{
		tdx[i] = tdx[i - 1];
		tdy[i] = tdy[i - 1];
	}
	tdx[0] = x; tdy[0] = y;
}
bool kttuong() {
	if (tdx[0] == 5 || tdx[0] == 110 || tdy[0] == 2 || tdy[0] == 25) {
		return true;
	}return false;
}
void ktqua() {
	xq = rand() % (100 - 10 + 1) + 10;
	yq = rand() % (22 - 5 + 1) + 5;
	for (int i = 0; i < sl; i++)
	{
		if (xq == tdx[i] && yq == tdy[i]) {
			xq = rand() % (109 - 7 + 1) + 7;
			yq = rand() % (25  - 4 + 1) + 4;
		}
	}
	for (int i = 19; i < 22; i++)
	{
		if (tdx[0] == 28 && tdy[0] == i) {
			xq = rand() % (109 - 7 + 1) + 7;
			yq = rand() % (25 - 4 + 1) + 4;
		}
	}
	for (int i = 9; i < 12; i++)
	{
		if (tdx[0] == 43 && tdy[0] == i) {
			xq = rand() % (109 - 7 + 1) + 7;
			yq = rand() % (25 - 4 + 1) + 4;
		}
	}
	for (int i = 13; i < 17; i++)
	{
		if (tdx[0] == 94 && tdy[0] == i) {
			xq = rand() % (109 - 7 + 1) + 7;
			yq = rand() % (25 - 4 + 1) + 4;
		}
	}
	for (int i = 21; i < 24; i++)
	{
		if (tdx[0] == 83 && tdy[0] == i) {
			xq = rand() % (109 - 7 + 1) + 7;
			yq = rand() % (25 - 4 + 1) + 4;
		}
	}
	for (int i = 25; i < 32; i++)
	{
		if (tdx[0] == i && tdy[0] == 18) {
			xq = rand() % (109 - 7 + 1) + 7;
			yq = rand() % (25 - 4 + 1) + 4;
		}
	}
	for (int i = 40; i < 47; i++)
	{
		if (tdx[0] == i && tdy[0] == 8) {
			xq = rand() % (109 - 7 + 1) + 7;
			yq = rand() % (25 - 4 + 1) + 4;
		}
	}
	for (int i = 90; i < 99; i++)
	{
		if (tdx[0] == i && tdy[0] == 12) {
			xq = rand() % (109 - 7 + 1) + 7;
			yq = rand() % (25 - 4 + 1) + 4;
		}
	}
	for (int i = 79; i < 89; i++)
	{
		if (tdx[0] == i && tdy[0] == 20) {
			xq = rand() % (109 - 7 + 1) + 7;
			yq = rand() % (25 - 4 + 1) + 4;
		}
	}

}
void vequa() {
	textcolor(4); gotoXY(xq, yq); printf("*");
}
void rananqua() {
	if (tdx[0]==xq&&tdy[0]==yq)
	{
		sl++;
		ktqua();
		vequa();
		speed -= 5;
	}
}
void vetuong1() {
	textcolor(7);
	gotoXY(25, 18); printf("=======");
	gotoXY(40, 8); printf("=======");
	gotoXY(90, 12); printf("=========");
	gotoXY(79, 20); printf("=========");
	for (int i = 19; i < 22; i++)
	{
		gotoXY(28, i); printf("|");
	}
	for (int i = 9; i < 12; i++)
	{
		gotoXY(43, i); printf("|");
	}
	for (int i = 13; i < 17; i++)
	{
		gotoXY(94, i); printf("|");
	}
	for (int i = 21; i < 24; i++)
	{
		gotoXY(83, i); printf("|");
	}

}
bool kttuong1() {
	for (int i = 19; i < 22; i++)
	{
		if (tdx[0] == 28 && tdy[0] == i) {
			return true;
		}
	}
	for (int i = 9; i < 12; i++)
	{
		if(tdx[0] == 43 && tdy[0] == i) {
			return true;
		}
	}
	for (int i = 13; i < 17; i++)
	{
		if (tdx[0] == 94 && tdy[0] == i) {
			return true;
		}
	}
	for (int i = 21; i < 24; i++)
	{
		if (tdx[0] == 83 && tdy[0] == i) {
			return true;
		}
	}
	for (int i = 25; i < 32; i++)
	{
		if (tdx[0] == i && tdy[0] == 18) {
			return true;
		}
	}
	for (int i = 40; i < 47; i++)
	{
		if (tdx[0] == i && tdy[0] == 8) {
			return true;
		}
	}
	for (int i = 90; i < 99; i++)
	{
		if (tdx[0] == i && tdy[0] == 12) {
			return true;
		}
	}
	for (int i = 79; i < 89; i++)
	{
		if (tdx[0] == i && tdy[0] == 20) {
			return true;
		}
	}
	return false;
}
void endgame() {
	vetuong();
	textcolor(7);
	gotoXY(20, 5); printf("   * * *        *      * *   * *  * * * *     * * *   *         * * * * *  * * *  ");
	gotoXY(20, 6); printf(" *       *     * *     *  * *  *  *         *       *  *       *  *        *    * ");
	gotoXY(20, 7); printf("*             *   *    *   *   *  * * * *  *         *  *     *   * * * *  * * *  ");
	gotoXY(20, 8); printf("*     ***    * * * *   *       *  *        *         *   *   *    *        * *    ");
	gotoXY(20, 9); printf(" *       *  *       *  *       *  *         *       *     * *     *        *   *  ");
	gotoXY(20, 10); printf("   * * *   *         * *       *  * * * *     * * *        *      * * * *  *    * ");
	gotoXY(35, 15); printf("Name        : %s", name);
	gotoXY(35, 16); printf("Diem cua ban: %d", sl -4 );
	gotoXY(35, 18); printf("Neu muon thoat nhan dau X, muon choi tiep nhap ki tu bat ki.");
	gotoXY(35, 19); printf("(Diem cua ban da duoc luu vao file, nap vip de co the xem)");
	ag = _getch();
}
void gifile() {
	d = fopen("in5.txt", "a");
	fprintf(d, "%d", sl-4 );
	fclose(d);
}
void edit() {
	vetuong();
	gotoXY(10, 6); printf("chon mau ran: (nhap ki tu so de chon)  ");
	gotoXY(10, 7); printf("0 - mau trang ");
	gotoXY(10, 8); printf("1 - mau do ");
	gotoXY(10, 9); printf("2 - mau hong");
	gotoXY(10, 10); printf("3 - mau vang");
	gotoXY(10, 11); printf("4 - mau xanh duong");
	char c;
	c = _getch();
	if (c==48)
	{
		cl1 = 7;
	}
	else if (c == 49) {
		cl1 = 4;
	}
	else if (c == 50) {
		cl1 = 5;
	}
	else if (c == 51) {
		cl1 = 6;
	}
	else if (c == 52) {
		cl1 = 1;
	}
	gotoXY(10, 12); printf("chon thanh cong mau cho ran  ");
	gotoXY(10, 6); printf("chon mau tuong: (nhap ki tu so de chon)  ");
	char a;
	a = _getch();
	if (a == 48)
	{
		cl2 = 15;
	}
	else if (a == 49) {
		cl2 = 12;
	}
	else if (a == 50) {
		cl2 = 13;
	}
	else if (a == 51) {
		cl2 = 14;
	}
	else if (a == 52) {
		cl2 = 9;
	}
	gotoXY(10, 7); printf("0 - mau trang");
	gotoXY(10, 8); printf("1 - mau do");
	gotoXY(10, 9); printf("2 - mau tim");
	gotoXY(10, 10); printf("3 - mau vang");
	gotoXY(10, 11); printf("4 - mau xanh duong");
	gotoXY(10, 12); printf("chon thanh cong mau cho tuong  ");
	system("cls");
	}

