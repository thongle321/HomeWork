var hour = 0;
var minute = 0;
var second = 0;
var stopwatch;

function Start() {
    stopwatch = setInterval(function () {
        Add1Second;
        ShowCurrentTime();
    }, 1000)
    document.getElementById("btnStart").disabled = true;
    document.getElementById("btnLap").disabled = false;
    document.getElementById("btnStop").disabled = false;
}
function Add1Second() {
    second++;
    if (second >= 60) {
        second = 0;
        minute++;
    }
    if (minute >= 60) {
        minute = 0;
        hour++;
    }

}
function ShowCurrentTime() {
    document.getElementById("hour").innerHTML = AddLeadingZero(hour);
    document.getElementById("minute").innerHTML = AddLeadingZero(minute);
    document.getElementById("second").innerHTML = AddLeadingZero(second);
}
function AddLeadingZero(number) {
    if (number < 10) {
        return "0" + number;
    }
    return number;
}