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


