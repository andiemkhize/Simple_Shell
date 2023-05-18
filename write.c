#include <stdio.h> /* STDOUT_FILENO */
#include <unistd.h> /* writes the sytem call */
#include <string.h> /* string length */

int main(void)
{
	/* defines a string that has shell prompt we want to display */
	char *shell_prompt = "$$";

	/* write the contents of the prompt string to standard output */
	write(STDOUT_FILENO, shell_prompt, strlen(shell prompt));

	return (0);
}
