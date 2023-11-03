declare @luong int
set @luong = (select count(MANV) from NHANVIEN join PHONGBAN on NHANVIEN.PHG = PHONGBAN.MAPHG
			  WHERE LUONG > 30000 And TENPHG = N'Nghiên Cứu')
if @luong > 0
	print @luong
else 
	print 'khong co nhan vien nao'

--2
declare @tenphong nvarchar(50) = N'Quản Lý', @luongmax money, @max money
select @max =	MAX(luong) from NHANVIEN join PHONGBAN on phg = MAPHG
where TENPHG = @tenphong
If(@max < @luongmax)
begin
	print N'Lương cao nhất ban đầu ' + cast(@max as nvarchar(10))
	Update NHANVIEN
	set luong = luong*1.1
	from PHONGBAN
	where phg = MAPHG and TENPHG = @tenphong and luong = @max
	select @max =	MAX(luong) from NHANVIEN join PHONGBAN on phg = MAPHG
	where TENPHG = @tenphong

	print N'Lương cao nhất sau tăng ' + cast(@max as nvarchar(10))
end
Else
	print N'Lương cao nhất đã thoả mãn'


--3
Declare @nam int = 60, @nu int = 50
select *
From NHANVIEN
where (year(getdate()) - year(ngsinh)) >= (case when PHAI = N'NAM' then @nam else @nu end)

--cach 2
select *
From NHANVIEN
where (year(getdate()) - year(ngsinh)) >= @nam and PHAI = N'NAM')



--4 
Declare @luongcan money = 50000, @sl int
SELECT @sl = COUNT(*) FROM NHANVIEN WHERE LUONG > @luongcan
PRINT N'Số nhân viên có mức lương trên ' + cast(@luongcan as nvarchar(10)) + ' la ' + cast(@sl as nvarchar(10))

--5
declare @tp nvarchar(50) = N'Nghiên Cứu', @ltbtarget money = 30000, @ltb money
Select @ltb = AVG(luong) from NHANVIEN join PHONGBAN on phg = MAPHG where TENPHG = @tp
Print N'Lương trung bình ban đầu ' + cast(@ltb as nvarchar(10))
while(@ltb < @ltbtarget)
begin
	update NHANVIEN set luong = luong * 1.1
	From PHONGBAN
	where phg = MAPHG and TENPHG = @tp
	Select @ltb = AVG(luong) from NHANVIEN join PHONGBAN on phg = MAPHG where TENPHG = @tp
End
Print N'Lương trung bình cuói cùng ' + cast(@ltb as nvarchar(10))
--B1: tính lương trung bình phòng nghiên cứu
--B2: so sánh luong tb < trung bình mong muốn nếu đúng thì tới b2, ngược lại tới b5
--B3: tăng lên mỗi nhân viên phòng nghiên cứu 10&
--B4: TÍNH LẠI LƯƠNG trung bình quay lại b2
--B5: xuất ra lương trung bình cuối cùng
