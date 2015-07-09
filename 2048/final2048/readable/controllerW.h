w(){
int i,  j,  temp,  m,  n;

for (j = 0; j < COLS; j++)
	    {
	      for (i = 0; i < ROWS; i++)
		{
		  temp = i;
		  if (grid[i][j] == 0)
		    {
		      for (m = i + 1; m < ROWS; m++)
			{
			  if (grid[m][j] != 0)
			    {
			      for (n = m; n < ROWS; n++)
				{
				  grid[temp][j] = grid[n][j];
				  temp++;
				}
			      for (n = temp; n < ROWS; n++)
				{
				  grid[n][j] = 0;
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

	      for (i = 0; i < ROWS - 1; i++)
		{

		  if (grid[i][j] != 0)
		    {
		      if ((grid[i][j]) == (grid[i + 1][j]))
			{
			  flag = 1;
			  grid[i][j] *= 2;
			  SCORE += grid[i][j];
			  temp = i;
			  for (n = i + 1; n < ROWS; n++)
			    {
			      grid[temp + 1][j] = grid[temp + 2][j];
			      temp++;
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
