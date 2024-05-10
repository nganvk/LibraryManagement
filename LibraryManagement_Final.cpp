#include "Function.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
	int soDocGia = 0;
	char maDocGia[MAX][20];
	char hoTen[MAX][100];
	char CMND[MAX][15];
	char ngaySinh[MAX][15];
	char gioiTinh[MAX][5];
	char email[MAX][100];
	char diaChi[MAX][100];
	char ngayLapThe[MAX][15];
	char ngayHetHan[MAX][15];

	int soSach = 0;
	char ISBN[MAX][15];
	char tenSach[MAX][100];
	char tacGia[MAX][100];
	char nhaXuatBan[MAX][100];
	char namXuatBan[MAX][5];
	char theLoai[MAX][100];
	char giaSach[MAX][30];
	char soQuyenSach[MAX][10];

	int soPhieuMuon = 0;
	char maPhieuMuon[MAX][15];
	char maDocGiaMuonSach[MAX][20];
	char ngayMuon[MAX][15];
	char ngayTraDuKien[MAX][15];
	char ISBNMuon[MAX][100];
	char soSachMuon[MAX][10];

	int soPhieuTra = 0;
	char maPhieuTra[MAX][15];
	char ngayTraThucTe[MAX][15];

	khoiTaoThongTinDocGia(maDocGia, hoTen, CMND, ngaySinh, gioiTinh, email, diaChi, ngayLapThe, ngayHetHan, soDocGia);
	khoiTaoThongTinSach(ISBN, tenSach, tacGia, nhaXuatBan, namXuatBan, theLoai, giaSach, soQuyenSach, soSach);

	int choice;
	printTitle();

	do {
		printMenu_Main();
		printf("Chon chuc nang: ");
		scanf_s("%d", &choice);
		xoaBuffer();
		xoaManHinh(3);

		switch (choice) {
		case 1:
			chucNangDocGia(maDocGia, hoTen, CMND, ngaySinh, gioiTinh, email, diaChi, ngayLapThe, ngayHetHan, soDocGia);
			printTitle();
			choice = 0;
			break;
		case 2:
			chucNangSach(ISBN, tenSach, tacGia, nhaXuatBan, namXuatBan, theLoai, giaSach, soQuyenSach, soSach);
			printTitle();
			choice = 0;
			break;
		case 3:
			chucNangPhieuMuon(soDocGia, soSach, maDocGia, ISBN, soQuyenSach, maPhieuMuon, maDocGiaMuonSach, ngayMuon, ngayTraDuKien, ISBNMuon, soSachMuon, soPhieuMuon, ngayTraThucTe, ngayHetHan);
			printTitle();
			choice = 0;
			break;
		case 4:
			printf("4. Lap phieu tra sach\n\n");
			lapPhieuTraSach(soPhieuMuon, maPhieuMuon, ngayTraDuKien, soSachMuon, ISBN, giaSach, tenSach, soSach, maPhieuTra, ngayTraThucTe, soPhieuTra, maDocGiaMuonSach, ngayMuon, ISBNMuon);
			printTitle();
			choice = 0;
			break;
		case 5:
			chucNangThongKe(soSach, tenSach, soQuyenSach, theLoai, soDocGia, gioiTinh, soPhieuMuon, ngayTraThucTe, ISBNMuon, ISBN, ngayTraDuKien, maDocGiaMuonSach, maDocGia, hoTen, maPhieuMuon);
			printTitle();
			choice = 0;
			break;
		default:
			xoaManHinh(3);
			printf("Lua chon khong hop le. Vui long nhap so tuong ung chuc nang can chon.\n\n");
		}
	} while (choice < 1 || choice > 5);
}

    

