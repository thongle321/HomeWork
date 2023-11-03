$(document).ready(function () {
    // $("p.demo").html("Hello World");

    // $("#btn").click(function () {
    //     alert("Xin chao");
    // });

    // $("#btn").click(function () {
    //     var hoten = $("#txt").val();
    //     $("#p").html(`Xin chao ${hoten}`);
    // });

    // $("#pwd").hover(
    //     function() {
    //         $("#pwd").attr("type", "text");
    //     },
    //     function() {
    //         $("#pwd").attr("type", "password");
    //     });

    // $("#p").click(function () {
    //     // $("#p").css("color", "red");
    //     // $("#p").css("background-color", "aqua");
    //     $("#p").toggleClass("text-red");
    // });

    // var dssv = new Array();
    // $("#btn").click(function() {
    //     dssv.push($("#txt").val());
    //     hienDSSV();
    // });
    // function hienDSSV()
    // {
    //     $("#dssv").html("");
    //     for (i = 0; i < dssv.length; i++)
    //     {
    //         $("#dssv").append(`<li> ${dssv[i]} </li>`)
    //     }
    // }

    // $("p").click(function () {
    //     $(this).hide();
    // });

    $("#btnHide").click(function () {
        $("img").hide(2000);//fadein, slideup
    });
    $("#btnHide").click(function () {
        $("img").show(2000);//fadeout, slidedown
    });
    $("#btnToggle").click(function () {
        $("img").toggle(2000);//fadetoggle
    });
});