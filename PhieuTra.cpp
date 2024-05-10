#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include "Function.h"

/* 
* Ham layNgayThangNam dung de lay ngay, thang, nam hien tai tu he thong. 
* Ham se lay ngay, thang, nam hien tai tu he thong, sau do chuyen doi thang tu dang chuoi sang dang so va luu vao ngayTra.
* @param ngayTra: Chuoi ky tu se chua ngay, thang, nam hien tai sau khi ham thuc thi, dinh dang ngay/thang/nam.
* Ket qua cua ham se duoc luu vao tham so ngayTra.
*/
void layNgayThangNam(char ngayTra[15]) {
	int ngay, nam, thangSo = 0;
	char thang[5];
	sscanf_s(__DATE__, "%s %d %d", thang, 5, &ngay, &nam);
	thang[4] = '\0';
	char tenThang[15][5] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };

	for (int i = 0; i < 12; i++) {
		if (strcmp(thang, tenThang[i]) == 0) {
			thangSo = i + 1;
			break;
		}
	}

	sprintf_s(ngayTra, 15, "%02d/%02d/%d", ngay, thangSo, nam);
}

/*
* Ham tinhSoNgay dung de tinh so ngay giua hai ngay du kien va thuc te.
* @param ngayDuKien: Chuoi ky tu luu tru ngay du kien, dinh dang ngay/thang/nam.
* @param ngayThucTe: Chuoi ky tu luu tru ngay thuc te, dinh dang ngay/thang/nam.
* Ham co gia tri tra ve la so ngay giua ngay du kien va ngay thuc te.
*/
int tinhSoNgay(char ngayDuKien[15], char ngayThucTe[15]) {
	int duKien_ngay, duKien_thang, duKien_nam;
	int thucTe_ngay, thucTe_thang, thucTe_nam;
	int soNgay = 0, soThang = 0, soNam = 0;
	int ngayTrongThang_namThuong[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int ngayTrongThang_namNhuan[12] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	sscanf_s(ngayDuKien, "%d/%d/%d", &duKien_ngay, &duKien_thang, &duKien_nam);
	sscanf_s(ngayThucTe, "%d/%d/%d", &thucTe_ngay, &thucTe_thang, &thucTe_nam);

	if ((duKien_thang == thucTe_thang) && (duKien_nam == thucTe_nam)) {
		soNgay = (thucTe_ngay - duKien_ngay);
	}
	else if (duKien_nam == thucTe_nam) {
		soThang = abs(thucTe_thang - duKien_thang);

		if (duKien_nam % 4 != 0) {
			soNgay = ngayTrongThang_namThuong[duKien_thang - 1] - duKien_ngay;

			while (soThang > 1) {
				soNgay = soNgay + ngayTrongThang_namThuong[duKien_thang];
				soThang--;
			}

			soNgay = soNgay + thucTe_ngay;
		}
		else {
			soNgay = ngayTrongThang_namNhuan[duKien_thang - 1] - duKien_ngay;

			while (soThang > 1) {
				soNgay = soNgay + ngayTrongThang_namNhuan[duKien_thang];
				soThang--;
			}

			soNgay = soNgay + thucTe_ngay;
		}
	}
	else {
		soNam = (thucTe_nam - duKien_nam);

		if (duKien_nam % 4 != 0) {
			soNgay = ngayTrongThang_namThuong[duKien_thang - 1] - duKien_ngay;
		}
		else {
			soNgay = ngayTrongThang_namNhuan[duKien_thang - 1] - duKien_ngay;
		}

		for (int i = duKien_thang; i < 12; i++) {
			if (duKien_nam % 4 != 0) {
				soNgay = soNgay + ngayTrongThang_namThuong[i];
			}
			else {
				soNgay = soNgay + ngayTrongThang_namNhuan[i];
			}
		}

		while (soNam > 1) {
			if (((duKien_nam + 1) % 4) != 0) {
				soNgay = soNgay + 365;
			}
			else {
				soNgay = soNgay + 366;
			}
		}

		for (int i = 0; i < thucTe_thang - 1; i++) {
			if (thucTe_nam % 4 != 0) {
				soNgay = soNgay + ngayTrongThang_namThuong[i];
			}
			else {
				soNgay = soNgay + ngayTrongThang_namNhuan[i];
			}
		}

		soNgay = soNgay + thucTe_ngay;
	}

	return soNgay;
}

/*
* Ham chuyenDoiSoTien dung de chuyen doi chuoi ky tu luu tru so tien thanh so nguyen. 
* Ham se loai bo dau cham trong chuoi so tien, sau do chuyen doi chuoi ky tu thanh so nguyen.
* @param soTien: Chuoi ky tu luu tru so tien can chuyen doi.
* Ham co gia tri tra ve la so nguyen tuong ung voi so tien sau khi da chuyen doi.
*/
int chuyenDoiSoTien(char soTien[30]) {
	char chuoiSoTien[30];
	chuoiSoTien[29] = '\0';
	int j = 0;
	double gia;

	for (int i = 0; i < strlen(soTien); i++) {
		if (soTien[i] != '.') {
			chuoiSoTien[j] = soTien[i];
			j++;
		}
	}

	gia = atof(chuoiSoTien);
	return gia;
}

/*
* Ham lapPhieuTraSach dung de lap phieu tra sach cho doc gia. 
* Ham se yeu cau nguoi dung nhap ma phieu muon can tra, sau do yeu cau nguoi dung nhap thong tin sach tra va luu vao phieu tra.
* @param soPhieuMuon: So nguyen luu tru so luong phieu muon hien tai.
* @param maPhieuMuon: chuoi ky tu luu tru ma phieu muon.
* @param ngayTraDuKien: chuoi ky tu luu tru ngay tra du kien, dinh dang ngay/thang/nam.
* @param soSachMuon: chuoi ky tu luu tru so sach muon.
* @param ISBN: chuoi ky tu luu tru ma ISBN cua sach.
* @param giaSach: chuoi ky tu luu tru gia sach.
* @param tenSach: chuoi ky tu luu tru ten sach.
* @param soSach: so nguyen chua so luong sach hien tai.
* @param maPhieuTra: chuoi ky tu luu tru ma phieu tra.
* @param ngayTraThucTe: chuoi ky tu luu tru ngay tra thuc te, dinh dang ngay/thang/nam.
* @param soPhieuTra: so nguyen chua so luong phieu tra hien tai.
*/
void lapPhieuTraSach(int soPhieuMuon, char maPhieuMuon[MAX][15], char ngayTraDuKien[MAX][15], char soSachMuon[MAX][10], char ISBN[MAX][15], char giaSach[MAX][30], char tenSach[MAX][100], int soSach, char maPhieuTra[MAX][15], char ngayTraThucTe[MAX][15], int& soPhieuTra, char maDocGiaMuonSach[MAX][20], char ngayMuon[MAX][15], char ISBNMuon[MAX][100]) {
	char maPhieuMuonCanTra[15];
	char ISBNSachMat[15];
	int soNgayMuon;
	int soTienPhatQuaHan = 0;
	int soTienPhatMatSach = 0;
	int soSachDaMuon;
	int soSachMat;
	int gia;
	int sachMat = 1;
	int back = 1;

	printf("Nhap phieu muon sach: ");
	scanf_s(" %s", maPhieuMuonCanTra, 15);
	maPhieuMuonCanTra[14] = '\0';

	for (int i = 0; i < soPhieuMuon; i++) {
		if (strcmp(maPhieuMuon[i], maPhieuMuonCanTra) == 0) {
			printf("\nMa phieu muon: \t\t%s\n", maPhieuMuon[i]);
			printf("Ma doc gia muon sach: \t%s\n", maDocGiaMuonSach[i]);
			printf("Ngay muon: \t\t%s\n", ngayMuon[i]);
			printf("Ngay tra du kien: \t%s\n", ngayTraDuKien[i]);
			printf("Ngay tra thuc te: \t%s\n", ngayTraThucTe[i]);
			printf("So sach muon: \t\t%s\n", soSachMuon[i]);
			printf("ISBN: \t\t\t%s\n", ISBNMuon[i]);
			strcpy_s(maPhieuTra[soPhieuTra], maPhieuMuon[i]);
			layNgayThangNam(ngayTraThucTe[i]);
			soNgayMuon = tinhSoNgay(ngayTraDuKien[i], ngayTraThucTe[i]);
			if (soNgayMuon > 0) soTienPhatQuaHan = TIEN_PHAT_QUA_HAN * soNgayMuon;
			sscanf_s(soSachMuon[i], "%d", &soSachDaMuon);
			printf("\nNhap so luong sach bi mat (0 - %d): ", soSachDaMuon);
			scanf_s(" %d", &soSachMat);

			while (soSachMat > 0) {
				int soTienPhatMatSach_Tam = 0;
				printf("\nNhap ISBN sach mat %d: ", sachMat);
				scanf_s(" %s", ISBNSachMat, 15);
				ISBNSachMat[14] = '\0';

				for (int i = 0; i < soSach; i++) {
					if (strcmp(ISBN[i], ISBNSachMat) == 0) {
						printf("\nTen sach: \t\t%s\n", tenSach[i]);
						printf("Gia sach: \t\t%s\n", giaSach[i]);
						gia = chuyenDoiSoTien(giaSach[i]);
						soTienPhatMatSach_Tam = TIEN_PHAT_MAT_SACH * gia;
						printf("Phat mat sach: \t\t%d.%03d\n", soTienPhatMatSach_Tam / 1000, soTienPhatMatSach_Tam % 1000);
					}
				}

				soTienPhatMatSach = soTienPhatMatSach + soTienPhatMatSach_Tam;
				sachMat++;
				soSachMat--;
			}

			if (soNgayMuon <= 0) {
				printf("\nSo ngay qua han: \t%d\n", 0);
			}
			else {
				printf("\nSo ngay qua han: \t%d\n", soNgayMuon);
			}

			printf("Phat qua han: \t\t%d.%03d\n", soTienPhatQuaHan / 1000, soTienPhatQuaHan % 1000);
			int tongSoTienPhat = soTienPhatQuaHan + soTienPhatMatSach;
			printf("----------------------------------------------------\n");
			printf("Tong so tien phat: \t%d.%03d\n\n", tongSoTienPhat / 1000, tongSoTienPhat % 1000);
			soPhieuTra++;
			printf("Lap phieu tra sach thanh cong!\n\n");
			break;
		}
	}

	printf("Tro ve truoc, bam '1'\n");
	printf("Thoat chuong trinh, bam '0'\n");
	scanf_s(" %d", &back);

	if (back == 1) {
		system("cls");
		return;
	}
	else exit(0);
}