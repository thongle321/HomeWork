--2 Nhap san pham ten chai so luong 10 cai
DECLARE @tensp nvarchar(50)
Set @tensp = N'heineken'
if(select count(*) from SanPham where TenSp = @tensp) > 0
begin
	UPDATE SanPham
	Set SoLuong = SoLuong + 10
	WHERE TenSp = @tensp
end
else 
begin
	declare @masplonnhat int = 1,
			@masptt int 
	set @masplonnhat = (SELECT MAX(MaSp) FROM SanPham)
	if(@masplonnhat > 0)
		set @masptt = @masplonnhat + 1
	insert into SanPham(MaSp,TenSp,SoLuong)
	values(@masptt,@tensp,10)
end
SELECT * FROM SanPham where TenSp = N'pepsi chai nhựa'
--3
declare @soluongban int = 20,
		@masp int = 2
IF EXISTS(Select * from SanPham where MaSp = @masp and SoLuong >= @soluongban)
	BEGIN
		print N'Đủ số lượng bán' + cast (@masp as varchar(100))
		DECLARE @mahdtt int = 1,
				@mahdmax int
		SET @mahdmax = (select MAX(MaHD) FROM HoaDon)
		IF @mahdmax > 0
			set @mahdtt = @mahdmax + 1
		INSERT INTO HoaDon(MaHD,NgayLapHD) VALUES (@mahdtt,GETDATE())
		INSERT INTO CT_HoaDon(MaHD,MaSp, SoLuong) VALUES (@mahdtt, @masp, @soluongban)
		UPDATE SanPham
		SET SoLuong = SoLuong - @soluongban
		WHERE MaSp = @masp 
	END
ELSE
	PRINT N'Không đủ Đủ số lượng bán' + cast (@masp as varchar(100))
SELECT * FROM SanPham Where MaSp = 2
--4 
ALTER TABLE SanPham
ADD TrangThai bit

UPDATE SanPham
SET TrangThai = 1

DECLARE @SanPham6Thang INT
SET @SanPham6Thang = (SELECT COUNT(*) FROM HoaDon WHERE NgayLapHD <= DATEADD(MONTH, -6, GETDATE()))

IF (@SanPham6Thang > 0)
BEGIN
    UPDATE SanPham
    SET TrangThai = 0
    WHERE MaSp IN (SELECT MaSp FROM CT_HoaDon WHERE MaHD IN (SELECT MaHD FROM HoaDon WHERE NgayLapHD <= DATEADD(MONTH, -6, GETDATE())))
END
ELSE
    PRINT 'Không có sản phẩm nào không bán được trong vòng 6 tháng'

--5 
DECLARE @soluong INT;
SELECT @soluong = COUNT(*) FROM KhachHang WHERE NOT EXISTS (
    SELECT *
    FROM HoaDon
    WHERE KhachHang.MaKh = HoaDon.MaKh
);

IF (@soluong > 0)
BEGIN
    SELECT * FROM KhachHang WHERE NOT EXISTS (
        SELECT *
	    FROM HoaDon
        WHERE KhachHang.MaKh = HoaDon.MaKh
    )

    DELETE FROM KhachHang WHERE MaKh IN (
        SELECT MaKh FROM KhachHang WHERE NOT EXISTS (
            SELECT *
            FROM HoaDon
            WHERE KhachHang.MaKh = HoaDon.MaKh
        )
    )
END
ELSE
BEGIN
    PRINT 'Không có khách hàng nào không mua hàng';
END
--6
DECLARE @tonggiolam float = 40
IF EXISTS (SELECT MA_NVIEN FROM PHANCONG GROUP BY MA_NVIEN HAVING SUM(THOIGIAN) >= @tonggiolam)
BEGIN
	--LAP DANH SACH NHAN VIEN THOA DIEU KIEN
	SELECT *
	FROM NHANVIEN
	WHERE MANV IN (SELECT MA_NVIEN FROM PHANCONG GROUP BY MA_NVIEN HAVING SUM(THOIGIAN) >= @tonggiolam)
	--TANG LUONG CAC NHAN VIEN
	UPDATE NHANVIEN
	SET LUONG = LUONG *1.1
	WHERE MANV IN (SELECT MA_NVIEN FROM PHANCONG GROUP BY MA_NVIEN HAVING SUM(THOIGIAN) >= @tonggiolam)
	--HIEN THI LAI DANH SACH
	SELECT *
	FROM NHANVIEN
	WHERE MANV IN (SELECT MA_NVIEN FROM PHANCONG GROUP BY MA_NVIEN HAVING SUM(THOIGIAN) >= @tonggiolam)
END
ELSE
	print N'Khong co nhan vien nao co tong gio lam  >= ' + cast(@tonggiolam as varchar(10))
--7
DECLARE @n int = 300
DECLARE @tong int = 0
DECLARE @i int = 1

WHILE @i <= @n
BEGIN
    SET @tong = @tong + @i;
    SET @i = @i + 1;
END

SELECT @tong AS Tong;
--8
DECLARE @luongtb money;
DECLARE @luongcan money = 100000
SELECT @luongtb = AVG(LUONG) FROM NHANVIEN;
print N'Luong trung binh truoc khi tang: ' + cast(@luongtb as nvarchar(10))
WHILE @luongtb <= @luongcan
BEGIN
    UPDATE NHANVIEN
    SET LUONG = LUONG * 1.15;
    SELECT @luongtb = AVG(LUONG) FROM NHANVIEN;
END
PRINT N'Luong trung binh sau khi tang: ' + cast(@luongtb as nvarchar(10))

--9
DECLARE @luongth money;
DECLARE @luongcan2 money = 100000
SELECT @luongth = MIN(LUONG) FROM NHANVIEN
WHILE @luongth < 100000
BEGIN
    UPDATE NHANVIEN
    SET LUONG = LUONG * 1.15;
    SELECT @luongth = MIN(LUONG) FROM NHANVIEN;
END

--10
DECLARE @luongtbnam money, @luongtbnu money

SELECT @luongtbnam = AVG(LUONG) FROM NHANVIEN WHERE PHAI = N'Nam'
SELECT @luongtbnu = AVG(LUONG) FROM NHANVIEN WHERE PHAI = N'Nữ'
PRINT N'Luong trung binh Nam truoc tang: ' + cast(@luongtbnu as nvarchar(10))
PRINT N'Luong trung binh Nữ truoc tang: ' + cast(@luongtbnu as nvarchar(10))
WHILE (@luongtbnu < @luongtbnam)
BEGIN
    UPDATE NHANVIEN
    SET LUONG = LUONG * 1.05
    WHERE PHAI = N'Nữ'

    SELECT @luongtbnu = AVG(LUONG) FROM NHANVIEN WHERE PHAI = N'Nữ'
END
PRINT N'Luong trung binh nu sau tang: ' + cast(@luongtbnu as nvarchar(10))
--11 
DECLARE @luongmaxphg4 money, @luongtruongphongp4 money, @PHG int = 4,
@matp4 nvarchar(9) 
--Biết mã nhân viên p4
SELECT @matp4 = TRPHG FROM PHONGBAN WHERE MAPHG = @PHG
--Biết lương cao nhất nhân viên còn lại phòng 4
SELECT @luongmaxphg4 = MAX(LUONG) FROM NHANVIEN WHERE PHG = @PHG AND MANV <> @matp4
--Biết lương nhân viên trưởng phòng số 4
SELECT @luongtruongphongp4 = LUONG
							 FROM NHANVIEN
							 WHERE MANV = @matp4
print N'Lương trưởng phòng 4 trước tăng: '  + cast(@luongtruongphong4 as nvarchar(10))
WHILE @luongtruongphongp4 < @luongtruongphongp4
BEGIN
	SET @luongtruongphongp4 = @luongmaxphg4 * (1+0.07)
	UPDATE NHANVIEN
    SET LUONG = @luongtruongphongp4
    WHERE MANV = @matp4
END
print N'Lương trưởng phòng 4 sau tăng: '  + cast(@luongtruongphong4 as nvarchar(10))
--12

DECLARE @ThanhTien1 MONEY,  @MAHD1 int = 10250, @MASPXET2 INT, @TIEN1 FLOAT = 300
-- LẤY THÔNG TIN CHI TIẾT CÓ THÀNH TIỀN THẤP NHẤT
SELECT TOP 1 @MASPXET2 = MaSp, @ThanhTien1 = SoLuong * DonGia * (1 - ChietKhau)
FROM CT_HoaDon 
WHERE MaHD = @MAHD1
ORDER BY SoLuong * DonGia * (1 - ChietKhau) ASC

SELECT * FROM CT_HoaDon WHERE MaHD = @MAHD1 AND MaSp = @MASPXET2

WHILE @ThanhTien1 >= @TIEN1
BEGIN
	DELETE FROM CT_HoaDon
	WHERE MaHD = @MAHD1 AND MaSp = @MASPXET2

	SELECT @ThanhTien1 = SoLuong * DonGia * (1 - ChietKhau)
	FROM CT_HoaDon
	WHERE MaHD = @MAHD1 AND MaSp = @MASPXET2
	ORDER BY SoLuong * DonGia * (1 - ChietKhau) ASC
END

SELECT * FROM CT_HoaDon WHERE MaHD = @MAHD1 AND MaSp = @MASPXET2

--13
DECLARE @ThanhTien2 MONEY,  @MAHD2 int = 10251, @MASPXET INT,@TIEN FLOAT = 300
-- LẤY THÔNG TIN CHI TIẾT CÓ THÀNH TIỀN CAO NHẤT
SELECT TOP 1 @MASPXET = MaSp, @ThanhTien2 = SoLuong * DonGia	* (1- ChietKhau)
FROM CT_HoaDon WHERE MAHD = @MAHD2
Order by SoLuong * DonGia * (1 - ChietKhau) desc

SELECT * FROM CT_HoaDon WHERE MaHD = @MAHD2 AND MaSp = @MASPXET

WHILE @ThanhTien2 > @TIEN
BEGIN
	UPDATE CT_HoaDon
	SET SoLuong = SoLuong -1
	WHERE MaHD = @MAHD2 AND MaSp = @MASPXET

	SELECT @ThanhTien2 = SoLuong * DonGia	* (1- ChietKhau)
	FROM CT_HoaDon
	WHERE MaHD = @MAHD2 AND MaSp = @MASPXET
END
SELECT * FROM CT_HoaDon WHERE MaHD = @MAHD2 AND MaSp = @MASPXET
--14
SELECT *,
	CASE 
		WHEN PHAI = N'NAM'THEN 1
		WHEN PHAI = N'NỮ' THEN 0
	END AS 'Giới Tính'
FROM NHANVIEN
--15
SELECT *,
	CASE 
		WHEN DDIEM_DA = 'TP HCM' THEN N'trọng yếu'
		WHEN DDIEM_DA = N'Hà Nội' THEN N'trọng yếu'
	END AS 'Thông Tin'
FROM DEAN
--16
SELECT HONV , TENLOT, TENNV, MANV, NGSINH, DCHI, PHAI, LUONG, SUM(THOIGIAN) AS TONGGIOLAM, MA_NVIEN,
	CASE 
		WHEN SUM(THOIGIAN) >= 40 THEN N'Khen Thưởng'
		Else
		N''
	END AS 'Khen Thưởng'
FROM NHANVIEN JOIN PHANCONG ON MANV = MA_NVIEN
GROUP BY HONV, TENLOT, TENNV, MANV, NGSINH, DCHI, PHAI, LUONG, MANV, MA_NVIEN
SELECT *
FROM NHANVIEN JOIN PHANCONG ON MANV = MA_NVIEN
--17
DECLARE @MAHD10252 INT = 10252
SELECT * FROM CT_HoaDon WHERE MaHD = @MAHD10252
UPDATE CT_HoaDon
SET	ChietKhau = (CASE WHEN SoLuong >= 30 THEN 0.1
					  WHEN SoLuong >= 10 THEN 0.05
				ELSE 0 END)
WHERE MaHD = @MAHD10252
SELECT * FROM CT_HoaDon WHERE MAHD = @MAHD10252