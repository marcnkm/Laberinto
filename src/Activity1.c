// llibreria unix
//#include <GL/glut.h>

// llibreria mac
#include <GLUT/GLUT.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WALL 1
#define FLOOR 0

void setPixel(int x, int y);
void setSquad(int x, int y);
void drawMaze(int xmax, int ymax){

  int **matrix;
  

  int i=0; // i recorre la columnas
  int j=0; // j recorre la filas

  printf("Hola %i\n", xmax);

  matrix = (int **) malloc(xmax * sizeof(int*));

  for (i=0; i<ymax; i++){
    matrix[i] = (int *) malloc(ymax * sizeof(int));
    // *matrix++;
  }

  
  matrix[0][0] = 100;
  matrix[1][2] = 100;
  int random;

  for (i=0; i<xmax; i++){
    for (j=0; j<ymax; j++){
      random = rand() % 2;
      if (i %2 == 0 || j%2 == 0) matrix[i][j] = WALL;
      else matrix[i][j] = FLOOR;
      matrix[i][j] = WALL;
    }
  }


//  -----------------------------

int neighbour_valid = 1;
int neighbour_x[4];
int neighbour_y[4];
int step[4];

int x_next;
int y_next;

if (x - 2 > 0 && is_closed(matrix, x-2, y)){ //upside

  neighbour_valid++;
  neighbour_x[neighbour_valid] = x - 2;
  neighbour_y[neighbour_valid] = y;
  step[neighbour_valid] = 1;
}

if (y -2 > 0 && is_closed(matrix, x, y-2)){ // leftside
  neighbour_valid++;
  neighbour_x[neighbour_valid] = x;
  neighbour_y[neighbour_valid] = y -2 ;
  step[neighbour_valid]=2;
}

if (y+2 < )





//  -----------------------------

// pintar una linea

  for(i=0; i<xmax; i++){
    for (j=0; j <ymax; j++){
      if (matrix[i][j] == 1){
        setSquad(i*5, j*5);
      }
    }
  }

// printf("muero %i\n", xmax);

if (1==2){
  for (i=0; i<xmax; i++){
    for (j=0; j<ymax; j++){
      printf("%i ", matrix[i][j]);
    }
    printf("\n");
  }
}
}


 
/*******************************************************/
// void display(int xmax, int ymax)
void display()
{

  glClearColor(1.0,1.0,1.0,0.0);
  glClear(GL_COLOR_BUFFER_BIT);

  drawMaze(101, 101);

  glFlush();
}


/*******************************************************/
int main(int argc, char **argv)
{
    int xmax = 0;
    int ymax = 0;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(50, 50);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Laberint");


    // printf("Hola %s  hola\n", argv[1]);

    glutDisplayFunc(display);

    glMatrixMode(GL_PROJECTION);
    
    gluOrtho2D(0.0,500.0,0.0,500.0);

    glutMainLoop();
    return 0;
}


// pinta un pixel.
void setPixel(int x, int y){
  glColor3f(0,1.0,0);
  glBegin(GL_POINTS);
    glVertex2i(x, y);
  glEnd();
}

void setSquad(int x, int y){
  glColor3f(0,1.0,0);
  glBegin(GL_POLYGON);
        glVertex2i(x, y+5);
        glVertex2i(x+5, y+5);
        glVertex2i(x+5, y);
        glVertex2i(x, y);
  glEnd();
}


