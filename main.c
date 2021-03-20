#include "get_next_line.h"

int main(void)
{
	char const *current_file;
	int current_file_descriptor;

	current_file = "./teste.txt";
	current_file_descriptor = open(current_file, O_RDONLY);
	test_gnl(current_file_descriptor, current_file);

	return (0);
}
