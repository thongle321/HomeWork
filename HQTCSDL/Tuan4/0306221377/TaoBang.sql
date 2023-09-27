CREATE DATABASE QuanLyDuAn
GO
USE QuanLyDuAn;
GO

-- Tạo bảng Đề Án
create table DEAN
(
	TENDA nvarchar(15),
	MADA int,
	DDIEM_DA nvarchar(15),
	PHONG int,
)

-- Tạo bảng Công Việc
create table CONGVIEC
(
	MADA int,
	STT int,
	TEN_CONG_VIEC nvarchar(50),
)

-- Tạo bảng Phòng Ban
create table PHONGBAN
(
	TENPHG nvarchar(15),
	MAPHG int,
	TRPHG char(9),
	NG_NHANCHUC date,
)

-- Tạo bảng Phân Công
create table PHANCONG
(
	MA_NVIEN  char(9),
	MADA int,
	STT int,
	THOIGIAN float,
)

-- Tạo bảng Thân Nhân
create table THANNHAN
(
	MA_NVIEN char(9),
	TENTN nvarchar(15),
	PHAI nvarchar(3),
	NGSINH date,
	QUANHE  nvarchar(15),
)

-- Tạo bảng Địa Điểm Phòng
create table DIADIEM_PHG
(
	MAPHG  int,
	DIADIEM nvarchar(15),
)

-- Tạo bảng Nhân Viên
CREATE TABLE NHANVIEN
(
	HONV NVARCHAR(15),
	TENLOT NVARCHAR(15),
	TENNV NVARCHAR(15),
	MANV CHAR(9),
	NGSINH DATE,
	DCHI NVARCHAR(30),
	PHAI NVARCHAR(3),
	LUONG FLOAT,
	MA_NQL CHAR(9),
	PHG INT
)


