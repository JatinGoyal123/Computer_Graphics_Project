#include <GL/glut.h>
#include <GL/gl.h>
#include <stdlib.h>
#define SPEED 20.0 // speed of traffic
float i = 0.0;     // movement of car
float j = 0.0;     // movement of ship
float m = 0.0;     // movement of clouds
float n = 0.0;     // movement of plane along x-axis
float o = 0.0;     //  and y-axis
float c = 0.0;     // movement of comet
int light = 1;     // 1 for green-light, 0 for red-light
int day = 1;       // 1 for day ,0 for night
int plane = 0;     // 1 for plane
int comet = 0;     // 1 for comet

void draw_pixel(int cx, int cy)
{
    glBegin(GL_POINTS);
    glVertex2i(cx, cy);
    glEnd();
}
void plotpixels(int h, int k, int x, int y)
{
    draw_pixel(x + h, y + k);
    draw_pixel(-x + h, y + k);
    draw_pixel(x + h, -y + k);
    draw_pixel(-x + h, -y + k);
    draw_pixel(y + h, x + k);
    draw_pixel(-y + h, x + k);
    draw_pixel(y + h, -x + k);
    draw_pixel(-y + h, -x + k);
}
// Circle da code (Midpoint Algo naal)
void draw_circle(int h, int k, int r)
{
    int d = 1 - r, x = 0, y = r;
    while (x < y)
    {
        plotpixels(h, k, x, y);
        if (d < 0)
            d += 2 * x + 3;
        else
        {
            d += 2 * (x - y) + 5;
            --y;
        }
        ++x;
    }
    plotpixels(h, k, x, y);
}
void draw_object()
{
    int l;
    if (day == 1)
    {
        glColor3f(0.52, 0.80, 0.92);
        glBegin(GL_POLYGON);
        glVertex2f(0, 0);
        glVertex2f(1100, 0);
        glVertex2f(1100, 700);
        glVertex2f(0, 700);
        glEnd();

        // sun
        for (l = 0; l <= 35; l++)
        {
            glColor3f(1.0, 0.9, 0.0);
            draw_circle(100, 625, l);
        }
        // plane
        if (plane == 1)
        {
            glColor3f(1.0, 1.0, 1.0);
            glBegin(GL_POLYGON);
            glVertex2f(925 + n, 625 + o);
            glVertex2f(950 + n, 640 + o);
            glVertex2f(1015 + n, 640 + o);
            glVertex2f(1030 + n, 650 + o);
            glVertex2f(1050 + n, 650 + o);
            glVertex2f(1010 + n, 625 + o);
            glEnd();
            glColor3f(0.8, 0.8, 0.8);
        }
        // badal
        for (l = 0; l <= 20; l++)
        {
            glColor3f(1.0, 1.0, 1.0);
            draw_circle(160 + m, 625, l);
        }
        for (l = 0; l <= 35; l++)
        {
            glColor3f(1.0, 1.0, 1.0);
            draw_circle(200 + m, 625, l);
            draw_circle(225 + m, 625, l);
        }
        for (l = 0; l <= 20; l++)
        {
            glColor3f(1.0, 1.0, 1.0);
            draw_circle(265 + m, 625, l);
        }
        // badal2
        for (l = 0; l <= 20; l++)
        {
            glColor3f(1.0, 1.0, 1.0);
            draw_circle(370 + m, 615, l);
        }
        for (l = 0; l <= 35; l++)
        {

            glColor3f(1.0, 1.0, 1.0);
            draw_circle(410 + m, 615, l);
            draw_circle(435 + m, 615, l);
            draw_circle(470 + m, 615, l);
        }

        for (l = 0; l <= 20; l++)
        {
            glColor3f(1.0, 1.0, 1.0);
            draw_circle(500 + m, 615, l);
        }
    }
    else
    {
        glColor3f(0.4, 0.4, 0.4);
        glBegin(GL_POLYGON);
        glVertex2f(0, 0);
        glVertex2f(1100, 0);
        glVertex2f(1100, 700);
        glVertex2f(0, 700);
        glEnd();

        // MOON
        for (l = 0; l <= 35; l++)
        {
            glColor3f(1.0, 1.0, 1.0);
            draw_circle(100, 625, l);
        }

        // plane
        if (plane == 1)
        {
            glColor3f(1.0, 1.0, 1.0);
            glBegin(GL_POLYGON);
            glVertex2f(925 + n, 625 + o);
            glVertex2f(950 + n, 640 + o);
            glVertex2f(1015 + n, 640 + o);
            glVertex2f(1030 + n, 650 + o);
            glVertex2f(1050 + n, 650 + o);
            glVertex2f(1010 + n, 625 + o);
            glEnd();
        }
        // comet
        if (comet == 1)
        {
            for (l = 0; l <= 7; l++)
            {
                glColor3f(1.0, 1.0, 1.0);
                draw_circle(300 + c, 675, l);
            }
            glColor3f(1.0, 1.0, 1.0);
            glBegin(GL_TRIANGLES);
            glVertex2f(200 + c, 675);
            glVertex2f(300 + c, 682);
            glVertex2f(300 + c, 668);
            glEnd();
        }

        glColor3f(1.0, 1.0, 1.0);
        glBegin(GL_TRIANGLES);
        glVertex2f(575, 653);
        glVertex2f(570, 645);
        glVertex2f(580, 645);
        glVertex2f(575, 642);
        glVertex2f(570, 650);
        glVertex2f(580, 650);
        glEnd();
        // star2
        glColor3f(1.0, 1.0, 1.0);
        glBegin(GL_TRIANGLES);
        glVertex2f(975, 643);
        glVertex2f(970, 635);
        glVertex2f(980, 635);
        glVertex2f(975, 632);
        glVertex2f(970, 640);
        glVertex2f(980, 640);
        glEnd();
        // star3
        glColor3f(1.0, 1.0, 1.0);
        glBegin(GL_TRIANGLES);
        glVertex2f(875, 543);
        glVertex2f(870, 535);
        glVertex2f(880, 535);
        glVertex2f(875, 532);
        glVertex2f(870, 540);
        glVertex2f(880, 540);
        glEnd();
        // star4
        glColor3f(1.0, 1.0, 1.0);
        glBegin(GL_TRIANGLES);
        glVertex2f(375, 598);
        glVertex2f(370, 590);
        glVertex2f(380, 590);
        glVertex2f(375, 587);
        glVertex2f(370, 595);
        glVertex2f(380, 595);
        glEnd();
    }
    // TREE 1
    glColor3f(0.9, 0.2, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(350, 325);
    glVertex2f(350, 395);
    glVertex2f(365, 395);
    glVertex2f(365, 325);
    glEnd();
    for (l = 0; l <= 30; l++)
    {
        glColor3f(0.0, 0.5, 0.0);
        draw_circle(340, 400, l);
        draw_circle(380, 400, l);
    }
    for (l = 0; l <= 25; l++)
    {
        glColor3f(0.0, 0.5, 0.0);
        draw_circle(350, 440, l);
        draw_circle(370, 440, l);
    }
    for (l = 0; l <= 20; l++)
    {
        glColor3f(0.0, 0.5, 0.0);
        draw_circle(360, 465, l);
    }

    // TREE 2
    glColor3f(0.9, 0.2, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(250, 325);
    glVertex2f(250, 395);
    glVertex2f(265, 395);
    glVertex2f(265, 325);
    glEnd();
    for (l = 0; l <= 30; l++)
    {
        glColor3f(0.0, 0.5, 0.0);
        draw_circle(240, 400, l);
        draw_circle(280, 400, l);
    }
    for (l = 0; l <= 25; l++)
    {
        glColor3f(0.0, 0.5, 0.0);
        draw_circle(250, 440, l);
        draw_circle(270, 440, l);
    }
    for (l = 0; l <= 20; l++)
    {
        glColor3f(0.0, 0.5, 0.0);
        draw_circle(260, 465, l);
    }
    // HOSPITAL
    glColor3f(0.5, 0.5, 0.5);
    glBegin(GL_POLYGON);
    glVertex2f(420, 330);
    glVertex2f(420, 380);
    glVertex2f(570, 380);
    glVertex2f(570, 330);
    glEnd();

    glColor4f(0.0, 1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex2f(570, 330);
    glVertex2f(570, 380);
    glVertex2f(630, 380);
    glVertex2f(630, 330);
    glEnd();

    glColor3f(0.5, 0.5, 0.5);
    glBegin(GL_POLYGON);
    glVertex2f(630, 330);
    glVertex2f(630, 380);
    glVertex2f(780, 380);
    glVertex2f(780, 330);
    glEnd();

    glColor3f(0.0, 0.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex2f(495, 370);
    glVertex2f(533, 400);
    glVertex2f(668, 400);
    glVertex2f(705, 370);
    glEnd();
    glColor3f(2.0, 0.5, 1.0);
    glBegin(GL_POLYGON);
    glVertex2f(533, 400);
    glVertex2f(533, 620);
    glVertex2f(668, 620);
    glVertex2f(668, 400);
    glEnd();
    glColor3f(0.5, 0.5, 0.5);
    glBegin(GL_POLYGON);
    glVertex2f(440, 380);
    glVertex2f(440, 600);
    glVertex2f(533, 600);
    glVertex2f(533, 400);
    glVertex2f(508, 380);
    glVertex2f(440, 380);
    glEnd();
    glColor3f(0.5, 0.5, 0.5);
    glBegin(GL_POLYGON);
    glVertex2f(668, 600);
    glVertex2f(760, 600);
    glVertex2f(760, 380);
    glVertex2f(692, 380);
    glVertex2f(668, 400);
    glVertex2f(668, 600);
    glEnd();
    if (day == 1)
    {
        glColor3f(0.0, 0.0, 1.0);
        glBegin(GL_POLYGON);
        glVertex2f(477, 590);
        glVertex2f(507, 590);
        glVertex2f(507, 560);
        glVertex2f(477, 560);
        glEnd();
        glColor3f(0.0, 0.0, 1.0);
        glBegin(GL_POLYGON);
        glVertex2f(477, 520);
        glVertex2f(507, 520);
        glVertex2f(507, 490);
        glVertex2f(477, 490);
        glEnd();
        glColor3f(0.0, 0.0, 1.0);
        glBegin(GL_POLYGON);
        glVertex2f(477, 450);
        glVertex2f(507, 450);
        glVertex2f(507, 420);
        glVertex2f(477, 420);
        glEnd();
        glColor3f(0.0, 0.0, 1.0);
        glBegin(GL_POLYGON);
        glVertex2f(700, 590);
        glVertex2f(730, 590);
        glVertex2f(730, 560);
        glVertex2f(700, 560);
        glEnd();
        glColor3f(0.0, 0.0, 1.0);
        glBegin(GL_POLYGON);
        glVertex2f(700, 520);
        glVertex2f(730, 520);
        glVertex2f(730, 490);
        glVertex2f(700, 490);
        glEnd();
        glColor3f(0.0, 0.0, 1.0);
        glBegin(GL_POLYGON);
        glVertex2f(700, 450);
        glVertex2f(730, 450);
        glVertex2f(730, 420);
        glVertex2f(700, 420);
        glEnd();
        glColor3f(0.0, 0.0, 1.0);
        glBegin(GL_POLYGON);
        glVertex2f(563, 580);
        glVertex2f(563, 500);
        glVertex2f(583, 500);
        glVertex2f(583, 580);
        glVertex2f(563, 500);
        glEnd();

        glColor3f(0.0, 0.0, 1.0);
        glBegin(GL_POLYGON);
        glVertex2f(583, 550);
        glVertex2f(623, 550);
        glVertex2f(623, 530);
        glVertex2f(583, 530);
        glVertex2f(583, 550);
        glEnd();

        glColor3f(0.0, 0.0, 1.0);
        glBegin(GL_POLYGON);
        glVertex2f(623, 580);
        glVertex2f(643, 580);
        glVertex2f(643, 500);
        glVertex2f(623, 500);
        glVertex2f(623, 580);
        glEnd();
    }
    else
    {
        glColor3f(1.0, 1.0, 0.0);
        glBegin(GL_POLYGON);
        glVertex2f(477, 590);
        glVertex2f(507, 590);
        glVertex2f(507, 560);
        glVertex2f(477, 560);
        glEnd();
        glColor3f(1.0, 1.0, 0.0);
        glBegin(GL_POLYGON);
        glVertex2f(477, 520);
        glVertex2f(507, 520);
        glVertex2f(507, 490);
        glVertex2f(477, 490);
        glEnd();
        glColor3f(1.0, 1.0, 0.0);
        glBegin(GL_POLYGON);
        glVertex2f(477, 450);
        glVertex2f(507, 450);
        glVertex2f(507, 420);
        glVertex2f(477, 420);
        glEnd();
        glColor3f(1.0, 1.0, 0.0);
        glBegin(GL_POLYGON);
        glVertex2f(700, 590);
        glVertex2f(730, 590);
        glVertex2f(730, 560);
        glVertex2f(700, 560);
        glEnd();
        glColor3f(1.0, 1.0, 0.0);
        glBegin(GL_POLYGON);
        glVertex2f(700, 520);
        glVertex2f(730, 520);
        glVertex2f(730, 490);
        glVertex2f(700, 490);
        glEnd();
        glColor3f(1.0, 1.0, 0.0);
        glBegin(GL_POLYGON);
        glVertex2f(700, 450);
        glVertex2f(730, 450);
        glVertex2f(730, 420);
        glVertex2f(700, 420);
        glEnd();
        glColor3f(1.0, 1.0, 0.0);
        glBegin(GL_POLYGON);
        glVertex2f(563, 580);
        glVertex2f(563, 500);
        glVertex2f(583, 500);
        glVertex2f(583, 580);
        glVertex2f(563, 500);
        glEnd();
        glColor3f(1.0, 1.0, 0.0);
        glBegin(GL_POLYGON);
        glVertex2f(583, 550);
        glVertex2f(623, 550);
        glVertex2f(623, 530);
        glVertex2f(583, 530);
        glVertex2f(583, 550);
        glEnd();

        glColor3f(1.0, 1.0, 0.0);
        glBegin(GL_POLYGON);
        glVertex2f(623, 580);
        glVertex2f(643, 580);
        glVertex2f(643, 500);
        glVertex2f(623, 500);
        glVertex2f(623, 580);
        glEnd();
    }

    // Cable (Bijli)
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(0, 100);
    glVertex2f(0, 320);
    glVertex2f(1100, 320);
    glVertex2f(1100, 100);
    glEnd();

    // WHITE STRAP's
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex2f(0, 225);
    glVertex2f(0, 245);
    glVertex2f(70, 245);
    glVertex2f(70, 225);
    glEnd();

    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex2f(100, 225);
    glVertex2f(100, 245);
    glVertex2f(190, 245);
    glVertex2f(190, 225);
    glEnd();

    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex2f(220, 225);
    glVertex2f(220, 245);
    glVertex2f(310, 245);
    glVertex2f(310, 225);
    glEnd();

    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex2f(340, 225);
    glVertex2f(340, 245);
    glVertex2f(430, 245);
    glVertex2f(430, 225);
    glEnd();

    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex2f(460, 225);
    glVertex2f(460, 245);
    glVertex2f(550, 245);
    glVertex2f(550, 225);
    glEnd();

    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex2f(580, 225);
    glVertex2f(580, 245);
    glVertex2f(670, 245);
    glVertex2f(670, 225);
    glEnd();

    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex2f(700, 225);
    glVertex2f(700, 245);
    glVertex2f(790, 245);
    glVertex2f(790, 225);
    glEnd();

    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex2f(820, 225);
    glVertex2f(820, 245);
    glVertex2f(910, 245);
    glVertex2f(910, 225);
    glEnd();

    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex2f(940, 225);
    glVertex2f(940, 245);
    glVertex2f(1030, 245);
    glVertex2f(1030, 225);
    glEnd();

    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex2f(1060, 225);
    glVertex2f(1060, 245);
    glVertex2f(1100, 245);
    glVertex2f(1100, 225);
    glEnd();

    // BLACK SADAK
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(0, 340);
    glVertex2f(0, 345);
    glVertex2f(1100, 345);
    glVertex2f(1100, 340);
    glEnd();

    // POND
    if (day == 1)
    {
        glColor3f(0.0, 0.9, 0.9);
        glBegin(GL_POLYGON);
        glVertex2f(0, 0);
        glVertex2f(0, 150);
        glVertex2f(1100, 150);
        glVertex2f(1100, 0);
        glEnd();
    }
    else
    {
        glColor3f(0.0, 0.0, 0.9);
        glBegin(GL_POLYGON);
        glVertex2f(0, 0);
        glVertex2f(0, 150);
        glVertex2f(1100, 150);
        glVertex2f(1100, 0);
        glEnd();
    }

    // BIJLI BUS

    // LOWER PART
    glColor3f(0.9, 0.2, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(100 + i, 200);
    glVertex2f(350 + i, 200);
    glVertex2f(350 + i, 240);
    glVertex2f(100 + i, 240);
    glEnd();

    // UPPER PART
    glColor3f(0.7, 0.8, 0.2);
    glBegin(GL_POLYGON);
    glVertex2f(100 + i, 240);
    glVertex2f(350 + i, 240);
    glVertex2f(350 + i, 300);
    glVertex2f(100 + i, 300);
    glEnd();

    // FRONT LIGHT
    glColor3f(0.1, 0.1, 0.2);
    glBegin(GL_POLYGON);
    glVertex2f(330 + i, 215);
    glVertex2f(350 + i, 215);
    glVertex2f(350 + i, 235);
    glVertex2f(330 + i, 235);
    glEnd();

    // UPPER BOX
    glColor3f(0.7, 0.8, 0.2);
    glBegin(GL_POLYGON);
    glVertex2f(200 + i, 300);
    glVertex2f(270 + i, 300);
    glVertex2f(270 + i, 310);
    glVertex2f(200 + i, 310);
    glEnd();

    // UPPER CABLE
    glColor3f(0.7, 0.8, 0.2);
    glBegin(GL_POLYGON);
    glVertex2f(240 + i, 310);
    glVertex2f(250 + i, 310);
    glVertex2f(200 + i, 340);
    glVertex2f(190 + i, 340);
    glEnd();

    // UPPER MOVING CABLE
    glColor3f(0.7, 0.8, 0.2);
    glBegin(GL_POLYGON);
    glVertex2f(140 + i, 340);
    glVertex2f(280 + i, 340);
    glVertex2f(280 + i, 345);
    glVertex2f(140 + i, 345);
    glEnd();

    // MIRROR 1
    glColor3f(0.5, 0.5, 0.5);
    glBegin(GL_POLYGON);
    glVertex2f(125 + i, 255);
    glVertex2f(165 + i, 255);
    glVertex2f(165 + i, 290);
    glVertex2f(125 + i, 290);
    glEnd();

    // MIRROR 2
    glColor3f(0.5, 0.5, 0.5);
    glBegin(GL_POLYGON);
    glVertex2f(175 + i, 255);
    glVertex2f(215 + i, 255);
    glVertex2f(215 + i, 290);
    glVertex2f(175 + i, 290);
    glEnd();

    // MIRROR 3
    glColor3f(0.5, 0.5, 0.5);
    glBegin(GL_POLYGON);
    glVertex2f(225 + i, 255);
    glVertex2f(265 + i, 255);
    glVertex2f(265 + i, 290);
    glVertex2f(225 + i, 290);
    glEnd();

    // MIRROR 4
    glColor3f(0.5, 0.5, 0.5);
    glBegin(GL_POLYGON);
    glVertex2f(275 + i, 250);
    glVertex2f(325 + i, 250);
    glVertex2f(325 + i, 290);
    glVertex2f(275 + i, 290);
    glEnd();

    // TYRES
    for (l = 0; l < 20; l++)
    {
        glColor3f(0.5, 0.5, 0.5);
        draw_circle(170 + i, 200, l);
        draw_circle(280 + i, 200, l);
    }
    // TRAFFIC SIGNAL
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(1060, 160);
    glVertex2f(1060, 350);
    glVertex2f(1070, 350);
    glVertex2f(1070, 160);
    glEnd();
    glColor3f(0.7, 0.7, 0.7);
    glBegin(GL_POLYGON);
    glVertex2f(1040, 350);
    glVertex2f(1040, 500);
    glVertex2f(1090, 500);
    glVertex2f(1090, 350);
    glEnd();
    // Initial Traffic light hai
    for (l = 0; l <= 20; l++)
    {
        glColor3f(0.0, 0.0, 0.0);
        draw_circle(1065, 475, l);
        glColor3f(0.7, 0.7, 0.0); // Yellow traffic light
        draw_circle(1065, 425, l);
        glColor3f(0.0, 0.0, 0.0);
        draw_circle(1065, 375, l);
    }
    // SHIP-PAANI

    // LOWER PART
    glColor3f(1, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2f(50 + j, 20);
    glVertex2f(140 + j, 20);
    glVertex2f(160 + j, 40);
    glVertex2f(30 + j, 40);
    glEnd();

    // MIDDLE PART OF SHIP
    glColor3f(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2f(60 + j, 40);
    glVertex2f(130 + j, 40);
    glVertex2f(130 + j, 80);
    glVertex2f(60 + j, 80);
    glEnd();

    // MIRROR 1
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex2f(70 + j, 50);
    glVertex2f(85 + j, 50);
    glVertex2f(85 + j, 70);
    glVertex2f(70 + j, 70);
    glEnd();

    // MIRROR 2
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex2f(90 + j, 50);
    glVertex2f(105 + j, 50);
    glVertex2f(105 + j, 70);
    glVertex2f(90 + j, 70);
    glEnd();

    // MIRROR 3
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex2f(110 + j, 50);
    glVertex2f(125 + j, 50);
    glVertex2f(125 + j, 70);
    glVertex2f(110 + j, 70);
    glEnd();

    // UPPER PART OF SHIP
    glColor3f(0.3, 0.4, 0.5);
    glBegin(GL_POLYGON);
    glVertex2f(30 + j, 80);
    glVertex2f(160 + j, 80);
    glVertex2f(160 + j, 90);
    glVertex2f(30 + j, 90);
    glEnd();
    glFlush();
}
void traffic_light()
{
    int l;
    if (light == 1)
    {
        for (l = 0; l <= 20; l++)
        {
            glColor3f(0.4, 0.0, 0.0);
            draw_circle(1065, 475, l);
            glColor3f(0.0, 0.7, 0.0);
            draw_circle(1065, 375, l);
        }
    }
    else
    {
        for (l = 0; l <= 20; l++)
        {
            glColor3f(1.0, 0.0, 0.0);
            draw_circle(1065, 475, l);
            glColor3f(0.0, 0.35, 0.0);
            draw_circle(1065, 375, l);
        }
    }
}
void idle()
{
    glClearColor(1.0, 1.0, 1.0, 1.0);
    if (light == 0 && (i >= 1200 && i <= 1620))
    {
        i += SPEED / 10;
        j += SPEED / 10;
        ++m;
        n -= 2;
        o += 0.2;
        c += 2;
    }
    if (light == 0)
    {
        i = i;
        j += SPEED / 10;
        ++m;
        n -= 2;
        o += 0.2;
        c += 2;
    }
    else
    {
        i += SPEED / 10;
        j += SPEED / 10;
        ++m;
        n -= 2;
        o += 0.2;
        c += 2;
    }
    if (i > 1630)
        i = 0.0;
    if (j > 1630)
        j = 0.0;
    if (m > 1100)
        m = 0.0;
    if (o > 75)
        plane = 0;
    if (c > 500)
        comet = 0;
    glutPostRedisplay();
}
void keyboardFunc(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'g':
    case 'G':
        light = 1;
        break;
    case 'r':
    case 'R':
        light = 0;
        break;
    case 'd':
    case 'D':
        day = 1;
        break;
    case 'n':
    case 'N':
        day = 0;
        break;
    };
}
void main_menu(int index)
{
    switch (index)
    {
    case 1:
        if (index == 1)
        {
            plane = 1;
            o = n = 0.0;
        }
        break;
    case 2:
        if (index == 2)
        {
            comet = 1;
            c = 0.0;
        }
        break;
    case 3:
        if (index == 3)
        {
            exit(0);
        }
        break;
    }
}
void myinit()
{
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glColor3f(0.0, 0.0, 1.0);
    glPointSize(2.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 1100.0, 0.0, 700.0);
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    draw_object();
    traffic_light();
    glFlush();
}
int main(int argc, char *argv[])
{
    int c_menu;
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1100.0, 700.0);
    glutInitWindowPosition(250, 0);
    glutCreateWindow("Landscape Simulation");
    myinit();
    glutDisplayFunc(display);
    glutIdleFunc(idle);
    glutKeyboardFunc(keyboardFunc);
    c_menu = glutCreateMenu(main_menu); // Calls the function
    glutAddMenuEntry("Aeroplane", 1);
    glutAddMenuEntry("Comet", 2);
    glutAddMenuEntry("Quit", 3);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
    glutMainLoop();
}
