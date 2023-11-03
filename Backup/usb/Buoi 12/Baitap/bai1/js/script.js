window.onload = function () {
    setInterval(ShowDateTime, 1000);
}
function ShowDateTime() {
    var d = new Date();
    var hour = AddLeadingZero(d.getHours());
    var minute = AddLeadingZero(d.getMinutes());
    var second = AddLeadingZero(d.getSeconds());
    var ampm = "AM";
    if (hour >= 12) {
        ampm = "PM";
        if (hour < 12) {
            hour = hour - 12;
        }
    }
    document.getElementById("Time").innerHTML = hour + ":" + minute + ":" + second + " " + ampm;

    var daysOfWeek = ["Chủ nhật", "Thứ hai", "Thứ ba", "Thứ tư", "Thứ năm", "Thứ sáu", "Thứ bảy"];
    document.getElementById("DayOfWeek").innerHTML = daysOfWeek[d.getDay()];

    var day = AddLeadingZero(d.getDate());
    var month = AddLeadingZero(d.getMonth() + 1);
    var year = d.getFullYear();
    document.getElementById("Date").innerHTML = day + "/" + month + "/" + year;
}
function AddLeadingZero(number) {
    if (number < 10) {
        return "0" + number
    }
    return number;
}