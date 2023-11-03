var dssv = ["Mizkif", "Esfand", "Nick"];

ShowDSSV();

function ShowDSSV() {
    document.getElementById("sl").innerHTML = dssv.length;
    document.getElementById("dssv").innerHTML = "";
    for (i = 0; i < dssv.length; i++) {
        document.getElementById("dssv").innerHTML += "<li>" + dssv[i] + "</li>";

    }
}