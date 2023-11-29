#include <iostream>
#include "Truong.h"
#include <string>
using namespace std;
void main()
{
	Truong*tr = new Truong();
	tr->NhapThongTinTruong();
	tr->XuatThongTinTruong();
	tr->XuatHocSinhXepLoaiKha();
	tr->XuatHocSinhXepLoaiGioi();
	tr->XuatThanhVienLonTuoiNhat();
	tr->XuatGiaoVienThamNienTren5Nam();
	//tr->XuatGiaoVienThamNienTren10Nam_CMToan_Ly();

}