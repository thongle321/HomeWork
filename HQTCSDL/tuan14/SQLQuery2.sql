CREATE DATABASE banhang
ON PRIMARY
(
	Name = banhang_data1,
	FileName = 'D:\Thi\banhang_data1.MDF'
),
(
	Name = banhang_data2,
	FileName = 'D:\Thi\banhang_data2.NDF'
)
LOG ON
(
	Name = banhang_log,
	FileName = 'D:\Thi\banhang_log.LDF'
)
ALTER DATABASE banhang
ADD FILE
(
	Name = banhang_data3,
	FileName = 'D:\Thi\banhang_data3.NDF',
	Size = 100mb,
	MaxSize = 150mb
)
ALTER DATABASE banhang
MODIFY FILE
(
	Name = banhang_data3,
	FileName = 'D:\Thi\banhang_data3.NDF',
	Maxsize = 200mb
)
--QL TABLE
--4
CREATE TABLE CT_HOADON
(
	MaHD int not null,
	MaSp int not null,
	SoLuong int,
	DonGia money,
	ChietKhau money,
	Primary key (MaHD,MaSp),
	FOREIGN KEY (MaHD) REFERENCES HoaDon(MaHD),
	FOREIGN KEY (MaSp) REFERENCES SanPham(MaSp)
)
--5
ALTER TABLE CT_HOADON
ADD CONSTRAINT CK_CTHD_SL
CHECK (SOLUONG > 0)
--6
ALTER TABLE HOADON
ADD CONSTRAINT DF_HD_NGAYLAPHD
DEFAULT (GETDATE()) FOR NGAYLAPHD
--7
CREATE TABLE LoaiSanPham
(
	tenloaisp nvarchar(20)
)
ALTER TABLE LoaiSanPham
ADD maloai int not null primary key identity(1,1)
--8
ALTER TABLE SANPHAM
ADD MALOAI INT FOREIGN KEY REFERENCES LOAISANPHAM(MALOAI)
--9
ALTER TABLE SANPHAM
ADD TrangThai int default 1
--10
INSERT INTO KhachHang
VALUES (1221, N'LE', N'THONG', NULL, NULL, NULL ,NULL)
INSERT INTO nhanvien
VALUES (2222, N'THONG', N'LE', 'NAM', NULL, NULL, NULL)
INSERT INTO HoaDon
VALUES(1111, '2011/1/1', 2222, NULL, 1221, 6)
INSERT INTO SanPham
VALUES(111, 'AI', 'CC', 'VND', NULL, NULL , 44, 4,1)
INSERT INTO NhaCungCap
VALUES (44, 'AIDINH', NULL, NULL, NULL ,NULL)
INSERT INTO CT_HOADON
VALUES(1111, 111, NULL, NULL, NULL)
--11
delete from CT_HOADON
where MaHD = 1111
--12
Update CT_HOADON
Set SoLuong = soluong + 10
where MaHD = 10248
--SELECT
--13
SELECT (SOLUONG * DonGia - ChietKhau) THANHTIEN
FROM CT_HOADON 
WHERE MaHD = 10248
--14
SELECT (SOLUONG * DonGia - ChietKhau) THANHTIEN
FROM CT_HOADON 
WHERE MaH
--15
SELECT DATEPART(day, NgayLapHD) AS Ngay, SUM(SoLuong * DonGia) AS ThanhTien
FROM HoaDon hd
JOIN CT_HOADON cthd ON hd.MaHD = cthd.MaHD
WHERE MONTH(NgayLapHD) = 5 AND YEAR(NgayLapHD) = 2020
GROUP BY DATEPART(day, NgayLapHD)
--16
SELECT TOP 5 sp.MaSp, sp.TenSp, SUM(cthd.SoLuong) AS TongSoLuong
FROM SanPham sp
JOIN CT_HOADON cthd ON sp.MaSp = cthd.MaSp
JOIN HoaDon hd ON cthd.MaHD = hd.MaHD
WHERE MONTH(hd.NgayLapHD) = 5 AND YEAR(hd.NgayLapHD) = 2020
GROUP BY sp.MaSp, sp.TenSp
ORDER BY TongSoLuong DESC
--17
SELECT kh.MaKh, kh.TenKh, SUM(cthd.SoLuong * cthd.DonGia) AS TongThanhTien
FROM KhachHang kh
JOIN HoaDon hd ON kh.MaKh = hd.MaKh
JOIN CT_HOADON cthd ON hd.MaHD = cthd.MaHD
WHERE MONTH(hd.NgayLapHD) = 5 AND YEAR(hd.NgayLapHD) = 2020
GROUP BY kh.MaKh, kh.TenKh
ORDER BY TongThanhTien DESC
--18
CREATE PROCEDURE InsertIntoHoaDon
   @MaHD int,
   @NgayLapHD datetime,
   @MaNV int,
   @NoiChuyen nvarchar(50),
   @MaKh char(5),
   @LoaiHD char(1)
AS
BEGIN
   IF @MaHD IS NULL
   BEGIN
       SET @MaHD = (SELECT MAX(MaHD) FROM HoaDon) + 1
   END
   INSERT INTO HoaDon (MaHD, NgayLapHD, MaNV, NoiChuyen, MaKh, LoaiHD)
   VALUES (@MaHD, @NgayLapHD, @MaNV, @NoiChuyen, @MaKh, @LoaiHD)
END
--19
CREATE PROCEDURE DeleteFromCTHoaDon
   @MaHD int,
   @MaSp int
AS
BEGIN
   DELETE FROM CT_HOADON
   WHERE MaHD = @MaHD AND MaSp = @MaSp
END
--20
CREATE PROCEDURE IncreaseSoLuong
   @MaHD int,
   @MaSp int,
   @SoLuong int
AS
BEGIN
   UPDATE CT_HOADON
   SET SoLuong = SoLuong + @SoLuong
   WHERE MaHD = @MaHD AND MaSp = @MaSp
END
--21
CREATE PROCEDURE ListTop5Products
   @Month int,
   @Year int
AS
BEGIN
   SELECT TOP 5 sp.MaSp, sp.TenSp, SUM(cthd.SoLuong) AS TongSoLuong
   FROM SanPham sp
   JOIN CT_HOADON cthd ON sp.MaSp = cthd.MaSp
   JOIN HoaDon hd ON cthd.MaHD = hd.MaHD
   WHERE MONTH(hd.NgayLapHD) = @Month AND YEAR(hd.NgayLapHD) = @Year
   GROUP BY sp.MaSp, sp.TenSp
   ORDER BY TongSoLuong DESC
END
--22
CREATE PROCEDURE ListTotalRevenue
   @Month int,
   @Year int
AS
BEGIN
   DECLARE @TotalRevenue decimal(18, 2)
   SELECT DATEPART(day, NgayLapHD) AS Ngay, SUM(SoLuong * DonGia) AS ThanhTien
   FROM HoaDon hd
   JOIN CT_HOADON cthd ON hd.MaHD = cthd.MaHD
   WHERE MONTH(NgayLapHD) = @Month AND YEAR(NgayLapHD) = @Year
   GROUP BY DATEPART(day, NgayLapHD)
   SELECT @TotalRevenue = SUM(ThanhTien)
   FROM (
       SELECT DATEPART(day, NgayLapHD) AS Ngay, SUM(SoLuong * DonGia) AS ThanhTien
       FROM HoaDon hd
       JOIN CT_HOADON cthd ON hd.MaHD = cthd.MaHD
       WHERE MONTH(NgayLapHD) = @Month AND YEAR(NgayLapHD) = @Year
       GROUP BY DATEPART(day, NgayLapHD)
   ) AS SubQuery
   SELECT @TotalRevenue AS TotalRevenue
END
--23
CREATE PROCEDURE ListTopCustomer
   @Month int,
   @Year int
AS
BEGIN
   SELECT kh.MaKh, kh.TenKh, SUM(cthd.SoLuong * cthd.DonGia) AS TongThanhTien
   FROM KhachHang kh
   JOIN HoaDon hd ON kh.MaKh = hd.MaKh
   JOIN CT_HOADON cthd ON hd.MaHD = cthd.MaHD
   WHERE MONTH(hd.NgayLapHD) = @Month AND YEAR(hd.NgayLapHD) = @Year
   GROUP BY kh.MaKh, kh.TenKh
   ORDER BY TongThanhTien DESC
END
--24
ALTER FUNCTION fnGetRevenue(@Date date)
RETURNS money
AS
BEGIN
   DECLARE @Revenue money
   SELECT @Revenue = SUM(SoLuong * DonGia)
   FROM HoaDon hd
   JOIN CT_HOADON cthd ON hd.MaHD = cthd.MaHD
   WHERE CAST(hd.NgayLapHD AS DATE) = @Date
   RETURN @Revenue
END
--25
CREATE FUNCTION fnGetInvoiceAmount(@MaHD int)
RETURNS money
AS
BEGIN
   DECLARE @Amount money
   SELECT @Amount = SUM(SoLuong * DonGia)
--26
CREATE FUNCTION fnGetDailyRevenue(@Month int, @Year int)
RETURNS TABLE
AS
RETURN
  SELECT DATEPART(day, NgayLapHD) AS Ngay, SUM(SoLuong * DonGia) AS ThanhTien
  FROM HoaDon hd
  JOIN CT_HOADON cthd ON hd.MaHD = cthd.MaHD
  WHERE MONTH(NgayLapHD) = @Month AND YEAR(NgayLapHD) = @Year
  GROUP BY DATEPART(day, NgayLapHD)
--27
CREATE FUNCTION fnGetTop5Products(@Month int, @Year int)
RETURNS TABLE
AS
RETURN
(
  SELECT TOP 5 sp.MaSp, sp.TenSp, SUM(cthd.SoLuong) AS TongSoLuong
  FROM SanPham sp
  JOIN CT_HOADON cthd ON sp.MaSp = cthd.MaSp
  JOIN HoaDon hd ON cthd.MaHD = hd.MaHD
  WHERE MONTH(hd.NgayLapHD) = @Month AND YEAR(hd.NgayLapHD) = @Year
  GROUP BY sp.MaSp, sp.TenSp
  ORDER BY TongSoLuong DESC
)
--28
CREATE FUNCTION fnGetTopCustomer(@Month int, @Year int)
RETURNS TABLE
AS
RETURN
(
  SELECT kh.MaKh, kh.TenKh, SUM(cthd.SoLuong * cthd.DonGia) AS TongThanhTien
  FROM KhachHang kh
  JOIN HoaDon hd ON kh.MaKh = hd.MaKh
  JOIN CT_HOADON cthd ON hd.MaHD = cthd.MaHD
  WHERE MONTH(hd.NgayLapHD) = @Month AND YEAR(hd.NgayLapHD) = @Year
  GROUP BY kh.MaKh, kh.TenKh
  ORDER BY TongThanhTien DESC
)
--29
CREATE FUNCTION fnGetDailyRevenueCurrentMonth(@Month int = MONTH(GETDATE()), @Year int = YEAR(GETDATE()))
RETURNS TABLE
AS
RETURN
(
  SELECT DATEPART(day, NgayLapHD) AS Ngay, SUM(SoLuong * DonGia) AS ThanhTien
  FROM HoaDon hd
  JOIN CT_HOADON cthd ON hd.MaHD = cthd.MaHD
  WHERE MONTH(NgayLapHD) = @Month AND YEAR(NgayLapHD) = @Year
  GROUP BY DATEPART(day, NgayLapHD)
)
--30
CREATE FUNCTION fnGetTop5ProductsCurrentMonth(@Month int = MONTH(GETDATE()), @Year int = YEAR(GETDATE()))
RETURNS TABLE
AS
RETURN
(
  SELECT TOP 5 sp.MaSp, sp.TenSp, SUM(cthd.SoLuong) AS TongSoLuong
  FROM SanPham sp
  JOIN CT_HOADON cthd ON sp.MaSp = cthd.MaSp
  JOIN HoaDon hd ON cthd.MaHD = hd.MaHD
  WHERE MONTH(hd.NgayLapHD) = @Month AND YEAR(hd.NgayLapHD) = @Year
  GROUP BY sp.MaSp, sp.TenSp
  ORDER BY TongSoLuong DESC
)
--31
CREATE FUNCTION fnGetTopCustomerCurrentMonth(@Month int = MONTH(GETDATE()), @Year int = YEAR(GETDATE()))
RETURNS TABLE
AS
RETURN
(
  SELECT kh.MaKh, kh.TenKh, SUM(cthd.SoLuong * cthd.DonGia) AS TongThanhTien
  FROM KhachHang kh
  JOIN HoaDon hd ON kh.MaKh = hd.MaKh
  JOIN CT_HOADON cthd ON hd.MaHD = cthd.MaHD
  WHERE MONTH(hd.NgayLapHD) = @Month AND YEAR(hd.NgayLapHD) = @Year
  GROUP BY kh.MaKh, kh.TenKh
  ORDER BY TongThanhTien DESC

