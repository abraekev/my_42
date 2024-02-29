typedef enum e_bool {false, true} bool;

typedef enum e_weekday { Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday } weekday;

#include <unistd.h>
#include <stdio.h>

int	main()
{
	char *e_weekday[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

	weekday today = Thursday;	
	printf("Today is %s\n", e_weekday[today]);
}
