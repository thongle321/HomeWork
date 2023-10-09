-- Lê Nguyễn Hoàng Thông
-- 0306221377
-- 1. Thêm vào mỗi bảng 1 record với nội dung bất kỳ, sao cho không lỗi
INSERT INTO KhachHang
VALUES (03062, 'Levisa', 'TPHCM', '0783438731', '18201', 'thongle857@gmail.com')

INSERT INTO NhaCungCap
VALUES (0306221378, 'Nortwhind', 'USA', '0783438732', '18202', 'Northwind@gmail.com')

INSERT INTO nhanvien
VALUES (0306221379, 'Mikey', 'Flux', 'Nam', 31/1/2004, 'TPHCM', '0783438733')

INSERT INTO SanPham(MaSp, TenSp, MoTa)
VALUES (0306221365, 'MakeUp','Describe')

INSERT INTO HOADON(MaHD, NgayLapHD, MaNV, MaKh)
VALUES (0306221380, 31/1/2022, 0306221379, 03062)


INSERT INTO CT_HoaDon(MaHD, MaSp, SoLuong, DonGia)
VALUES (0306221380, 0306221365, 50000, 10000)

--2. Chay file northwind
--NhanVien
INSERT INTO nhanvien(MaNV, HoNV, TenNV,GioiTinh, NgaySinh,DiaChi, Phone)
SELECT EmployeeID, LastName, FirstName, CASE WHEN TitleOfCourtesy LIKE '%n%' THEN N'Nữ' ELSE 'Nam' END,BirthDate, Address + ',' + CITY + ',' + Country, HomePhone
FROM Northwind..Employees 
SELECT * FROM nhanvien

--SanPham
INSERT INTO SanPham(MaSp,TenSp)
SELECT ProductID, ProductID
FROM Northwind..Products
SELECT * FROM SanPham


--NHA CUNG CAP
INSERT INTO NhaCungCap(MaNCC, TenNcc, Diachi, Phone)
SELECT SupplierID, CompanyName, Address, Phone
FROM  Northwind..Suppliers
Select * from NhaCungCap

--Khachhang
INSERT INTO KhachHang(MaKh,TenKh,DiaChi,Phone)
SELECT CustomerID, ContactName, Address + ',' + City + ',' + Country, Phone
FROM Northwind..Customers
SELECT * FROM KhachHang

--HOADON
INSERT INTO HOADON(MaHD, NgayLapHD, MAKH)
SELECT OrderID, OrderDate, CustomerID
FROM Northwind..Orders
SELECT* FROM HOADON


--3. Cap nhat don gia
UPDATE SanPham
SET DonGia = 30000
WHERE TenSp like 'T%'
--4 Cap nhat so luong
update SanPham
SET SoLuong = SoLuong + 50
where MaSp = 1
--5 Cap nhat so luong
update SanPham
SET SoLuong = SoLuong -5
where MaSp = 2
--6 Cap nhat ma khach hang
Update KhachHang
SET MaKh = 'ONTAN'
WHERE MAKH = 'ANTON'
-- Lỗi foreign key

--7 Tang don gia
UPDATE SanPham
SET DonGia = (DonGia * 0.03)
where mancc = 1 
--8 Cap nhat thong tin co ma 'ALFKI'
UPDATE KhachHang
SET MaKh = 'ALFKI'
WHERE TenKh = N'Nguyễn Văn Tâm' AND PHONE = '0909090909'
--9 Xoa cac hoa don 
























































































































































)
VALUES (0306221381, 0306221366, 50000)