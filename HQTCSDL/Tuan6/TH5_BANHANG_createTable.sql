--csdl quản lý bán hàng
use master
create database banhang
go
--
use banhang
go
create table SanPham
(MaSp	int 	primary key,
TenSp	nvarchar(100)	,
MoTa	nvarchar(200),	
Donvitinh	nvarchar(20),
SoLuong int,	
DonGia	 Money,
mancc int
)
go
create table
nhanvien
(
	MaNV int primary key,
	HoNV	nvarchar(30),
	TenNV	nvarchar(30),
	GioiTinh	nvarchar(3),
	NgaySinh	datetime,
	DiaChi	nvarchar(100),
	Phone varchar(24)

)
create table HoaDon
(
MaHD	Int	primary key,
NgayLapHD	DateTime,
MaNV int,
NoiChuyen	nvarchar(50),
MaKh	char(5),
LoaiHD char(1)
)
create table CT_HoaDon
(
MaHD	Int	,
MaSp	int	,
SoLuong	Int	,
DonGia	Money,	
ChietKhau	Money,primary key(mahd,masp)
)
create table NhaCungCap
(
MaNCC	Int	primary key,
TenNcc	Nvarchar(100)	,
Diachi	Nvarchar(100),	
Phone	Varchar(24)	,
SoFax	Varchar(24)	,
DCMail	Varchar(50)	
)
create table KhachHang
(
MaKh	Char(5)primary key	,
TenKh	Nvarchar(100)	,
DiaChi	Nvarchar(100),	
Phone	Varchar(24),	
SoFax	Varchar(24)	,
DCMail	varchar(50)	
)
alter table hoadon
add foreign key(makh) references khachhang(makh)
--
alter table hoadon
add foreign key(manv)references nhanvien(manv)
--
alter table ct_hoadon
add foreign key(mahd) references hoadon(mahd)
--
alter table ct_hoadon
add foreign key(masp) references sanpham(masp)
--
alter table sanpham
add foreign key(mancc) references nhacungcap(mancc)