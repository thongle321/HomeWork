--1 Viet ham tinh luong cao nhat 
CREATE FUNCTION FN_LUONGMAX()
RETURNS MONEY
AS
BEGIN
	DECLARE @l money
	SELECT @l = MAX(LUONG) FROM NHANVIEN
	RETURN @l
END
SELECT *, QuanLyDeAn.dbo.FN_LUONGMAX() AS LUONG_MAX 
FROM NHANVIEN
WHERE LUONG = QuanLyDeAn.dbo.FN_LUONGMAX() 
--2 Viet ham tinh tuoi khi nguoi dung nhap ngay sinh
CREATE FUNCTION FN_TINHTUOI(@NGSINH DATE)
RETURNS INT
AS
BEGIN
	DECLARE @TUOI INT
	SELECT @TUOI = (YEAR(GETDATE()) - YEAR(@NGSINH))
	RETURN @TUOI
END

SELECT *,QuanLyDeAn.dbo.FN_TINHTUOI('1979/03/15')
FROM NHANVIEN
--2b Truy van cac nhan vien va tuoi cua ho
SELECT *, QuanLyDeAn.DBO.FN_TINHTUOI(NGSINH) AS 'TUOI'
FROM NHANVIEN
--2c Truy van nhan vien va them cot ve huu: ghi dau x neu nhan vien da ve huu
SELECT *, CASE WHEN (PHAI = N'Nữ' AND QuanLyDeAn.DBO.FN_TINHTUOI(NGSINH) >= 55) THEN 'X'
				WHEN (PHAI = N'Nam' AND QuanLyDeAn.DBO.FN_TINHTUOI(NGSINH) >= 60) THEN 'X'
				ELSE ''
				END AS VEHUU
					 
FROM NHANVIEN
--3 Viet ham dem so nhan vien cua 1 ten du an
ALTER FUNCTION FN_SLNVDUAN(@TEN NVARCHAR(50))
RETURNS INT
AS
BEGIN
	DECLARE @SL INT
	SELECT @SL = COUNT(MA_NVIEN)
	FROM DEAN D JOIN PHANCONG P ON D.MADA = P.MADA
	WHERE TENDA = @TEN
	RETURN @SL
END
SELECT DBO.FN_SLNVDUAN(N'Tin học hoá') AS SOLUONG

--3b Liet ke du an co so nhan vien >= so nhan vien du an tin hoc hoa
SELECT *
FROM DEAN
WHERE DBO.FN_SLNVDUAN(TENDA) >= DBO.FN_SLNVDUAN(N'Tin học hoá')
AND TENDA <> N'Tin học hoá'

--3c Liet ke du an co so nhan vien thap nhat
SELECT DBO.FN_SLNVDUAN(TENDA)
FROM DEAN 
WHERE DBO.FN_SLNVDUAN(TENDA) >= ALL (SELECT DBO.FN_SLNVDUAN(TENDA)
									 FROM DEAN)
--4 Viet ham tinh luong cua 1 ma nhan vien, biet tong gio lam >= 40
ALTER FUNCTION FN_LUONGNV(@MANV CHAR(9))
RETURNS MONEY
AS
BEGIN
	DECLARE @tonggiolam float,@LUONG MONEY
	SELECT @tonggiolam = SUM(THOIGIAN) FROM PHANCONG
	IF @tonggiolam >= 40
	BEGIN
		UPDATE NHANVIEN
		SET LUONG = LUONG + (@tonggiolam-40) * 1000


END

SELECT *, DBO.FN_LUONGNV('009')
FROM NHANVIEN

--4B Tinh luong cua tat ca nhan vien
SELECT *, DBO.FN_LUONGNV(MANV) LUONGSUM
FROM NHANVIEN

--4C Truy
--5 Viet ham tra ve ho ten cua 1 ma nhan vien
CREATE FUNCTION dsnhanvien(@manv char(9))
returns table
as
	return(
		select MANV, HONV +' '+ TENLOT +' '+ TENNV AS HOTEN
		from NHANVIEN
		where  MANV = @manv)

select * from  dbo.dsnhanvien('009')

--6 Viet ham tro ve cac nhan vien do nguoi dung nhap
CREATE function dsnvien(@tennv nvarchar(15))
returns table
as
	return(
		select HONV +' '+ TENLOT +' '+ TENNV AS HOTEN, DEAN.TENDA
		from NHANVIEN, DEAN, PHANCONG
		where TENNV = @tennv and NHANVIEN.MANV = PHANCONG.MA_NVIEN and DEAN.MADA = PHANCONG.MADA  
		)
select * from dbo.dsnvien(N'Tiên')
--7 Viet ham tra ve danh sach nhan vien tham gia 1 ma de an
alter function danhsachnv(@mada int)
returns table
as
	return (select MANV, TENNV, MADA
			from NHANVIEN, PHANCONG
			where NHANVIEN.MANV = PHANCONG.MA_NVIEN and MADA = @mada )


select * from dbo.danhsachnv(2)  
--7b Truy van nhan vi