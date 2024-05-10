#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Function.h"

/*
* Ham tinhNgayTraDuKien dung de tinh ngay tra du kien cho sach muon, theo quy tac: ngay muon + 7 ngay. 
* Neu ngay tra du kien vuot qua so ngay trong thang, ham se tu dong chuyen sang thang ke tiep. 
* Neu thang tra du kien vuot qua 12, ham se tu dong chuyen sang nam ke tiep
* @param: ngayMuon: chuoi ky tu the hien ngay muon sach, dinh dang ngay/thang/nam
* @param: ngayTraDuKien: chuoi ky tu se chua ngay tra du kien sau khi ham thuc thi
* Ket qua cua ham se duoc luu vao tham so ngayTraDuKien
*/
void tinhNgayTraDuKien(char ngayMuon[15], char ngayTraDuKien[15]) {
	int ngay, thang, nam, ngayTra;
	sscanf_s(ngayMuon, "%d/%d/%d", &ngay, &thang, &nam);
	ngayTra = ngay + 7;
	int ngayTrongThang_namThuong[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int ngayTrongThang_namNhuan[12] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	if (nam % 4 != 0) {
		if (ngayTra > ngayTrongThang_namThuong[thang - 1]) {
			ngayTra = ngayTra - ngayTrongThang_namThuong[thang - 1];
			thang++;
		}
	}
	else {
		if (ngayTra > ngayTrongThang_namNhuan[thang - 1]) {
			ngayTra = ngayTra - ngayTrongThang_namNhuan[thang - 1];
			thang++;
		}
	}

	if (thang > 12) {
		nam++;
		thang = 1;
	}

	sprintf_s(ngayTraDuKien, 15, "%02d/%02d/%d", ngayTra, thang, nam);
}

//void khoiTaoPhieuMuon(char maPhieuMuon[MAX][15], char maDocGiaMuonSach[MAX][20], char ngayMuon[MAX][15], char ngayTraDuKien[MAX][15], char ISBNMuon[MAX][100], char soSachMuon[MAX][10], int& soPhieuMuon) {
//	sprintf_s(maPhieuMuon[soPhieuMuon], "%04d", soPhieuMuon + 1);
//	strcpy_s(maDocGiaMuonSach[soPhieuMuon], "0719890");
//	strcpy_s(ngayMuon[soPhieuMuon], "07/04/2024");
//	tinhNgayTraDuKien(ngayMuon[soPhieuMuon], ngayTraDuKien[soPhieuMuon]);
//	strcpy_s(ISBNMuon[soPhieuMuon], "9786047758760,9786043770018");
//	strcpy_s(soSachMuon[soPhieuMuon], "2");
//	soPhieuMuon++;
//
//	sprintf_s(maPhieuMuon[soPhieuMuon], "%04d", soPhieuMuon + 1);
//	strcpy_s(maDocGiaMuonSach[soPhieuMuon], "0319951");
//	strcpy_s(ngayMuon[soPhieuMuon], "01/03/2024");
//	tinhNgayTraDuKien(ngayMuon[soPhieuMuon], ngayTraDuKien[soPhieuMuon]);
//	strcpy_s(ISBNMuon[soPhieuMuon], "9786043989519");
//	strcpy_s(soSachMuon[soPhieuMuon], "1");
//	soPhieuMuon++;
//}

bool theConHan(char ngayHetHan[15]) {
	int hetHan_ngay, hetHan_thang, hetHan_nam;
	int hienTai_ngay, hienTai_nam;
	char hienTai_thang[5];
	sscanf_s(ngayHetHan, "%d/%d/%d", &hetHan_ngay, &hetHan_thang, &hetHan_nam);
	sscanf_s(__DATE__, "%s %d %d", hienTai_thang, 5, &hienTai_ngay, &hienTai_nam);
	if (hetHan_nam < hienTai_nam) return false;
	if (hetHan_nam > hienTai_nam) return true;
	hienTai_thang[4] = '\0';
	char tenThang[15][5] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
	int hienTai_thangSo = 0;

	for (int i = 0; i < 12; i++) {
		if (strcmp(hienTai_thang, tenThang[i]) == 0) {
			hienTai_thangSo = i + 1;
			break;
		}
	}

	if (hetHan_thang < hienTai_thangSo) return false;
	if (hetHan_thang > hienTai_thangSo) return true;
	if (hetHan_ngay < hienTai_ngay) return false;
	if (hetHan_ngay >= hienTai_ngay) return true;
}

/*
* Ham lapPhieuMuonSach dung de lap phieu muon sach cho doc gia. 
* Ham yeu cau nguoi dung nhap ma doc gia muon sach, sau do yeu cau nguoi dung nhap thong tin sach muon va luu vao phieu muon.
* @param soDocGia: So nguyen luu tru so luong doc gia hien tai.
* @param soSach: So nguyen luu tru so luong sach hien co trong thu vien.
* @param maDocGia: chuoi ky tu luu tru ma doc gia.
* @param ISBN: chuoi ky tu luu tru ma ISBN cua sach.
* @param soQuyenSach: chuoi ky tu luu tru so quyen sach con lai cua moi tua sach.
* @param maPhieuMuon: chuoi ky tu luu tru ma phieu muon.
* @param maDocGiaMuonSach: chuoi ky tu luu tru ma doc gia muon sach.
* @param ngayMuon: chuoi ky tu luu tru ngay muon sach, dinh dang ngay/thang/nam.
* @param ngayTraDuKien: chuoi ky tu luu tru ngay tra du kien, dinh dang ngay/thang/nam.
* @param ISBNMuon: chuoi ky tu luu tru ma ISBN cua sach muon.
* @param soSachMuon: chuoi ky tu luu tru so sach muon.
* @param soPhieuMuon: so nguyen chua so luong phieu muon hien tai.
* @param ngayTraThucTe: chuoi ky tu luu tru ngay tra thuc te, dinh dang ngay/thang/nam.
*/
void lapPhieuMuonSach(int soDocGia, int soSach, char maDocGia[MAX][20], char ISBN[MAX][15], char soQuyenSach[MAX][10], char maPhieuMuon[MAX][15], char maDocGiaMuonSach[MAX][20], char ngayMuon[MAX][15], char ngayTraDuKien[MAX][15], char ISBNMuon[MAX][100], char soSachMuon[MAX][10], int& soPhieuMuon, char ngayTraThucTe[MAX][15], char ngayHetHan[MAX][15]) {
	int nhapLai;

	for (int i = soPhieuMuon; i < MAX; i++) {
		ISBNMuon[i][0] = '\0';
		ngayTraThucTe[i][0] = '\0';
	}

	do {
		int found = 0;
		char nhapMaDocGiaMuonSach[20];
		printf("Nhap ma doc gia muon sach: ");
		scanf_s(" %s", nhapMaDocGiaMuonSach, 20);
		nhapMaDocGiaMuonSach[19] = '\0';

		for (int i = 0; i < soDocGia; i++) {
			if (strcmp(nhapMaDocGiaMuonSach, maDocGia[i]) == 0) {
				if (theConHan(ngayHetHan[i])) {
					char nhapNgayMuon[15];
					sprintf_s(maPhieuMuon[soPhieuMuon], "%04d", soPhieuMuon + 1);
					strcpy_s(maDocGiaMuonSach[soPhieuMuon], nhapMaDocGiaMuonSach);
					printf("\nNhap ngay muon sach: ");
					scanf_s(" %s", ngayMuon[soPhieuMuon], 15);
					tinhNgayTraDuKien(ngayMuon[soPhieuMuon], ngayTraDuKien[soPhieuMuon]);
					char tiepTuc;
					int countSoSachMuon = 0;

					do {
						char nhapISBNMuon[15];
						printf("\nNhap ma sach (ISBN) muon: ");
						scanf_s(" %s", nhapISBNMuon, 15);
						nhapISBNMuon[14] = '\0';
						int viTriBatDau = strlen(ISBNMuon[soPhieuMuon]);

						for (int j = 0; j < soSach; j++) {
							if (strcmp(nhapISBNMuon, ISBN[j]) == 0) {
								int soQuyen;
								sscanf_s(soQuyenSach[j], "%d", &soQuyen);

								if (soQuyen == 0) {
									printf("Tua sach nay hien da het, vui long chon tua sach khac");
									break;
								}
								else {
									if (ISBNMuon[soPhieuMuon][0] != '\0') {
										ISBNMuon[soPhieuMuon][viTriBatDau] = ',';
										viTriBatDau++;
									}

									for (int i = 0; i < strlen(nhapISBNMuon); i++) {
										ISBNMuon[soPhieuMuon][i + viTriBatDau] = nhapISBNMuon[i];
									}

									soQuyen--;
									sprintf_s(soQuyenSach[j], "%d", soQuyen);
									countSoSachMuon++;
									ISBNMuon[soPhieuMuon][strlen(nhapISBNMuon) * countSoSachMuon + (countSoSachMuon - 1)] = '\0';
									break;
								}
							}
							else if ((strcmp(nhapISBNMuon, ISBN[j]) != 0) && (j == (soSach - 1))) {
								printf("\nSach nay hien khong co trong thu vien. Vui long chon sach khac\n");
							}
						}
						
						printf("\nBan co muon muon them sach khac? (Y/N): ");
						scanf_s(" %c", &tiepTuc, 1);
					} while (tiepTuc == 'y' || tiepTuc == 'Y');

					sprintf_s(soSachMuon[soPhieuMuon], "%d", countSoSachMuon);
					soPhieuMuon++;
					printf("\nLap phieu muon sach thanh cong!\n\n");
					found = 1;
					break;
				}
				else {
					printf("\nThe thu vien het han!\n\n");
					found = 1;
					break;
				}
			}
		}

		if (found == 1) break;

		printf("\nMa doc gia khong ton tai!\n\n");
		break;
		scanf_s(" %d", &nhapLai);

		if (nhapLai == 1) {
			system("cls");
			printTitle();
		}

	} while (nhapLai == 1);
}

/*
* Ham inPhieuMuonSach dung de in ra danh sach cac phieu muon sach. Ham se in ra danh sach cac phieu muon sach tren man hinh console.
* @param maPhieuMuon: chuoi ky tu luu tru ma phieu muon.
* @param maDocGiaMuonSach: chuoi ky tu luu tru ma doc gia muon sach.
* @param ngayMuon: chuoi ky tu luu tru ngay muon sach, dinh dang ngay/thang/nam.
* @param ngayTraDuKien: chuoi ky tu luu tru ngay tra du kien, dinh dang ngay/thang/nam.
* @param ISBNMuon: chuoi ky tu luu tru ma ISBN cua sach muon.
* @param soSachMuon: chuoi ky tu luu tru so sach muon.
* @param soPhieuMuon: so nguyen chua so luong phieu muon hien tai.
* @param ngayTraThucTe: chuoi ky tu luu tru ngay tra thuc te, dinh dang ngay/thang/nam.
*/
void inPhieuMuonSach(char maPhieuMuon[MAX][15], char maDocGiaMuonSach[MAX][20], char ngayMuon[MAX][15], char ngayTraDuKien[MAX][15], char ISBNMuon[MAX][100], char soSachMuon[MAX][10], int soPhieuMuon, char ngayTraThucTe[MAX][15]) {
	printf("-------------------------------------\n");
	printf("         Danh Sach Phieu Muon           \n\n");
	printf("Tong so phieu muon: %d\n", soPhieuMuon);
	printf("-------------------------------------\n\n");

	for (int i = 0; i < soPhieuMuon; i++) {
		printf("Ma phieu muon: \t\t%s\n", maPhieuMuon[i]);
		printf("Ma doc gia muon sach: \t%s\n", maDocGiaMuonSach[i]);
		printf("Ngay muon: \t\t%s\n", ngayMuon[i]);
		printf("Ngay tra du kien: \t%s\n", ngayTraDuKien[i]);
		printf("Ngay tra thuc te: \t%s\n", ngayTraThucTe[i]);
		printf("So sach muon: \t\t%s\n", soSachMuon[i]);
		printf("ISBN: \t\t\t%s\n", ISBNMuon[i]);
		printf("\n");
	}
}

/*
* Ham chucNangPhieuMuon dung de thuc hien cac chuc nang lien quan den phieu muon sach. 
* Ham se hien thi menu chuc nang va yeu cau nguoi dung chon chuc nang can thuc hien. 
* Cac chuc nang bao gom: lap phieu muon sach, in danh sach phieu muon.
*/
void chucNangPhieuMuon(int soDocGia, int soSach, char maDocGia[MAX][20], char ISBN[MAX][15], char soQuyenSach[MAX][10], char maPhieuMuon[MAX][15], char maDocGiaMuonSach[MAX][20], char ngayMuon[MAX][15], char ngayTraDuKien[MAX][15], char ISBNMuon[MAX][100], char soSachMuon[MAX][10], int& soPhieuMuon, char ngayTraThucTe[MAX][15], char ngayHetHan[MAX][15]) {
	char tiepTuc, choice_kyTu;
	int back = 1;

	do {
		printMenu_PhieuMuon();
		printf("Tiep tuc (Y/N): ");
		scanf_s(" %c", &tiepTuc, 1);

		if (tiepTuc == 'n' || tiepTuc == 'N') {
			xoaManHinh(0);
			break;
		}

		if (tiepTuc == 'y' || tiepTuc == 'Y') {
			printf("\nChon chuc nang: ");
			scanf_s(" %c", &choice_kyTu, 1);
			xoaManHinh(5);

			switch (choice_kyTu) {
			case 'a':
			case 'A':
				lapPhieuMuonSach(soDocGia, soSach, maDocGia, ISBN, soQuyenSach, maPhieuMuon, maDocGiaMuonSach, ngayMuon, ngayTraDuKien, ISBNMuon, soSachMuon, soPhieuMuon, ngayTraThucTe, ngayHetHan);
				break;
			case 'b':
			case 'B':
				inPhieuMuonSach(maPhieuMuon, maDocGiaMuonSach, ngayMuon, ngayTraDuKien, ISBNMuon, soSachMuon, soPhieuMuon, ngayTraThucTe);
				break;
			default:
				printf("Khong hop le. Vui long nhap dung ky tu tuong ung chuc nang can chon\n\n");
				break;
			}

			printf("Tro ve truoc, bam '1'\n");
			printf("Thoat chuong trinh, bam '0'\n");
			scanf_s(" %d", &back);

			if (back == 1) {
				system("cls");
				printTitle();
			}
			else {
				exit(0);
			}
		}
		else {
			xoaManHinh(3);
		}	
	} while (back == 1);
}