#include "TXLib.h"

const int Strike1 = 30;
const int Strike2 = 35;

struct korabl
{
  int x;

  int y;
};


void stan_o_war(int x, int y, HDC ship);


void shapard_normandy(int x, int y, HDC ship);


void kama_pulya_3d(int x, int y,
                   int r,
                   COLORREF cvet);


void draw_kama_pulya_3d(int x, int y,
                        int rmax,
                        int color1, int color2);


double dist(int x1, int y1, int x2, int y2);


void ship_batle_game(struct korabl ship_stan_o_war, int vy_stan_o_war,
                     struct korabl ship_shapard_normandy, int vy_shapard_normandy,
                     int dt);


void control_ship_battle(int *vy_ship,
                         int up, int down,
                         struct korabl *stan_o_war,
                         struct korabl *shapard_normandy,
                         int *x_kama_pulya3, int *y_kama_pulya3,
                         int *x_kama_pulya4, int *y_kama_pulya4,
                         int space,
                         int *taa);


void move_ship_battle(struct korabl *ship, int *vy_ship,
                      int *x_kama_pulya, int *vx_kama_pulya,
                      int *dt,
                      int minus_plus);


int main()
{
  txCreateWindow (1000, 600);

  struct korabl stan_o_war;

  stan_o_war.x = 116;

  stan_o_war.y = 143;


  struct korabl shapard_normandy;

  shapard_normandy.x = 824;

  shapard_normandy.y = 143;


  ship_batle_game (stan_o_war, 5,
                   shapard_normandy, 5,
                   1);

  /*control_ship_battle ();

  //control_kama_pulya_3D ();

  //move_ship_batle ();

  //move_kama_pulya_3D ();

  //draw_stan_o_war (116, 143);

  //stan_o_war (116, 143);

  //shapard_normandy (413, 143);

  //kama_pulya_3d ();

  /*draw_kama_pulya_3d (200, 200,
                        20,
                        80, 0);*/

  return 0;
}
void stan_o_war(int x, int y, HDC ship)
{
  int x_diff = txGetExtentX (ship) / 2;
  int y_diff = txGetExtentY (ship) / 2 + 20;

  txTransparentBlt (x - x_diff, y - y_diff, ship, TX_WHITE);

  /*txSetFillColor (TX_YELLOW);

  //printf("%d %d\n", txGetExtentX (ship), txGetExtentY (ship));

  txCircle (x, y, 5);


  txSetColor (TX_YELLOW);

  txSetFillColor (TX_NULL);

  txCircle (x, y, Strike1);


  /*int x_machta1 = x;
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

  txSetColor (TX_BLUE);

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
               x_korma2, y_korma2);*/
}



void shapard_normandy(int x, int y, HDC ship)
{
  int x_diff = txGetExtentX (ship) / 2 - 20;
  int y_diff = txGetExtentY (ship) / 2 + 20;

  txTransparentBlt (x - x_diff, y - y_diff, ship, TX_WHITE);

/*txSetFillColor (TX_YELLOW);

//printf("%d %d\n", txGetExtentX (ship), txGetExtentY (ship));

  txCircle (x, y, 5);


  txSetColor (TX_YELLOW);

  txSetFillColor (TX_NULL);

  txCircle (x, y, Strike2);



  /*int x_machta1 = x;
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
               x_korma2, y_korma2);*/
}



void kama_pulya_3d(int x, int y,
                   int r,
                   COLORREF cvet)
{
  txSetColor (cvet);
  txSetFillColor (cvet);

  txCircle (x, y, r);
}



void draw_kama_pulya_3d(int x, int y,
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



double dist(int x1, int y1, int x2, int y2)
{
  return sqrt ((x2  - x1) * (x2  - x1) + (y2 - y1) * (y2 - y1));
}



void ship_batle_game(struct korabl ship_stan_o_war, int vy_stan_o_war,
                     struct korabl ship_shapard_normandy, int vy_shapard_normandy,
                     int dt)
{
  int x_kama_pulya_3d_1 = ship_stan_o_war.x, y_kama_pulya_3d_1 = ship_stan_o_war.y, vx_kama_pulya_3d_1 = 5;

  int x_kama_pulya_3d_2 = ship_shapard_normandy.x, y_kama_pulya_3d_2 = ship_shapard_normandy.y, vx_kama_pulya_3d_2 = 5;

  HDC graphika = txLoadImage ("кек.bmp");

  if (graphika == 0) txMessageBox ("лох");


  HDC korabel = txLoadImage ("посудина.bmp");

  if (korabel == 0) txMessageBox ("sorry bat you lox");


  HDC korabelbel = txLoadImage ("корабль.bmp");

  if (korabelbel == 0) txMessageBox ("sorry bat you looser");


  int taa = 0;


  while (true)
  {
    txBegin();

    txSetColor (TX_BLACK);

    txSetFillColor (TX_BLACK);

    txClear ();

    txBitBlt (txDC(), 0, 0, 1000, 600, graphika);


    double d1 = dist (ship_stan_o_war.x, ship_stan_o_war.y,
                      x_kama_pulya_3d_2, y_kama_pulya_3d_2);
    double d2 = dist (ship_shapard_normandy.x, ship_shapard_normandy.y,
                      x_kama_pulya_3d_1, y_kama_pulya_3d_1);


    if (d1 < Strike1)
    {
      txPlaySound ("lox.wav");

      txMessageBox ("Ti ovca eji !!");

      break;
    }


    if (d2 < Strike2)
    {
      txPlaySound ("jorik.wav");

      txMessageBox ("Krasauvchik eji!!");

      break;
    }


    control_ship_battle (&vy_stan_o_war,
                         VK_UP, VK_DOWN,
                         &ship_stan_o_war,
                         &ship_shapard_normandy,
                         &x_kama_pulya_3d_1, &y_kama_pulya_3d_1,
                         &x_kama_pulya_3d_2, &y_kama_pulya_3d_2,
                         VK_SPACE,
                         &taa);

    move_ship_battle (&ship_stan_o_war, &vy_stan_o_war,
                      &x_kama_pulya_3d_1, &vx_kama_pulya_3d_1,
                      &dt,
                      0);

    stan_o_war (ship_stan_o_war.x, ship_stan_o_war.y, korabel);


    move_ship_battle (&ship_shapard_normandy, &vy_shapard_normandy,
                      &x_kama_pulya_3d_2, &vx_kama_pulya_3d_2,
                      &dt,
                      1);

    shapard_normandy (ship_shapard_normandy.x, ship_shapard_normandy.y, korabelbel);

    txSleep (25);
  }

  txDeleteDC (graphika);

  txDeleteDC (korabel);

  txDeleteDC (korabelbel);
}



void move_ship_battle(struct korabl *ship, int *vy_ship,
                      int *x_kama_pulya, int *vx_kama_pulya,
                      int *dt,
                      int minus_plus)
{
  if ((ship->y) < 0)
    (*vy_ship) = - (*vy_ship);

  if ((ship->y) > 600)
    (*vy_ship) = - (*vy_ship);


  ship->y = ship->y + *vy_ship * *dt;

  if (minus_plus == 0)
  {
    *x_kama_pulya = *x_kama_pulya + *vx_kama_pulya * *dt;
  }


  if (minus_plus == 1)
  {
    *x_kama_pulya = *x_kama_pulya - *vx_kama_pulya * *dt;
  }
}



void control_ship_battle(int *vy_ship,
                         int up, int down,
                         struct korabl *stan_o_war,
                         struct korabl *shapard_normandy,
                         int *x_kama_pulya3, int *y_kama_pulya3,
                         int *x_kama_pulya4, int *y_kama_pulya4,
                         int space,
                         int *taa)
{
  if (GetAsyncKeyState (up))
    (*vy_ship)--;

  if (GetAsyncKeyState (down))
    (*vy_ship)++;


  if (GetAsyncKeyState (space))
  {
    *taa = 1;

    *x_kama_pulya3 = stan_o_war->x;

    *y_kama_pulya3 = stan_o_war->y;

    *x_kama_pulya4 = shapard_normandy->x;

    *y_kama_pulya4 = shapard_normandy->y;

    txPlaySound ("gun5.wav");

    txPlaySound ("gun6.wav");

  }


  if ((*taa) == 1)
  {
    draw_kama_pulya_3d (*x_kama_pulya3, *y_kama_pulya3,
                        10,
                        80, 0);


    draw_kama_pulya_3d (*x_kama_pulya4, *y_kama_pulya4,
                        10,
                        0, 80);


    txSetColor (TX_RED);

    txTextOut (355, 35, "shaa!!");


    txSetColor (TX_GREEN);

    txTextOut (555, 35, "bud derzkim!!");
  }

}
