#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<ctime>
#include<conio.h>
#include<vector>
#include"mylib.h"
#define MAX 10000;
using namespace std;
int x = 99; int y = 20; int locate; int locateGV; int locateAd; int locateXoa; int locateMoKhoa;
int const dai = 50; int const rong = 20;
int const XL = 20; int const YL = 0;
int const CAOL = 40; int const RONGL = 140;
using namespace std;
bool thoat = false, dangXuat = false;
int viTriXoa;
//-----------------------------------GIAO DIEN--------------------------------------------------------
void box(int x, int y, int dai, int rong, int t_color, int b_color, string nd) {
	SetBGColor(b_color);
	for (int iy = y + 1; iy < y + rong - 1; iy++) {
		for (int ix = x + 1; ix <= x + dai - 1; ix++) {
			gotoxy(ix, iy);
			cout << " ";
		}
	}
	if (rong <= 1 || dai <= 1) {
		return;
	}
	SetBGColor(0);
	SetColor(t_color);
	for (int iy = y; iy < y + rong; iy++) {
		gotoxy(x, iy);
		cout << '#';
		gotoxy(x + dai - 1, iy);
		cout << '#';
	}
	for (int ix = x; ix < x + dai; ix++) {
		gotoxy(ix, y);
		cout << '#';
		gotoxy(ix, y + rong);
		cout << '#';
	}
	SetColor(7);
	gotoxy(x + 1, y + 1);
	cout << nd;
}
void thanh_sang(int x, int y, int dai, int rong, int b_color, string nd) {
	SetBGColor(b_color);
	for (int iy = y + 1; iy < y + rong - 1; iy++) {
		for (int ix = x + 1; ix <= x + dai - 2; ix++) {
			gotoxy(ix, iy);
			cout << " ";
		}
	}
	SetBGColor(0);
	gotoxy(x + 1, y + 1);
	cout << nd;
}
void veMenu(){
	Sleep(40);
    gotoxy(85, 10);
	cout << "|$$$  /$$$$  |$$$$$$$$$  |$$$$   |$$  |$$    |$$ \n";
	Sleep(45);
	gotoxy(85, 11);
	cout << "|$$ $/$ |$$  |$$         |$$ $$  |$$  |$$    |$$  \n";
	Sleep(50);
	gotoxy(85, 12);
	cout << "|$$  $  |$$  |$$$$$$$$$  |$$  $$ |$$  |$$    |$$   \n";
	Sleep(55);
	gotoxy(85, 13);
	cout << "|$$     |$$  |$$         |$$   $$|$$  |$$    |$$    \n";
	Sleep(60);
	gotoxy(85, 14);
	cout << "|$$     |$$  |$$$$$$$$$  |$$    $$$$  |$$$$$$$$$     \n";
	Sleep(100);
}
void veDangNhap() {
	SetColor(11);
	Sleep(55); gotoxy(70, 2);
	cout << "           $$   $$                                                  $$$\n";
	Sleep(60); gotoxy(70, 3);
	cout << "             $$$                                                  $$   $$\n";
	Sleep(65); gotoxy(70, 5);
	cout << " $$$$$$      $$$$   $$    $$    $$$$$$        $$    $$  $$    $$    $$$$   $$$$$$\n";
	Sleep(70); gotoxy(70, 6);
	cout << " $$    $$  $$   $$  $$    $$  $$              $$    $$  $$    $$  $$   $$  $$    $$\n";
	Sleep(75); gotoxy(70, 7);
	cout << "$$$$   $$  $$   $$  $$$$  $$  $$    $$$$      $$$$  $$  $$$$$$$$  $$   $$  $$$$$$$$\n";
	Sleep(80); gotoxy(70, 8);
	cout << " $$    $$  $$$$$$$  $$  $$$$  $$      $$      $$  $$$$  $$    $$  $$$$$$$  $$\n";
	Sleep(85); gotoxy(70, 9);
	cout << " $$$$$$    $$   $$  $$    $$    $$$$$$        $$    $$  $$    $$  $$   $$  $$\n";
	Sleep(90); gotoxy(70, 11);
	cout << "                                                                    $$$\n";
	SetColor(7);
}
void menu() {
	ShowCursor(0);
	gotoxy(93, 40);
	cout << "-- DUNG PHIM MUI TEN DE DI CHUYEN --";
	int dai = 20, rong = 2;
	int t_color = 14;
	int b_color = 71;
	int b_color_hop = 77;
	string noiDung[3] = { "1.DANG NHAP GV","2.DANG NHAP ADMIN","3.THOAT" };
	int xp = x, yp = y, ip = 0;
	for (int i = 0; i < 3; i++) {
		box(x, y + (i * 2), dai, rong, t_color, b_color, noiDung[i]);
		//box(x, y, dai, rong, t_color, b_color, noiDung[i]);
	}
	bool kt = true;
	while (true) {
		if (kt == true) {
			thanh_sang(xp, yp, dai, rong, b_color_hop, noiDung[ip]);
			kt = false;
		}
		//=== dieu khien ===
		if (_kbhit()) {
			char c = _getch();
			if (c == -32) {
				kt = true;
				c = _getch();
				if (c == 72 && yp != y) {// mui ten di xuong
					yp -= 2;
					ip -= 1;
				}
				else if (c == 80 && yp != y + rong * 2) {// mui ten di len
					yp += 2;
					ip += 1;
				}
			}
			else {
				if (c == 13) {
					locate = (yp - y) / 2;
					break;
				}
			}
		}
	}
}
void menuGV() {
	ShowCursor(0);
	gotoxy(93, 40);
	cout << "-- DUNG PHIM MUI TEN DE DI CHUYEN --";
	int dai = 25, rong = 2;
	int t_color = 14;
	int b_color = 71;
	int b_color_hop = 77;
	string noiDung[4] = { " Dat lich "," Xem lich da dat "," Xoa lich da dat "," Dang xuat "};
	int xp = x, yp = y, ip = 0;
	for (int i = 0; i < 4; i++) {
		box(x, y + (i * 2), dai, rong, t_color, b_color, noiDung[i]);
		//box(x, y, dai, rong, t_color, b_color, noiDung[i]);
	}
	bool kt = true;
	while (true) {
		if (kt == true) {
			thanh_sang(xp, yp, dai, rong, b_color_hop, noiDung[ip]);
			kt = false;
		}
		//=== dieu khien ===
		if (_kbhit()) {
			char c = _getch();
			if (c == -32) {
				kt = true;
				c = _getch();
				if (c == 72 && yp != y) {// mui ten di xuong
					yp -= 2;
					ip -= 1;
				}
				else if (c == 80 && yp != y + rong * 3) {// mui ten di len
					yp += 2;
					ip += 1;
				}
			}
			else {
				if (c == 13) {
					locateGV = (yp - y) / 2;
					break;
				}
			}
		}
	}
}
void menuAd() {
	ShowCursor(0);
	gotoxy(93, 40);
	cout << "-- DUNG PHIM MUI TEN DE DI CHUYEN --";
	int dai = 25, rong = 2;
	int t_color = 14;
	int b_color = 71;
	int b_color_hop = 77;
	string noiDung[4] = { " Xem lich "," Xoa lich "," Mo/Khoa tai khoan "," Dang xuat " };
	int xp = x, yp = y, ip = 0;
	for (int i = 0; i < 4; i++) {
		box(x, y + (i * 2), dai, rong, t_color, b_color, noiDung[i]);
		//box(x, y, dai, rong, t_color, b_color, noiDung[i]);
	}
	bool kt = true;
	while (true) {
		if (kt == true) {
			thanh_sang(xp, yp, dai, rong, b_color_hop, noiDung[ip]);
			kt = false;
		}
		//=== dieu khien ===
		if (_kbhit()) {
			char c = _getch();
			if (c == -32) {
				kt = true;
				c = _getch();
				if (c == 72 && yp != y) {// mui ten di xuong
					yp -= 2;
					ip -= 1;
				}
				else if (c == 80 && yp != y + rong * 3) {// mui ten di len
					yp += 2;
					ip += 1;
				}
			}
			else {
				if (c == 13) {
					locateAd = (yp - y) / 2;
					break;
				}
			}
		}
	}
}
void menuXoa(string nd[100], int n) {
	ShowCursor(0);
	gotoxy(93, 40);
	cout << "-- DUNG PHIM MUI TEN DE DI CHUYEN --";
	int dai = 25, rong = 2;
	int t_color = 14;
	int b_color = 71;
	int b_color_hop = 77;
	int xp = x, yp = y, ip = 0;
	for (int i = 0; i < n; i++) {
		box(x, y + (i * 2), dai, rong, t_color, b_color, nd[i]);
		//box(x, y, dai, rong, t_color, b_color, noiDung[i]);
	}
	bool kt = true;
	while (true) {
		if (kt == true) {
			thanh_sang(xp, yp, dai, rong, b_color_hop, nd[ip]);
			kt = false;
		}
		//=== dieu khien ===
		if (_kbhit()) {
			char c = _getch();
			if (c == -32) {
				kt = true;
				c = _getch();
				if (c == 72 && yp != y) {// mui ten di xuong
					yp -= 2;
					ip -= 1;
				}
				else if (c == 80 && yp != y + rong * (n - 1)) {// mui ten di len
					yp += 2;
					ip += 1;
				}
			}
			else {
				if (c == 13) {
					locateXoa = (yp - y) / 2;
					break;
				}
			}
		}
	}
}
void menuMoKhoa(string nd[100], int n) {
	ShowCursor(0);
	gotoxy(93, 40);
	cout << "-- DUNG PHIM MUI TEN DE DI CHUYEN --";
	int dai = 25, rong = 2;
	int t_color = 14;
	int b_color = 71;
	int b_color_hop = 77;
	int xp = x, yp = y, ip = 0;
	for (int i = 0; i < n; i++) {
		box(x, y + (i * 2), dai, rong, t_color, b_color, nd[i]);
		//box(x, y, dai, rong, t_color, b_color, noiDung[i]);
	}
	bool kt = true;
	while (true) {
		if (kt == true) {
			thanh_sang(xp, yp, dai, rong, b_color_hop, nd[ip]);
			kt = false;
		}
		//=== dieu khien ===
		if (_kbhit()) {
			char c = _getch();
			if (c == -32) {
				kt = true;
				c = _getch();
				if (c == 72 && yp != y) {// mui ten di xuong
					yp -= 2;
					ip -= 1;
				}
				else if (c == 80 && yp != y + rong * (n - 1)) {// mui ten di len
					yp += 2;
					ip += 1;
				}
			}
			else {
				if (c == 13) {
					locateMoKhoa = (yp - y) / 2;
					break;
				}
			}
		}
	}
}
void veKhung(int XKHUNG, int YKHUNG, int HK, int WK) {
	SetColor(14);
	for (int i = YKHUNG; i <= YKHUNG + HK; i++) {
		gotoxy(XKHUNG, i);
		cout << "#";
		gotoxy(XKHUNG + WK, i);
		cout << "#";
	}
	for (int i = XKHUNG; i <= XKHUNG + WK; i++) {
		gotoxy(i, YKHUNG);
		cout << "=";
		gotoxy(i, YKHUNG + HK);
		cout << "=";
	}
	SetColor(7);
}
void taoMenuDangNhap() {
	ShowCursor(0);
	int dai = 20, rong = 2;
	int t_color = 14;
	int b_color = 71;
	int b_color_hop = 77;
	string noiDung[2] = { "",""};
	int xp = x, yp = y, ip = 0;
	for (int i = 0; i < 2; i++) {
		box(x, y + (i * 4), dai, rong, t_color, b_color, noiDung[i]);
		//box(x, y, dai, rong, t_color, b_color, noiDung[i]);
	}
	for (int iy = y + 1; iy < y + rong - 1; iy++) {
		for (int ix = x + 1; ix <= x + dai - 2; ix++) {
			gotoxy(ix, iy);
			cout << " ";
		}
	}
	SetColor(12);
	gotoxy(x, 19);
	cout << "TAI KHOAN:";
	gotoxy(x, 23);
	cout << "MAT KHAU:";
	SetColor(7);
}
//-------------------------------CHUONG TRINH XEP LICH-------------------------------------------------------
int checkTKMK(string tk, string mk) {
	ifstream docTK, docMK;
	docTK.open("tk.txt", ios_base::in);
	docMK.open("mk.txt", ios_base::in);
	string filetk[100], filemk[100];
	int k = 0;
	while (!docTK.eof()) {
		docTK >> filetk[k];
		docMK >> filemk[k];
		if (tk == filetk[k] && mk == filemk[k])
			return 1;
		++k;
	}
	return 0;
	docTK.close();
	docMK.close();
}
int checkTKMKAdmin(string tk, string mk) {
	ifstream docTkMk;
	docTkMk.open("admin.txt", ios_base::in);
	string filetk, filemk;
	while (!docTkMk.eof()) {
		docTkMk >> filetk >> filemk;
		if (tk == filetk && mk == filemk)
			return 1;
	}
	return 0;
	docTkMk.close();
}
int checkNgayTK1(string ngay) {
	ifstream docNgay;
	string fileNgay;
	docNgay.open("ngay_dat_1.txt", ios_base::in);
	while (!docNgay.eof()) {
		getline(docNgay, fileNgay);
		if (ngay == fileNgay)
			return 1;
	}
	return 0;
	docNgay.close();
}
int checkNgayTK2(string ngay) {
	ifstream docNgay;
	string fileNgay;
	docNgay.open("ngay_dat_2.txt", ios_base::in);
	while (!docNgay.eof()) {
		getline(docNgay, fileNgay);
		if (ngay == fileNgay)
			return 1;
	}
	return 0;
	docNgay.close();
}
int checkNgayChung(string ngay) {
	ifstream docNgay;
	string fileNgay;
	docNgay.open("tkb_chung.txt", ios_base::in);//doc file
	while (!docNgay.eof()) {
		docNgay >> fileNgay;
		if (ngay == fileNgay)
			return 1;
	}
	return 0;
	docNgay.close();//dong file
}
void xoaNgay1(string Lich) { // cua nguoi dung 1
	ifstream inFile;
	ofstream outFile;
	string ngaySS[100];
	int n = 0;
	inFile.open("ngay_dat_1.txt", ios_base::in);
	outFile.open("ngay_dat_1.txt", ios_base::app);
	if (!inFile) {
	}
	else {
		while (!inFile.eof()) {
			inFile >> ngaySS[n];
			++n;
		}
		n--;
	}
	inFile.close();
	outFile.close();
	outFile.open("ngay_dat_1.txt", ios_base::out);
	outFile << ' ';
	outFile.close();
	outFile.open("ngay_dat_1.txt", ios_base::out);
	for (int i = 0; i < n; i++) {
		if (Lich == ngaySS[i]) {
			ngaySS[i] = ' ';
		}
		outFile << ngaySS[i] << endl;
	}
	outFile.close();
	
}
void xoaNgay2(string Lich) { // cua nguoi dung 2
	ifstream inFile;
	ofstream outFile;
	string ngaySS[100];
	int n = 0;
	inFile.open("ngay_dat_2.txt", ios_base::in);
	outFile.open("ngay_dat_2.txt", ios_base::app);
	if (!inFile) {
	}
	else {
		while (!inFile.eof()) {
			inFile >> ngaySS[n];
			++n;
		}
		n--;
	}
	inFile.close();
	outFile.close();
	outFile.open("ngay_dat_2.txt", ios_base::out);
	outFile << ' ';
	outFile.close();
	outFile.open("ngay_dat_2.txt", ios_base::out);
	for (int i = 0; i < n; i++) {
		if (Lich == ngaySS[i]) {
			ngaySS[i] = ' ';
		}
		outFile << ngaySS[i] << endl;
	}
	outFile.close();

}
void xoaTKBChung(string Lich) {
	ifstream inFile;
	ofstream outFile;
	string ngaySS[100];
	int n = 0;
	inFile.open("tkb_chung.txt", ios_base::in);
	outFile.open("tkb_chung.txt", ios_base::app);
	if (!inFile) {
	}
	else {
		while (!inFile.eof()) {
			inFile >> ngaySS[n];
			++n;
		}
		n--;
	}
	inFile.close();
	outFile.close();
	outFile.open("tkb_chung.txt", ios_base::out);
	outFile << ' ';
	outFile.close();
	outFile.open("tkb_chung.txt", ios_base::out);
	for (int i = 0; i < n; i++) {
		if (Lich == ngaySS[i]) {
			ngaySS[i] = ' ';
			viTriXoa = i;
		}
		outFile << ngaySS[i] << endl;
	}
	outFile.close();

}
void xoaTKBChungGon() {
	ifstream inFile;
	ofstream outFile;
	string ngaySS[100];
	int n = 0;
	inFile.open("tkb_chung_gon.txt", ios_base::in);
	outFile.open("tkb_chung_gon.txt", ios_base::app);
	if (!inFile) {
	}
	else {
		while (!inFile.eof()) {
			inFile >> ngaySS[n];
			++n;
		}
		n--;
	}
	inFile.close();
	outFile.close();
	outFile.open("tkb_chung_gon.txt", ios_base::out);
	outFile << ' ';
	outFile.close();
	outFile.open("tkb_chung_gon.txt", ios_base::out);
	for (int i = 0; i < n; i++) {
		if (i==viTriXoa) {
			ngaySS[i] = ' ';
		}
		outFile << ngaySS[i] << endl;
	}
	outFile.close();

}
string timThu(int day, int month, int year) {
	string thuHienCo[7] = { "thu_2","thu_3","thu_4","thu_5","thu_6","thu_7","chu_nhat" };
	int week = (day + ((153 * (month + 12 * ((14 - month) / 12) - 3) + 2) / 5) + (365 * (year + 4800 - ((14 - month) / 12))) +((year + 4800 - ((14 - month) / 12)) / 4) -((year + 4800 - ((14 - month) / 12)) / 100) +((year + 4800 - ((14 - month) / 12)) / 400) - 32045) % 7;
	return thuHienCo[week];
}
void veKhungXemLich(string tk) {
	ifstream docFile;
	string lichDemo[1000];
	int nD = 0;
	if (tk == "anh") {
		docFile.open("ngay_dat_1.txt", ios_base::in);
		while (!docFile.eof()) {
			docFile >> lichDemo[nD];
			++nD;
		}
		docFile.close();
	}
	else if (tk=="bao") {
		docFile.open("ngay_dat_2.txt", ios_base::in);
		while (!docFile.eof()) {
			docFile >> lichDemo[nD];
			++nD;
		}
		docFile.close();
	}
	gotoxy(99, 1);
	cout << "-- TKB HIEN TAI BAN DA DANG KY --";
	veKhung(100, 2, (nD+2)+(nD+2)/2+2, 30);
	for (int i = 0; i <= nD; i++) {
		gotoxy(100 + 2, 3 + (i * 2));
		cout << lichDemo[i];
	}
	gotoxy(0, 0);
}
void veLich(string tk) {
	int dem2S = 0, dem3S = 0, dem4S = 0, dem5S = 0, dem6S = 0, dem2C = 0, dem3C = 0, dem4C = 0, dem5C = 0, dem6C = 0;
	string thu2S[100], thu3S[100], thu4S[100], thu5S[100], thu6S[100], thu2C[100], thu3C[100], thu4C[100], thu5C[100], thu6C[100];
	ifstream moFile;
	string lichInFile[100], tmp[100];
	string tmp2[100]; int nTmp2 = 0;
	string tmpBuoi[100], tmp1[100];
	if (tk == "anh") {
		moFile.open("ngay_dat_1.txt", ios_base::in);
		while (!moFile.eof()) {
			getline(moFile, lichInFile[nTmp2]);
			++nTmp2;
		}
		moFile.close();
	}
	else if (tk=="bao") {
		moFile.open("ngay_dat_2.txt", ios_base::in);
		while (!moFile.eof()) {
			getline(moFile, lichInFile[nTmp2]);
			++nTmp2;
		}
		moFile.close();
	}
	for (int i = 0; i <= nTmp2; i++) {
		tmp[i] = lichInFile[i];
		stringstream tach(tmp[i]);
		getline(tach, tmp2[i], ';');
		getline(tach, tmp1[i], '|');
		getline(tach, tmpBuoi[i], ';');
		if (tmp2[i] == "thu_2") {
			if (tmpBuoi[i] == "sang") {
				thu2S[dem2S] = tmp1[i];
				dem2S++;
			}
			if (tmpBuoi[i] == "chieu") {
				thu2C[dem2C] = tmp1[i];
				dem2C++;
			}
		}
		if (tmp2[i] == "thu_3") {
			if (tmpBuoi[i] == "sang") {
				thu3S[dem3S] = tmp1[i];
				dem3S++;
			}
			if (tmpBuoi[i] == "chieu") {
				thu3C[dem3C] = tmp1[i];
				dem3C++;
			}
		}
		if (tmp2[i] == "thu_4") {
			if (tmpBuoi[i] == "sang") {
				thu4S[dem4S] = tmp1[i];
				dem4S++;
			}
			if (tmpBuoi[i] == "chieu") {
				thu4C[dem4C] = tmp1[i];
				dem4C++;
			}
		}
		if (tmp2[i] == "thu_5") {
			if (tmpBuoi[i] == "sang") {
				thu5S[dem5S] = tmp1[i];
				dem5S++;
			}
			if (tmpBuoi[i] == "chieu") {
				thu5C[dem5C] = tmp1[i];
				dem5C++;
			}
		}
		if (tmp2[i] == "thu_6") {
			if (tmpBuoi[i] == "sang") {
				thu6S[dem6S] = tmp1[i];
				dem6S++;
			}
			if (tmpBuoi[i] == "chieu") {
				thu6C[dem6C] = tmp1[i];
				dem6C++;
			}
		}
	}
	gotoxy(XL + 10, YL + 2);
	SetColor(12);
	cout << "THU 2";
	SetColor(7);
	for (int i = 0; i < dem2S; i++) {
		gotoxy(XL + 3, YL + 5 + (i * 2));
		cout << thu2S[i];
	}
	for (int i = 0; i < dem2C; i++) {
		gotoxy(XL + 3, YL + CAOL / 2 + 2 + (i * 2));
		cout << thu2C[i];
	}
	//----------------------------------------------
	gotoxy(XL + RONGL / 6 * 1 + 10, YL + 2);
	SetColor(12);
	cout << "THU 3";
	SetColor(7);
	for (int i = 0; i < dem3S; i++) {
		gotoxy(XL + RONGL / 6 + 3, YL + 5 + (i * 2));
		cout << thu3S[i];
	}
	for (int i = 0; i < dem3C; i++) {
		gotoxy(XL + RONGL / 6 + 3, YL + CAOL / 2 + 2 + (i * 2));
		cout << thu3C[i];
	}
	//---------------------------------------------------
	gotoxy(XL + RONGL / 6 * 2 + 10, YL + 2);
	SetColor(12);
	cout << "THU 4";
	SetColor(7);
	for (int i = 0; i < dem4S; i++) {
		gotoxy(XL + RONGL / 6 * 2 + 3, YL + 5 + (i * 2));
		cout << thu4S[i];
	}
	for (int i = 0; i < dem4C; i++) {
		gotoxy(XL + RONGL / 6 * 2 + 3, YL + CAOL / 2 + 2 + (i * 2));
		cout << thu4C[i];
	}
	//----------------------------------------------------
	gotoxy(XL + RONGL / 6 * 3 + 10, YL + 2);
	SetColor(12);
	cout << "THU 5";
	SetColor(7);
	for (int i = 0; i < dem5S; i++) {
		gotoxy(XL + RONGL / 6 * 3 + 3, YL + 5 + (i * 2));
		cout << thu5S[i];
	}
	for (int i = 0; i < dem5C; i++) {
		gotoxy(XL + RONGL / 6 * 3 + 3, YL + CAOL / 2 + 2 + (i * 2));
		cout << thu5C[i];
	}
	//--------------------------------------------------
	gotoxy(XL + RONGL / 6 * 4 + 10, YL + 2);
	SetColor(12);
	cout << "THU 6";
	SetColor(7);
	for (int i = 0; i < dem6S; i++) {
		gotoxy(XL + RONGL / 6 * 4 + 3, YL + 5 + (i * 2));
		cout << thu6S[i];
	}
	for (int i = 0; i < dem6C; i++) {
		gotoxy(XL + RONGL / 6 * 4 + 3, YL + CAOL / 2 + 2 + (i * 2));
		cout << thu6C[i];
	}
	gotoxy(XL + RONGL / 6 * 5 + 10, YL + 2);
	SetColor(12);
	cout << "THU 7";
	SetColor(7);
	for (int i = YL; i < YL + CAOL; i++) {
		gotoxy(XL, i);
		cout << '#';
		gotoxy(XL + RONGL / 6, i);
		cout << '|';
		gotoxy(XL + RONGL / 6 * 2, i);
		cout << '|';
		gotoxy(XL + RONGL / 6 * 3, i);
		cout << '|';
		gotoxy(XL + RONGL / 6 * 4, i);
		cout << '|';
		gotoxy(XL + RONGL / 6 * 5, i);
		cout << '|';
		gotoxy(XL + RONGL, i);
		cout << '#';
	}
	for (int i = XL; i <= XL + RONGL; i++) {
		gotoxy(i, YL);
		cout << '=';
		gotoxy(i, YL + 4);
		cout << '=';
		gotoxy(i, YL + CAOL / 2);
		cout << '=';
		gotoxy(i, YL + CAOL);
		cout << '=';
	}
	cout << endl;
	system("pause");
}
void xemTinhTrangTk() {
	bool case0on = true;
	if (case0on == true) {
		ifstream docFile;
		string a, arrcheck[100], tkif[100];// tkif: tai khoan co trong file;
		int nn = 0;
		docFile.open("tk.txt", ios_base::in);
		while (!docFile.eof()) {
			docFile >> tkif[nn];
			nn++;
		}
		docFile.close();
		int m = 0;
		bool checkk = false;
		docFile.open("tk_bi_vo_hieu.txt", ios_base::in);
		while (!docFile.eof()) {
			docFile >> a;
			for (int i = 0; i < nn; i++) {
				if (a == tkif[i]) {
					arrcheck[m] = a;
					m++;
					checkk = true;
				}
			}
		}
		docFile.close();
		if (checkk == true) {
			gotoxy(88, y - 2);
			cout << "-- NHUNG TAI KHOAN BI VO HIEU --";
			for (int i = 0; i < m-1; i++) {
				SetColor(14);
				gotoxy(99, y + (i * 2));
				cout << arrcheck[i];
			}
			SetColor(7);
			gotoxy(88, 25);
			system("pause");
		}
		else {
			gotoxy(88, y - 2);
			cout << "-- KHONG CO TAI KHOAN NAO BI VO HIEU --";
			system("pause");
		}
	}
}
int checkVoHieuTk(string tk) {
	ifstream docFile;
	string checktk;
	docFile.open("tk_bi_vo_hieu.txt", ios_base::in);
	while (!docFile.eof()) {
		docFile >> checktk;
		if (checktk == tk) {
			return 1;
		}
	}
	return 0;
	docFile.close();
}
void thucHienChTrinh() {
	string taiKhoan, matKhau, ngay, buoi, phong, thu, tkb, tkbGoiY, tkbGon, chuoiChe="";
	string buoiGoiY[2] = { "sang", "chieu" }, phongGoiY[10] = { "ph1","ph2","ph3","ph4","ph5","ph6","ph7","pm1","pm2","pm3" };
	string bienLuuSauKhiTach[4];
	char che;
	int bienDoi[4];
	//int chonMenu;
	struct tm newtime; // lay ngay hien tai
	time_t now = time(0);
	localtime_s(&newtime, &now);
	int namNow = 1900 + newtime.tm_year;
	int thangNow = 1 + newtime.tm_mon;
	int ngayNow = newtime.tm_mday;
	//===========================================================================================================================
	veDangNhap();
	veKhung(90, 15, 16, 37);
	taoMenuDangNhap();
	gotoxy(x + 2, 21);
	cin >> taiKhoan;
	gotoxy(x + 2, 25);
	do {
		che = _getch();
		if (che != 13) {
			if (che == 8) {// -------------- XOA 1 KY TU --------------
				chuoiChe.pop_back();
				matKhau.pop_back();
				SetColor(0);
				gotoxy(x + 2, 25);
				cout << "              ";
				SetColor(7);
				gotoxy(x + 2, 25);
				cout << chuoiChe;
			}
			else {
				matKhau = matKhau + che;
				chuoiChe = chuoiChe + '*';
				gotoxy(x + 2, 25);
				cout << chuoiChe;
			}
		}
	} while ((che = _getch()) != 13);
	do {
		if (checkTKMK(taiKhoan, matKhau) == 1) {
			system("cls");
			if (checkVoHieuTk(taiKhoan) == 1) {
				gotoxy(88, y);
				cout << "-- TAI KHOAN DA BI VO HIEU HOA --";
				gotoxy(83, y + 2);
				cout << "-- VUI LONG LIEN HE ADMIN DE MO TAI KHOAN --";
				gotoxy(88, y + 4);
				system("pause");
				dangXuat = true;
			}
			else {
				dangXuat = false;
				veMenu();
				menuGV();
				switch (locateGV) {
				case 0: // --------------------------------- DAT LICH ------------------------------
					system("cls");
					bool checkNgay;
					bool checkLich;
					veKhungXemLich(taiKhoan);
					do {
						checkLich = false;
						//----------------------------------------------------------
						do {
							checkNgay = false;
							int kiemTraNgayDat = 0;
							int i = 0;
							cout << "NGAY MUON DAT - dd/mm/yyyy:  "; cin >> ngay;
							if (ngay.length() <= 8) {
								cout << "NHAP SAI! " << endl;
								kiemTraNgayDat = 1;
							}
							else {
								stringstream tach(ngay);
								for (i = 0; i < 3; i++) {
									getline(tach, bienLuuSauKhiTach[i], '/');
									bienDoi[i] = stoi(bienLuuSauKhiTach[i]);
								}
								//tim thu
								thu = timThu(bienDoi[0], bienDoi[1], bienDoi[2]);
								if (thu == "thu_7" || thu == "chu_nhat") {
									cout << "DAY LA: " << thu << " ! Khong duoc dang ky lich vao thu bay hoac chu nhat !" << endl;
									kiemTraNgayDat = 1;
								}
								else {
									if (bienDoi[1] == thangNow) {
										if (bienDoi[2] == namNow) {
											if (bienDoi[0] >= ngayNow && bienDoi[0] <= ngayNow + 7) {
												switch (bienDoi[0])
												{
												case 1:case 3:case 5:case 7: case 8: case 10: case 12:
													if (bienDoi[0] <= 0 || bienDoi[0] > 32) {
														kiemTraNgayDat = 1;
														cout << "ngay dat khong hop le do thang chi co tu 1 - 31 ngay !" << endl;
													}
													break;
												case 2:
													if (bienDoi[0] % 4 == 0 && bienDoi[0] % 100 != 0 && bienDoi[0] % 400 == 0) {
														if (bienDoi[0] <= 0 || bienDoi[0] > 30) {
															kiemTraNgayDat = 1;
															cout << "ngay dat khong hop le do nam nam nhuan chi co 1 - 29 ngay !" << endl;;
														}
													}
													else {
														if (bienDoi[0] <= 0 || bienDoi[0] > 29) {
															kiemTraNgayDat = 1;
															cout << "ngay dat khong hop le do nam khong nhuan chi co 1 - 28 ngay !" << endl;
														}
													}
													break;
												default:
													if (bienDoi[0] <= 0 || bienDoi[0] > 31) {
														kiemTraNgayDat = 1;
														cout << "Ngay dat khong hop le do thang chi co tu 1 - 30 ngay!" << endl;
													}
													break;
												}
											}
											else {
												kiemTraNgayDat = 1;
												cout << "Ngay dat khong hop le do qua 7 ngay ke tu ngay hien tai !" << endl;
											}
										}
										else {
											kiemTraNgayDat = 1;
											cout << "nam khong hop le !" << endl;
										}
									}
									else {
										kiemTraNgayDat = 1;
										cout << "thang khong hop le !" << endl;
									}
								}
							}
							if (kiemTraNgayDat == 0)
								checkNgay = true;
							else {
								checkNgay = false;
							}
						} while (checkNgay != true);
						bool checkPhong;
						do {
							checkPhong = false;
							cout << "\nPHONG MUON DAT - ph1/ph2/ph3/ph4/ph5/ph6/ph7/pm1/pm2/pm3:  "; cin >> phong;
							if (phong == "ph1" || phong == "ph2" || phong == "ph3" || phong == "ph4" || phong == "ph5" || phong == "ph6" || phong == "ph7" || phong == "pm1" || phong == "pm2" || phong == "pm3") {
								checkPhong = true;
							}
							else {
								cout << "NHAP SAI!" << endl;
							}
						} while (checkPhong != true);
						bool checkBuoi;
						do {
							checkBuoi = false;
							cout << "\nBUOI MUON DAT - sang/chieu:  "; cin >> buoi;
							if (buoi == "sang" || buoi == "chieu") {
								checkBuoi = true;
							}
							else {
								cout << "\NNHAP SAI !" << endl;
							}
						} while (checkBuoi != true);
						tkb = thu + ';' + ngay + ';' + phong + '|' + buoi + ';';
						tkbGon = taiKhoan + ';' + ngay + ';' + phong;
						string khongTrung;
						khongTrung = ngay + buoi;
						if (taiKhoan == "anh") {
							ifstream moFile;
							string ltf[100], tl[100], moi[100], lkt, lktn[100], lktb[100]; // ltf: lich tu file; tl: tam luu; lkt: luu de kiem tra ngay sau tach; lktb: luu de kiem tra buoi sau tach
							int k = 0;
							moFile.open("ngay_dat_1.txt", ios_base::in);
							while (!moFile.eof()) {
								moFile >> ltf[k];
								++k;
							}
							for (int i = 0; i < k; i++) {
								tl[i] = ltf[i];
								stringstream tach(tl[i]);
								getline(tach, moi[i], ';');
								getline(tach, lktn[i], ';');
								getline(tach, moi[i], '|');
								getline(tach, lktb[i], ';');
								lkt = lktn[i] + lktb[i];
								if (lkt != khongTrung) {
									checkLich = true;
								}
								else {
									checkLich = false;
									break;
								}
							}
							if (checkLich != true) {
								cout << "\n>>> KHONG DUOC DAT LICH CUNG BUOI TRONG CUNG MOT NGAY ! <<<\n";
								cout << ">>> MOI BAN NHAP LAI ! <<<\n";
							}
							moFile.close();
						}
						if (taiKhoan == "bao") {
							ifstream moFile;
							string ltf[100], tl[100], moi[100], lkt, lktn[100], lktb[100]; // ltf: lich tu file; tl: tam luu; lkt: luu de kiem tra ngay sau tach; lktb: luu de kiem tra buoi sau tach
							int k = 0;
							moFile.open("ngay_dat_2.txt", ios_base::in);
							while (!moFile.eof()) {
								moFile >> ltf[k];
								++k;
							}
							for (int i = 0; i <= k; i++) {
								tl[i] = ltf[i];
								stringstream tach(tl[i]);
								getline(tach, moi[i], ';');
								getline(tach, lktn[i], ';');
								getline(tach, moi[i], '|');
								getline(tach, lktb[i], ';');
								lkt = lktn[i] + lktb[i];
								if (lkt != khongTrung) {
									checkLich = true;
								}
								else {
									checkLich = false;
									break;
								}
								//cout << lkt << endl;
							}
							if (checkLich != true) {
								cout << "\n>>> KHONG DUOC DAT LICH CUNG BUOI TRONG CUNG MOT NGAY ! <<<\n";
								cout << ">>> MOI BAN NHAP LAI ! <<<\n";
							}
							moFile.close();
						}
						//--------------------------------------------------
					} while (checkLich != true);
					if (taiKhoan == "anh") {
						if (checkNgayChung(tkb) == 0) {
							ofstream xuatFile;
							xuatFile.open("tkb_chung.txt", ios_base::app);
							xuatFile << tkb << endl;
							xuatFile.close();
							xuatFile.open("ngay_dat_1.txt", ios_base::app);
							xuatFile << tkb << endl;
							xuatFile.close();
							xuatFile.open("tkb_chung_gon.txt", ios_base::app);
							xuatFile << tkbGon << endl;
							xuatFile.close();
							cout << "\n\n>>> === <<< \nBan da dat THANH CONG TKB ! \n";
							cout << "Moi ban kiem tra lai ngay da dat:   " << tkb;
							cout << endl;
							system("pause");
						}
						else {
							cout << "\n\n>>> === <<<\nBan da dat THAT BAI TKB do da co giang vien khac dat roi! \n";
							cout << "da dat lich that bai ! \nDay la mot so goi y trong ngay: " << endl;
							if (phong < "pm1") {
								for (int i = 0; i < 7; i++) {
									tkbGoiY = thu + ';' + ngay + ';' + phongGoiY[i] + '|' + buoi + ';';
									if (checkNgayChung(tkbGoiY) == 0) {
										cout << tkbGoiY << endl;
									}
								}
							}
							else {
								for (int i = 7; i < 10; i++) {
									tkbGoiY = thu + ';' + ngay + ';' + phongGoiY[i] + '|' + buoi + ';';
									if (checkNgayChung(tkbGoiY) == 0) {
										cout << tkbGoiY << endl;
									}
								}
							}
							system("pause");
						}
					}
					if (taiKhoan == "bao") {
						if (checkNgayChung(tkb) == 0) {
							ofstream xuatFile;
							xuatFile.open("tkb_chung.txt", ios_base::app);//ghi file
							xuatFile << tkb << endl;
							xuatFile.close();
							xuatFile.open("ngay_dat_2.txt", ios_base::app);
							xuatFile << tkb << endl;
							xuatFile.close();
							xuatFile.open("tkb_chung_gon.txt", ios_base::app);
							xuatFile << tkbGon << endl;
							xuatFile.close();
							cout << "\n\n>>> === <<< \nBan da dat THANH CONG TKB ! \n";
							cout << "Moi ban kiem tra lai ngay da dat:   " << tkb;
							cout << endl;
							system("pause");
						}
						else {
							cout << "Ban da dat THAT BAI TKB do da co giang vien khac dat roi! \n";
							cout << "da dat lich that bai ! \nDay la mot so goi y trong ngay: " << endl;
							if (phong < "pm1") {
								for (int i = 0; i < 7; i++) {
									tkbGoiY = thu +';' + ngay + ';' + phongGoiY[i] + '|' + buoi + ';';
									if (checkNgayChung(tkbGoiY) == 0) {
										cout << tkbGoiY << endl;
									}
								}
							}
							else {
								for (int i = 7; i < 10; i++) {
									tkbGoiY = thu +';' + ngay + ';' + phongGoiY[i] + '|' + buoi + ';';
									if (checkNgayChung(tkbGoiY) == 0) {
										cout << tkbGoiY << endl;
									}
								}
							}
							system("pause");
						}
					}
					break;
				case 1:// --------------------------- XEM LICH --------------------------------
					system("cls");
					/*if (taiKhoan == "anh") {
						ifstream docFile;
						docFile.open("ngay_dat_1.txt", ios_base::in);
						string lich[100];
						bool tmp = false;
						int n = 0;
						while (!docFile.eof()) {
							docFile >> lich[n];
							if (lich[n] == "" && tmp == false) {
								cout << "Giang vien chua dang ky tkb nao !\n";
							}
							else {
								tmp = true;
							}
							++n;
						}
						for (int i = 0; i < n; i++) {
							cout << lich[i] << endl;
						}
						docFile.close();
						system("pause");
					}
					if (taiKhoan == "bao") {
						ifstream docFile;
						docFile.open("ngay_dat_2.txt", ios_base::in);
						string lich[100];
						bool tmp = false;
						int n = 0;
						while (!docFile.eof()) {
							docFile >> lich[n];
							if (lich[n] == "" && tmp == false) {
								cout << "Giang vien chua dang ky tkb nao !\n";
							}
							else {
								tmp = true;
							}
							++n;
						}
						for (int i = 0; i < n; i++) {
							cout << lich[i] << endl;
						}
						docFile.close();
						system("pause");
					}*/
					veLich(taiKhoan);
					break;
				case 2:// -------------------------- XOA LICH -----------------------------
					system("cls");
					if (taiKhoan == "anh") {
						ifstream docFile;
						docFile.open("ngay_dat_1.txt", ios_base::in);
						string lich[100];
						bool tmp = false;
						int n = 0;
						bool co = true;
						while (!docFile.eof()) {
							docFile >> lich[n];
							if (lich[n] == "" && tmp == false) {
								gotoxy(80, y);
								cout << "Giang vien chua dang ky tkb nao !\n";
								co = false;
							}
							else {
								tmp = true;
								++n;
							}

						}
						veKhung(85, 2, n + 2 + (n + 2) / 2 + 2, 36);
						for (int i = 0; i < n-1; i++) {
							gotoxy(88, 3 + (i * 2));
							cout << i << ", " << lich[i] << endl;
						}
						docFile.close();
						// bat dau xoa
						if (co == true) {
							int stt;
							gotoxy(0, 1);
							do {
								cout << "\n>>> HAY NHAP STT CO CHUA LICH CAN XOA <<<\n";
								cin >> stt;
								cout << endl;
							} while (stt >= n - 1);
							cout << lich[stt] << "   Day la lich ban muon xoa ?   (Y/N)  " << endl;
							char checkagain;
							cin >> checkagain;
							if (checkagain == 'y' || checkagain == 'Y') {
								xoaTKBChung(lich[stt]);
								xoaTKBChungGon();
								xoaNgay1(lich[stt]);
								cout << ">>> DA XOA THANH CONG <<<\n";
							}
						}
						system("pause");
					}
					if (taiKhoan == "bao") {
						ifstream docFile;
						docFile.open("ngay_dat_2.txt", ios_base::in);
						string lich[100];
						bool tmp = false;
						int n = 0;
						bool co = true;
						while (!docFile.eof()) {
							docFile >> lich[n];
							if (lich[n] == "" && tmp == false) {
								gotoxy(80, y);
								cout << "Giang vien chua dang ky tkb nao !\n";
								co = false;
							}
							else {
								tmp = true;
								++n;
							}

						}
						veKhung(85, 2, n + 2 + (n + 2) / 2 + 2, 36);
						for (int i = 0; i < n-1; i++) {
							gotoxy(88, 3 + (i * 2));
							cout << i << ", " << lich[i] << endl;
						}
						docFile.close();
						// bat dau xoa
						if (co == true) {
							int stt;
							gotoxy(0, 1);
							do {
								cout << "\n>>> HAY NHAP STT CO CHUA LICH CAN XOA <<<\n";
								cin >> stt;
								cout << endl;
							} while (stt >= n - 1);
							cout << lich[stt] << "   Day la lich ban muon xoa ?   (Y/N)  " << endl;
							char checkagain;
							cin >> checkagain;
							if (checkagain == 'y' || checkagain == 'Y') {
								xoaTKBChung(lich[stt]);
								xoaTKBChungGon();
								xoaNgay2(lich[stt]);
								cout << ">>> DA XOA THANH CONG <<<\n";
							}
						}
						system("pause");
					}

					dangXuat = false;
					break;
				case 3:// ------------------------- DANG XUAT ----------------------------
					dangXuat = true;
					break;
				}
			}
		}
		else {
			system("cls");
			gotoxy(80, y);
			cout << ">>> Dang nhap THAT BAI do sai tai khoan hoac mat khau ! <<<" << endl;
			gotoxy(87, y + 2);
			system("pause");
			dangXuat = true;
		}
	} while (dangXuat != true);
	system("cls");
}
void thucHienChTrinhAdmin() {
	//int chonMenu;
	string taiKhoan, matKhau, chuoiChe="";
	char che;
	bool dangXuat = false;
	bool on = true;
	bool onCase1 = true;
	veDangNhap();
	veKhung(90, 15, 16, 37);
	taoMenuDangNhap();
	gotoxy(x + 2, 21);
	cin >> taiKhoan;
	gotoxy(x + 2, 25);
	do {
		che = _getch();
		if (che == 8) {// ----------- XOA 1 KY TU DUNG TRUOC -------------
			chuoiChe.pop_back();
			matKhau.pop_back();
			SetColor(0);
			gotoxy(x + 2, 25);
			cout << "              ";
			SetColor(7);
			gotoxy(x + 2, 25);
			cout << chuoiChe;
		}
		else {
			matKhau = matKhau + che;
			chuoiChe = chuoiChe + '*';
			gotoxy(x + 2, 25);
			cout << chuoiChe;
		}
	} while ((che = _getch()) != 13);
	do {
		if (checkTKMKAdmin(taiKhoan, matKhau) == 1) {
			system("cls");
			dangXuat = false;
			bool case2on=true;
			int dem2S = 0, dem3S = 0, dem4S = 0, dem5S = 0, dem6S = 0, dem2C = 0, dem3C = 0, dem4C = 0, dem5C = 0, dem6C = 0;
			string thu2S[100], thu3S[100], thu4S[100], thu5S[100], thu6S[100], thu2C[100], thu3C[100], thu4C[100], thu5C[100], thu6C[100];
			veMenu();
			menuAd();
			switch (locateAd) {
			case 0: // ------------------------------- XEM LICH --------------------------------
				system("cls");
				on = true;
				int vtThu2;
				if (on == true) {
					ifstream moFile;
					string lichInFile[100], tmp[100], lichGon[100];
					string tmp2[100]; int nTmp2 = 0;
					string tmpBuoi[100], tmp1[100];
					moFile.open("tkb_chung.txt", ios_base::in);
					while (!moFile.eof()) {
						getline(moFile, lichInFile[nTmp2]);
						++nTmp2;
					}
					moFile.close();
					int nGon = 0;
					moFile.open("tkb_chung_gon.txt", ios_base::in);
					while (!moFile.eof()) {
						getline(moFile, lichGon[nGon]);
						++nGon;
					}
					moFile.close();
					for (int i = 0; i <= nTmp2; i++) {
						tmp[i] = lichInFile[i];
						stringstream tach(tmp[i]);
						getline(tach, tmp2[i], ';');
						getline(tach, tmp1[i], '|');
						getline(tach, tmpBuoi[i], ';');

						if (tmp2[i] == "thu_2") {
							if (tmpBuoi[i] == "sang") {
								thu2S[dem2S] = lichGon[i];
								dem2S++;
								
							}
							if (tmpBuoi[i]=="chieu") {
								thu2C[dem2C] = lichGon[i];
								dem2C++;
							}
						}
						if (tmp2[i] == "thu_3") {
							if (tmpBuoi[i] == "sang") {
								thu3S[dem3S] = lichGon[i];
								dem3S++;
							}
							if (tmpBuoi[i] == "chieu") {
								thu3C[dem3C] = lichGon[i];
								dem3C++;
							}
						}
						if (tmp2[i] == "thu_4") {
							if (tmpBuoi[i] == "sang") {
								thu4S[dem4S] = lichGon[i];
								dem4S++;
							}
							if (tmpBuoi[i] == "chieu") {
								thu4C[dem4C] = lichGon[i];
								dem4C++;
							}
						}
						if (tmp2[i] == "thu_5") {
							if (tmpBuoi[i] == "sang") {
								thu5S[dem5S] = lichGon[i];
								dem5S++;
							}
							if (tmpBuoi[i] == "chieu") {
								thu5C[dem5C] = lichGon[i];
								dem5C++;
							}
						}
						if (tmp2[i] == "thu_6") {
							if (tmpBuoi[i] == "sang") {
								thu6S[dem6S] = lichGon[i];
								dem6S++;
							}
							if (tmpBuoi[i] == "chieu") {
								thu6C[dem6C] = lichGon[i];
								dem6C++;
							}
						}
					}
				}
				gotoxy(XL + 10, YL + 2);
				SetColor(12);
				cout << "THU 2";
				SetColor(7);
				for (int i = 0; i < dem2S; i++) {
					gotoxy(XL + 3, YL + 5 + (i * 2));
					string lichInFile[100], tmp[100], tmp2[100];
					tmp[i] = thu2S[i];
					stringstream tach(tmp[i]);
					getline(tach, tmp2[i], ';');
					if (tmp2[i] == "anh") {
						SetColor(190);
						cout << thu2S[i];
						SetColor(7);
					}
					if (tmp2[i] == "bao") {
						SetColor(15);
						cout << thu2S[i];
						SetColor(7);
					}
				}
				for (int i = 0; i < dem2C; i++) {
					gotoxy(XL + 3, YL + CAOL/2 + 2 + (i * 2));
					string lichInFile[100], tmp[100], tmp2[100];
					tmp[i] = thu2C[i];
					stringstream tach(tmp[i]);
					getline(tach, tmp2[i], ';');
					if (tmp2[i] == "anh") {
						SetColor(190);
						cout << thu2C[i];
						SetColor(7);
					}
					if (tmp2[i] == "bao") {
						SetColor(15);
						cout << thu2C[i];
						SetColor(7);
					}
				}
				//----------------------------------------------
				gotoxy(XL + RONGL / 6 * 1 + 10, YL + 2);
				SetColor(12);
				cout << "THU 3";
				SetColor(7);
				for (int i = 0; i < dem3S; i++) {
					gotoxy(XL + RONGL / 6 +3, YL + 5 + (i * 2));
					string lichInFile[100], tmp[100], tmp2[100];
					tmp[i] = thu3S[i];
					stringstream tach(tmp[i]);
					getline(tach, tmp2[i], ';');
					if (tmp2[i] == "anh") {
						SetColor(190);
						cout << thu3S[i];
						SetColor(7);
					}
					if (tmp2[i] == "bao") {
						SetColor(15);
						cout << thu3S[i];
						SetColor(7);
					}
				}
				for (int i = 0; i < dem3C; i++) {
					gotoxy(XL + RONGL / 6 + 3, YL + CAOL / 2 + 2 + (i * 2));
					string lichInFile[100], tmp[100], tmp2[100];
					tmp[i] = thu3C[i];
					stringstream tach(tmp[i]);
					getline(tach, tmp2[i], ';');
					if (tmp2[i] == "anh") {
						SetColor(190);
						cout << thu3C[i];
						SetColor(7);
					}
					if (tmp2[i] == "bao") {
						SetColor(15);
						cout << thu3C[i];
						SetColor(7);
					}
				}
				//---------------------------------------------------
				gotoxy(XL + RONGL / 6 * 2 + 10, YL + 2);
				SetColor(12);
				cout << "THU 4";
				SetColor(7);
				for (int i = 0; i < dem4S; i++) {
					gotoxy(XL + RONGL / 6 * 2 + 3, YL + 5 + (i * 2));
					string lichInFile[100], tmp[100], tmp2[100];
					tmp[i] = thu4S[i];
					stringstream tach(tmp[i]);
					getline(tach, tmp2[i], ';');
					if (tmp2[i] == "anh") {
						SetColor(190);
						cout << thu4S[i];
						SetColor(7);
					}
					if (tmp2[i] == "bao") {
						SetColor(15);
						cout << thu4S[i];
						SetColor(7);
					}
				}
				for (int i = 0; i < dem4C; i++) {
					gotoxy(XL + RONGL / 6 * 2 + 3, YL + CAOL / 2 + 2 + (i * 2));
					string lichInFile[100], tmp[100], tmp2[100];
					tmp[i] = thu4C[i];
					stringstream tach(tmp[i]);
					getline(tach, tmp2[i], ';');
					if (tmp2[i] == "anh") {
						SetColor(190);
						cout << thu4C[i];
						SetColor(7);
					}
					if (tmp2[i] == "bao") {
						SetColor(15);
						cout << thu4C[i];
						SetColor(7);
					}
				}
				//----------------------------------------------------
				gotoxy(XL + RONGL / 6 * 3 + 10, YL + 2);
				SetColor(12);
				cout << "THU 5";
				SetColor(7);
				for (int i = 0; i < dem5S; i++) {
					gotoxy(XL + RONGL / 6 * 3 + 3, YL + 5 + (i * 2));
					string lichInFile[100], tmp[100], tmp2[100];
					tmp[i] = thu5S[i];
					stringstream tach(tmp[i]);
					getline(tach, tmp2[i], ';');
					if (tmp2[i] == "anh") {
						SetColor(190);
						cout << thu5S[i];
						SetColor(7);
					}
					if (tmp2[i] == "bao") {
						SetColor(15);
						cout << thu5S[i];
						SetColor(7);
					}
				}
				for (int i = 0; i < dem5C; i++) {
					gotoxy(XL + RONGL / 6 * 3 + 3, YL + CAOL / 2 + 2 + (i * 2));
					string lichInFile[100], tmp[100], tmp2[100];
					tmp[i] = thu5C[i];
					stringstream tach(tmp[i]);
					getline(tach, tmp2[i], ';');
					if (tmp2[i] == "anh") {
						SetColor(190);
						cout << thu5C[i];
						SetColor(7);
					}
					if (tmp2[i] == "bao") {
						SetColor(15);
						cout << thu5C[i];
						SetColor(7);
					}
				}
				//--------------------------------------------------
				gotoxy(XL + RONGL / 6 * 4 + 10, YL + 2);
				SetColor(12);
				cout << "THU 6";
				SetColor(7);
				for (int i = 0; i < dem6S; i++) {
					gotoxy(XL + RONGL / 6 * 4 + 3, YL + 5 + (i * 2));
					string lichInFile[100], tmp[100], tmp2[100];
					tmp[i] = thu6S[i];
					stringstream tach(tmp[i]);
					getline(tach, tmp2[i], ';');
					if (tmp2[i] == "anh") {
						SetColor(190);
						cout << thu6S[i];
						SetColor(7);
					}
					if (tmp2[i] == "bao") {
						SetColor(15);
						cout << thu6S[i];
						SetColor(7);
					}
				}
				for (int i = 0; i < dem6C; i++) {
					gotoxy(XL + RONGL / 6 * 4 + 3, YL + CAOL / 2 + 2 + (i * 2));
					string lichInFile[100], tmp[100], tmp2[100];
					tmp[i] = thu6C[i];
					stringstream tach(tmp[i]);
					getline(tach, tmp2[i], ';');
					if (tmp2[i] == "anh") {
						SetColor(190);
						cout << thu6C[i];
						SetColor(7);
					}
					if (tmp2[i] == "bao") {
						SetColor(15);
						cout << thu6C[i];
						SetColor(7);
					}
				}
				gotoxy(XL + RONGL / 6 * 5 + 10, YL + 2);
				SetColor(12);
				cout << "THU 7";
				SetColor(7);
				for (int i = YL; i < YL + CAOL; i++) {
					gotoxy(XL, i);
					cout << '#';
					gotoxy(XL+RONGL / 6, i);
					cout << '|';
					gotoxy(XL + RONGL / 6*2, i);
					cout << '|';
					gotoxy(XL + RONGL / 6*3, i);
					cout << '|';
					gotoxy(XL + RONGL / 6*4, i);
					cout << '|';
					gotoxy(XL + RONGL / 6*5, i);
					cout << '|';
					gotoxy(XL + RONGL, i);
					cout << '#';
				}
				for (int i = XL; i <= XL + RONGL; i++) {
					gotoxy(i, YL);
					cout << '=';
					gotoxy(i, YL + 4);
					cout << '=';
					gotoxy(i, YL + CAOL / 2);
					cout << '=';
					gotoxy(i, YL + CAOL);
					cout << '=';
				}
				cout << endl;
				system("pause");
				break;
			case 1: // ----------------------- XOA LICH -----------------------
				system("cls");
				onCase1 = true;
				if (onCase1 == true) {
					string tkHienCo[3] = { " anh ", " bao ", " tro ve "};
					int ntk=3;
					ifstream docFile, docFile2;
					ofstream xuatFile, xuatFile2;
					bool case0on, case1on;
					system("cls");
					menuXoa(tkHienCo, ntk);
					switch (locateXoa) {
					case 0:
						case0on = true;
						system("cls");
						if (case0on == true) {
							ifstream docFile;
							docFile.open("ngay_dat_1.txt", ios_base::in);
							string lich[100];
							bool tmp = false;
							int n = 0;
							bool co = true;
							while (!docFile.eof()) {
								docFile >> lich[n];
								if (lich[n] == "" && tmp == false) {
									cout << "Giang vien chua dang ky tkb nao !\n";
									co = false;
								}
								else {
									tmp = true;
									++n;
								}

							}
							veKhung(85, 2, n + 2 + (n + 2) / 2 + 2, 36);
							for (int i = 0; i < n-1; i++) {
								gotoxy(88, 3 + (i * 2));
								cout << i << ", " << lich[i] << endl;
							}
							docFile.close();
							// bat dau xoa
							if (co == true) {
								int stt;
								gotoxy(0, 1);
								do {
									cout << "\n>>> HAY NHAP STT CO CHUA LICH CAN XOA <<<\n";
									cin >> stt;
									cout << endl;
								} while (stt >= n - 1);
								cout << lich[stt] << "   Day la lich ban muon xoa ?   (Y/N)  " << endl;
								char checkagain;
								cin >> checkagain;
								if (checkagain == 'y' || checkagain == 'Y') {
									xoaTKBChung(lich[stt]);
									xoaTKBChungGon();
									xoaNgay1(lich[stt]);
									cout << ">>> DA XOA THANH CONG <<<\n";
								}
							}
							system("pause");
						}
						case0on = false;
						break;
					case 1:
						case1on = true;
						system("cls");
						if (case1on == true) {
							ifstream docFile;
							docFile.open("ngay_dat_2.txt", ios_base::in);
							string lich[100];
							bool tmp = false;
							int n = 0;
							bool co = true;
							while (!docFile.eof()) {
								docFile >> lich[n];
								if (lich[n] == "" && tmp == false) {
									cout << "Giang vien chua dang ky tkb nao !\n";
									co = false;
								}
								else {
									tmp = true;
									++n;
								}

							}
							veKhung(85, 2, n + 2 + (n + 2) / 2 + 2, 36);
							for (int i = 0; i < n-1; i++) {
								gotoxy(88, 3 + (i * 2));
								cout << i << ", " << lich[i] << endl;
							}
							docFile.close();
							// bat dau xoa
							if (co == true) {
								int stt;
								gotoxy(0, 1);
								do {
									cout << "\n>>> HAY NHAP STT CO CHUA LICH CAN XOA <<<\n";
									cin >> stt;
									cout << endl;
								} while (stt >= n - 1);
								cout << lich[stt] << "   Day la lich ban muon xoa ?   (Y/N)  " << endl;
								char checkagain;
								cin >> checkagain;
								if (checkagain == 'y' || checkagain == 'Y') {
									xoaTKBChung(lich[stt]);
									xoaTKBChungGon();
									xoaNgay1(lich[stt]);
									cout << ">>> DA XOA THANH CONG <<<\n";
								}
							}
							system("pause");
						}
						case1on = false; 
						break;
					default:
						break;
					}
				}
				onCase1 = false;
				break;
			case 2:// ------------------------ MO / KHOA TAI KHOAN -----------------------
				system("cls");
				if (case2on == true) {
					bool case0on, case1on, case2on ;
					string ndMenuMoKhoa[4] = { " Xem tinh trang TK "," Mo tai khoan "," Khoa tai khoan ", " Thoat " };
					menuMoKhoa(ndMenuMoKhoa, 4);
					switch (locateMoKhoa) {
					case 0:
						system("cls");
						xemTinhTrangTk();
						break;
					case 1:// ------------------- MO TAI KHOAN -----------------------
						system("cls");
						case1on = true;
						if (case1on == true) {
							ifstream docFile;
							bool co = false;
							string checkFile;
							docFile.open("tk_bi_vo_hieu.txt", ios_base::in);
							while (!docFile.eof()) {
								docFile >> checkFile;
								if (checkFile != "") {
									co = true;
									break;
								}
							}
							docFile.close();
							if (co == true) {
								ifstream docFile;
								ofstream xuatFile,xuatFile2;
								string tkHienCo[100],ss[100];
								bool co = false;
								int nTK = 0, m=0;
								docFile.open("tk.txt", ios_base::in);
								while (!docFile.eof()) {
									docFile >> tkHienCo[nTK];
									++nTK;
								}
								++nTK;
								tkHienCo[nTK - 1] = " Thoat ";
								docFile.close();
								int locateMotk;
								menuXoa(tkHienCo, nTK);
								locateMotk = locateXoa;
								bool checkMo = false;
								docFile.open("tk_bi_vo_hieu.txt", ios_base::in);
								xuatFile.open("tk_bi_vo_hieu.txt", ios_base::app);
								switch (locateMotk) {
								case 0:
									while (!docFile.eof()) {
										docFile >> ss[m];
										if (ss[m] == tkHienCo[0]) {
											ss[m] = "";
											checkMo = true;
										}
										m++;
									}
									if (checkMo == true) {
										xuatFile2.open("tk_bi_vo_hieu.txt", ios_base::out);
										xuatFile2 << ' ';
										xuatFile2.close();
										for (int i = 0; i < m; i++) {
											xuatFile << ss[i] << endl;
										}
										system("cls");
										gotoxy(88, y);
										cout << "-- DA MO TAI KHOAN THANH CONG --";
										gotoxy(88, y + 2);
										system("pause");
									}
									else if (checkMo == false) {
										system("cls");
										gotoxy(85, y);
										cout << "-- DA MO TAI KHOAN THAT BAI DO TAI KHOAN HIEN TAI KHONG BI KHOA --";
										gotoxy(88, y + 2);
										system("pause");
									}
									break;
								case 1:
									while (!docFile.eof()) {
										docFile >> ss[m];
										if (ss[m] == tkHienCo[1]) {
											ss[m] = "";
											checkMo = true;
										}
										m++;
									}
									m--;
									if (checkMo == true) {
										xuatFile2.open("tk_bi_vo_hieu.txt", ios_base::out);
										xuatFile2 << ' ';
										xuatFile2.close();
										for (int i = 0; i < m; i++) {
											xuatFile << ss[i] << endl;
										}
										system("cls");
										gotoxy(88, y);
										cout << "-- DA MO TAI KHOAN THANH CONG --";
										gotoxy(88, y + 2);
										system("pause");
									}
									else if (checkMo == false) {
										system("cls");
										gotoxy(85, y);
										cout << "-- DA MO TAI KHOAN THAT BAI DO TAI KHOAN HIEN TAI KHONG BI KHOA --";
										gotoxy(88, y + 2);
										system("pause");
									}
									break;
								case 2:
									break;
								}
								xuatFile.close();
								docFile.close();

							}
							else if (co == false) {
								gotoxy(88, y);
								cout << "-- KHONG CO TAI KHOAN BI VO HIEU --";
								gotoxy(88, y + 4);
								system("pause");
							}
						}
						case1on = false;
						break;

					case 2:// ------------------- KHOA TAI KHOAN --------------------------
						case2on= true;
						if (case2on == true) {
							system("cls");
							ifstream docFile;
							ofstream xuatFile;
							string tkHienCo[100], ss;
							bool co = false;
							int nTK = 0;
							int viTri;
							docFile.open("tk.txt", ios_base::in);
							while (!docFile.eof()) {
								docFile >> tkHienCo[nTK];
								++nTK;
							}
							++nTK;
							tkHienCo[nTK - 1] = " Thoat ";
							docFile.close();
							menuXoa(tkHienCo, nTK);
							viTri = locateXoa;
							xuatFile.open("tk_bi_vo_hieu.txt", ios_base::app);
							docFile.open("tk_bi_vo_hieu.txt", ios_base::in);
							switch (viTri) {
							case 0:
								while (!docFile.eof()) {
									string moi;
									docFile >> moi;
									if (moi == tkHienCo[0]) {
										co = true;
										break;
									}
								}
								if (co == false) {
									system("cls");
									xuatFile << tkHienCo[0] << endl;
									gotoxy(88, y);
									cout << "-- DA KHOA TAI KHOAN THANH CONG ! --";
									gotoxy(88, y + 2);
									system("pause");
								}
								else if (co == true) {
									system("cls");
									gotoxy(88, y);
									cout << "-- TAI KHOAN DA BI VO HIEU --";
									gotoxy(88, y + 2);
									system("pause");
								}
								break;
							case 1:
								while (!docFile.eof()) {
									string moi;
									docFile >> moi;
									if (moi == tkHienCo[1]) {
										co = true;
										break;
									}
								}
								if (co == false) {
									system("cls");
									xuatFile << tkHienCo[1] << endl;
									gotoxy(88, y);
									cout << "-- DA KHOA TAI KHOAN THANH CONG ! --";
									gotoxy(88, y + 2);
									system("pause");
								}
								else if (co == true) {
									system("cls");
									gotoxy(88, y);
									cout << "-- TAI KHOAN DA BI VO HIEU --";
									gotoxy(88, y + 2);
									system("pause");
								}
								break;
							case 2:
								break;
							}
							docFile.close();
							xuatFile.close();
						}
						break;
					}
				}

				break;
			default: // ---------------------- DANG XUAT -----------------------
				dangXuat = true;
				system("cls");
				break;
			}
		}
		else {
			system("cls");
			gotoxy(88, y);
			cout << ">>> Dang nhap THAT BAI do sai tai khoan hoac mat khau ! <<<" << endl;
			gotoxy(87, y + 2);
			system("pause");
			system("cls");
			dangXuat = true;
		}
	} while (dangXuat != true);
	
}
//----------------------------------------------------------------------------------------
void menu_tinh(int opt) {
	SetColor(7);
	switch (locate) {
	case 0:
		system("cls");
		thucHienChTrinh();
		break;
	case 1:
		system("cls");
		thucHienChTrinhAdmin();
		break;
	case 2:
		system("cls");
		thoat = true;
		break;
	}
}
int main() {
	system("pause");
	system("cls");
	while (!thoat) {
		menu();
		menu_tinh(locate);
	}
	return 0;
}