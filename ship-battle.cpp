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


void ship_batle_game (int x_stan_o_war, int y_stan_o_war, int vy_stan_o_war,
                      int x_shapard_normandy, int y_shapard_normandy, int vy_shapard_normandy,
                      int dt);

void control_ship_battle (int *vy,
                          int up, int down);


void move_ship_battle (int *y, int *vy,
                       int *dt);


void move_kama_pulya_3D (int *x, int *vx,
                         int *dt,
                         int minus_plus);

void control_kama_pulya_3D (int *x1, int *y1,
                            int *x2, int *y2,
                            int *x3, int *y3,
                            int *x4, int *y4,
                            int space,
                            int *taa);





int main()
{
  txCreateWindow (1000, 600);

  ship_batle_game (116, 143, 5,
                   624, 143, 5,
                   1);

  //control_ship_battle ();

  //control_kama_pulya_3D ();

  //move_ship_batle ();

  //move_kama_pulya_3D ();

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




void ship_batle_game (int x_stan_o_war, int y_stan_o_war, int vy_stan_o_war,
                      int x_shapard_normandy, int y_shapard_normandy, int vy_shapard_normandy,
                      int dt)

{
  int x_kama_pulya_3d_1 = x_stan_o_war, y_kama_pulya_3d_1 = y_stan_o_war, vx_kama_pulya_3d_1 = 4;

  int x_kama_pulya_3d_2 = x_shapard_normandy, y_kama_pulya_3d_2 = y_shapard_normandy, vx_kama_pulya_3d_2 = 4;

  int taa = 0;


  while (true)
  {
    txBegin();

    txSetColor (TX_BLACK);

    txSetFillColor (TX_BLACK);

    txClear ();


    double d1 = dist (x_stan_o_war, y_stan_o_war,
                      x_kama_pulya_3d_2, y_kama_pulya_3d_2);
    double d2 = dist (x_shapard_normandy, y_shapard_normandy,
                      x_kama_pulya_3d_1, y_kama_pulya_3d_1);


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


    control_kama_pulya_3D (&x_stan_o_war, &y_stan_o_war,
                           &x_shapard_normandy, &y_shapard_normandy,
                           &x_kama_pulya_3d_1, &y_kama_pulya_3d_1,
                           &x_kama_pulya_3d_2, &y_kama_pulya_3d_2,
                           VK_SPACE,
                           &taa);


    control_ship_battle (&vy_stan_o_war,
                         VK_UP, VK_DOWN);
    move_ship_battle (&y_stan_o_war, &vy_stan_o_war,
                      &dt);

    stan_o_war (x_stan_o_war, y_stan_o_war);


    move_ship_battle (&y_shapard_normandy, &vy_shapard_normandy,
                      &dt);

    shapard_normandy (x_shapard_normandy, y_shapard_normandy);


    move_kama_pulya_3D (&x_kama_pulya_3d_1, &vx_kama_pulya_3d_1,
                        &dt,
                        0);


    move_kama_pulya_3D (&x_kama_pulya_3d_2, &vx_kama_pulya_3d_2,
                        &dt,
                        1);


    txSleep (25);
  }
}




void move_ship_battle (int *y, int *vy,
                       int *dt)
{
  if ((*y) < 0)
    (*vy) = - (*vy);

  if ((*y) > 600)
    (*vy) = - (*vy);


  *y = *y + *vy * *dt;
}




void move_kama_pulya_3D (int *x, int *vx,
                         int *dt,
                         int minus_plus)
{
  if (minus_plus == 0)
  {
  *x = *x + *vx * *dt;
  }

  if (minus_plus == 1)
  {
  *x = *x - *vx * *dt;
  }
}




void control_ship_battle (int *vy,
                          int up, int down)
{
if (GetAsyncKeyState (up))
        (*vy)--;

if (GetAsyncKeyState (down))
        (*vy)++;
}




void control_kama_pulya_3D (int *x1, int *y1,
                            int *x2, int *y2,
                            int *x3, int *y3,
                            int *x4, int *y4,
                            int space,
                            int *taa)
{

  if (GetAsyncKeyState (space))
  {
    *taa = 1;

    *x3 = *x1;

    *y3 = *y1;

    *x4 = *x2;

    *y4 = *y2;

  }


  if ((*taa) == 1)
  {
    draw_kama_pulya_3d (*x3, *y3,
                            10,
                            80, 0);


    draw_kama_pulya_3d (*x4, *y4,
                            10,
                            0, 80);


    txSetColor (TX_RED);

    txTextOut (355, 35, "шааа!!");


    txSetColor (TX_GREEN);

    txTextOut (555, 35, "Будь Дерзким!!");
  }
}
