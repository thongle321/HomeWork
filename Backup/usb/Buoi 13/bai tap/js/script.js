// $(document).ready(function () {
//     $("#btn").click(function () {
//         var hoten = $("#hoten").val();
//         alert("xin chao " + hoten);
//     });
// });
$(document).ready(function () {
    $("#pwd").hover(function () {
        $("#pwd").attr("type", "text");
    },
        function () {
            $("#pwd").attr("type", "password");
        });
    $("#check").click(function () {
        $("#pwd").attr("type", "text");
    },
        function () {
            $("#pwd").attr("type");
        });
});
