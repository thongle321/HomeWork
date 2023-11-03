window.onload = function () {
    setInterval(ShowDateTime, 1000);
}

function ShowDateTime() {
    var d = new Date();
    var hour = d.getHours();
    var minute = AddLeadingZero(d.getMinutes());
    var second = AddLeadingZero(d.getSeconds());
    var ampm = "AM";
    if (hour >= 12) {
        ampm = "PM"
        if (hour > 12) {
            hour = hour - 12;
        }
    }
    document.getElementById("lblTime").innerHTML = hour + ":" + minute + ":" + second + " " + ampm;

    var daysOfWeek = ["Chủ Nhật", "thứ Hai", "thứ Ba", "thứ Tư", "thứ Năm", "thứ Sáu", "thứ Bảy"];
    document.getElementById("lblDaysOfWeek").innerHTML = daysOfWeek[d.getDay()];

    var day = AddLeadingZero(d.getDate());
    var month = AddLeadingZero(d.getMonth() + 1);
    var year = d.getFullYear();

    document.getElementById("lblDate").innerHTML = day + "/" + month + "/" + year;
}

function AddLeadingZero(number) {
    if (number < 10) {
        return "0" + number;
    }
    return number;
}