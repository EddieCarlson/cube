#ifndef sphere_h
#define sphere_h

class Sphere {
  public:
  Cube* cube;
  int colorI;
  int* rainbow;
  int xSize;
  int ySize;
  int zSize;
  float brightness;

  Sphere(Cube* _cube, int* _rainbow, float _brightness) {
    cube = _cube;
    colorI = 0;
    rainbow = _rainbow;
    brightness = _brightness;

    xSize = cube->xSize;
    ySize = cube->ySize;
    zSize = cube->zSize;
  }

  void manhattanSphereRad(Point *start, Point *color, float tt, int colorI) {
    if (tt < 0) {
      return;
    }

    float t = tt / 3;
    float maxDist = 40;
    //long startT = millis();

    for(int x = 0; x < xSize; x++) {
      for(int y = 0; y < ySize; y++) {
        for(int z = 0; z < zSize; z++) {
          int xd = x - start->x;
          int yd = y - start->y;
          int zd = z - start->z;
          int dist = abs((xd * xd) + (yd * yd) + (zd * zd) - t * t);
          if (dist < maxDist) {
            float factor = (abs(maxDist - dist) / maxDist);
            float factor1 = factor;
            factor = factor * factor;
            factor = factor * factor1;
            factor = factor * factor;
            cube->setPixel(x, y, z, dimInt(rainbow[colorI], factor * brightness));
          }
        }
      }
    }
  }

  void sphere() {
    Point start = Point (rand() % xSize, rand() % ySize, rand() % zSize);

    float t = 0.1;
    while(t < 31.3) {
      manhattanSphereRad(&start, &start, t * 2, colorI);
      cube->show();
      colorI = (colorI + 2) % 180;
      //long start = millis();
      cube->resetPixels();
      //long duration = millis() - start;
      t = pow((pow(t, 1.5) + 2), 2.0/3.0);
    }
    delay(710);
  }

/*
void manhattanSphereRad(Point *start, Point *color, float tt, int colorI) {
  if (tt < 0) {
    return;
  }

  float t = tt / 3;
  float maxDist = 40;
  float dimness = 0.4;
  long startT = millis();

  for(int x = 0; x < xSize; x++) {
    for(int y = 0; y < ySize; y++) {
      for(int z = 0; z < zSize; z++) {
        int xd = x - start->x;
        int yd = y - start->y;
        int zd = z - start->z;
        int dist = abs((xd * xd) + (yd * yd) + (zd * zd) - t * t);
        if (dist < maxDist) {
          float factor = (abs(maxDist - dist) / maxDist);
          float factor1 = factor;
          factor = factor * factor;
          factor = factor * factor1;
          factor = factor * factor;
          cube.setPixel(x, y, z, dimInt(rainbow[colorI], factor * dimness));
        }
      }
    }
  }
}

int colorI = 0;

void sphere() {
  Point start = Point (rand() % xSize, rand() % ySize, rand() % zSize);

  float t = 0.1;
  while(t < 31.3) {
    manhattanSphereRad(&start, &start, t * 2, colorI);
    cube.show();
    colorI = (colorI + 2) % 180;
    long start = millis();
    cube.resetPixels();
    long duration = millis() - start;
    t = pow((pow(t, 1.5) + 2), 2.0/3.0);
  }
  delay(710);
}

void manhattanSphere() {
  Point start = Point (rand() % xSize, rand() % ySize, rand() % zSize);

  for (int t = 0; t < 75; t++) {
      manhattanSphereRad(&start, &start, t * 2, colorI);
      //manhattanSphereRad(&start, &start, t - 50, colorI);
      cube.show();
      //delay(9);
      colorI = (colorI + 2) % 180;
      long start = millis();
      cube.resetPixels();
      long duration = millis() - start;
      Serial.print("reset took: ");
      Serial.println(duration);
    }
  //delay(1000);
}
*/
};

#endif
