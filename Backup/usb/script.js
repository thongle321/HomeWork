var dssv = ["Anday", "Brent", "Chris"];
var spanSL = document.getElementById("sl");
var olDSSV = document.getElementById("dssv");
var inputHoTen = document.getElementById("HoTen");
HienDSSV();
function HienDSSV() {
    spanSL.innerHTML = dssv.length;
    olDSSV.innerHTML = "";
    for (i = 0; i < dssv.length; i++)
    {
        olDSSV.innerHTML += "<li>" + dssv[i] + "</li>";
    }
}
function them() {
    var hoten = inputHoTen.value;
    dssv.push(hoten);
    HienDSSV();
}
function Sua() {
    var hoten = inputHoTen.value;
    var i = dssv.indexOf(hoten);
    if (i == -1) {
        alert("Ko tim thay SV " + hoten);
        return;
    }
    dssv[i] = prompt("Nhập tên mới: ");
    HienDSSV();
}
function Xoa() {
    var hoten = inputHoTen.value;
    var i = dssv.indexOf(hoten);
    if (i == -1) {
        alert("Không tìm thấy SV " + hoten);
        return;
    }
    if (confirm("Bạn có chắc muốn xóa SV " + hoten + "?")){
        dssv.splice(i, 1);
    HienDSSV();
}
}
function TimKiem() {
     var hoten = inputHoten.value;
     var i = dssv.indexOf(hoten);
    if (i == -1) {
        alert("ko tim thay SV " + hoten);
        return;
    }
     alert(`SV ${hoten} có STT là ${i + 1}`);
    }
function SapXep() {
    dssv.sort();
    HienDSSV();
}
