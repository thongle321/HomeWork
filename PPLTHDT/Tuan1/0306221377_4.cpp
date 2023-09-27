// Viết chương trình nhập vào một ngày (ngày, tháng, năm). Hãy cho biết ngày tiếp theo (ngày, tháng, năm)
// Ghi chú: Năm có thể là năm thường hoặc năm nhuận
#include <iostream>
using std::cin;
using std::cout;
int main()
{
	int ngay, thang, nam, maxNgay;
	bool nhuan;
	cin >> ngay >> thang >> nam;
	nhuan = nam % 400 == 0 || (nam % 4 == 0 && nam % 100 != 0);
	switch (thang)
	{
	case 4:
	case 6:
	case 9:
	case 11:
		maxNgay = 30;
		break;
	case 2:
		maxNgay = nhuan ? 29 : 30;
		break;
	default:
		maxNgay = 31;
		break;
	}
	if (ngay < maxNgay)
	{
		ngay++;
	}
	else
	{
		ngay = 1;
		if (thang < 12)
		{
			thang++;
		}
		else
		{
			thang = 1;
			nam++;
		}
	}
	cout << "Ngay tiep theo la: " << ngay << "/" << thang << "/" << nam;
	if (nhuan)
	{
		cout << " (nam nhuan)";
	}
	cout << '\n';
	return 0;
}