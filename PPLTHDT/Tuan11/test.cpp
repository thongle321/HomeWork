#include <iostream>
#include <cmath>
using namespace std;
class Hinh {
protected:
  float chieudai, chieurong;

public:
  Hinh() {
    chieudai = 0;
    chieurong = 0;
  }
  virtual float TinhChuVi() {
      
  }
  virtual float TinhDienTich() {
      
  }

  virtual void Nhap() {
    cout << "Nhap chieu dai: ";
    cin >> chieudai;
    cout << "Nhap chieu rong: ";
    cin >> chieurong;
  }

  virtual void Xuat() {
    cout << "Chieu dai: " << chieudai << endl;
    cout << "Chieu rong: " << chieurong << endl;
  }
};
class HinhChuNhat : public Hinh {
public:
  HinhChuNhat() : Hinh() {}

  float TinhChuVi(){
    return (2 * chieudai) + (2 * chieurong);
  }

  float TinhDienTich(){
    return chieudai * chieurong;
  }
};

class HinhTamGiac : public Hinh {
protected:
  float canhday;

public:
  HinhTamGiac() : Hinh() {}
  
  virtual void Nhap() {
    cout << "Nhap a: ";
    cin >> chieudai;
    cout << "Nhap b: ";
    cin >> chieurong;
    cout << "Nhap c: ";
    cin >> canhday;
  }
  float TinhChuVi(){
    return (chieudai + chieurong + canhday);
  }

  float TinhDienTich(){
    float p = TinhChuVi()/2.0;
    return sqrt(p*(p - chieudai)*(p - chieurong)*(p - canhday));
    
  }
};
class HinhTamGiacDeu : public HinhTamGiac {
public:
  HinhTamGiacDeu() : HinhTamGiac() {}

  void Nhap()
  {
      cout << "Kich thuoc canh: ";
      cin >> chieudai;
  }
  float TinhChuVi(){
    return (chieudai * 3);
  }

  float TinhDienTich(){
    return (chieudai * 2 * sqrt(3) / 4);
  }
};
int main() {

  HinhChuNhat hinhchunhat1;
  HinhTamGiac hinhtamgiac1;
  HinhTamGiacDeu hinhtamgiacdeu1;

  // Nhập dữ liệu cho các đối tượng hình
  hinhchunhat1.Nhap();
  hinhtamgiac1.Nhap();
  hinhtamgiacdeu1.Nhap();

  // Tính chu vi và diện tích cho các đối tượng hình
  cout << "Chu vi hình chữ nhật: " << hinhchunhat1.TinhChuVi() << endl;
  cout << "Diện tích hình chữ nhật: " << hinhchunhat1.TinhDienTich() << endl;
  cout << "Chu vi hình tam giác: " << hinhtamgiac1.TinhChuVi() << endl;
  cout << "Diện tích hình tam giác: " << hinhtamgiac1.TinhDienTich() << endl;
  cout << "Chu vi hình tam giác đều: " << hinhtamgiacdeu1.TinhChuVi() << endl;
  cout << "Diện tích hình tam giác đều: " << hinhtamgiacdeu1.TinhDienTich() << endl;

  return 0;
}

