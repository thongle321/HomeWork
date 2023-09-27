class SoPhuc
{
private:
    float a;
    float b;

public:
    void SetPhanThuc(float PhanThuc);
    void SetPhanAo(float PhanAo);
    float GetPhanThuc();
    float GetPhanAo();
    void Nhap();
    void Xuat();
    SoPhuc Cong(SoPhuc A, SoPhuc B);
    SoPhuc Tru(SoPhuc A, SoPhuc B);
    SoPhuc Nhan(SoPhuc A, SoPhuc B);
    SoPhuc Chia(SoPhuc A, SoPhuc B);
    int SoSanh(SoPhuc A, SoPhuc B);
};