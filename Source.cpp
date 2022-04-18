#define _CRT_SECURE_NO_DEPRECATE
#include"mylib.h"

//////////////
void ChonLevel(int check, int color1, int color2, int color3); // chon cap do choi
void ChonMap(int check, int color1, int color2, int color3);// chon map
void trangtriran(); // ve con ran to bang ascii
void gifile(); // ghi lich su nguoi choi
void Doc_file(); // xem lich su nguoi choi
void intro(); // intro vao game
void in4(); // luu thong tin nguoi choi
void play(); // chay cho choi
void khoitaoran(); //tao ra toa do x,y cho ran
void veran();// ve ran tu toa do x,y
void dichuyenran(int x, int y);// su li man cho ran di chuyen, voi x,y la tham so truyen vao cua viec dieu khien ran o trong play();
void ktqua();// tao ra toa do x,y cho qua
void vequa(); // ve qua tu toa do qua da co
void rananqua(); // kiem tra khi dau cua con ran dung qua
void endgame(); // ham end game khi lost
void Menu(); // lua chon
void vetuong1(); // ban do 1
bool kttuong1(); // kiem tra cham tuong 1
void vetuong2(); // ban do 2
bool kttuong2(); // kiem tra cham tuong 2
void vetuong3(); // ban do 3
bool kttuong3(); // kiem tra cham tuong 3
void veMap(); // ve ban do tong hop
bool kiemtratuong(); // kiem tra tuong tong hop
void Map1(char kitu); // ki tu truyen vao de ve map bang ki tu do
void Map2(char kitu1, char kitu2);
void Map3(char kitu1, char kitu2);
bool kiemtratonghop();
/// </summary>
int main() {
	system("cls");
	ShowCur(0);
	do {
		sl = 2;
		Menu();
		intro();
		play();
		endgame();
		system("cls");
	} while (ag);
	textcolor(0);
}
