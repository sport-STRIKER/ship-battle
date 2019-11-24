#include "TXLib.h"

const int Strike1 = 30;
const int Strike2 = 35;

struct object
{
 int x;

 int y;

 int v;
};

struct ship_battle
{
  object ship_left;

  object ship_right;

  object bullet_left;

  object bullet_right;
};

void ship1(int x, int y, HDC ship);


void ship2(int x, int y, HDC ship);


void bullet_3d(int x, int y,
                   int r,
                   COLORREF cvet);


void draw_bullet_3d(int x, int y,
                        int rmax,
                        int color1, int color2);


double dist(int x1, int y1, int x2, int y2);


void ship_batle_game(struct ship_battle game,
                     int dt);


void control_ship_battle(struct ship_battle *game,
                         int up, int down,
                         int space,
                         bool proviso);


void move_ship_battle(struct ship_battle *game,
                      int *dt,
                      bool minus_plus);


int main()
{
  txCreateWindow (1000, 600);

  struct object ship_left = {116, 143, 7};

  struct object ship_right = {824, 143, 7};

  struct object bullet_left = {116, 143, 7};

  struct object bullet_right = {824, 143, 7};

  struct ship_battle game;

  game.ship_left = ship_left;
  game.ship_right = ship_right;
  game.bullet_left = bullet_left;
  game.bullet_right = bullet_right;


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


void ship1(int x, int y, HDC ship)
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



void ship2(int x, int y, HDC ship)
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



void bullet_3d(int x, int y,
               int r,
               COLORREF cvet)
{
  txSetColor (cvet);
  txSetFillColor (cvet);

  txCircle (x, y, r);
}



void draw_bullet_3d(int x, int y,
                    int rmax,
                    int color1, int color2)
{
  int t = 0;


  while (t <= 50)
  {
    int radius = rmax - (rmax / 50.0) * t;
    COLORREF cvet = RGB (color1 + (color1 / 25.0) * t, color2 + (color2 / 25.0) * t, 0);

     bullet_3d (x, y,
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

  if (graphika == 0) txMessageBox ("ëîõ");


  HDC korabel = txLoadImage ("tortuga.bmp");

  if (korabel == 0) txMessageBox ("sorry bat you lox");


  HDC korabelbel = txLoadImage ("vessel.bmp");

  if (korabelbel == 0) txMessageBox ("sorry bat you looser");


  while (true)
  {
    txBegin();

    txSetColor (TX_BLACK);

    txSetFillColor (TX_BLACK);

    txClear ();

    txBitBlt (txDC(), 0, 0, 1000, 600, graphika);


    double d1 = dist (game.ship_left.x, game.ship_left.y,
                      game.bullet_right.x, game.bullet_right.x);

    double d2 = dist (game.ship_right.x, game.ship_right.y,
                      game.bullet_left.x, game.bullet_left.y);


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

    ship1 (game.ship_left.x, game.ship_left.y, korabel);


    move_ship_battle (&game,
                      &dt,
                      1);

    ship2 (game.ship_right.x, game.ship_right.y, korabelbel);

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
  if (game->ship_left.y < 0)
    game->ship_left.v = - game->ship_left.v;

  if (game->ship_left.y > 600)
    game->ship_left.v = - game->ship_left.v;

  if (game->ship_right.y < 0)
    game->ship_right.v  = - game->ship_right.v;

  if (game->ship_right.y > 600)
    game->ship_right.v  = - game->ship_right.v;


  game->ship_left.y = game->ship_left.y + game->ship_left.v * *dt;

  game->ship_right.y = game->ship_right.y + game->ship_right.v * *dt;

  if (minus_plus == 0)
  {
    game->bullet_left.x = game->bullet_left.x + game->bullet_left.v * *dt;
  }


  if (minus_plus == 1)
  {
    game->bullet_right.x = game->bullet_right.x - game->bullet_right.v * *dt;
  }
}



void control_ship_battle(struct ship_battle *game,
                         int up, int down,
                         int space,
                         bool proviso)
{
  if (GetAsyncKeyState (up))
    (game->ship_left.v)--;

  if (GetAsyncKeyState (down))
    (game->ship_left.v)++;


  if (GetAsyncKeyState (space))
  {
    proviso = 1;

    game->bullet_left.x = game->ship_left.x;

    game->bullet_left.y = game->ship_left.y;

    game->bullet_right.x = game->ship_right.x;

    game->bullet_right.y = game->ship_right.y;

    txPlaySound ("gun5.wav");

    txPlaySound ("gun6.wav");

  }


  if (proviso == 1)
  {
    draw_bullet_3d (game->bullet_left.x, game->bullet_left.y,
                    10,
                    80, 0);


    draw_bullet_3d (game->bullet_right.x, game->bullet_right.y,
                    10,
                    0, 80);


    txSetColor (TX_RED);

    txTextOut (355, 35, "shaa!!");


    txSetColor (TX_GREEN);

    txTextOut (555, 35, "bud derzkim!!");
  }

}
