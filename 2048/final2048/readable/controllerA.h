a(){
	int i,  j,  temp,  m,  n;
	  for (i = 0; i < ROWS; i++)
	    {
	      for (j = 0; j < COLS; j++)
		{

		  if (grid[i][j] == 0)
		    {
		      temp = j;
		      for (m = j + 1; m < COLS; m++)
			{
			  if (grid[i][m] != 0)
			    {
			      for (n = m; n < COLS; n++)
				{
				  grid[i][temp] = grid[i][n];
				  temp++;
				}
			      for (n = temp; n < COLS; n++)
				{
				  grid[i][n] = 0;
				}
			      flag = 1;
			      break;
			    }

			}
		    }
		}

	    }
	  for (i = 0; i < ROWS; i++)
	    {

	      for (j = 0; j < COLS - 1; j++)
		{

		  if (grid[i][j] != 0)
		    {


		      if ((grid[i][j]) == (grid[i][j + 1]))
			{
			  flag = 1;
			  grid[i][j] *= 2;
			  SCORE += grid[i][j];
			  temp = j;
			  for (n = j + 1; n < COLS; n++)
			    {
			      grid[i][temp + 1] = grid[i][temp + 2];
			      temp++;

			    }
			  grid[i][temp] = 0;

			}

		    }
		}

	    }
	  if (flag == 1)
	    {
	      prg ();
	      freem ();
	    }

	  //  printf("game value: %d", gameoverval);
	 
}


