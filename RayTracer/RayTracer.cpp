#include <iostream>
#include <fstream>
#include <sstream>
#include "vec3.h"
#include "Ray.h"

// Linearly blen white and blue depending on the y coordinate
// this give a smooth gradient from blue to white
vec3 color(const Ray& r)
{
	vec3 unitDirection = UnitVector(r.Direction());	// y coordinate is between -1 and +1
	float t = 0.5 * (unitDirection.y() + 1.0);		// scale so that 0 < t < 1
	return (1.0 - t) * vec3(1.0, 1.0, 1.0) + t * vec3(0.5, 0.7, 1.0);	// lerp t == 1 : blue , t == 0 : white
}

int main()
{
	std::ofstream file("file.ppm",std::ios::binary);
	std::stringstream stream;
	
	// PPM format setup
	int nx = 200;	// width
	int ny = 100;	// height
	stream << "P3\n" << nx << " " << ny << "\n255\n";
	file << stream.rdbuf();

	// Setup camera and screen
	vec3 lowerLeftCorner(-2.0, -1.0, -1.0);
	vec3 horizontal(4.0, 0.0, 0.0);
	vec3 vertical(4.0, 2.0, 0.0);
	vec3 origin(0.0, 0.0, 0.0);


	for (int j = ny - 1; j >= 0; j--)
	{
		for (int i = 0; i < nx; i++)
		{
			stream.clear();

			// screen UV coordinates
			float u = float(i) / float(nx);	
			float v = float(j) / float(ny);

			// construct ray from camera origin to every point on screen
			Ray r(origin, lowerLeftCorner + u * horizontal + v * vertical); 

			// Get color of a pixel
			vec3 col = color(r);

			// Write to PPM format
			int ir = int(255.99 * col[0]);
			int ig = int(255.99 * col[1]);  
			int ib = int(255.99 * col[2]);
			stream << ir << " " << ig << " " << ib << "\n";
			file << stream.rdbuf();
		}
	}
}