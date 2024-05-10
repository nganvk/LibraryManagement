#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "Function.h"

/*
* Hàm xoaBuffer dung de xoa bo dem dau vao, de loai bo tat ca cac ky tu con lai trong bo dem dau vao, bao gom ky tu xuong dong \n
*/
void xoaBuffer() {
	while (getc(stdin) != '\n');
}

/*
* Hàm xoaManHinh dung de xoa noi dung tren man hinh console tu mot vi tri nhat dinh.
* @param viTriBatDauXoa: so nguyen chi vi tri bat dau xoa tren man hinh console.
*/
void xoaManHinh(int viTriBatDauXoa) {
	printf("\033[%d;1H\033[0J", viTriBatDauXoa);
}

