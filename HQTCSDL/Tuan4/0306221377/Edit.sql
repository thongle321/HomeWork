--4A.
i
INSERT INTO NHANVIEN
VALUES (N'Nguyễn', N'Thanh', N'Trúc', '004', '1/1/2000', N'200 Cống Quỳnh Q1 TP HCM',N'nữ', 10000, null, null)
ii
INSERT INTO NHANVIEN
VALUES (N'Nguyễn', N'Thị', N'Loan', '004', '2/2/2000', N'200 Thành Thái Q10 TP HCM',N'nữ', 10000, null, null)
iii
INSERT INTO NHANVIEN
VALUES (N'Nguyễn', N'Thị', N'Loan', '005', '2/2/2000', N'200 Thành Thái Q10 TP HCM',N'nữ', 10000, null, null)

--4B.
i
INSERT INTO NHANVIEN
VALUES (N'Nguyễn', null, N'Lý', '006', '3/3/2000', N'2 Nguyễn Tri Phương Q5 TP HCM',N'nam', 10000, null, 1)
ii
INSERT INTO NHANVIEN
VALUES (N'Nguyễn', null, N'Lý', '006', '3/3/2000', N'2 Nguyễn Tri Phương Q5 TP HCM',N'nam', 10000, null, null)

--5
ALTER TABLE NHANVIEN
ADD CONSTRAINT CK_NV CHECK (PHAI = 'Nam' or PHAI = N'Nữ')

--6
