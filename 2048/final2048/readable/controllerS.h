s(){ 
 int i,  j,  temp,  m,  n, p;
for (j = 0; j < COLS; j++)
	    {
	      for (i = ROWS - 1; i >= 0; i--)
		{
		  temp = i;
		  if (grid[i][j] == 0)
		    {
		      for (m = i - 1; m >= 0; m--)
			{
			  if (grid[m][j] != 0)
			    {
			      for (n = m; n >= 0; n--)
				{
				  grid[temp][j] = grid[n][j];
				  temp--;
				}
			      for (p = temp; p >= 0; p--)
				{
				  grid[p][j] = 0;
				}
			      flag = 1;
			      break;
			    }

			}
		    }
		}

	    }
	  for (j = 0; j < COLS; j++)
	    {

	      for (i = ROWS - 1; i > 0; i--)
		{

		  if (grid[i][j] != 0)
		    {
		    if ((grid[i][j]) == (grid[i - 1][j]))
			{
			  flag = 1;
			  grid[i][j] *= 2;
			  SCORE += grid[i][j];
			  temp = i;
			  for (n = i - 1; n >= 0; n--)
			    {

			      grid[temp - 1][j] = grid[temp - 2][j];
			      temp--;
			    }
			  grid[temp][j] = 0;

			}

		    }
		}

	    }
	  if (flag == 1)
	    {
	      prg ();
	      freem ();
	    }
}
