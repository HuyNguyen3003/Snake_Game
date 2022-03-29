#include <stdio.h> 
#include <conio.h> 
#include<ctime> 
#include <windows.h>
#include <stdint.h>
#define KEY_NONE -1;
//======= lấy tọa độ x của con trỏ hiện tại =============
int whereX(){
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
		return csbi.dwCursorPosition.X;
	return -1;
}
//========= lấy tọa độ y của con trỏ hiện tại =======
int whereY(){
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
		return csbi.dwCursorPosition.Y;
	return -1;
}
//============== dịch con trỏ hiện tại đến điểm có tọa độ (x,y) ==========
void gotoXY(int x, int y){
	HANDLE hConsoleOutput;
	COORD Cursor_an_Pos = { x, y };
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
}
//============= đặt màu cho chữ =========
void SetColor(WORD color){
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
void ShowCur(bool CursorVisibility){
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor = { 1, CursorVisibility };
	SetConsoleCursorInfo(handle, &cursor);
}
//======= trả về mã phím người dùng bấm =========
int inputKey(){
	if (_kbhit()) { //true
		int key = _getch();
		if (key == 224){
			key = _getch();
			return key + 1000;
		}
		return key;
	}
	else{
		return KEY_NONE;
	}
	return KEY_NONE;
}
//======= chỉnh màu =========
void textcolor(int x){
	HANDLE mau;
	mau = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau, x);
}
 FILE* d;
int tdx[100] = { 0 }, tdy[100] = { 0 };
int sl = 4;
int speed = 300;
int xq = -1, yq = -1;
int ag;
char name[30];
int diem;

void gifile();
void intro();
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

int main() {
	system("cls");
	srand(time(NULL));
	ShowCur(0);
	do{
		intro();
		play();
		endgame();
		system("cls");
		
	} while (ag);

	textcolor(0);
}
void intro() {
	int i = 2, u = 10; int z = 0;
	while (true){
		vetuong();
		textcolor(u); gotoXY(49, 5);  printf("--------------");
		textcolor(u); gotoXY(49, 7);  printf("--------------");
		textcolor(u); gotoXY(49, 6);  printf("|");
		textcolor(u); gotoXY(62, 6);  printf("|");
		textcolor(i); gotoXY(50, 6);  printf("Game con ran");
		textcolor(2); gotoXY(88, 20); printf("CODE BY: ");
		textcolor(2); gotoXY(67, 20); printf("6251071040 - Nguyen Pham Phu Huy");
		textcolor(6); gotoXY(67, 21); printf("6251071105 - PHan Ngoc Nhu Tranh");
		textcolor(4); gotoXY(67, 22); printf("6251071038 - Nguyen Ngoc Huy");
		textcolor(5); gotoXY(67, 23); printf("6251071104 - Ho Vinh Tin");
		i++; if (i == 10) i = 2;  u--; if (u == 2) u = 10; z++; Sleep(14);
		textcolor(7); gotoXY(30, 10); printf("loading %d ",z);
		if (z == 100) break;
	}
	in4();
	system("cls");
}
void in4() {
	textcolor(7); gotoXY(30, 12); printf("Nhap ten: ");fflush(stdin);fgets(name, sizeof(name), stdin);fflush(stdin);
}
void vetuong(){
	textcolor(10);
	for (int x = 6; x < 111; x++){
		gotoXY(x, 2); printf("=");
		gotoXY(x, 25); printf("=");
	}
	for (int y = 3; y < 26; y++){
		gotoXY(5, y); printf("||");
		gotoXY(110, y); printf("||");
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
	diem = 0;
	while (true){
		gotoXY(tdx[sl], tdy[sl]); printf(" ");
		veran();
		gotoXY(50,1 ); printf("Diem: %d", diem);
		if (_kbhit()){
			char c = _getch();
			if (c == -32){
				c = _getch();
				if ((c == 80 || c == 115) && check != 0){ // xuong
					check = 1; 
				}
				else if ((c == 72 || c == 119) && check != 1){ // len
					check = 0;
				}
				else if ((c == 75 || c == 97) && check != 2){ // trai
					check = 3;
				}
				else if ((c == 77 || c == 100) && check != 3){ // phai
					check = 2;
				}
			}
		}
		if (check == 1){
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
void ktran(){
	int x = 56; int y = 12;
	for (int i = 0; i < sl; i++)
	{
		tdx[i] = x--; tdy[i] = y;
	}
}
void veran() {
	textcolor(11);
	for (int i = 0; i < sl; i++){
		if (i == 0) {
			gotoXY(tdx[i], tdy[i]); printf("0");
		}
		else {
			gotoXY(tdx[i], tdy[i]); printf("o");
		}
	}
}
void dcran(int x,int y) {
	for (int i = sl; i > 0; i--){
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
	for (int i = 0; i < sl; i++){
		if (xq == tdx[i] && yq == tdy[i]) {
			xq = rand() % (109 - 7 + 1) + 7;
			yq = rand() % (25  - 4 + 1) + 4;
		}
	}
	for (int i = 19; i < 22; i++){
		if (tdx[0] == 28 && tdy[0] == i) {
			xq = rand() % (109 - 7 + 1) + 7;
			yq = rand() % (25 - 4 + 1) + 4;
		}
	}
	for (int i = 9; i < 12; i++){
		if (tdx[0] == 43 && tdy[0] == i) {
			xq = rand() % (109 - 7 + 1) + 7;
			yq = rand() % (25 - 4 + 1) + 4;
		}
	}
	for (int i = 13; i < 17; i++){
		if (tdx[0] == 94 && tdy[0] == i) {
			xq = rand() % (109 - 7 + 1) + 7;
			yq = rand() % (25 - 4 + 1) + 4;
		}
	}
	for (int i = 21; i < 24; i++){
		if (tdx[0] == 83 && tdy[0] == i) {
			xq = rand() % (109 - 7 + 1) + 7;
			yq = rand() % (25 - 4 + 1) + 4;
		}
	}
	for (int i = 25; i < 32; i++){
		if (tdx[0] == i && tdy[0] == 18) {
			xq = rand() % (109 - 7 + 1) + 7;
			yq = rand() % (25 - 4 + 1) + 4;
		}
	}
	for (int i = 40; i < 47; i++){
		if (tdx[0] == i && tdy[0] == 8) {
			xq = rand() % (109 - 7 + 1) + 7;
			yq = rand() % (25 - 4 + 1) + 4;
		}
	}
	for (int i = 90; i < 99; i++){
		if (tdx[0] == i && tdy[0] == 12) {
			xq = rand() % (109 - 7 + 1) + 7;
			yq = rand() % (25 - 4 + 1) + 4;
		}
	}
	for (int i = 79; i < 89; i++){
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
	if (tdx[0]==xq && tdy[0]==yq){
		sl++;diem++;
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
	for (int i = 19; i < 22; i++){
		gotoXY(28, i); printf("|");
	}
	for (int i = 9; i < 12; i++){
		gotoXY(43, i); printf("|");
	}
	for (int i = 13; i < 17; i++){
		gotoXY(94, i); printf("|");
	}
	for (int i = 21; i < 24; i++){
		gotoXY(83, i); printf("|");
	}
}
bool kttuong1() {
	for (int i = 19; i < 22; i++){
		if (tdx[0] == 28 && tdy[0] == i) {
			return true;
		}
	}
	for (int i = 9; i < 12; i++){
		if(tdx[0] == 43 && tdy[0] == i) {
			return true;
		}
	}
	for (int i = 13; i < 17; i++){
		if (tdx[0] == 94 && tdy[0] == i) {
			return true;
		}
	}
	for (int i = 21; i < 24; i++){
		if (tdx[0] == 83 && tdy[0] == i) {
			return true;
		}
	}
	for (int i = 25; i < 32; i++){
		if (tdx[0] == i && tdy[0] == 18) {
			return true;
		}
	}
	for (int i = 40; i < 47; i++){
		if (tdx[0] == i && tdy[0] == 8) {
			return true;
		}
	}
	for (int i = 90; i < 99; i++){
		if (tdx[0] == i && tdy[0] == 12) {
			return true;
		}
	}
	for (int i = 79; i < 89; i++){
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
	d = fopen("history.txt", "a");
	for(int i=0; i<strlen(name); i++){
		if(name[i] == '\n') name[i] = '\0';
	}
	fprintf(d, "%s: %d\n",name, diem);
	fclose(d);
}
