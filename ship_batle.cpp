#include "TXLib.h"

const int Strike1 = 30;
const int Strike2 = 35;

struct ship_battle
{
  int x_stan_o_war;

  int y_stan_o_war;

  int vy_stan_o_war;


  int x_shapard_normandy;

  int y_shapard_normandy;

  int vy_shapard_normandy;


  int x_taa;

  int y_taa;

  int vx_taa;


  int x_shaa;

  int y_shaa;

  int vx_shaa;
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


void ship_batle_game(struct ship_battle game,
                     int dt);


void control_ship_battle(struct ship_battle *game,
                         int up, int down,
                         int space,
                         bool ovca_eji);


void move_ship_battle(struct ship_battle *game,
                      int *dt,
                      bool minus_plus);


int main()
{
  txCreateWindow (1000, 600);

  struct ship_battle game =
  {
    116, 143, 7,
    824, 143, 7,
    116, 143, 5,
    824, 143, 5
  };

  ship_batle_game (game,
                   1);

/*control_ship_battle ();
//control_kama_pulya_3D ();
//move_ship_batle ();
//move_kama_pulya_3D ();
//draw_stan_o_war (116, 143);
//stan_o_war (116, 143);
//shapard_normandy (413, 143);
//kama_pulya_3d ();
draw_kama_pulya_3d (200, 200,
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


void ship_batle_game(struct ship_battle game,
                     int dt)
{
  HDC graphika = txLoadImage ("space.bmp");

  if (graphika == 0) txMessageBox ("Г«Г®Гµ");


  HDC korabel = txLoadImage ("tortuga.bmp");

  if (korabel == 0) txMessageBox ("sorry bat you lox");


  HDC korabelbel = txLoadImage ("vessel.bmp");

  if (korabelbel == 0) txMessageBox ("sorry bat you looser");


  int taa = 0;


  while (true)
  {
    txBegin();

    txSetColor (TX_BLACK);

    txSetFillColor (TX_BLACK);

    txClear ();

    txBitBlt (txDC(), 0, 0, 1000, 600, graphika);


    double d1 = dist (game.x_stan_o_war, game.y_stan_o_war,
                      game.x_shaa, game.y_shaa);
    double d2 = dist (game.x_shapard_normandy, game.y_shapard_normandy,
                      game.x_taa, game.y_taa);


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


    control_ship_battle (&game,
                         VK_UP, VK_DOWN,
                         VK_SPACE,
                         1);

    move_ship_battle (&game,
                      &dt,
                      0);

    stan_o_war (game.x_stan_o_war, game.y_stan_o_war, korabel);


    move_ship_battle (&game,
                      &dt,
                      1);

    shapard_normandy (game.x_shapard_normandy, game.y_shapard_normandy, korabelbel);

    txSleep (25);
  }

  txDeleteDC (graphika);

  txDeleteDC (korabel);

  txDeleteDC (korabelbel);
}



void move_ship_battle(struct ship_battle *game,
                      int *dt,
                      bool minus_plus)
{
  if (game->y_stan_o_war < 0)
    game->vy_stan_o_war = - game->vy_stan_o_war;

  if (game->y_stan_o_war > 600)
    game->vy_stan_o_war = - game->vy_stan_o_war;

  if (game->y_shapard_normandy  < 0)
    game->vy_shapard_normandy  = - game->vy_shapard_normandy;

  if (game->y_shapard_normandy  > 600)
    game->vy_shapard_normandy  = - game->vy_shapard_normandy;


  game->y_stan_o_war = game->y_stan_o_war + game->vy_stan_o_war * *dt;

  game->y_shapard_normandy = game->y_shapard_normandy + game->vy_shapard_normandy * *dt;

  if (minus_plus == 0)
  {
    game->x_taa = game->x_taa + game->vx_taa * *dt;
  }


  if (minus_plus == 1)
  {
    game->x_shaa = game->x_shaa - game->vx_shaa * *dt;
  }
}



void control_ship_battle(struct ship_battle *game,
                         int up, int down,
                         int space,
                         bool ovca_eji)
{
  if (GetAsyncKeyState (up))
    (game-> vy_stan_o_war)--;

  if (GetAsyncKeyState (down))
    (game-> vy_stan_o_war)++;


  if (GetAsyncKeyState (space))
  {
    ovca_eji = 1;

    game->x_taa = game->x_stan_o_war;

    game->y_taa = game->y_stan_o_war;

    game->x_shaa = game->x_shapard_normandy;

    game->y_shaa = game->y_shapard_normandy;

    txPlaySound ("gun5.wav");

    txPlaySound ("gun6.wav");

  }


  if (ovca_eji == 1)
  {
    draw_kama_pulya_3d (game->x_taa, game->y_taa,
                        10,
                        80, 0);


    draw_kama_pulya_3d (game->x_shaa, game->y_shaa,
                        10,
                        0, 80);


    txSetColor (TX_RED);

    txTextOut (355, 35, "shaa!!");


    txSetColor (TX_GREEN);

    txTextOut (555, 35, "bud derzkim!!");
  }

}
