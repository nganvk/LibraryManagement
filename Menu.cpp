#include <stdio.h>

/*
* Ham printTitle dung de in ra tieu de chuong trinh
*/
void printTitle() {
	printf("---------* QUAN LY THU VIEN *---------\n\n");
}

/*
* Ham printMenu_Main dung de in ra menu chinh cua chuong trinh
*/
void printMenu_Main() {
	printf("1. Quan Ly Doc Gia\n");
	printf("2. Quan Ly Sach\n");
	printf("3. Lap Phieu Muon Sach\n");
	printf("4. Lap Phieu Tra Sach\n");
	printf("5. Cac Thong Ke Co Ban\n\n");
}

/*
* Ham printMenu_DocGia dung de in ra menu quan ly doc gia.
*/
void printMenu_DocGia() {
	printf("1. Quan Ly Doc Gia\n\n");
	printf("a. Xem danh sach doc gia trong thu vien\n");
	printf("b. Them doc gia\n");
	printf("c. Chinh sua thong tin mot doc gia\n");
	printf("d. Xoa thong tin mot doc gia\n");
	printf("e. Tim kiem doc gia theo CMND\n");
	printf("f. Tim kiem doc gia theo ho ten\n\n");
}

/*
* Ham printMenu_Sach dung de in ra menu quan ly sach.
*/
void printMenu_Sach() {
	printf("2. Quan Ly Sach\n\n");
	printf("a. Xem danh sach cac sach trong thu vien\n");
	printf("b. Them sach\n");
	printf("c. Chinh sua thong tin mot quyen sach\n");
	printf("d. Xoa thong tin sach\n");
	printf("e. Tim kiem sach theo ISBN\n");
	printf("f. Tim kiem sach theo ten sach\n\n");
}

/*
* Ham printMenu_PhieuMuon dung de in ra menu quan ly phieu muon sach.
*/
void printMenu_PhieuMuon() {
	printf("3. Quan Ly Phieu Muon Sach\n\n");
	printf("a. Lap phieu muon sach\n");
	printf("b. Xem danh sach phieu muon\n\n");
}

void printMenu_ThongKe() {
	printf("5. Cac Thong Ke Co Ban\n\n");
	printf("a. Thong ke so luong sach trong thu vien\n");
	printf("b. Thong ke so luong sach theo the loai\n");
	printf("c. Thong ke so luong doc gia\n");
	printf("d. Thong ke so luong doc gia theo gioi tinh\n");
	printf("e. Thong ke so sach dang duoc muon\n");
	printf("f. Thong ke danh sach doc gia bi tre han\n\n");
}

