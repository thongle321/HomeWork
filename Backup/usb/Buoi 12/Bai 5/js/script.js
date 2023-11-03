function CalculateAge() {
    var ngay = document.getElementById("ngay").value;
    var thang = document.getElementById("thang").value;
    var nam = document.getElementById("nam").value;
    var dob = new Date(nam, thang - 1, ngay);
    var today = new Date();

    // Tính tuổi (theo ms)
    var age = today.getTime() - dob.getTime();
    // Chuyển tuổi sang ngày
    age = age / (1000 * 60 * 60 * 24);

    document.getElementById("lbl").innerHTML = "Tuổi: " + Math.floor(age / 365) + " năm " + Math.floor(age % 365 / 30) + " tháng " + Math.floor(age % 30) + " ngày";
}