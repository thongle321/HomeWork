var showDuration = 2000;// thời gian hiển thị 1 hình (ms)
var slides = document.querySelectorAll('#slideshow .slide');
var numOfSlide = slides.length;
var current=0;
var next=1;
slides[current].classList.add('current');
function changeSlide(){
	slides[next].classList.add('next');
	setTimeout(function(){
		slides[next].classList.add('current');
		slides[next].classList.remove('next');
		slides[current].classList.remove('current');
		current=next;
		next = (next + 1)%numOfSlide;

	},1000);
}
setInterval(changeSlide,showDuration);//hẹn thời gian lặp lại việc chuyển slide
