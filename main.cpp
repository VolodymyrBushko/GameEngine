#include <iostream>
#include <vector>
#include <GL/glut.h>

#include "object.h"
#include "triangle.h"
#include "square.h"
#include "circle.h"
#include "color.h"
#include "point.h"
#include "init.h"


std::vector<Object*> vect;

void DrawFigure() {
   std::cout << "DrawFigure" << std::endl;
   glClearColor(1.0,1.0,1.0,0.0);
   glClear(GL_COLOR_BUFFER_BIT);
   for(auto item : vect){
     item->Draw();
   }
   glutSwapBuffers();
}


int main(int argc, char** argv) {

   glutInit(&argc, argv);

   InitMainWindow("MainWindow");

   //*************CreateFigure*************//

   std::vector<Point> points;
   points.push_back(Point(0.5,0.5,0.0));

   Circle* circle = new Circle(points,0.1,0.1);

   vect.push_back(circle);

   //*************CreateFigure*************//


   glutDisplayFunc(DrawFigure);
   glutMainLoop();

   return 0;
}
