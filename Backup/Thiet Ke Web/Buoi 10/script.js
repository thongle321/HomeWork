//var dssv = new Array();

var dssv = ["Andy", "Brent", "Chris"];

var spanSL = document.getElementById("sl");
var olDSSV = document.getElementById("dssv");
var inputHoTen = document.getElementById("hoten");

ShowDSSV();

function ShowDSSV() {
  spanSL.innerHTML = dssv.length;
  olDSSV.innerHTML = "";
  for (i = 0; i < dssv.length; i++) {
    olDSSV.innerHTML += "<li>" + dssv[i] + "</li>";
  }
}

function add() {
  var hoten = inputHoTen.value;
  dssv.push(hoten);
  ShowDSSV();
}

function change() {
  var hoten = inputHoTen.value;
  var i = dssv.indexOf(hoten);
  if (i == -1) {
    alert("Không tìm thấy SV " + hoten);
    return;
  }
  dssv[i] = prompt("Nhập tên mới: ");
  ShowDSSV();
}

function remove() {
  var hoten = inputHoTen.value;
  var i = dssv.indexOf(hoten);
  if (i == -1) {
    alert("Không tìm thấy SV " + hoten);
    return;
  }
  if (confirm("Bạn có chắc muốn xoá SV " + hoten + "?")) {
    dssv.splice(i, 1);
    ShowDSSV();
  }
}

function find() {
  var hoten = inputHoTen.value;
  var i = dssv.indexOf(hoten);
  if (i == -1) {
    alert("Không tìm thấy SV " + hoten)
  }
  else {
    //alert("SV " + hoten + " có STT là " + (i + 1));
    alert(`SV ${hoten} có STT là ${i + 1}`);
  }
}

function sort() {
  dssv.sort();
  ShowDSSV();
}