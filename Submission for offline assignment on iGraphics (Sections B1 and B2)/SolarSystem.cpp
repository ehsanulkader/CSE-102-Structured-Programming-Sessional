
# include "iGraphics.h"
# include "gl.h"

#define N_PLANETS 9


int g_sunX, g_sunY, g_sunR,lr,ud,orbit=0,satorbit=0;
double z=1;

int g_planetMajorAxisLen[N_PLANETS];
int g_planetMinorAxisLen[N_PLANETS];
int g_planetRadius[N_PLANETS];
int g_planetSweepAngle[N_PLANETS];
int g_planetDelSweepAngle[N_PLANETS];

int g_satelliteOrbitR, g_satelliteR, g_satelliteSweepAngle;

void drawStar(int x, int y, int r) {
    iSetColor(252,212,64);
    iFilledCircle(x, y, r);

}

void drawOrbit(int x, int y, int a, int b) {
    if(orbit%2==0){
        iSetColor(255, 255, 255);
        iEllipse(x, y, a, b);
    }
}

void drawPlanet(int x, int y, int orbitA, int orbitB, int planetR, int sweepAngle,int i) {
    double pi = 2*acos(0);
    double sweepRadian = sweepAngle * pi / 180;
    int planetX = x + orbitA * cos(sweepRadian);
    int planetY = y + orbitB * sin(sweepRadian);


    if (i == 0) {
            iSetColor(246, 0, 0);
	}

    if (i == 1) {
            iSetColor(55, 131, 255);
	}
	if (i == 2) {
                iSetColor(255, 238, 0);
	}
	if (i == 3) {
                iSetColor(255, 140, 0);
	}
	if (i == 4) {

                iSetColor(77, 233, 76);
	}
	if (i == 5) {
                iSetColor(72, 21, 170);
	}
	if (i == 6) {

                iSetColor(160, 51, 47);
	}
	if (i == 7) {

                iSetColor(93, 3, 153);
	}
	if (i == 8) {
                iSetColor(17, 178, 170);
	}

    //iSetColor(255, 0, 0);
    iFilledCircle(planetX, planetY, planetR*z);
}

void drawSatellite(
    int x,
    int y,
    int planetOrbitA,
    int planetOrbitB,
    int planetR,
    int planetSweepAngle,
    int satelliteOrbitR,
    int satelliteR,
    int satelliteSweepAngle,
    int m) {
    double pi = 2*acos(0);
    double planetSweepRadian = planetSweepAngle * pi / 180;
    double satelliteSweepRadian = (satelliteSweepAngle) * pi / 180;

    int planetX = x + planetOrbitA * cos(planetSweepRadian);
    int planetY = y + planetOrbitB * sin(planetSweepRadian);

    int satelliteOrbitA=satelliteOrbitR+(20*m);
    int satelliteOrbitB=satelliteOrbitR+(10*m);
     iSetColor(0, 0, 255);
    if(satorbit%2==0){
    iEllipse(planetX,planetY, satelliteOrbitA*z, satelliteOrbitB*z);
    }

    int satelliteX = planetX + z*satelliteOrbitA * cos(satelliteSweepRadian);
    int satelliteY = planetY + z*satelliteOrbitB * sin(satelliteSweepRadian);

    iSetColor(0, 255, 0);
    iFilledCircle(satelliteX, satelliteY, satelliteR*z);
    //iEllipse(x, y, a, b);
}

/*
	function iDraw() is called again and again by the system.
*/
void iDraw()
{
	int centerX, centerY;
	int i;

	iClear();

	//
	// The sun is at the left focal point of the eliptical orbit. So, the center of orbit
	// needs to be translated appropriately.
	//
    //iShowBMP(0,0,"stars.bmp");
	drawStar(g_sunX+lr, g_sunY+ud, g_sunR*z);

	for (i = 0; i < N_PLANETS; i++) {
        centerX = g_sunX +lr+ sqrt(pow(g_planetMajorAxisLen[i]*z, 2) - pow(g_planetMinorAxisLen[i]*z, 2));
        centerY = g_sunY+ud;
        drawOrbit(centerX, centerY, g_planetMajorAxisLen[i]*z, g_planetMinorAxisLen[i]*z);

        drawPlanet(
            centerX,
            centerY,
            g_planetMajorAxisLen[i]*z,
            g_planetMinorAxisLen[i]*z,
            g_planetRadius[i]*z,
            g_planetSweepAngle[i],
            i
            );
        int m;
        if (i == 2) {
            for(m=0;m<1;m++){
                drawSatellite(
                centerX,
                centerY,
                g_planetMajorAxisLen[i]*z,
                g_planetMinorAxisLen[i]*z,
                g_planetRadius[i]*z,
                g_planetSweepAngle[i],
                g_satelliteOrbitR*z,
                g_satelliteR*z,
                g_satelliteSweepAngle,m
                );
            }
        }
        if (i == 3) {
            for(m=0;m<2;m++){
                drawSatellite(
                centerX,
                centerY,
                g_planetMajorAxisLen[i]*z,
                g_planetMinorAxisLen[i]*z,
                g_planetRadius[i]*z,
                g_planetSweepAngle[i],
                g_satelliteOrbitR*z,
                g_satelliteR*z,
                g_satelliteSweepAngle,m
                );
            }
        }
         if (i == 4) {
            for(m=0;m<4;m++){
                    drawSatellite(
                centerX,
                centerY,
                g_planetMajorAxisLen[i]*z,
                g_planetMinorAxisLen[i]*z,
                g_planetRadius[i]*z,
                g_planetSweepAngle[i],
                g_satelliteOrbitR*z,
                g_satelliteR*z,
                g_satelliteSweepAngle,m
                );
            }
         }
         if (i == 5) {
                for(m=0;m<4;m++){
                drawSatellite(
                centerX,
                centerY,
                g_planetMajorAxisLen[i]*z,
                g_planetMinorAxisLen[i]*z,
                g_planetRadius[i]*z,
                g_planetSweepAngle[i],
                g_satelliteOrbitR*z,
                g_satelliteR*z,
                g_satelliteSweepAngle,m
                );
            }
         }
         if (i == 6) {
            for(m=0;m<2;m++){
                drawSatellite(
                centerX,
                centerY,
                g_planetMajorAxisLen[i]*z,
                g_planetMinorAxisLen[i]*z,
                g_planetRadius[i]*z,
                g_planetSweepAngle[i],
                g_satelliteOrbitR*z,
                g_satelliteR*z,
                g_satelliteSweepAngle,m
                );
            }
         }
         if (i == 7) {
            for(m=0;m<2;m++){
                drawSatellite(
                centerX,
                centerY,
                g_planetMajorAxisLen[i]*z,
                g_planetMinorAxisLen[i]*z,
                g_planetRadius[i]*z,
                g_planetSweepAngle[i],
                g_satelliteOrbitR*z,
                g_satelliteR*z,
                g_satelliteSweepAngle,m
                );
            }

         }


        }



	//iSetColor(255, 255, 255);
	iText(10, 10, "Press p for pause, r for resume, END for exit.");

}

/*
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouseMove(int mx, int my)
{
	//place your codes here
}

/*
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here
	}
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here
	}
}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.
*/
void iKeyboard(unsigned char key)
{
	if(key == 'p')
	{
		//do something with 'q'
		iPauseTimer(0);
	}
	if(key == 'r')
	{
		iResumeTimer(0);
	}
	if(key == 'i' ){
        z=z*1.2;
    }
    if(key == 'o'){
        z=z*0.8;
    }
     if(key == 'c' ){
        orbit++;
    }
     if(key == 's' ){
        satorbit++;
    }
	//place your codes for other keys here
}

/*
	function iSpecialKeyboard() is called whenver user hits special keys like-
	function keys, home, end, pg up, pg down, arraows etc. you have to use
	appropriate constants to detect them. A list is:
	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
*/
void iSpecialKeyboard(unsigned char key)
{

	if(key == GLUT_KEY_END)
	{
		exit(0);
	}
	if(key == GLUT_KEY_LEFT){
        lr-=5;
    }

    if(key == GLUT_KEY_RIGHT){
        lr+=5;
    }

    if(key == GLUT_KEY_DOWN){
        ud-=5;
    }

    if(key == GLUT_KEY_UP){
        ud+=5;
    }
	//place your codes for other keys here
}

void movePlanets(){
    const int g_dSatelliteSweepAngle = 10;

    int i;

    for (i = 0; i < N_PLANETS; i++) {
        g_planetSweepAngle[i] = ((g_planetSweepAngle[i] + g_planetDelSweepAngle[i]))%360;
        g_satelliteSweepAngle = ((g_satelliteSweepAngle + g_dSatelliteSweepAngle))%360;
    }
}

int main()
{
    const int CX_MAX = 1800;
    const int CY_MAX = 1200;

    // Initialize Sun's position and size.
    g_sunX = 400;
    g_sunY = CY_MAX/2;
    g_sunR = 30;

    g_planetMajorAxisLen[0] =90;
    g_planetMinorAxisLen[0] =80;
    g_planetRadius[0] = 6;
    g_planetSweepAngle[0] = 0;
    g_planetDelSweepAngle[0] = 9;

    g_planetMajorAxisLen[1] = 150;
    g_planetMinorAxisLen[1] = 120;
    g_planetRadius[1] = 9;
    g_planetSweepAngle[1] = 0;
    g_planetDelSweepAngle[1] = 8;

    g_planetMajorAxisLen[2] = 210;
    g_planetMinorAxisLen[2] = 160;
    g_planetRadius[2] = 9;
    g_planetSweepAngle[2] = 0;
    g_planetDelSweepAngle[2] = 7;

    g_planetMajorAxisLen[3] = 270;
    g_planetMinorAxisLen[3] = 200;
    g_planetRadius[3] = 8;
    g_planetSweepAngle[3] = 0;
    g_planetDelSweepAngle[3] = 6;

    g_planetMajorAxisLen[4] = 330;
    g_planetMinorAxisLen[4] = 240;
    g_planetRadius[4] = 20;
    g_planetSweepAngle[4] = 0;
    g_planetDelSweepAngle[4] = 5;

    g_planetMajorAxisLen[5] = 390;
    g_planetMinorAxisLen[5] = 280;
    g_planetRadius[5] = 18;
    g_planetSweepAngle[5] = 0;
    g_planetDelSweepAngle[5] = 4;

    g_planetMajorAxisLen[6] = 450;
    g_planetMinorAxisLen[6] = 320;
    g_planetRadius[6] = 15;
    g_planetSweepAngle[6] = 0;
    g_planetDelSweepAngle[6] = 3;

    g_planetMajorAxisLen[7] = 510;
    g_planetMinorAxisLen[7] = 360;
    g_planetRadius[7] = 15;
    g_planetSweepAngle[7] = 0;
    g_planetDelSweepAngle[7] = 2;

    g_planetMajorAxisLen[8] = 570;
    g_planetMinorAxisLen[8] = 400;
    g_planetRadius[8] = 5;
    g_planetSweepAngle[8] = 0;
    g_planetDelSweepAngle[8] = 1;

    // Initialize moon's orbit and radius
    g_satelliteOrbitR = 10;
    g_satelliteR = 4;

	//place your own initialization codes here.
	iSetTimer(20, movePlanets);
	iInitialize(CX_MAX, CY_MAX, "Solar system!");

	return 0;
}

