#define MAX 50
#define TIEN_PHAT_QUA_HAN 5000
#define TIEN_PHAT_MAT_SACH 2

void taoMaDocGia(char ngaySinh[15], int soDocGia, char maDocGia[20]);
void tinhNgayHetHanThe(char ngayLapThe[15], char ngayHetHanThe[15]);
void khoiTaoThongTinDocGia(char maDocGia[MAX][20], char hoTen[MAX][100], char CMND[MAX][15], char ngaySinh[MAX][15], char gioiTinh[MAX][5], char email[MAX][100], char diaChi[MAX][100], char ngayLapThe[MAX][15], char ngayHetHan[MAX][15], int& soDocGia);
void inDanhSachDocGia(char maDocGia[MAX][20], char hoTen[MAX][100], char CMND[MAX][15], char ngaySinh[MAX][15], char gioiTinh[MAX][5], char email[MAX][100], char diaChi[MAX][100], char ngayLapThe[MAX][15], char ngayHetHan[MAX][15], int soDocGia);
void chucNangDocGia(char maDocGia[MAX][20], char hoTen[MAX][100], char CMND[MAX][15], char ngaySinh[MAX][15], char gioiTinh[MAX][5], char email[MAX][100], char diaChi[MAX][100], char ngayLapThe[MAX][15], char ngayHetHan[MAX][15], int& soDocGia);
void khoiTaoThongTinSach(char ISBN[MAX][15], char tenSach[MAX][100], char tacGia[MAX][100], char nhaXuatBan[MAX][100], char namXuatBan[MAX][5], char theLoai[MAX][100], char giaSach[MAX][30], char soQuyenSach[MAX][10], int& soSach);
void chucNangSach(char ISBN[MAX][15], char tenSach[MAX][100], char tacGia[MAX][100], char nhaXuatBan[MAX][100], char namXuatBan[MAX][5], char theLoai[MAX][100], char giaSach[MAX][30], char soQuyenSach[MAX][10], int& soSach);
void printMenu_Main();
void printMenu_DocGia();
void printMenu_Sach();
void printMenu_PhieuMuon();
void printMenu_ThongKe();
void printTitle();
void xoaManHinh(int viTriBatDauXoa);
void xoaBuffer();
void layNgayThangNam(char ngayMuon[15]);
void tinhNgayTraDuKien(char ngayMuon[15], char ngayTraDuKien[15]);
void lapPhieuMuonSach(int soDocGia, int soSach, char maDocGia[MAX][20], char ISBN[MAX][15], char soQuyenSach[MAX][10], char maPhieuMuon[MAX][15], char maDocGiaMuonSach[MAX][20], char ngayMuon[MAX][15], char ngayTraDuKien[MAX][15], char ISBNMuon[MAX][100], char soSachMuon[MAX][10], int& soPhieuMuon, char ngayTraThucTe[MAX][15], char ngayHetHan[MAX][15]);
void inPhieuMuonSach(char maPhieuMuon[MAX][15], char maDocGiaMuonSach[MAX][20], char ngayMuon[MAX][15], char ngayTraDuKien[MAX][15], char ISBNMuon[MAX][100], char soSachMuon[MAX][10], int soPhieuMuon, char ngayTraThucTe[MAX][15]);
void chucNangPhieuMuon(int soDocGia, int soSach, char maDocGia[MAX][20], char ISBN[MAX][15], char soQuyenSach[MAX][10], char maPhieuMuon[MAX][15], char maDocGiaMuonSach[MAX][20], char ngayMuon[MAX][15], char ngayTraDuKien[MAX][15], char ISBNMuon[MAX][100], char soSachMuon[MAX][10], int& soPhieuMuon, char ngayTraThucTe[MAX][15], char ngayHetHan[MAX][15]);
void lapPhieuTraSach(int soPhieuMuon, char maPhieuMuon[MAX][15], char ngayTraDuKien[MAX][15], char soSachMuon[MAX][10], char ISBN[MAX][15], char giaSach[MAX][30], char tenSach[MAX][100], int soSach, char maPhieuTra[MAX][15], char ngayTraThucTe[MAX][15], int& soPhieuTra, char maDocGiaMuonSach[MAX][20], char ngayMuon[MAX][15], char ISBNMuon[MAX][100]);
void chucNangThongKe(int soSach, char tenSach[MAX][100], char soQuyenSach[MAX][10], char theLoai[MAX][100], int soDocGia, char gioiTinh[MAX][5], int soPhieuMuon, char ngayTraThucTe[MAX][15], char ISBNMuon[MAX][100], char ISBN[MAX][15], char ngayTraDuKien[MAX][15], char maDocGiaMuonSach[MAX][20], char maDocGia[MAX][20], char hoTen[MAX][100], char maPhieuMuon[MAX][15]);
int tinhSoNgay(char ngayDuKien[15], char ngayThucTe[15]);
