#include<iostream>
#include<string>
#include<vector>
using namespace std;

class DrawingContext {
public:
    void setPoint() {

    }

    void clearScreen() {

    }

    void getVerticalSize() {

    }

    void getHorizontalSize() {
        
    }
};

class Event {

};

class Frame {

}; 

class Window : public Frame{
public:
    void open() {

    }

    void close() {

    }

    void move() {

    }

    void display() {

    }

    void handleEvent(Event* e) {

    }
private:
    vector<Shape*>myShapeList; 
};

class Shape {
public:
    virtual void draw() {};
    virtual void erase() {};
    virtual void move() {};
    virtual void resize() {};
private:
    Window* myWindow = new Window;
};

class Rectangle : public Shape {

};

class Polygon : public Shape {

};

class Circle : public Shape {
private:
    float radius;
    int center;
public:
    void area(float radius) {

    }
};

class ConsoleWindow : public Window {

};

class DialogBox : public Window {

};

int main() {


}