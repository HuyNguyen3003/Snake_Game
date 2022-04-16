#define _CRT_SECURE_NO_DEPRECATE
#include"mylib.h"

//////////////
void ChonLevel(int check, int color1, int color2, int color3);
void ChonMap(int check, int color1, int color2, int color3);
void trangtriran();
void gifile(); // ghi lich su nguoi choi
void Doc_file(); // xem lich su nguoi choi
void intro();
void in4();
void play();
void khoitaoran();
void veran();
void dichuyenran(int x, int y);
void ktqua();
void vequa();
void rananqua();
void endgame();
void time();
void Menu(); // lua chon
void vetuong1(); // ban do 1
bool kttuong1(); // kiem tra cham tuong 1
void vetuong2(); // ban do 2
bool kttuong2(); // kiem tra cham tuong 2
void vetuong3(); // ban do 3
bool kttuong3(); // kiem tra cham tuong 3
void veMap(); // ve ban do tong hop
bool kiemtratuong(); // kiem tra tuong tong hop
void Map1(char kitu);
void Map2(char kitu1, char kitu2);
void Map3(char kitu1, char kitu2);
/// </summary>
int main() {
	system("cls");
	ShowCur(0);
	do {
		Menu();
		intro();
		play();
		endgame();
		system("cls");
	} while (ag);
	textcolor(0);
}

