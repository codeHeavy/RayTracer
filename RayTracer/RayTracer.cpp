#include <iostream>
#include <fstream>
#include <sstream>
#include "vec3.h"

int main()
{
	vec3 s();
	std::ofstream file("file.ppm",std::ios::binary);
	std::stringstream stream;
	
	int nx = 200;
	int ny = 100;
	stream << "P3\n" << nx << " " << ny << "\n255\n";
	file << stream.rdbuf();
	for (int j = ny - 1; j >= 0; j--)
	{
		for (int i = 0; i < nx; i++)
		{
			stream.clear();
			vec3 col(float(i) / float(nx), float(j) / float(ny), 0.2);
			int ir = int(255.99 * col[0]);
			int ig = int(255.99 * col[1]);
			int ib = int(255.99 * col[2]);
			stream << ir << " " << ig << " " << ib << "\n";
			file << stream.rdbuf();
		}
	}
}