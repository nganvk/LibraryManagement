#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "Function.h"

/*
* Ham khoiTaoThongTinSach dung de khoi tao thong tin cho sach. Ham se cap nhat soSach sau moi lan khoi tao thong tin cho mot quyen sach. 
* @param ISBN: chuoi ky tu luu tru ma ISBN cua sach.
* @param tenSach: chuoi ky tu luu tru ten sach.
* @param tacGia: chuoi ky tu luu tru ten tac gia cua sach.
* @param nhaXuatBan: chuoi ky tu luu tru ten nha xuat ban cua sach.
* @param namXuatBan: chuoi ky tu luu tru nam xuat ban cua sach.
* @param theLoai: chuoi ky tu luu tru the loai cua sach.
* @param giaSach: chuoi ky tu luu tru gia sach.
* @param soQuyenSach: chuoi ky tu luu tru so quyen sach con lai cua moi tua sach.
* @param soSach: so nguyen chua so luong sach hien tai.
*/
void khoiTaoThongTinSach(char ISBN[MAX][15], char tenSach[MAX][100], char tacGia[MAX][100], char nhaXuatBan[MAX][100], char namXuatBan[MAX][5], char theLoai[MAX][100], char giaSach[MAX][30], char soQuyenSach[MAX][10], int& soSach) {
	strcpy_s(ISBN[soSach], "9786043989519");
	strcpy_s(tenSach[soSach], "Kinh Te Hoc Vi Mo");
	strcpy_s(tacGia[soSach], "N.Gregory Mankiw");
	strcpy_s(nhaXuatBan[soSach], "Hong Duc");
	strcpy_s(namXuatBan[soSach], "2023");
	strcpy_s(theLoai[soSach], "Giao Trinh");
	strcpy_s(giaSach[soSach], "288.000");
	strcpy_s(soQuyenSach[soSach], "15");
	soSach++;

	strcpy_s(ISBN[soSach], "9786047758760");
	strcpy_s(tenSach[soSach], "Chinh Sach Tien Te The Ky 21");
	strcpy_s(tacGia[soSach], "Ben S. Bernanke");
	strcpy_s(nhaXuatBan[soSach], "The Gioi");
	strcpy_s(namXuatBan[soSach], "2024");
	strcpy_s(theLoai[soSach], "Kinh Te");
	strcpy_s(giaSach[soSach], "325.000");
	strcpy_s(soQuyenSach[soSach], "10");
	soSach++;

	strcpy_s(ISBN[soSach], "9786043770018");
	strcpy_s(tenSach[soSach], "Chien Luoc Du Lieu");
	strcpy_s(tacGia[soSach], "Bernard Marr");
	strcpy_s(nhaXuatBan[soSach], "Tong Hop Thanh Pho Ho Chi Minh");
	strcpy_s(namXuatBan[soSach], "2022");
	strcpy_s(theLoai[soSach], "Khoa Hoc Ky Thuat");
	strcpy_s(giaSach[soSach], "158.000");
	strcpy_s(soQuyenSach[soSach], "5");
	soSach++;
}

/*
* Ham inDanhSachSach dung de in ra danh sach cac quyen sach. Ham se in ra danh sach cac quyen sach tren man hinh console.
*/
void inDanhSachSach(char ISBN[MAX][15], char tenSach[MAX][100], char tacGia[MAX][100], char nhaXuatBan[MAX][100], char namXuatBan[MAX][5], char theLoai[MAX][100], char giaSach[MAX][30], char soQuyenSach[MAX][10], int soSach) {
	printf("-------------------------------------\n");
	printf("         Danh Sach Cac Sach           \n\n");
	printf("Tong so sach: %d\n", soSach);
	printf("-------------------------------------\n\n");

	for (int i = 0; i < soSach; i++) {
		printf("ISBN: \t\t%s\n", ISBN[i]);
		printf("Ten Sach: \t%s\n", tenSach[i]);
		printf("Tac Gia: \t%s\n", tacGia[i]);
		printf("Nha Xuat Ban: \t%s\n", nhaXuatBan[i]);
		printf("Nam Xuat Ban: \t%s\n", namXuatBan[i]);
		printf("The Loai: \t%s\n", theLoai[i]);
		printf("Gia Sach: \t%s\n", giaSach[i]);
		printf("So Quyen Sach: \t%s\n", soQuyenSach[i]);
		printf("\n");
	}
}

/* 
* Ham themSach yeu cau nguoi dung nhap thong tin sach moi, sau do them sach do vao danh sach va cap nhat soSach sau moi lan them sach.
*/
void themSach(char ISBN[MAX][15], char tenSach[MAX][100], char tacGia[MAX][100], char nhaXuatBan[MAX][100], char namXuatBan[MAX][5], char theLoai[MAX][100], char giaSach[MAX][30], char soQuyenSach[MAX][10], int& soSach) {
	xoaBuffer();
	printf("Nhap cac thong tin sau de them sach:\n");
	printf("- ISBN (VD: 9786043989519): ");
	gets_s(ISBN[soSach]);
	printf("- Ten sach (VD: Kinh Te Hoc Vi Mo): ");
	gets_s(tenSach[soSach]);
	printf("- Tac gia (VD: N.Gregory Mankiw): ");
	gets_s(tacGia[soSach]);
	printf("- Nha xuat ban (VD: Hong Duc): ");
	gets_s(nhaXuatBan[soSach]);
	printf("- Nam xuat ban (VD: 2023): ");
	gets_s(namXuatBan[soSach]);
	printf("- The loai (VD: Giao Trinh): ");
	gets_s(theLoai[soSach]);
	printf("- Gia sach (VD: 288.000): ");
	gets_s(giaSach[soSach]);
	printf("- So quyen sach (VD: 10): ");
	gets_s(soQuyenSach[soSach]);
	soSach++;
	printf("\nThem sach thanh cong!\n\n");
}

/*
* Ham suaThongTinSach dung de sua thong tin sach. 
* Ham yeu cau nguoi dung nhap ISBN cua sach can sua, sau do yeu cau nguoi dung nhap thong tin moi cho sach do.
*/
void suaThongTinSach(char ISBN[MAX][15], char tenSach[MAX][100], char tacGia[MAX][100], char nhaXuatBan[MAX][100], char namXuatBan[MAX][5], char theLoai[MAX][100], char giaSach[MAX][30], char soQuyenSach[MAX][10], int soSach) {
	char ISBNCanSua[15];
	printf("Nhap ma sach (ISBN) can chinh sua: ");
	scanf_s(" %s", ISBNCanSua, 15);
	ISBNCanSua[14] = '\0';

	for (int i = 0; i < soSach; i++) {
		if (strcmp(ISBN[i], ISBNCanSua) == 0) {
			int choice;
			char tiepTucStr[5];
			char tiepTuc;
			printf("\nBan dang sua thong tin sach [%s - %s]\n", ISBN[i], tenSach[i]);
			printf("1. ISBN: \t\t%s\n", ISBN[i]);
			printf("2. Ten sach: \t\t%s\n", tenSach[i]);
			printf("3. Tac gia: \t\t%s\n", tacGia[i]);
			printf("4. Nha xuat ban: \t%s\n", nhaXuatBan[i]);
			printf("5. Nam xuat ban: \t%s\n", namXuatBan[i]);
			printf("6. The loai: \t\t%s\n", theLoai[i]);
			printf("7. Gia sach: \t\t%s\n", giaSach[i]);
			printf("8. So quyen sach: \t%s\n", soQuyenSach[i]);

			do {
				printf("\nNhap so tuong ung truong thong tin can sua: ");
				scanf_s(" %d", &choice);
				xoaBuffer();
				switch (choice) {
				case 1:
					printf("\nISBN moi (VD: 9786043989519): ");
					gets_s(ISBN[i]);
					break;
				case 2:
					printf("\nTen sach moi(VD: Kinh Te Hoc Vi Mo): ");
					gets_s(tenSach[i]);
					break;
				case 3:
					printf("\nTac gia moi (VD: N.Gregory Mankiw): ");
					gets_s(tacGia[i]);
					break;
				case 4:
					printf("\nNha xuat ban moi (VD: Hong Duc): ");
					gets_s(nhaXuatBan[i]);
					break;
				case 5:
					printf("\nNam xuat ban moi (VD: 2023): ");
					gets_s(namXuatBan[i]);
					break;
				case 6:
					printf("\nThe loai moi (VD: Giao Trinh): ");
					gets_s(theLoai[i]);
					break;
				case 7:
					printf("\nGia sach moi (VD: 288.000): ");
					gets_s(giaSach[i]);
					break;
				case 8:
					printf("\nSo quyen sach moi (VD: 10): ");
					gets_s(soQuyenSach[i]);
					break;
				default:
					printf("\nLua chon khong hop le. Vui long nhap so tu 1 den 8.\n");
					break;
				}

				printf("\nBan co muon tiep tuc sua thong tin khac khong? (Y/N): ");
				gets_s(tiepTucStr);
				tiepTuc = tiepTucStr[0];

				while (tiepTuc != 'y' && tiepTuc != 'Y' && tiepTuc != 'n' && tiepTuc != 'N') {
					printf("\nLua chon khong hop le. Vui long nhap Y de tiep tuc hoac N de ket thuc chinh sua.\n");
					gets_s(tiepTucStr);
					tiepTuc = tiepTucStr[0];
				}
			} while (tiepTuc == 'y' || tiepTuc == 'Y');

			printf("\nChinh sua thanh cong thong tin sach [%s - %s]\n\n", ISBN[i], tenSach[i]);
			return;
		}
	}

	printf("\nISBN khong hop le.\n\n");
}

/*
* Ham xoaThongTinSach dung de xoa thong tin sach khoi danh sach. 
* Ham yeu cau nguoi dung nhap ISBN sach can xoa, sau do xoa thong tin sach do va cap nhap lai soSach
*/
void xoaThongTinSach(char ISBN[MAX][15], char tenSach[MAX][100], char tacGia[MAX][100], char nhaXuatBan[MAX][100], char namXuatBan[MAX][5], char theLoai[MAX][100], char giaSach[MAX][30], char soQuyenSach[MAX][10], int& soSach) {
	char ISBNCanXoa[15];
	printf("Nhap ma sach (ISBN) can xoa: ");
	scanf_s(" %s", ISBNCanXoa, 15);
	ISBNCanXoa[14] = '\0';
	xoaBuffer();

	for (int i = 0; i < soSach; i++) {
		if (strcmp(ISBNCanXoa, ISBN[i]) == 0) {
			char tenSachXoa[100];
			strcpy_s(tenSachXoa, tenSach[i]);
			printf("\nBan co chac muon xoa sach [%s - %s]? (Y/N): ", ISBNCanXoa, tenSachXoa);
			char confirmStr[5];
			char confirm;
			gets_s(confirmStr);
			confirm = confirmStr[0];

			while (confirm != 'y' && confirm != 'Y' && confirm != 'n' && confirm != 'N') {
				printf("\nLua chon khong hop le. Vui long nhap Y de tiep tuc hoac N de ket thuc.\n");
				gets_s(confirmStr);
				confirm = confirmStr[0];
			}

			if (confirm == 'Y' || confirm == 'y') {
				for (int j = i; j < soSach - 1; j++) {
					strcpy_s(ISBN[j], ISBN[j + 1]);
					strcpy_s(tenSach[j], tenSach[j + 1]);
					strcpy_s(tacGia[j], tacGia[j + 1]);
					strcpy_s(nhaXuatBan[j], nhaXuatBan[j + 1]);
					strcpy_s(namXuatBan[j], namXuatBan[j + 1]);
					strcpy_s(theLoai[j], theLoai[j + 1]);
					strcpy_s(giaSach[j], giaSach[j + 1]);
					strcpy_s(soQuyenSach[j], soQuyenSach[j + 1]);
				}

				soSach--;
				printf("\nXoa thanh cong sach [%s - %s]\n\n", ISBNCanXoa, tenSachXoa);
				return;
			}
			else {
				printf("\n");
				return;
			}
		}
	}

	printf("\nISBN khong hop le.\n\n");
}

/*
* Ham timKiemSachISBN dung de tim kiem sach theo ISBN. Ham yeu cau nguoi dung nhap ISBN can tim, sau do in ra thong tin sach co ISBN tuong ung.
*/
void timKiemSachISBN(char ISBN[MAX][15], char tenSach[MAX][100], char tacGia[MAX][100], char nhaXuatBan[MAX][100], char namXuatBan[MAX][5], char theLoai[MAX][100], char giaSach[MAX][30], char soQuyenSach[MAX][10], int soSach) {
	char ISBNCanTim[15];
	printf("Nhap ISBN can tim: ");
	scanf_s(" %s", &ISBNCanTim, 15);
	ISBNCanTim[14] = '\0';

	for (int i = 0; i < soSach; i++) {
		if (strcmp(ISBN[i], ISBNCanTim) == 0) {
			printf("\n");
			printf("ISBN: \t\t%s\n", ISBN[i]);
			printf("Ten Sach: \t%s\n", tenSach[i]);
			printf("Tac Gia: \t%s\n", tacGia[i]);
			printf("Nha Xuat Ban: \t%s\n", nhaXuatBan[i]);
			printf("Nam Xuat Ban: \t%s\n", namXuatBan[i]);
			printf("The Loai: \t%s\n", theLoai[i]);
			printf("Gia Sach: \t%s\n", giaSach[i]);
			printf("So Quyen Sach: \t%s\n", soQuyenSach[i]);
			printf("\n");
			return;
		}
	}

	printf("\ISBN khong hop le.\n\n");
}

/*
* Ham timKiemSachTheoTen dung de tim kiem sach theo ten sach. Ham yeu cau nguoi dung nhap ten sach, sau do in ra thong tin sach co ten tuong ung
*/
void timKiemSachTheoTen(char ISBN[MAX][15], char tenSach[MAX][100], char tacGia[MAX][100], char nhaXuatBan[MAX][100], char namXuatBan[MAX][5], char theLoai[MAX][100], char giaSach[MAX][30], char soQuyenSach[MAX][10], int soSach) {
	char tenSachCanTim[100];
	char tenSachTam[100];
	printf("Nhap ten sach can tim: ");
	xoaBuffer();
	gets_s(tenSachCanTim);
	tenSachCanTim[99] = '\0';
	_strlwr_s(tenSachCanTim);

	for (int i = 0; i < soSach; i++) {
		strcpy_s(tenSachTam, tenSach[i]);
		_strlwr_s(tenSachTam);

		if (strcmp(tenSachTam, tenSachCanTim) == 0) {
			printf("\n");
			printf("ISBN: \t\t%s\n", ISBN[i]);
			printf("Ten Sach: \t%s\n", tenSach[i]);
			printf("Tac Gia: \t%s\n", tacGia[i]);
			printf("Nha Xuat Ban: \t%s\n", nhaXuatBan[i]);
			printf("Nam Xuat Ban: \t%s\n", namXuatBan[i]);
			printf("The Loai: \t%s\n", theLoai[i]);
			printf("Gia Sach: \t%s\n", giaSach[i]);
			printf("So Quyen Sach: \t%s\n", soQuyenSach[i]);
			printf("\n");
			return;
		}
	}

	printf("\Ten sach khong hop le.\n\n");
}

/*
* Ham chucNangSach dung de thuc hien cac chuc nang lien quan den quan ly sach.
* Ham hien thi menu chuc nang va yeu cau nguoi dung nhap chuc nang can thuc hien.
* Cac chuc nang gom: xem danh sach sach, them sach, sua thong tin sach, xoa thong tin sach, tim kiem sach theo ISBN, tim kiem sach theo ten
*/
void chucNangSach(char ISBN[MAX][15], char tenSach[MAX][100], char tacGia[MAX][100], char nhaXuatBan[MAX][100], char namXuatBan[MAX][5], char theLoai[MAX][100], char giaSach[MAX][30], char soQuyenSach[MAX][10], int& soSach) {
	char tiepTuc, choice_kyTu;
	int back = 1;

	do {
		printMenu_Sach();
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
				inDanhSachSach(ISBN, tenSach, tacGia, nhaXuatBan, namXuatBan, theLoai, giaSach, soQuyenSach, soSach);
				break;
			case 'b':
			case 'B':
				themSach(ISBN, tenSach, tacGia, nhaXuatBan, namXuatBan, theLoai, giaSach, soQuyenSach, soSach);
				break;
			case 'c':
			case 'C':
				suaThongTinSach(ISBN, tenSach, tacGia, nhaXuatBan, namXuatBan, theLoai, giaSach, soQuyenSach, soSach);
				break;
			case 'd':
			case 'D':
				xoaThongTinSach(ISBN, tenSach, tacGia, nhaXuatBan, namXuatBan, theLoai, giaSach, soQuyenSach, soSach);
				break;
			case 'e':
			case 'E':
				timKiemSachISBN(ISBN, tenSach, tacGia, nhaXuatBan, namXuatBan, theLoai, giaSach, soQuyenSach, soSach);
				break;
			case 'f':
			case 'F':
				timKiemSachTheoTen(ISBN, tenSach, tacGia, nhaXuatBan, namXuatBan, theLoai, giaSach, soQuyenSach, soSach);
				break;
			default:
				printf("Khong hop le. Vui long nhap dung ky tu tuong ung chuc nang can chon\n\n");
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