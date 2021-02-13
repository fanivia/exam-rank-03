

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct	s_background
{
	float		width;
	float		height;
	char 		back;
}				t_background;

int main(int argc, char **argv)
{
	FILE			*file;
	t_background	back;
	char			*draw;
	float 			i;
	int 			result;
	char 			type;
	int 			x;
	int 			y;
	int 			radius;
	char			color;

	if (argc != 2)
	{
		write(1, "Error: argument\n", 16);
		return (1);
	}
	if (!(file = fopen(argv[1], "r")))
	{
		write(1, "Error: Operation file corrupted\n", 32);
		return (1);
	}
	if (fscanf(file, "%d %d %c\n", &back.width, &back.height, &back.back) != 3)
		return (1);
	if (back.width <= 0 || back.width > 301 || back.height <= 0 || back.height > 301)
		return (1);
	if (!(draw = (char *)malloc(sizeof(char) * back.height * back.width)))
		return (1);
	i = 0;
	while (i < back.width * back.height)
	{
		draw[i] = back.back;
		i++;
	}
	while ((result = fscanf(file, "%c %f %f %f %c\n", &type, &x, &y, &radius, &color)) == 5)
	{
		if (radius <= 0 || (type != 'c' && type != 'C'))
			return (1);

		int 	a;
		int 	b;
		int 	hit;
		i = 0;
		while (i < back.width)
		{
			j = 0;
			while (j < back.height)
			{
				float 	distance;

				distance = sqrtf((i - x) * (i - x) + (j - y) * (j - y));
				if (distance <= radius)
				{
					if (distance - radius <= -1)
						return (1);
					return (2);
				}
				hit =
				j++;
			}
			i++;
		}
	}
}