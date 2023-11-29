#pragma once
#include "Nguoi.h"
#define MAX 100
class Truong
{
	int n;
	Nguoi* arrThanhVien[MAX];
public:
	Truong();
	~Truong();
	void NhapThongTinTruong();
	void XuatThongTinTruong();
	void XuatHocSinhXepLoaiKha();
	void XuatHocSinhXepLoaiGioi();

	void XuatThanhVienLonTuoiNhat();
	void XuatGiaoVienThamNienTren5Nam();
	void XuatGiaoVienThamNienTren10Nam_CMToan_Ly();
};