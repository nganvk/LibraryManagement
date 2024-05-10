#include "Function.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/*
 *Ham taoMaDocGia dung de tao ma doc gia tu ngay sinh va so doc gia, theo quy tac: 2 chu so cua thang sinh + nam sinh + so doc gia
 * @param ngaySinh: chuoi ky tu the hien ngay sinh doc gia, dinh dang ngay/thang/nam
 * @param soDocGia: so nguyen the hien so luong doc gia
 * @param maDocGia: chuoi ky tu se chua ma doc gia sau khi ham thuc thi.
 * Ket qua cua ham duoc luu vao tham so maDocGia
 */
void taoMaDocGia(char ngaySinh[15], int soDocGia, char maDocGia[20]) {
	int ngay, thang, nam;
	sscanf_s(ngaySinh, "%d/%d/%d", &ngay, &thang, &nam);
	sprintf_s(maDocGia, 20, "%02d%d%d", thang, nam, soDocGia);
}

/*
 * Ham tinhNgayHetHanThe dung de tinh ngay het han the doc gia tu ngay lap the, theo quy tac: ngay lap the + 48 thang
 * @param ngayLapThe: chuoi ky tu the hien ngay lap the cua doc gia, dinh dang ngay/thang/nam.
 * @param ngayHetHanThe: chuoi ky tu se chua ngay het han the sau khi ham thuc thi.
 * Ket qua cua ham se duoc luu vao tham so ngayHetHanThe.
 */
void tinhNgayHetHanThe(char ngayLapThe[15], char ngayHetHanThe[15]) {
	int ngay = 0, thang = 0, nam = 0;
	int soThangHetHan = 48;
	sscanf_s(ngayLapThe, "%d/%d/%d", &ngay, &thang, &nam);
	int namHetHan = nam + (soThangHetHan / 12);
	sprintf_s(ngayHetHanThe, 15, "%02d/%02d/%4d", ngay, thang, namHetHan);
}

/*
 * Ham khoiTaoThongTinDocGia dung de khoi tao thong tin cho doc gia, ham se cap nhat soDocGia sau moi lan khoi tao thong tin cho mot doc gia
 * @param maDocGia: chuoi ky tu luu tru ma doc gia.
 * @param hoTen: chuoi ky tu luu tru ho ten doc gia.
 * @param CMND: chuoi ky tu luu tru so CMND cua doc gia.
 * @param ngaySinh: chuoi ky tu luu tru ngay sinh cua doc gia, dinh dang ngay/thang/nam.
 * @param gioiTinh: chuoi ky tu luu tru gioi tinh cua doc gia, "M" cho nam, "F" cho nu.
 * @param email: chuoi ky tu luu tru dia chi email cua doc gia.
 * @param diaChi: chuoi ky tu luu tru dia chi cua doc gia.
 * @param ngayLapThe: chuoi ky tu luu tru ngay lap the cua doc gia, dinh dang ngay/thang/nam.
 * @param ngayHetHan: chuoi ky tu luu tru ngay het han the cua doc gia.
 * @param soDocGia: so nguyen chua so luong doc gia hien tai.
 * Ket qua cua ham se duoc luu vao cac tham so tren.
 * Ham se cap nhat soDocGia sau moi lan khoi tao thong tin cho mot doc gia.
 */
void khoiTaoThongTinDocGia(char maDocGia[MAX][20], char hoTen[MAX][100], char CMND[MAX][15], char ngaySinh[MAX][15], char gioiTinh[MAX][5], char email[MAX][100], char diaChi[MAX][100], char ngayLapThe[MAX][15], char ngayHetHan[MAX][15], int& soDocGia) {
	strcpy_s(hoTen[soDocGia], "Nguyen Thi Hang");
	strcpy_s(CMND[soDocGia], "154289376");
	strcpy_s(ngaySinh[soDocGia], "18/07/1989");
	strcpy_s(gioiTinh[soDocGia], "F");
	strcpy_s(email[soDocGia], "hang.nguyen@example.com");
	strcpy_s(diaChi[soDocGia], "23 Nguyen Van Linh, Q.5, TPHCM");
	strcpy_s(ngayLapThe[soDocGia], "05/04/2024");
	taoMaDocGia(ngaySinh[soDocGia], soDocGia, maDocGia[soDocGia]);
	tinhNgayHetHanThe(ngayLapThe[soDocGia], ngayHetHan[soDocGia]);
	soDocGia++;

	strcpy_s(hoTen[soDocGia], "Tran Van Nam");
	strcpy_s(CMND[soDocGia], "287645901");
	strcpy_s(ngaySinh[soDocGia], "12/03/1995");
	strcpy_s(gioiTinh[soDocGia], "M");
	strcpy_s(email[soDocGia], "nam.tran@example.com");
	strcpy_s(diaChi[soDocGia], "57 Le Loi, Q1, TPHCM");
	strcpy_s(ngayLapThe[soDocGia], "10/02/2024");
	taoMaDocGia(ngaySinh[soDocGia], soDocGia, maDocGia[soDocGia]);
	tinhNgayHetHanThe(ngayLapThe[soDocGia], ngayHetHan[soDocGia]);
	soDocGia++;

	strcpy_s(hoTen[soDocGia], "Pham Thi Lan Anh");
	strcpy_s(CMND[soDocGia], "325874609");
	strcpy_s(ngaySinh[soDocGia], "25/09/1987");
	strcpy_s(gioiTinh[soDocGia], "F");
	strcpy_s(email[soDocGia], "lananh.pham@example.com");
	strcpy_s(diaChi[soDocGia], "102 Ba Thang Hai, Quan 10, TPHCM");
	strcpy_s(ngayLapThe[soDocGia], "20/01/2024");
	taoMaDocGia(ngaySinh[soDocGia], soDocGia, maDocGia[soDocGia]);
	tinhNgayHetHanThe(ngayLapThe[soDocGia], ngayHetHan[soDocGia]);
	soDocGia++;
}

/*
 * Ham inDanhSachDocGia dung de in ra danh sach doc gia tren man hinh console.
 */
void inDanhSachDocGia(char maDocGia[MAX][20], char hoTen[MAX][100], char CMND[MAX][15], char ngaySinh[MAX][15], char gioiTinh[MAX][5], char email[MAX][100], char diaChi[MAX][100], char ngayLapThe[MAX][15], char ngayHetHan[MAX][15], int soDocGia) {
	printf("-------------------------------------\n");
	printf("         Danh Sach Doc Gia           \n\n");
	printf("Tong so doc gia: %d\n", soDocGia);
	printf("-------------------------------------\n\n");

	for (int i = 0; i < soDocGia; i++) {
		printf("Ma Doc Gia: \t\t%s\n", maDocGia[i]);
		printf("Ho Ten: \t\t%s\n", hoTen[i]);
		printf("CMND: \t\t\t%s\n", CMND[i]);
		printf("Ngay Thang Nam Sinh: \t%s\n", ngaySinh[i]);
		printf("Gioi Tinh: \t\t%s\n", gioiTinh[i]);
		printf("Email: \t\t\t%s\n", email[i]);
		printf("Dia Chi: \t\t%s\n", diaChi[i]);
		printf("Ngay Lap The: \t\t%s\n", ngayLapThe[i]);
		printf("Ngay Het Han The: \t%s\n", ngayHetHan[i]);
		printf("\n");
	}
}

/*
 * Ham themDocGia yeu cau nguoi dung nhap thong tin doc gia moi, sau do them doc gia do vao danh sach
 * Ham se cap nhat soDocGia sau moi lan them doc gia. 
 */
void themDocGia(char maDocGia[MAX][20], char hoTen[MAX][100], char CMND[MAX][15], char ngaySinh[MAX][15], char gioiTinh[MAX][5], char email[MAX][100], char diaChi[MAX][100], char ngayLapThe[MAX][15], char ngayHetHan[MAX][15], int& soDocGia) {
	xoaBuffer();
	printf("Nhap cac thong tin sau de them doc gia:\n");
	printf("- Ho ten (VD: Nguyen Thi Hang): ");
	gets_s(hoTen[soDocGia]);
	printf("- CMND (VD: 154289376): ");
	gets_s(CMND[soDocGia]);
	printf("- Ngay thang nam sinh (VD: 18/07/1989): ");
	gets_s(ngaySinh[soDocGia]);
	printf("- Gioi tinh (VD: F hoac M): ");
	gets_s(gioiTinh[soDocGia]);
	printf("- Email (VD: hang.nguyen@example.com): ");
	gets_s(email[soDocGia]);
	printf("- Dia chi (VD: 23 Nguyen Van Linh, Q.5, TPHCM): ");
	gets_s(diaChi[soDocGia]);
	printf("- Ngay lap the (VD: 05/04/2024): ");
	gets_s(ngayLapThe[soDocGia], 15);
	tinhNgayHetHanThe(ngayLapThe[soDocGia], ngayHetHan[soDocGia]);
	taoMaDocGia(ngaySinh[soDocGia], soDocGia, maDocGia[soDocGia]);
	soDocGia++;
	printf("\nThem doc gia thanh cong!\n\n");
}

/*
 * Ham suaThongTinDocGia dung de chinh sua thong tin doc gia trong danh sach. 
 * Ham yeu cau nguoi dung nhap ma doc gia can chinh sua, sau do yeu cau nguoi dung nhap thong tin moi cho doc gia do.
 */
void suaThongTinDocGia(char maDocGia[MAX][20], char hoTen[MAX][100], char CMND[MAX][15], char ngaySinh[MAX][15], char gioiTinh[MAX][5], char email[MAX][100], char diaChi[MAX][100], char ngayLapThe[MAX][15], char ngayHetHan[MAX][15], int soDocGia) {
	char maDocGiaCanSua[20];
	printf("Nhap ma doc gia can chinh sua: ");
	scanf_s(" %s", maDocGiaCanSua, 20);
	maDocGiaCanSua[19] = '\0';

	for (int i = 0; i < soDocGia; i++) {
		if (strcmp(maDocGia[i], maDocGiaCanSua) == 0) {
			printf("\nBan dang sua thong tin doc gia [%s - %s]\n", maDocGia[i], hoTen[i]);
			printf("1. Ho Ten:\t\t%s\n", hoTen[i]);
			printf("2. CMND:\t\t%s\n", CMND[i]);
			printf("3. Ngay Thang Nam Sinh:\t%s\n", ngaySinh[i]);
			printf("4. Gioi Tinh:\t\t%s\n", gioiTinh[i]);
			printf("5. Email:\t\t%s\n", email[i]);
			printf("6. Dia Chi:\t\t%s\n", diaChi[i]);
			printf("7. Ngay Lap The:\t%s\n", ngayLapThe[i]);
			int choice;
			char tiepTucStr[5];
			char tiepTuc;

			do {
				printf("\nNhap so tuong ung truong thong tin can sua: ");
				scanf_s(" %d", &choice);
				xoaBuffer();
				switch (choice) {
				case 1:
					printf("\nHo ten moi (VD: Nguyen Thi Hang): ");
					gets_s(hoTen[i]);
					break;
				case 2:
					printf("\nCMND moi (VD: 154289376): ");
					gets_s(CMND[i]);
					break;
				case 3:
					printf("\nNgay thang nam sinh moi (VD: 18/07/1989): ");
					gets_s(ngaySinh[i]);
					break;
				case 4:
					printf("\nGioi tinh moi (VD: F hoac M): ");
					gets_s(gioiTinh[i]);
					break;
				case 5:
					printf("\nEmail moi (VD: hang.nguyen@example.com): ");
					gets_s(email[i]);
					break;	
				case 6:
					printf("\nDia chi moi (VD: 23 Nguyen Van Linh, Q.5, TPHCM): ");
					gets_s(diaChi[i]);
					break;
				case 7:
					printf("\nNgay lap the moi (VD: 05/04/2024): ");
					gets_s(ngayLapThe[i]);
					tinhNgayHetHanThe(ngayLapThe[i], ngayHetHan[i]);
					break;
				default:
					printf("\nLua chon khong hop le. Vui long nhap so tu 1 den 7.\n");
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
			
			printf("\nChinh sua thanh cong thong tin doc gia [%s - %s]\n\n", maDocGia[i], hoTen[i]);
			return;
		}
	}

	printf("\nMa doc gia khong hop le.\n\n");
}

/*
 * Ham xoaThongTinDocGia dung de xoa thong tin doc gia trong danh sach.
 * Ham yeu cau nguoi dung nhap ma doc gia can xoa, sau do xoa doc gia do khoi danh sach va cap nhat soDocGia.
 */
void xoaThongTinDocGia(char maDocGia[MAX][20], char hoTen[MAX][100], char CMND[MAX][15], char ngaySinh[MAX][15], char gioiTinh[MAX][5], char email[MAX][100], char diaChi[MAX][100], char ngayLapThe[MAX][15], char ngayHetHan[MAX][15], int& soDocGia) {
	char maDocGiaCanXoa[20];
	printf("Nhap ma doc gia can xoa: ");
	scanf_s(" %s", maDocGiaCanXoa, 20);
	maDocGiaCanXoa[19] = '\0';
	xoaBuffer();

	for (int i = 0; i < soDocGia; i++) {
		if (strcmp(maDocGiaCanXoa, maDocGia[i]) == 0) {
			char tenDocGiaXoa[100];
			strcpy_s(tenDocGiaXoa, hoTen[i]);
			printf("\nBan co chac muon xoa doc gia [%s - %s]? (Y/N): ", maDocGiaCanXoa, tenDocGiaXoa);
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
				for (int j = i; j < soDocGia - 1; j++) {
					strcpy_s(maDocGia[j], maDocGia[j + 1]);
					strcpy_s(hoTen[j], hoTen[j + 1]);
					strcpy_s(CMND[j], CMND[j + 1]);
					strcpy_s(ngaySinh[j], ngaySinh[j + 1]);
					strcpy_s(gioiTinh[j], gioiTinh[j + 1]);
					strcpy_s(email[j], email[j + 1]);
					strcpy_s(diaChi[j], diaChi[j + 1]);
					strcpy_s(ngayLapThe[j], ngayLapThe[j + 1]);
					strcpy_s(ngayHetHan[j], ngayHetHan[j + 1]);
				}

				soDocGia--;
				printf("\nXoa thanh cong doc gia [%s - %s]\n\n", maDocGiaCanXoa, tenDocGiaXoa);
				return;
			}
			else {
				printf("\n");
				return;
			}
		}
	}

	printf("\nMa doc gia khong hop le.\n\n");
}

/*
* Ham timKiemDocGiaCMND dung de tim kiem doc gia trong danh sach theo CMND
* Ham yeu cau nguoi dung nhap CMND can tim, sau do in ra thong tin doc gia co CMND tuong ung.
*/
void timKiemDocGiaCMND(char maDocGia[MAX][20], char hoTen[MAX][100], char CMND[MAX][15], char ngaySinh[MAX][15], char gioiTinh[MAX][5], char email[MAX][100], char diaChi[MAX][100], char ngayLapThe[MAX][15], char ngayHetHan[MAX][15], int soDocGia) {
	char CMNDCanTim[15];
	printf("Nhap CMND can tim: ");
	scanf_s(" %s", &CMNDCanTim, 15);
	CMNDCanTim[14] = '\0';

	for (int i = 0; i < soDocGia; i++) {
		if (strcmp(CMND[i], CMNDCanTim) == 0) {
			printf("\n");
			printf("Ma Doc Gia: \t\t%s\n", maDocGia[i]);
			printf("Ho Ten: \t\t%s\n", hoTen[i]);
			printf("CMND: \t\t\t%s\n", CMND[i]);
			printf("Ngay Thang Nam Sinh: \t%s\n", ngaySinh[i]);
			printf("Gioi Tinh: \t\t%s\n", gioiTinh[i]);
			printf("Email: \t\t\t%s\n", email[i]);
			printf("Dia Chi: \t\t%s\n", diaChi[i]);
			printf("Ngay Lap The: \t\t%s\n", ngayLapThe[i]);
			printf("Ngay Het Han The: \t%s\n\n", ngayHetHan[i]);
			return;
		}
	}

	printf("\nCMND khong hop le.\n\n");
}

/*
* Ham timKiemDocGiaTheoHoTen dung de tim kiem doc gia trong danh sach theo ho ten
* Ham yeu cau nguoi dung nhap ho ten can tim, sau do in ra thong tin doc gia co ho ten tuong ung
*/
void timKiemDocGiaTheoHoTen(char maDocGia[MAX][20], char hoTen[MAX][100], char CMND[MAX][15], char ngaySinh[MAX][15], char gioiTinh[MAX][5], char email[MAX][100], char diaChi[MAX][100], char ngayLapThe[MAX][15], char ngayHetHan[MAX][15], int soDocGia) {
	char hoTenDocGiaCanTim[100];
	printf("Nhap ho ten doc gia can tim: ");
	xoaBuffer();
	gets_s(hoTenDocGiaCanTim, 100);
	hoTenDocGiaCanTim[99] = '\0';
	_strlwr_s(hoTenDocGiaCanTim);

	for (int i = 0; i < soDocGia; i++) {
		char hoTenTam[100];
		strcpy_s(hoTenTam, hoTen[i]);
		_strlwr_s(hoTenTam);

		if (strcmp(hoTenTam, hoTenDocGiaCanTim) == 0) {
			printf("\n");
			printf("Ma Doc Gia: \t\t%s\n", maDocGia[i]);
			printf("Ho Ten: \t\t%s\n", hoTen[i]);
			printf("CMND: \t\t\t%s\n", CMND[i]);
			printf("Ngay Thang Nam Sinh: \t%s\n", ngaySinh[i]);
			printf("Gioi Tinh: \t\t%s\n", gioiTinh[i]);
			printf("Email: \t\t\t%s\n", email[i]);
			printf("Dia Chi: \t\t%s\n", diaChi[i]);
			printf("Ngay Lap The: \t\t%s\n", ngayLapThe[i]);
			printf("Ngay Het Han The: \t%s\n\n", ngayHetHan[i]);
			return;
		}
	}

	printf("\Ho ten khong hop le.\n\n");
}

/*
 * Ham chucNangDocGia dung de thuc hien cac chuc nang lien quan den doc gia. 
 * Ham hien thi menu chuc nang va yeu cau nguoi dung chon chuc nang can thuc hien.
 * Cac chuc nang bao gom: xem danh sach doc gia, them doc gia, sua thong tin doc gia, xoa thong tin doc gia, tim kiem doc gia theo CMND, tim kiem doc gia theo ho ten.
 */
void chucNangDocGia(char maDocGia[MAX][20], char hoTen[MAX][100], char CMND[MAX][15], char ngaySinh[MAX][15], char gioiTinh[MAX][5], char email[MAX][100], char diaChi[MAX][100], char ngayLapThe[MAX][15], char ngayHetHan[MAX][15], int& soDocGia) {
	char tiepTuc, choice_kyTu;
	int back = 1;

	do {
		printMenu_DocGia();
		printf("Tiep tuc (Y/N): ");
		scanf_s(" %c", &tiepTuc, 1);

		if (tiepTuc == 'n' || tiepTuc == 'N') {
			xoaManHinh(0);
			return;
		}

		if (tiepTuc == 'y' || tiepTuc == 'Y') {
			printf("\nChon chuc nang: ");
			scanf_s(" %c", &choice_kyTu, 1);
			xoaManHinh(5);

			switch (choice_kyTu) {
			case 'a':
			case 'A':
				inDanhSachDocGia(maDocGia, hoTen, CMND, ngaySinh, gioiTinh, email, diaChi, ngayLapThe, ngayHetHan, soDocGia);
				break;
			case 'b':
			case 'B':
				themDocGia(maDocGia, hoTen, CMND, ngaySinh, gioiTinh, email, diaChi, ngayLapThe, ngayHetHan, soDocGia);
				break;
			case 'c':
			case 'C':
				suaThongTinDocGia(maDocGia, hoTen, CMND, ngaySinh, gioiTinh, email, diaChi, ngayLapThe, ngayHetHan, soDocGia);
				break;
			case 'd':
			case 'D':
				xoaThongTinDocGia(maDocGia, hoTen, CMND, ngaySinh, gioiTinh, email, diaChi, ngayLapThe, ngayHetHan, soDocGia);
				break;
			case 'e':
			case 'E':
				timKiemDocGiaCMND(maDocGia, hoTen, CMND, ngaySinh, gioiTinh, email, diaChi, ngayLapThe, ngayHetHan, soDocGia);
				break;
			case 'f':
			case 'F':
				timKiemDocGiaTheoHoTen(maDocGia, hoTen, CMND, ngaySinh, gioiTinh, email, diaChi, ngayLapThe, ngayHetHan, soDocGia);
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