
#include <stdio.h>
#include <stdlib.h>

List* init_history()
{
  struct s_List* start = NULL;
  start = (struct s_List*)malloc(sizeof(struct s_List));
  start->root = NULL;
  return start;
}

void add_history(List* list, char* str)
{
  struct s_Item* temp;
  temp = (struct s_Item*)malloc(sizeof(struct s_Item));
  if(list->root == NULL)
    {
      temp->str = str;
      temp->id = 0;
      list->root= temp;
      list->root->next = NULL;
      return;
    }
  else
    {
      struct s_Item* point;
      point = list->root;
      int i = 0;
      for(int i = 0; point->next != NULL ;i++)
	{
	  point = point->next;
	}
      if(point->next == NULL)
	{
	  temp->str = str;
	  temp->id = i;
	  temp->next = NULL;
	  point->next = temp;
	  return;
	}
    }
}

char* get_history(List* list, int id)
{
  struct s_Item* point;
  point = list->root;
  for(int i = 0; i < id ;i++)
    {
      point = point->next;
    }
  return point->str;
}

void print_history(List* list)
{
  if(list->root = NULL)
    {
      return;
    }
  struct s_Item* point;
  point = list->root;
  for(int i = 0;point->next != NULL;i++)
    {
      if(point->next = NULL)
	{
	  return;
	}
      else
	{
	  printf("%s", point->str);
	}
      point = point->next;
    }
}

void free_history(List* list)
{
  while(list->root != NULL)
    {
      if(list->root = NULL)
	{
	  free(list);
	  return;
	}
      struct s_Item* point;
      point = list->root;
      for(int i = 0; point->next != NULL;i++)
	{
	  point = point->next;
	  if(point->next = NULL)
	    {
	      free(point);
	    }
	}
    }
  if(list->root = NULL)
    {
      free(list);
      return;
    }
}
