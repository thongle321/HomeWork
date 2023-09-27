class DonThuc
{
private:
	float a;
	float b;
public:
	void SetHeSoA(int A);
	void SetHeSoB(int B);
	int GetHeSoA();
	int GetHeSoB();
	void NhapDonThuc();
	void XuatDonThuc();
	DonThuc Tong(DonThuc A, DonThuc B);
	DonThuc Hieu(DonThuc A, DonThuc B);
	float fx(DonThuc A, DonThuc B);
};
