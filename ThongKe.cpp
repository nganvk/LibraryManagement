#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Function.h"

void sachTrongThuVien(int soSach, char tenSach[MAX][100], char soQuyenSach[MAX][10]) {
	printf("| %-6s | %-45s | %-16s \n", "STT", "Ten sach", "So luong");
	printf("--------------------------------------------------------------------\n");

	for (int i = 0; i < soSach; i++) {
		printf("| %-6d | %-45s | %-16s \n", i + 1, tenSach[i], soQuyenSach[i]);
	}

	printf("\n");
}

void sachTheoTheLoai(int soSach, char theLoai[MAX][100]) {
	printf("| %-6s | %-34s | %-34s \n", "STT", "The loai", "So luong dau sach");
	printf("--------------------------------------------------------------------\n");
	char danhSachTheLoai[MAX][100];
	int soLuongTheoTheLoai[MAX] = { 0 };
	int j = 0;

	for (int i = 0; i < soSach; i++) {
		int daDem = 0;

		for (int k = 0; k < j; k++) {
			if (strcmp(theLoai[i], danhSachTheLoai[k]) == 0) {
				soLuongTheoTheLoai[k]++;
				daDem = 1;
				break;
			}
		}

		if (!daDem) {
			strcpy_s(danhSachTheLoai[j], theLoai[i]);
			soLuongTheoTheLoai[j] = 1;
			j++;
		}
	}

	for (int i = 0; i < j; i++) {
		printf("| %-6d | %-34s | %-34d \n", i + 1, danhSachTheLoai[i], soLuongTheoTheLoai[i]);
	}

	printf("\n");
}

void docGia(int soDocGia) {
	printf("So luong doc gia: %d\n\n", soDocGia);
}

void docGiaTheoGioiTinh(int soDocGia, char gioiTinh[MAX][5]) {
	printf("| %-6s | %-18s | %-16s \n", "STT", "Gioi tinh", "So luong");
	printf("-------------------------------------------------------\n");
	char danhSachGioiTinh[MAX][5];
	int soLuongTheoGioiTinh[MAX] = { 0 };
	int j = 0;

	for (int i = 0; i < soDocGia; i++) {
		int daDem = 0;

		for (int k = 0; k < j; k++) {
			if (strcmp(gioiTinh[i], danhSachGioiTinh[k]) == 0) {
				soLuongTheoGioiTinh[k]++;
				daDem = 1;
				break;
			}
		}

		if (!daDem) {
			strcpy_s(danhSachGioiTinh[j], gioiTinh[i]);
			soLuongTheoGioiTinh[j] = 1;
			j++;
		}
	}

	for (int i = 0; i < j; i++) {
		printf("| %-6d | %-18s | %-16d \n", i + 1, danhSachGioiTinh[i], soLuongTheoGioiTinh[i]);
	}

	printf("\n");
}

void sachDangDuocMuon(int soPhieuMuon, char ngayTraThucTe[MAX][15], char ISBNMuon[MAX][100], int soSach, char ISBN[MAX][15], char tenSach[MAX][100]) {
	printf("| %-6s | %-26s | %-45s | %-16s \n", "STT", "ISBN", "Ten sach", "So luong dang muon");
	printf("--------------------------------------------------------------------------------------------------------------\n");
	int m = 0;
	int soLuongTungISBNDangMuon[MAX] = { 0 };
	char ISBNDangMuon[MAX][15];

	for (int i = 0; i < soPhieuMuon; i++) {
		if (ngayTraThucTe[i][0] == '\0') {
			char tachISBN[100];
			int k = 0;
			
			for (int j = 0; j <= strlen(ISBNMuon[i]); j++) {

				if (ISBNMuon[i][j] != ',' && ISBNMuon[i][j] != '\0') {
					tachISBN[k] = ISBNMuon[i][j];
					k++;
				}
				else {
					tachISBN[k] = '\0';
					int daDem = 0;

					for (int i = 0; i < m; i++) {
						if (strcmp(ISBNDangMuon[i], tachISBN) == 0) {
							soLuongTungISBNDangMuon[i]++;
							daDem = 1;
							break;
						}
					}

					if (!daDem) {
						strcpy_s(ISBNDangMuon[m], tachISBN);
						soLuongTungISBNDangMuon[m] = 1;
						m++;
					}

					k = 0;
				}
			}
		}
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < soSach; j++) {
			if (strcmp(ISBNDangMuon[i], ISBN[j]) == 0) {
				printf("| %-6d | %-26s | %-45s | %-16d \n", i + 1, ISBN[j], tenSach[j], soLuongTungISBNDangMuon[i]);
				break;
			}
		}
	}

	printf("\n");
}

void danhSachDocGiaTreHan(int soPhieuMuon, char ngayTraThucTe[MAX][15], char ngayTraDuKien[MAX][15], char maDocGiaMuonSach[MAX][20], int soDocGia, char maDocGia[MAX][20], char hoTen[MAX][100], char maPhieuMuon[MAX][15]) {
	printf("| %-6s | %-16s | %-18s | %-22s | %-24s \n", "STT", "Ma doc gia", "Ten doc gia", "Ma phieu muon", "So ngay tre han");
	printf("---------------------------------------------------------------------------------------------------------------\n");
	int stt = 1;

	for (int i = 0; i < soPhieuMuon; i++) {
		if (ngayTraThucTe[i][0] != '\0') {
			int soNgayTre = tinhSoNgay(ngayTraDuKien[i], ngayTraThucTe[i]);
			
			if (soNgayTre > 0) {
				char tenDocGiaTreHan[100];

				for (int j = 0; j < soDocGia; j++) {
					if (strcmp(maDocGia[j], maDocGiaMuonSach[i]) == 0) {
						strcpy_s(tenDocGiaTreHan, hoTen[j]);
					}
				}

				printf("| %-6d | %-16s | %-18s | %-22s | %-24d \n", stt, maDocGiaMuonSach[i], tenDocGiaTreHan, maPhieuMuon[i], soNgayTre);
				stt++;
			}
		}
	}

	printf("\n");
}

void chucNangThongKe(int soSach, char tenSach[MAX][100], char soQuyenSach[MAX][10], char theLoai[MAX][100], int soDocGia, char gioiTinh[MAX][5], int soPhieuMuon, char ngayTraThucTe[MAX][15], char ISBNMuon[MAX][100], char ISBN[MAX][15], char ngayTraDuKien[MAX][15], char maDocGiaMuonSach[MAX][20], char maDocGia[MAX][20], char hoTen[MAX][100], char maPhieuMuon[MAX][15]) {
	char tiepTuc, choice_kyTu;
	int back = 1;

	do {
		printMenu_ThongKe();
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
				printf("a. Thong ke so luong sach trong thu vien\n\n");
				sachTrongThuVien(soSach, tenSach, soQuyenSach);
				break;
			case 'b':
			case 'B':
				printf("b. Thong ke so luong sach theo the loai\n\n");
				sachTheoTheLoai(soSach, theLoai);
				break;
			case 'c':
			case 'C':
				printf("c. Thong ke so luong doc gia\n\n");
				docGia(soDocGia);
				break;
			case 'd':
			case 'D':
				printf("d. Thong ke so luong doc gia theo gioi tinh\n\n");
				docGiaTheoGioiTinh(soDocGia, gioiTinh);
				break;
			case 'e':
			case 'E':
				printf("e. Thong ke so sach dang duoc muon\n\n");
				sachDangDuocMuon(soPhieuMuon, ngayTraThucTe, ISBNMuon, soSach, ISBN, tenSach);
				break;
			case 'f':
			case 'F':
				printf("f. Thong ke danh sach doc gia bi tre han\n\n");
				danhSachDocGiaTreHan(soPhieuMuon, ngayTraThucTe, ngayTraDuKien, maDocGiaMuonSach, soDocGia, maDocGia, hoTen, maPhieuMuon);
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