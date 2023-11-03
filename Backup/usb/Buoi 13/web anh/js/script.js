function changeSize() {
    $('#screen').height($('#screen').width() / 2);
}
$(window).on('resize', function () {
    changeSize();
})
var lst_img = ['church_todtnau.jpg', 'fantasy.jpg', 'grass_stalks.jpg',
    'nice_lake_width_house.jpg', 'peyto_canada.jpg', 'sunset_background.jpg',
    'the_rozendaal_castle.jpg', 'wildflowers.jpg'];
for (var i = 0; i < lst_img.length; i++) {
    $('aside.right').html($('aside.right').html() + '<img idx = "' + i + '" src= "images/'
        + lst_img[i] + '">');
}
$('aside.right img:first-child').addClass('img-active');
$('#screen').css('background-image', 'url(images/' + lst_img[0] + ')');
$('aside.right img').click(function () {
    $('.img-active').removeClass('img-active');
    $(this).addClass('img-active');
    $('screen').css('background-image', 'url')
});