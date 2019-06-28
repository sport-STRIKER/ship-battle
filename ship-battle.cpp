#include "TXLib.h"


void stan_o_war (int x, int y);


void shapard_normandy (int x, int y);

void kama_pulya_3d (int x, int y,
                    int r,
                    COLORREF cvet);


void draw_kama_pulya_3d (int x, int y,
                         int rmax,
                         int color1, int color2);


double dist (int x1, int y1, int x2, int y2);


void ship_batle_game (int x1, int y1, int vx1, int vy1,
                      int x2, int y2, int vx2, int vy2,
                      int dt);




int main()
{
  txCreateWindow (1000, 600);

  ship_batle_game (116, 143, 0, 5,
                   624, 143, 0, 5,
                   1);

  //stan_o_war (116, 143);

  //shapard_normandy (413, 143);

  //kama_pulya_3d ();

  /*draw_kama_pulya_3d (200, 200,
                        20,
                        80, 0);*/
  return 0;
}




void stan_o_war (int x, int y)
{
  int x_machta1 = x;
  int y_machta1 = y - 56;


  int x_korma1 = x - 33;
  int y_korma1 = y;


  int x_korma2 = x + 35;
  int y_korma2 = y + 37;


  int x_parus1 = x_machta1;
  int y_parus1 = y_machta1;


  int x_parus2 = x_korma1;
  int y_parus2 = y_korma1;


  int x_parus3 = x_korma2;
  int y_parus3 = y_korma1;


  txSetColor (RGB (185, 122, 87));

  txLine (x_machta1, y_machta1,
          x, y);

  txSetColor (TX_WHITE);
  txSetFillColor (TX_WHITE);

  txLine (x_parus1, y_parus1,
          x_parus2, y_parus2);
  txLine (x_parus1, y_parus1,
          x_parus3, y_parus3);


  txSetColor (RGB (185, 122, 87));
  txSetFillColor (TX_BLACK);

  txRectangle (x_korma1, y_korma1,
               x_korma2, y_korma2);
}





void shapard_normandy (int x, int y)
{
  int x_machta1 = x;
  int y_machta1 = y - 56;


  int x_korma1 = x - 33;
  int y_korma1 = y;


  int x_korma2 = x + 35;
  int y_korma2 = y + 37;


  int x_parus1 = x_machta1;
  int y_parus1 = y_machta1;


  int x_parus2 = x_korma1;
  int y_parus2 = y_korma1;


  int x_parus3 = x_korma2;
  int y_parus3 = y_korma1;


  txSetColor (TX_GREEN);

  txLine (x_machta1, y_machta1,
          x, y);

  txSetColor (TX_WHITE);
  txSetFillColor (TX_WHITE);

  txLine (x_parus1, y_parus1,
          x_parus2, y_parus2);
  txLine (x_parus1, y_parus1,
          x_parus3, y_parus3);


  txSetColor (TX_RED);
  txSetFillColor (TX_BLACK);

  txRectangle (x_korma1, y_korma1,
               x_korma2, y_korma2);
}




void kama_pulya_3d (int x, int y,
                    int r,
                    COLORREF cvet)
{
  txSetColor (cvet);
  txSetFillColor (cvet);

  txCircle (x, y, r);
}




void draw_kama_pulya_3d (int x, int y,
                         int rmax,
                         int color1, int color2)
{
  int t = 0;


  while (t <= 50)
  {
    int radius = rmax - (rmax / 50.0) * t;
    COLORREF cvet = RGB (color1 + (color1 / 25.0) * t, color2 + (color2 / 25.0) * t, 0);


    kama_pulya_3d (x, y,
                   radius,
                   cvet);

    t++;
  }
}




double dist (int x1, int y1, int x2, int y2)
{
  return sqrt ((x2  - x1) * (x2  - x1) + (y2 - y1) * (y2 - y1));
}




void ship_batle_game (int x1, int y1, int vx1, int vy1,
                      int x2, int y2, int vx2, int vy2,
                      int dt)

{
  int x3 = x1, y3 = y1, vx3 = 4;

  int x4 = x2, y4 = y2, vx4 = 4;

  int taa = 0;


  while (true)
  {
    txSetColor (TX_BLACK);

    txSetFillColor (TX_BLACK);

    txClear ();


    double d1 = dist (x1, y1,
                      x4, y4);
    double d2 = dist (x2, y2,
                      x3, y3);


    if (d1 < 35)
    {
      txMessageBox ("Ты офца ежжи!!");

      break;
    }


    if (d2 < 35)
    {
      txMessageBox ("Красаувчек ежжи!!");

      break;
    }


    if (GetAsyncKeyState (VK_SPACE))
    {
        taa = 1;

        x3 = x1;

        y3 = y1;

        x4 = x2;

        y4 = y2;

    }


    if (taa == 1)
    {
        draw_kama_pulya_3d (x3, y3,
                            10,
                            80, 0);

        draw_kama_pulya_3d (x4, y4,
                            10,
                            0, 80);


        txSetColor (TX_RED);

        txTextOut (355, 35, "шааа!!");


        txSetColor (TX_GREEN);

        txTextOut (555, 35, "Будь Дерзким!!");
    }


    if (GetAsyncKeyState (VK_UP))
        (vy1)--;

    if (GetAsyncKeyState (VK_DOWN))
        (vy1)++;

    stan_o_war (x1, y1);


    shapard_normandy (x2, y2);


    if (x1 < 0)
        (vx1) = - (vx1);

    if (x1 > 1000)
        (vx1) = - (vx1);

    if (y1 < 0)
        (vy1) = - (vy1);

    if (y1 > 600)
        (vy1) = - (vy1);


    if (x2 < 0)
        (vx2) = - (vx2);

    if (x2 > 1000)
        (vx2) = - (vx2);

    if (y2 < 0)
        (vy2) = - (vy2);

    if (y2 > 600)
        (vy2) = - (vy2);


    y1 = y1 + vy1 * dt;


    y2 = y2 + vy2 * dt;


    x3 = x3 + vx3 * dt;


    x4 = x4 - vx4 * dt;


    txSleep (25);
  }
}




