#include <stdio.h>
typedef enum {q0=0, q1, q2} stateType;
// print stateType appropriately to screen
void print_state(stateType state)
{
if (state == 0)
printf("q0");
else if (state == 1)
printf("q1");
else
printf("q2");
}
int main(void)
{
char c;
stateType state;
// establish starting state of DFA
state = q0;
// prompt user for input
printf("Enter string w: ");
// DFA processes the input
while((c = getchar()) != ’\n’) {
printf("delta(")");
print_state(state);
printf(",");
printf("%c",c);
printf(") = ",c);
switch(state) {
// q0 is the starting state
case q0: switch(c) {
case ’0’: state = q2;
break;
case ’1’: state = q0;
}
break;
// q1 is the final state
case q1: switch(c) {
case ’0’: state = q1;
break;
case ’1’: state = q1;
}
break;
case q2: switch(c) {
case ’0’: state = q2;
break;
case ’1’: state = q1;
}
}
print_state(state);
printf("\n");
}
/* determine if DFA accepts input string */
if (state == q1)
printf("\nw is accepted\n");
else
printf("\nw is not accepted\n");
return 0;
}

