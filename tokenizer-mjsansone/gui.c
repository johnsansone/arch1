#include <stdio.h>
#include <stdlib.h>
#include <history.h>
#include <tokenizer.h>


int main()
{

  int tf = 0;
  char** token;
  List* list;
  list = init_history();

  while(tf == 0)
    {
      char s[256];
      printf("\n welcome to my program to tokenize something enter * .\nTo view history if you have allready tokenized something enter ^ .\n If you want to re tokenize something enter ! .\nIf if you want to clear history press - .\n to quit enter @ (note this will only read the first character) \n");
      printf("$");
      scanf("%255s",s);
      char* str;
      str = malloc(sizeof(char)*256);
      // i could of done a char strtemp[256] here to get the input and then malloc char* str bassed on how many char is in the array but memory does not matter in this example
      if(s[0] == '*')
	{
	  printf("enter your string to tokenize.\n");
	  printf("$");
	  scanf("\n %[^\n]s",str);
	  token = tokenize(str);
	  print_tokens(token);
	  free_tokens(token);
	  add_history(list,str);
	}
      if(s[0] == '^')
	{
	  printf("Here is your history! \n");
	  print_history(list);
	}
      if(s[0] == '!')
	{
	  printf("enter the number of the sentance that you want to retokenize (count in decending order from 0) \n");
	  int i;
	  scanf("%d", &i);

	  printf("%s \n",get_history(list,i));
	}
      if(s[0] == '-')
	{
	  printf("clearing history\n");
	  free_history(list);
	  list = init_history();
	}
      if(s[0] == '@')
	{
	  free_history(list);
	  tf = 1;
	  return 0;
	}

    }

      
  return 0;
}



