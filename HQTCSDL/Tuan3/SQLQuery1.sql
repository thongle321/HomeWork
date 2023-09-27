INSERT INTO DEAN (TENDA, MADA, DDIEM_DA, PHONG)
VALUES (N'Sản phẩm X', 1, N'Vũng Tàu', 5),
	   (N'Sản phẩm Y', 2, N'Nha Trang', 5),
	   (N'Sản phẩm Z', 3, 'TP HCM', 5),
	   (N'Tin học hoá', 10, N'Hà Nội', 4),
	   (N'Cáp quang', 20, 'TP HCM', 1)

BACKUP DATABASE QuanLyDuAn
TO DISK = 'D:\0306221377\quanlyduan_da_full.bak'

INSERT INTO CONGVIEC( MADA, STT, TEN_CONG_VIEC)
VALUES (1, 1, N'Thiết kế sản phẩm  X'),
	   (1, 2, N'Thử nghiệm sản phẩm X'),
	   (2, 1, N'Sản xuất sản phẩm Y'),
	   (2, 2, N'Quảng cáo sản phẩm Y'),
	   (3, 1, N'Khuyến mãi sản phẩm Z')

BACKUP DATABASE QuanLyDuAn
TO DISK = 'D:\0306221377\quanlyduan_cv_dif.bak'
WITH DIFFERENTIAL

DELETE FROM CONGVIEC
DELETE FROM DEAN
DELETE FROM NHANVIEN
DELETE FROM PHANCONG
DELETE FROM PHONGBAN
DELETE FROM THANNHAN


RESTORE DATABASE QuanLyDuAn2
FROM DISK = 'D:\0306221377\quanlyduan_da_full.bak' WITH FILE = 1, norecovery,
MOVE 'QuanLyDuAn' TO 'D:\0306221377_1\QuanLyDuAn2.mdf',
MOVE 'QuanLyDuAn_log' TO 'D:\0306221377_1\QuanLyDuAn2_log.ldf';
RESTORE DATABASE QuanLyDuAn2
FROM DISK = 'D:\0306221377\quanlyduan_cv_dif.bak' WITH FILE = 1, RECOVERY

		