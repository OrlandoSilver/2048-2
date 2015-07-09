#define ROWS 4
#define COLS 4
struct scoredata{
  char name[20];
  int score;
};

struct node
{
  int datarow;
  int datacol;
  struct node *next;
};

int flag = 0;
int SCORE = 0;
int COUNTER = 0;
int grid[ROWS][COLS] = { 0 };
struct scoredata scr[200];
struct scoredata tempo;
struct node *head = NULL;



filarranger(){
	int k = -1, bekar;
	int t = 0, i, j;
	char line[100];
	FILE* filename;
	char temp[20];
	char tempscore[30];
    filename = fopen("scoredata.bin", "r+");
   
     
   while(fgets(line, 100, filename) != NULL)
   { 
   
   	 k++;
   	 t = 0 ;
   	  memset(temp, '\0' , 20);
   	  memset(tempscore, '\0' , 30);
	 for(i=0; line[i]!=' '; i++ )
	 {
	 	temp[i] = line[i];
	 
	 }
	 i++;
	 for(;line[i]!= '\n';i++){
	 	tempscore[t] = line[i];
	 	t++;
	 }
	 		
	 for(i=0; i<k; i++){
	 if (strcmp(temp, scr[i].name)==0){
	 	if(atoi(tempscore)>scr[i].score){
	 		scr[i].score = atoi(tempscore);
	 	}
	 	k--;
	 	goto skip;
	 }
	 }
	 strcpy(scr[k].name, temp);
	 scr[k].score = atoi(tempscore);
     skip : 
     bekar = 2;
   }
	
    fclose(filename);


for(i=0;i<200-1;i++){
	for(j=0;j<200-i-1;j++){
		if(scr[j].score < scr[j+1].score){
			strcpy(tempo.name ,scr[j].name);
			tempo.score = scr[j].score;
			strcpy(scr[j].name, scr[j+1].name);
			scr[j].score = scr[j+1].score;
			strcpy(scr[j+1].name, tempo.name);
			scr[j+1].score = tempo.score;
			
		}
	}

}


FILE* fp;
fp = fopen("score.pdf", "w");
for(i=0; i<200; i++){
	if(strlen(scr[i].name)>1){
		fprintf(fp ," %d -->  %s  <--\t\t\t\t %10d",i+1, scr[i].name, scr[i].score);
		fprintf(fp, "\n\n\n");
	}
}
fclose(fp);

}

spacecreator (int a)
{
  int i;
  for (i = 0; i < a; i++)
    {
      printf (" ");
    }
}

starcreator (int a)
{
  int i;
  for (i = 0; i < a; i++)
    {
      printf ("*");
    }
}

entercreator (int a)
{
  int i;
  for (i = 0; i < a; i++)
    {
      printf ("\n");
    }

}

welcomescreen ()
{
  int i;
  entercreator (100);
  for (i = 0; i < 61; i = i + 3)
    {
      spacecreator (i);
      starcreator (i);
      printf ("\n");
    }
  starcreator (74);
  spacecreator (5);
  printf ("WELCOME     ");
  starcreator (35);
  printf ("     press \"5\" to start");
  printf ("\n");
  for (i = 61; i > 0; i = i - 3)
    {
      spacecreator (i);
      starcreator (i);
      printf ("\n");

    }
  printf ("\n");
}

gamestart ()
{

  welcomescreen ();

  int a;
  char s[50];
loop:
  scanf ("%d", &a);
  if (a == 5)
    { 
      
      entercreator(50);
      printf("\t\t\tENTER YOUR NAME:\t");
      scanf("%s",s);
      FILE* filename;
      filename = fopen("scoredata.bin", "a");
      fprintf(filename, "%s ",s);
      fclose(filename);
      return;
    
    }
  else
    {
      printf
	("                                                          SORRY !!!!\n PLEASE ENTER \"5\" TO CONTINUE!!!");
goto loop;
    }
}


freem ()
{
  free (head);
  head = NULL;
  COUNTER = 0;
}

insert (int a, int b)
{
  struct node *temp = (struct node *) malloc (sizeof (struct node));
  temp->datarow = a;
  temp->datacol = b;
  temp->next = head;
  head = temp;
}

int count ()
{
  struct node *temp = head;
  while (temp != NULL)
    {
      //printf("row:%d  colm:%d\n", temp->datarow, temp->datacol);
      COUNTER++;
      temp = temp->next;
    }
  return COUNTER;
}

int checkadjacent ()
{
  int i, j;
  for (i = 0; i < ROWS; i++)
    {
      for (j = 0; j < COLS - 1; j++)
	{
	  if (grid[i][j] == grid[i][j + 1])
	    {
	      return -1;
	    }
	}
    }
  for (j = 0; j < COLS; j++)
    {
      for (i = 0; i < ROWS - 1; i++)
	{
	  if (grid[i][j] == grid[i + 1][j])
	    {
	      return -1;
	    }
	}
    }
  return 0;
}

int gameover ()
{
  int i, j;

  for (i = 0; i < ROWS; i++)
    {
      for (j = 0; j < COLS; j++)
	{
	  if (grid[i][j] == 0)
	    return -1;
	}

    }
  if (checkadjacent () == 0)
    return 0;

}

int fourcreator(){
int a;
a = rand()%100 ;
if(a<10)
return 0;
}


prg ()
{

  int i, j, random, x;
  for (i = 0; i < ROWS; i++)
    {
      for (j = 0; j < COLS; j++)
	{
	  if (grid[i][j] == 0)
	    {
	      insert (i, j);

	    }
	}
    }

  x = count ();
  if (x != 0)
    {
      random = rand () % x;

      // printf ("%d   %d", x, random);
      struct node *temp2 = head;

      for (i = 0; i < random; i++)
	{
	  temp2 = temp2->next;
	}
      // printf ("row:%d  column:%d", temp2->datarow, temp2->datacol);
      if(fourcreator() == 0)
      grid[temp2->datarow][temp2->datacol] = 4;
      else
      grid[temp2->datarow][temp2->datacol] = 2;
    }
}

printscore ()
{
  printf ("\n\n                              SCORE: %d\n\n", SCORE);
}

printgrid (int a[ROWS][COLS])
{
  int i, j;
  printf ("\n\n\n");
  for (i = 0; i < ROWS; i++)
    {

      printf ("\n\n\n");
      printf ("                               ");
      for (j = 0; j < COLS; j++)
	{
	  if (grid[i][j] != 0)
	    printf ("%4d    ", a[i][j]);
	  else
	    printf ("%4c    ", '.');
	}

    }
  printf ("\n\n\n");
  entercreator (10);


}

int conditioner(){

 if (flag == 0 && gameover () == 0)
	    {
	      printf("                            ****************  GAME OVER!! YOUR SCORE: %d  ********************* ",SCORE);
	      return 0;
	    }
	  printscore ();
	  printgrid (grid);

}


