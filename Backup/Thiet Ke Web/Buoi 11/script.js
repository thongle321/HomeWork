// var d = new Date();
// var d2 = new Date(2023, 4, 15);

// // document.write(d > d2);
// function displayDateTime() {
//     var d = new Date();
//     document.getElementById("p").innerHTML = `Hiện tại là ${d.getHours()}:${addLeadingZero(d.getMinutes())}:${addLeadingZero(d.getSeconds())},
//                ngày ${d.getDate()}/${d.getMonth() + 1}/${d.getFullYear()}`;
// }
// document.write(`Hiện tại là ${d.getHours()}:${addLeadingZero(d.getMinutes())}:${addLeadingZero(d.getSeconds())},
//                ngày ${d.getDate()}/${d.getMonth() + 1}/${d.getFullYear()}`);

// function addLeadingZero(x) {
//     if (x < 10) {
//         return "0" + x;
//     }
//     return x;
// }

// var newTab;

// function OpenGG() {
//     newTab = window.open("Hello.html");
// }
// function CloseGG() {
//     newTab.close();
// }

// var i = 0;

// setInterval(function () {
//     i++;
//     document.write(i);
// }, 2000);

// setInterval(function () {
//     displayDateTime();
// }, 1000);

// setInterval(displayDateTime, 1000);

// var minute = 3;
// var second = 0;

// function subtract1Sec() {
//     second--;
//     if (second < 0) {
//         minute--;
//         second = 59;
//     }
// }

// function displayTime() {
//     document.getElementById("p").innerHTML = `${addLeadingZero(minute)}:${addLeadingZero(second)}`
// }
// var countdown = setInterval(function () {
//     subtract1Sec();
//     displayTime();
//     if (minute == 0 & second == 0) {
//         clearInterval(countdown);
//     }
// }, 1000);
var second = 6;

function open() {
    setInterval(function () {
        document.getElementById("p").innerHTML = `Chuyển trang sau ${--second} giây`;
    }, 1000);
    setTimeout(function () {
        window.location.href = "http://www.google.com";
    }, 6000);
}