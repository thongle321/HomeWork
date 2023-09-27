class PhanSo
{
private:
	int tuso;
	int mauso;
	int UCLN(int a, int b);
public:
	void SetTuSo(int TuSo);
	void SetMauSo(int MauSo);
	int GetTuSo();
	int GetMauSo();
	void NhapPhanSo();
	void XuatPhanSo();
	PhanSo TinhTong(PhanSo A, PhanSo B);
	PhanSo TinhHieu(PhanSo A, PhanSo B);
	PhanSo TinhTich(PhanSo A, PhanSo B);
	PhanSo TinhThuong(PhanSo A, PhanSo B);
	PhanSo RutGon();
	int SoSanh(PhanSo A, PhanSo B);
};