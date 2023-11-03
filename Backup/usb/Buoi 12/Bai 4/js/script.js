function TinhKC() {
    // Lấy ngày, tháng, năm A
    var ngayA = document.getElementById("ngayA").value;
    var thangA = document.getElementById("thangA").value;
    var namA = document.getElementById("namA").value;
    // Lấy ngày, tháng, năm B
    var ngayB = document.getElementById("ngayB").value;
    var thangB = document.getElementById("thangB").value;
    var namB = document.getElementById("namB").value;

    // Tạo biến kiểu Date
    var a = new Date(namA, thangA - 1, ngayA);
    var b = new Date(namB, thangB - 1, ngayB);

    var kc = Math.abs(a.getTime() - b.getTime());
    kc = kc / (1000 * 60 * 60 * 24);
    document.getElementById("lblKC").innerHTML = "Khoảng cách là " + kc + " ngày";
}