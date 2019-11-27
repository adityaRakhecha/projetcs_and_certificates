# This is a project to test and understand the working of QPainter class of Qt
# QBlinker (Painter_Test)
+ A Qt widget application using QPainter class of Qt
+ QPainter class can be used to draw or paint on a QWidget class(Qt widgets), QImage and many other Qt classes.
+ In this application I have made a custom widget QBlinkingWidget used in my main Qt widget.

## Output : 
+ As soon as the application starts you will see a blinking window inside the main application window after every half second.

![painter_test1](https://user-images.githubusercontent.com/25251763/45583034-39fb0900-b8d8-11e8-9d75-99c771b3a280.png)
![painter_test2](https://user-images.githubusercontent.com/25251763/45583036-47b08e80-b8d8-11e8-922e-288fcf604db9.png)

## In general you can create your own custom Qt widget by following these steps :
+ Create a new class that inherits QWidget(or any main Qt class).
+ Override its paintEvent function.
+ Add a widget to your main application window.
+ Promote(connect) it to your newly created widget.
