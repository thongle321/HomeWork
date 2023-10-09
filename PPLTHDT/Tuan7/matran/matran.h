#define MAX_DONG 100
#define MAX_COT 100
class matran
{
private:
    int dong;
    int cot;
    float n[MAX_DONG][MAX_COT];

public:
    matran();
    ~matran();
    void nhap();
    void xuat();
    friend matran operator+(matran &mt1, matran &mt2);
    friend matran operator-(matran &mt1, matran &mt2);
    friend matran operator*(matran &mt1, matran &mt2);
    matran &operator=(const matran &mt2);
    friend float dinh_thuc(matran &mt);
    friend matran nghich_dao(matran &mt);
};
