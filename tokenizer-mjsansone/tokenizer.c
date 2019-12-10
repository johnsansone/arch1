#include <stdio.h>

#include <stdlib.h>

int string_length(char* str)
{
  int i = 0;
  while(*str !='\0')
    {
      i++;
      *str++;
    }
  return i;
}
char is_valid_character(char c)
{
  if( c >= 33 && c <= 126)
    {
      return 1;
    }
  else
    {
      return 0;
    }
}
char* find_word_start(char* str)
{
  while(is_valid_character(*str) == 0)
    {
      if (*str == '\0')
	{
	  break;
	}
      *str++;
    }
  return str;
}
char* find_word_end(char* str)
{
  while((is_valid_character(*str) != 1)& *str != '\0')
    {
      *str++;
    }
  while(is_valid_character(*str) == 1)
    {
      *str++;
    }
  return str;
}

char is_valid_character(char c)
{
  if( c >= 33 && c <= 126)
    {
      return 1;
    }
  else
    {
      return 0;
    }
}

int count_words(char* str)
{
  int c = 0;
  while(*str != '\0')
    {
      if(is_valid_character(*str) == 1)
	{
	  c++;
	  while(is_valid_character(*str) == 1)
	    {
	      *str++;
	    }
	}
      *str++;
    }
  return c;
}

char* copy_word(char* str)
{
  char* p1;
  p1 = find_word_start(str);
  int diff = find_word_end(str)-find_word_start(str);
  char* ret = malloc(sizeof(char)*(find_word_end(str)-find_word_start(str)));
  for(int a = 0 ; a < diff; a++)
    {
      ret[a] = *p1;
      *p1++;
    }
  ret[diff] = 0;
  return ret;
}

void print_tokens(char** tokens)
{
  char** tokenstemp;
  tokenstemp = tokens;
  while(*tokenstemp != 0)
    {
      if(**tokenstemp == 0)
	{
	  break;
	}
      printf(":%s:", *tokenstemp);
      *tokenstemp++;
    }
}

void free_tokens(char** tokens)
{
  char** tokens;
  tokens = tokens1;
  for(int i = 0; tokens[i] != NULL;i++)
    {
      if(*tokens = NULL)
	{
	  free(tokens[i]);
	  break;
	}
      else
	{
	  free(tokens[i]);
	}
    }
  free(tokens1);
}

char** tokenize(char* str)
{
  char** tokenlist;
  int size = count_words(str);
  tokenlist = malloc(sizeof(char*)*(size+1));
  for(int i = 0; i < size; i++)
    {
      char* temp = copy_word(str);
      tokenlist[i] = temp;
      str = find_word_end(str); //progresses the string
    }
  tokenlist[size] = NULL;
  return tokenlist;
}
