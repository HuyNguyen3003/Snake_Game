#include <stdio.h> 
#include <conio.h> 
#include<ctime> 
#include <windows.h>
#include <iostream>

//============== dịch con trỏ hiện tại đến điểm có tọa độ (x,y) ==========
void gotoXY(int x, int y) {
	HANDLE hConsoleOutput;
	COORD Cursor_an_Pos = { x, y };
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
}
//============= đặt màu cho chữ =========
void SetColor(WORD color) {
	HANDLE hConsoleOutput;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
	GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);

	WORD wAttributes = screen_buffer_info.wAttributes;
	color &= 0x000f;
	wAttributes &= 0xfff0;
	wAttributes |= color;

	SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}
//============== làm ẩn trỏ chuột ===========
void ShowCur(bool CursorVisibility) {
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor = { 1, CursorVisibility };
	SetConsoleCursorInfo(handle, &cursor);
}
//======= chỉnh màu =========
void textcolor(int x) {
	HANDLE mau;
	mau = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau, x);
}
////////
FILE* d;
int tdx[100] = { 0 }, tdy[100] = { 0 };
int sl = 10;
int speed = -1;
int xq = -1, yq = -1;
int ag;
char name[30];
int diem=1;
int map = 0; // lua chon che do choi
int m3x[4] = { 0 }, m3y[4] = { 0 };
/// ///////////////////////////////
void quamap(int a);
void khoitaoran() {
	int x = 56; int y = 12;
	for (int i = 0; i < sl; i++) {
		tdx[i] = x--; tdy[i] = y;
	}
}
void veran() {
	int z = 2;
	if (diem % 3 == 0)z++;
	textcolor(z);
		for (int i = 0; i < sl; i++) {
			if (i == 0) {
				gotoXY(tdx[i], tdy[i]); printf("0");
			}
			else {
				gotoXY(tdx[i], tdy[i]); printf("%c", 149);
			}
		}
}
void dichuyenran(int x, int y) {
	for (int i = sl; i > 0; i--) {
		tdx[i] = tdx[i - 1];
		tdy[i] = tdy[i - 1];
	}
	tdx[0] = x; tdy[0] = y;
}
void ktqua() {
	xq = rand() % (100 - 10 + 1) + 10;
	yq = rand() % (22 - 5 + 1) + 5;
	// kiem tra qua trung con ran
	for (int i = 0; i < sl; i++) {
		if (xq == tdx[i] && yq == tdy[i]) {
			xq = rand() % (109 - 7 + 1) + 7;
			yq = rand() % (25 - 4 + 1) + 4;
		}
	}
	if (map == 2) { // kiem tra qua trung tuong map 2
		for (int i = 19; i < 22; i++) {
			if (tdx[0] == 28 && tdy[0] == i) {
				xq = rand() % (109 - 7 + 1) + 7;
				yq = rand() % (25 - 4 + 1) + 4;
			}
		}
		for (int i = 9; i < 12; i++) {
			if (tdx[0] == 43 && tdy[0] == i) {
				xq = rand() % (109 - 7 + 1) + 7;
				yq = rand() % (25 - 4 + 1) + 4;
			}
		}
		for (int i = 13; i < 17; i++) {
			if (tdx[0] == 94 && tdy[0] == i) {
				xq = rand() % (109 - 7 + 1) + 7;
				yq = rand() % (25 - 4 + 1) + 4;
			}
		}
		for (int i = 21; i < 24; i++) {
			if (tdx[0] == 83 && tdy[0] == i) {
				xq = rand() % (109 - 7 + 1) + 7;
				yq = rand() % (25 - 4 + 1) + 4;
			}
		}
		for (int i = 25; i < 32; i++) {
			if (tdx[0] == i && tdy[0] == 18) {
				xq = rand() % (109 - 7 + 1) + 7;
				yq = rand() % (25 - 4 + 1) + 4;
			}
		}
		for (int i = 40; i < 47; i++) {
			if (tdx[0] == i && tdy[0] == 8) {
				xq = rand() % (109 - 7 + 1) + 7;
				yq = rand() % (25 - 4 + 1) + 4;
			}
		}
		for (int i = 90; i < 99; i++) {
			if (tdx[0] == i && tdy[0] == 12) {
				xq = rand() % (109 - 7 + 1) + 7;
				yq = rand() % (25 - 4 + 1) + 4;
			}
		}
		for (int i = 79; i < 89; i++) {
			if (tdx[0] == i && tdy[0] == 20) {
				xq = rand() % (109 - 7 + 1) + 7;
				yq = rand() % (25 - 4 + 1) + 4;
			}
		}
	}
	else if (map == 3) {
		for (int i = 27; i < 85; i++) {
			if (xq == i && (yq == 8 || yq == 19)) {
				xq = rand() % (109 - 7 + 1) + 7;
				yq = rand() % (25 - 4 + 1) + 4;
			}
		}
		for (int i = 7; i < 21; i++) {
			if ((xq == 18 || xq == 95) && yq == i) {
				xq = rand() % (109 - 7 + 1) + 7;
				yq = rand() % (25 - 4 + 1) + 4;
			}
		}
	}
}
void vequa() {
	textcolor(4); gotoXY(xq, yq); printf("*");
}
void rananqua() {
	if (tdx[0] == xq && tdy[0] == yq) {
		sl++; diem++;
		ktqua();
		vequa();
		speed -= 5;
	}
}
void endgame() {
	textcolor(10);
	for (int x = 6; x < 111; x++) {
		gotoXY(x, 2); printf("=");
		gotoXY(x, 25); printf("=");
	}
	for (int y = 3; y < 26; y++) {
		gotoXY(5, y); printf("||");
		gotoXY(110, y); printf("||");
	}
	textcolor(7);
	gotoXY(20, 5); printf("   * * *        *      * *   * *  * * * *     * * *   *         * * * * *  * * *  ");
	gotoXY(20, 6); printf(" *       *     * *     *  * *  *  *         *       *  *       *  *        *    * ");
	gotoXY(20, 7); printf("*             *   *    *   *   *  * * * *  *         *  *     *   * * * *  * * *  ");
	gotoXY(20, 8); printf("*     ***    * * * *   *       *  *        *         *   *   *    *        * *    ");
	gotoXY(20, 9); printf(" *       *  *       *  *       *  *         *       *     * *     *        *   *  ");
	gotoXY(20, 10); printf("   * * *   *         * *       *  * * * *     * * *        *      * * * *  *    * ");
	gotoXY(35, 15); printf("Name         :  %s", name);
	gotoXY(35, 16); printf("Diem cua ban :  %d", diem);
	gotoXY(35, 18); printf("Neu muon thoat nhan alt + f4, muon choi tiep nhap ki tu bat ki.\n");
	ag = _getch();
}
void gifile() { // ghi lich su nguoi choi
	d = fopen("history.txt", "w");
	for (int i = 0; i < strlen(name); i++) {
		if (name[i] == '\n') name[i] = '\0';
	}
	fprintf(d, "%s: %d\n", name, diem);
	fclose(d);
}
void Doc_file() { // xem lich su nguoi choi
	d = fopen("history.txt", "r");
	char str[128];
	system("cls");
	while (fgets(str, 128, d) != NULL)  //Xuất từng dòng ra màn hình
	{
		printf("%s", str);
	}
	fclose(d);
}
void trangtriran()
{
	gotoXY(78, 5); printf("       ---_ ......._-_--.");
	gotoXY(78, 6); printf("      (|\\ /      / /| \\  \\");
	gotoXY(78, 7); printf("      /  /     .'  -=-'   `.");
	gotoXY(78, 8); printf("     /  /    .'             )");
	gotoXY(78, 9); printf("   _/  /   .'        _.)   /");
	gotoXY(78, 10); printf("  \\          _.-'    / .'*|");
	gotoXY(78, 11); printf("   \\______.-'//    .'.' \\*|");
	gotoXY(78, 12); printf("    \\|  \\ | //   .'.' _ |*|");
	gotoXY(78, 13); printf("     `   \\|//  .'.'_ _ _|*|");
	gotoXY(78, 14); printf("      .  .// .'.' | _ _ \\*|");
	gotoXY(78, 15); printf("      \\`-|\\_/ /    \\ _ _ \\*\\");
	gotoXY(78, 16); printf("       `/'\\__/      \\ _ _ \\*\\");
	gotoXY(78, 17); printf("      /^|            \\ _ _ \\*");
	gotoXY(78, 18); printf("      /^|            \\ _ _ \\*");
	gotoXY(78, 19); printf("      /^|            \\ _ _ \\*");
	gotoXY(78, 20); printf("      /^|            \\ _ _ \\*");
}
// review map
void Map1(char kitu)
{
	for (int x = 5; x < 30; x++) {
		gotoXY(x, 7); printf("%c", kitu);
		gotoXY(x, 18); printf("%c", kitu);
	}
	for (int y = 7; y < 19; y++) {
		gotoXY(5, y); printf("%c", kitu);
		gotoXY(29, y); printf("%c", kitu);
	}
}
void Map2(char kitu1, char kitu2)
{
	int i;
	for (i = 9; i <= 11; i++) { gotoXY(i, 12); printf("%c", kitu1); }
	for (i = 23; i <= 25; i++) { gotoXY(i, 12); printf("%c", kitu1); }
	for (i = 15; i <= 17; i++) { gotoXY(i, 8); printf("%c", kitu1); }
	for (i = 15; i <= 17; i++) { gotoXY(i, 16); printf("%c", kitu1); }
	gotoXY(10, 13); printf("%c", kitu2);
	gotoXY(24, 13); printf("%c", kitu2);
	gotoXY(16, 9); printf("%c", kitu2);
	gotoXY(16, 17); printf("%c", kitu2);
	Map1(42);
}
void Map3(char kitu1, char kitu2)
{
	int x, y;
	textcolor(13);
	for (x = 10; x < 25; x++) {
		gotoXY(x, 10); printf("%c", kitu1);
		gotoXY(x, 15); printf("%c", kitu1);
	}
	for (y = 10; y < 16; y++) {
		gotoXY(8, y); printf("%c", kitu2);
		gotoXY(26, y); printf("%c", kitu2);
	}
	Map1(42);
}
void ChonLevel(int check, int color1, int color2, int color3)
{
	system("cls");
	while (true) { // chon level
		SetColor(13);
		if (check == 1) {
			color1 = 4; color2 = 2; color3 = 2;
		}
		else if (check == 2) {
			color1 = 2; color2 = 4; color3 = 2;
		}
		else if (check == 3) {
			color1 = 2; color2 = 2; color3 = 4;
		}
		textcolor(7);
		trangtriran();
		SetColor(9); gotoXY(45, 6); printf("========= MENU =========");
		SetColor(9); gotoXY(52, 9); printf("CHON LEVEL");
		SetColor(color1); gotoXY(55, 11); printf("DE");
		SetColor(color2); gotoXY(51, 13); printf("TRUNG BINH");
		SetColor(color3); gotoXY(55, 15); printf("KHO");
		if (_kbhit()) {
			char kitu = _getch();
			if (kitu == -32) {
				kitu = _getch();
				if (kitu == 80) check++;// di xuong 
				else if (kitu == 72) check--;// di len
			}
			else if (kitu == 13) {
				color1 = 4, color2 = 2, color3 = 2; // chi dinh mau sac
				if (check == 1) speed = 150;
				else if (check == 2) speed = 100;
				else if (check == 3) speed = 60;
				check = 1;
				break;

			}
		}
		if (check > 3) check = 1;
		else if (check < 1) check = 3;
		textcolor(12);
		trangtriran();
	}
}
void ChonMap(int check, int color1, int color2, int color3)
{
	system("cls");
	while (true) { // chon map
		SetColor(13);

		if (check == 1) {
			Map2(32, 32);
			Map3(32, 32);
			Map1(42);
			color1 = 4; color2 = 2; color3 = 2;
		}
		else if (check == 2) {
			Map3(32, 32);
			Map2(61, 124);
			color1 = 2; color2 = 4; color3 = 2;
		}
		else if (check == 3) {
			Map2(32, 32);
			Map3(61, 124);
			color1 = 2; color2 = 2; color3 = 4;
		}
		textcolor(7);
		trangtriran();
		SetColor(9); gotoXY(45, 6); printf("========= MENU =========");
		SetColor(9); gotoXY(52, 9); printf("CHON BAN DO");
		SetColor(color1); gotoXY(53, 11); printf("BAN DO 1");
		SetColor(color2); gotoXY(53, 13); printf("BAN DO 2  ");
		SetColor(color3); gotoXY(53, 15); printf("BAN DO 3");
		if (_kbhit()) {
			char kitu = _getch();
			if (kitu == -32) {
				kitu = _getch();
				if (kitu == 80) check++;// di xuong 
				else if (kitu == 72) check--;// di len
			}
			else if (kitu == 13) {
				color1 = 4, color2 = 2, color3 = 2; // chi dinh mau sac
				if (check == 1) map = 1;
				else if (check == 2) map = 2;
				else if (check == 3) map = 3;
				check = 1;
				break;
			}
		}
		if (check > 3) check = 1;
		else if (check < 1) check = 3;
		textcolor(12);
		trangtriran();
	}
	system("cls");
}
void in4() {
	textcolor(7); gotoXY(30, 12);
	printf("Nhap ten: ");
	fgets(name, sizeof(name), stdin);
}
void vetuong1() { // ban do 1
	textcolor(10);
	for (int x = 7; x < 110; x++) {
		gotoXY(x, 2); printf("=");
		gotoXY(x, 25); printf("=");
	}
	for (int y = 2; y < 26; y++) {
		gotoXY(5, y); printf("||");
		gotoXY(110, y); printf("||");
	}
}
bool kttuong1() { // kiem tra cham tuong 1
	if (tdx[0] == 6 || tdx[0] == 110 || tdy[0] == 2 || tdy[0] == 25) {
		return true;
	}return false;
}
void vetuong2() { // ban do 2
	textcolor(7);
	gotoXY(25, 18); printf("=======");
	gotoXY(40, 8); printf("=======");
	gotoXY(90, 12); printf("=========");
	gotoXY(79, 20); printf("=========");
	// ve tuong trong
	for (int i = 19; i < 22; i++) {
		gotoXY(28, i); printf("|");
	}
	for (int i = 9; i < 12; i++) {
		gotoXY(43, i); printf("|");
	}
	for (int i = 13; i < 17; i++) {
		gotoXY(94, i); printf("|");
	}
	for (int i = 21; i < 24; i++) {
		gotoXY(83, i); printf("|");
	}
	// ve tuong ngoai
	textcolor(10);
	vetuong1();
}
bool kttuong2() { // kiem tra cham tuong 2
	// kiem tra tuong ngoai
	if (tdx[0] == 5 || tdx[0] == 110 || tdy[0] == 2 || tdy[0] == 25) return true;
	// kiem tra tuong trong
	for (int i = 19; i < 22; i++) {
		if (tdx[0] == 28 && tdy[0] == i)
			return true;
	}
	for (int i = 9; i < 12; i++) {
		if (tdx[0] == 43 && tdy[0] == i)
			return true;
	}
	for (int i = 13; i < 17; i++) {
		if (tdx[0] == 94 && tdy[0] == i)
			return true;
	}
	for (int i = 21; i < 24; i++) {
		if (tdx[0] == 83 && tdy[0] == i)
			return true;
	}
	for (int i = 25; i < 32; i++) {
		if (tdx[0] == i && tdy[0] == 18)
			return true;
	}
	for (int i = 40; i < 47; i++) {
		if (tdx[0] == i && tdy[0] == 8)
			return true;
	}
	for (int i = 90; i < 99; i++) {
		if (tdx[0] == i && tdy[0] == 12)
			return true;
	}
	for (int i = 79; i < 89; i++) {
		if (tdx[0] == i && tdy[0] == 20)
			return true;
	}
	return false;
}
void vetuong3() { // ban do 3
	int x, y;
	textcolor(10);
	vetuong1();
	textcolor(13);
	for (x = 27; x < 85; x++) {
		gotoXY(x, 8); printf("=");
		gotoXY(x, 19); printf("=");
	}
	for (y = 7; y < 21; y++) {
		gotoXY(18, y); printf("H");
		gotoXY(95, y); printf("H");
	}

}
bool kttuong3() { // kiem tra cham tuong 3
	// kiem tra tuong ngoai
	if (tdx[0] == 6 || tdx[0] == 110 || tdy[0] == 2 || tdy[0] == 25)
		return true;
	// kiem tra tuong trong
	for (int i = 27; i < 85; i++) {
		if (tdx[0] == i && tdy[0] == 8)
			return true;
		else if (tdx[0] == i && tdy[0] == 19)
			return true;
	}
	for (int i = 7; i < 21; i++) {
		if (tdx[0] == 18 && tdy[0] == i)
			return true;
		else if (tdx[0] == 95 && tdy[0] == i)
			return true;
	}
	return false;
}
void veMap() { // ve ban do tong hop
	if (map == 1) vetuong1();
	else if (map == 2) vetuong2();
	else if (map == 3) vetuong3();
}
bool kiemtratuong() { // kiem tra tuong tong hop
	if (map == 1) return kttuong1();
	else if (map == 2) return kttuong2();
	else if (map == 3) return kttuong3();
}
void intro() {

	int i = 2, u = 10; float z = 0; int m = 31, n = 10;
	while (true) {
		textcolor(7);
		trangtriran();
		textcolor(10);
		for (int x = 7; x < 110; x++) {
			gotoXY(x, 2); printf("=");
			gotoXY(x, 25); printf("=");
		}
		for (int y = 2; y < 26; y++) {
			gotoXY(5, y); printf("||");
			gotoXY(110, y); printf("||");
		}
		textcolor(u); gotoXY(49, 5);  printf("--------------");
		textcolor(u); gotoXY(49, 7);  printf("--------------");
		textcolor(u); gotoXY(49, 6);  printf("|");
		textcolor(u); gotoXY(62, 6);  printf("|");
		textcolor(i); gotoXY(50, 6);  printf(" SNAKE GAME");
		textcolor(2); gotoXY(30, 20); printf("CODE BY: ");
		textcolor(2); gotoXY(40, 20); printf("6251071038 - Nguyen Pham Phu Huy");
		textcolor(6); gotoXY(40, 21); printf("6251071105 - PHan Ngoc Nhu Tranh");
		textcolor(4); gotoXY(40, 22); printf("6251071040 - Nguyen Ngoc Huy");
		textcolor(5); gotoXY(40, 23); printf("6251071104 - Ho Vinh Tin");
		textcolor(12);
		trangtriran();
		i++; if (i == 10) i = 2;
		u--;
		if (u == 2) u = 10; z += 2.5; m++; Sleep(20);
		textcolor(7); gotoXY(73, 10); printf("%d %c", (int)z, 37);
		int o = 2;
		textcolor(i); gotoXY(m, n); printf("%c", 164);
		if (o == 15)o = 2;

		gotoXY(m, n); printf("%c", 164);
		if (z == 100) break;
	}
	in4();
	system("cls");
}
bool kiemtratonghop() { // kiem tra tuong tong hop
	for (int i = 1; i < sl; i++) {
		if (tdx[0] == tdx[i] && tdy[0] == tdy[i]) return true;
	}
	if (map == 1) return kttuong1();
	else if (map == 2) return kttuong2();
	else if (map == 3) return kttuong3();
}
void Menu() {

	vetuong1();
	ShowCur(0); // ẩn con trỏ
	int color1 = 4, color2 = 2, color3 = 2; // chi dinh mau sac
	int check = 1;
	SetColor(15);
	gotoXY(45, 6); printf("========= MENU =========");
	SetColor(color1); gotoXY(52, 9); printf(">  CHOI");
	SetColor(color2); gotoXY(54, 12); printf("LICH SU");
	while (true) { // chon choi hoac xem lich su
		SetColor(13);
		if (check == 1) {
			color1 = 4; color2 = 2; color3 = 2; 
		}
		else if (check == 2) {
			color1 = 2; color2 = 4; color3 = 2;
		}
		SetColor(15);
		gotoXY(45, 6); printf("========= MENU =========");
		SetColor(color1); gotoXY(55, 9); printf("CHOI");
		SetColor(color2); gotoXY(54, 12); printf("LICH SU");
		textcolor(7);
		trangtriran();
		textcolor(7);
		for (int i = 49; i < 66; i++)
		{
			gotoXY(i, 7); printf("_");
			gotoXY(i, 13); printf("_");
		}
		for (int i = 8; i < 14; i++)
		{
			gotoXY(48, i); printf("|");
			gotoXY(66, i); printf("|");
		}	for (int i = 49; i < 66; i++)
		{
			gotoXY(i, 10); printf("_");
		}
		textcolor(12);
		trangtriran();
		if (_kbhit()) {

			char kitu = _getch();
			if (kitu == -32) {
				kitu = _getch();
				if (kitu == 80) {
					check = check != 1 ? 1 : 2;// di xuong
				}
				else if (kitu == 72) {
					check = check != 2 ? 2 : 1;
				}
				// di len
				if (check == 1)
				{
					gotoXY(52, 12); printf(" ");
					gotoXY(52, 9); printf(">");
				}
				else if (check == 2)
				{
					gotoXY(52, 9); printf(" ");
					gotoXY(52, 12); printf(">");
				}
			}
			else if (kitu == 13 && check == 1) {
				color1 = 4, color2 = 2, color3 = 2; // chi dinh mau sac
				check = 1;
				break;
			}
			else if (kitu == 13 && check == 2) {
				Doc_file();
				system("pause");
				system("cls");
				vetuong1();
			}
		}
		if (check > 2) check = 1;
		else if (check < 1) check = 2;
	}
	ChonLevel(check, color1, color2, color3);
	ChonMap(check, color1, color2, color3);
}
void play() {
	veMap();
	khoitaoran();
	int check = 2;
	int x = tdx[0], y = tdy[0];
	ktqua();
	vequa();
	while (map) {
		textcolor(2);
		gotoXY(30, 1); printf("%s", name);
		gotoXY(tdx[sl], tdy[sl]); printf(" ");
		veran();
		gotoXY(50, 1); printf("Diem: %d", diem);
		if (_kbhit()) {
			char c = _getch();
			if (c == -32) {
				c = _getch();
				if ((c == 80 || c == 115) && check != 0) { // xuong
					check = 1;
				}
				else if ((c == 72 || c == 119) && check != 1) { // len
					check = 0;
				}
				else if ((c == 75 || c == 97) && check != 2) { // trai
					check = 3;
				}
				else if ((c == 77 || c == 100) && check != 3) { // phai
					check = 2;
				}
			}
			else if (c == 115 && check != 0)
			{
				check = 1;
			}
			else if (c == 119 && check != 1)
			{
				check = 0;
			}
			else if (c == 97 && check != 2)
			{
				check = 3;
			}
			else if (c == 100 && check != 3)
			{
				check = 2;
			}
		}
		if (check == 1) {
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
		if (kiemtratonghop()) break;
		rananqua();
		//quamap(diem);
		if (diem >= 3)
		{
			if (map == 1 && diem % 3 ==0) {
				map++;
				vetuong2();
			}
			else if (map == 2 && diem % 5==0 ) {
				map++;
				system("cls");
				vetuong3();
				ktqua();
				vequa();
			}
			else if (map == 3 && diem % 8 == 0) {
				map=1;
				system("cls");
				vetuong1();
				ktqua();
				vequa();
			}
		}
		dichuyenran(x, y);
		Sleep(speed);
	}
	gifile();
	system("cls");
}
void quamap(int a) {
	if (a==10)
	{
		a = 12;
		int x = 56, y = 12;
		int tdx[100] = { 0 }, tdy[100] = { 0 };
		khoitaoran();
		veran();
		system("cls");
		vetuong2();
		ktqua();
		vequa();
		
	}
}
