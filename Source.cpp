#define _CRT_SECURE_NO_DEPRECATE
#include"mylib.h"
/// <summary>
FILE* d;
int tdx[100] = { 0 }, tdy[100] = { 0 };
int sl = 4;
int speed = -1;
int xq = -1, yq = -1;
int ag;
char name[30];
int diem;
int map = 0; // lua chon che do choi

void gifile(); // ghi lich su nguoi choi
void Doc_file(); // xem lich su nguoi choi
void intro();
void in4();
void play();
void ktran();
void veran();
void dcran(int x, int y);
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
/// </summary>


int main() {
	system("cls");
	srand(time(NULL));
	ShowCur(0);
	do {
		do {
			Menu();
		} while (map == 0);
		intro();
		play();
		endgame();
		system("cls");
	} while (ag);
	textcolor(0);
}
void Menu() {
	vetuong1();
	int luachon = 0;
	// lua chon level
	gotoXY(45, 4); SetColor(9); printf("========= MENU =========");
	gotoXY(45, 5); printf("1. PLAY");
	gotoXY(45, 6); printf("2. LICH SU NGUOI CHOI");
	gotoXY(45, 7); printf("Nhap lua chon: ");
	scanf("%d", &luachon);
	getchar();
	switch (luachon) {
	case 1:
		SetColor(10); 
		gotoXY(20, 8);	printf("CHON LEVEL");
		gotoXY(20, 9);	printf("1. DE");
		gotoXY(20, 10);	printf("2. TRUNG BINH");
		gotoXY(20, 11);	printf("3. KHO");
		gotoXY(20, 12); printf("LEVEL: ");
		scanf("%d", &luachon); getchar();
		switch (luachon) {
		case 1: speed = 120; break;
		case 2: speed = 100; break;
		case 3: speed = 80; break;
		}
		SetColor(11); 
		gotoXY(80, 8);  printf("CHON BAN DO:");	// lua chon map
		gotoXY(80,9);	printf("1. MAP 1");
		gotoXY(80, 10); printf("2. MAP 2");
		gotoXY(80, 11); printf("3. MAP 3");
		gotoXY(80, 12);	printf("MAP: "); scanf("%d", &luachon); getchar();
		switch (luachon) {
		case 1: map = 1; break;
		case 2: map = 2; break;
		case 3: map = 3; break;
		}
		break;
	case 2:Doc_file();
		printf("\t\t\tNHAN PHIM BAT KY DE QUAY LAI MENU.\n");
		ag = _getch(); if (_kbhit()) exit(0); // nhan phim bat ky de thoat
		break;
	}
	system("cls");
}
void intro() {
	int i = 2, u = 10; int z = 0; int m=35, n=10;
	while (true) {
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
		textcolor(2); gotoXY(88, 20); printf("CODE BY: ");
		textcolor(2); gotoXY(67, 20); printf("6251071038 - Nguyen Pham Phu Huy");
		textcolor(6); gotoXY(67, 21); printf("6251071105 - PHan Ngoc Nhu Tranh");
		textcolor(4); gotoXY(67, 22); printf("6251071040 - Nguyen Ngoc Huy");
		textcolor(5); gotoXY(67, 23); printf("6251071104 - Ho Vinh Tin");
		i++; if (i == 10) i = 2;
		u--; 
		if (u == 2) u = 10; z+=2;m++; Sleep(15);
		textcolor(7);gotoXY(90, 10);printf("%d %c", z,37); 
		gotoXY(m, n); printf("%c",164);
		if (z == 100) break;
	}
	in4();
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
	for (int x = 7; x < 110; x++) {
		gotoXY(x, 2); printf("=");
		gotoXY(x, 25); printf("=");
	}
	for (int y = 2; y < 26; y++) {
		gotoXY(5, y); printf("||");
		gotoXY(110, y); printf("||");
	}
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
	for (x = 7; x < 110; x++) {
		gotoXY(x, 2); printf("=");
		gotoXY(x, 25); printf("=");
	}
	for (y = 2; y < 26; y++) {
		gotoXY(5, y); printf("||");
		gotoXY(110, y); printf("||");
	}
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
void play() {
	veMap();
	ktran();
	int check = 2;
	int x = tdx[0], y = tdy[0];
	ktqua();
	vequa();
	diem = 0;
	while (map) {
		time();
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
		if (kiemtratuong()) break;
		rananqua();
		dcran(x, y);
		Sleep(speed);
	}
	gifile();
	system("cls");
}
void ktran() {
	int x = 56; int y = 12;
	for (int i = 0; i < sl; i++) {
		tdx[i] = x--; tdy[i] = y;
	}
}
void veran() {
	int z=2;
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
void dcran(int x, int y) {
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
	gotoXY(35, 15); printf("Name        : %s", name);
	gotoXY(35, 16); printf("Diem cua ban: %d", sl - 4);
	gotoXY(35, 18); printf("Neu muon thoat nhan dau X, muon choi tiep nhap ki tu bat ki.\n");
	gotoXY(35, 19); printf("(Diem cua ban da duoc luu vao file, nap vip de co the xem)");
	ag = _getch();
}
void gifile() { // ghi lich su nguoi choi
	d = fopen("history.txt", "a");
	for (int i = 0; i < strlen(name); i++) {
		if (name[i] == '\n') name[i] = '\0';
	}
	fprintf(d, "%s: %d\n", name, diem);
	fclose(d);
}
void Doc_file() { // xem lich su nguoi choi
	d = fopen("history.txt", "r");
	if (d == nullptr) printf("CHUA CO DU LIEU\n"); // kiem tra su ton tai cua file
	char str[128];
	system("cls");
	while (fgets(str, 128, d) != NULL)  //Xuất từng dòng ra màn hình
	{
		printf("%s", str);
	}
	fclose(d);
}
void time() { // hien thi thoi gian hien tai
	SetColor(1);
	time_t rawtime; // LAY CHI SO THOI GIAN HIEN TAI CUA HE THONG
	struct tm* info; //
	char buffer[80];
	time(&rawtime);
	info = localtime(&rawtime);
	gotoXY(70, 1); printf("%s", asctime(info));
}
