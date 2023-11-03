var arr = [9, 6, 3, 2, 5, 7, 1, 2];

// Arrow function
var vt = arr.findIndex(x => x % 2 == 0);

//Anonymous function

// var vt = arr.findIndex(function (x)
// {
//     return x % 5 == 0;
// });

document.write("So chan dau tien o vi tri " + vt);


// function lasochan(x)
// {
//     return x % 2 == 0;
// }

function displayArray()
{
    document.write(arr.join(" - "));
}