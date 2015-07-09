#include <stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include"filehandlers.h"
#include"controllerA.h"
#include"controllerW.h"
#include"controllerS.h"
#include"controllerD.h"



int main ()
{
  filarranger();
  FILE* filename;
  filename = fopen("scoredata.bin", "a");
  srand (time (NULL));

  int i, j, k, n, m, p, temp, dir = 0, osgr1 = 0, osgc1 = 0, osgr2 = 0, osgc2 = 0;
  char keypressed;

  while (osgr1 == osgr2 && osgc1 == osgc2)
    {
      osgr1 = rand () % 4;
      osgc1 = rand () % 4;
      osgr2 = rand () % 4;
      osgc2 = rand () % 4;
    }
  
  grid[osgr1][osgc1] = 2;
  grid[osgr2][osgc2] = 2;
  gamestart ();
  entercreator (100);
  printscore ();
  printgrid (grid);
  


  while (1)
    {
      flag = 0;
      keypressed = getchar ();
      if (keypressed == 'a' || keypressed == 'A')
	{
		a();
		if(conditioner() == 0){
			break;
		}
	}

      else if (keypressed == 'w' || keypressed == 'W')
	{
		w();
		if(conditioner() == 0){
			break;
		}	 
 	
	}

      else if (keypressed == 'd' || keypressed == 'D')
	{
	 	d();
		if(conditioner() == 0){
			break;
		}	
	}
      else if (keypressed == 's' || keypressed == 'S')
	{
	 	s();
		if(conditioner() == 0){
			break;
		}
	}
}
  fprintf(filename, "%d\n", SCORE);
  fclose(filename);
  return 0;
}
