Flappy bird game 

2 class tube và bird nằm trong gameloop là vòng lặp game
chim bay và có khoảng delay input nhảy, cột nằm trong 1 vector các cột và tự sinh ra riêng biệt từ emplace_back, tự xóa khi đi hết màn hình

gameloop dùng biến gamestate để duy trì event, event có hãm fps và trong event có play là cho bird bay và các tube tự sinh ra tiêu diệt và di chuyển.

event sử dụng gameplay là 1 bool khác để đưa về màn hình gameover

tự đánh giá là được 7


có tham khảo từ về input bay


