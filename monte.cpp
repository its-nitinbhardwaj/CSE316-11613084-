/* C++ program for estimation of Pi using Monte
Carlo Simulation */
#include <bits/stdc++.h>

// Defines precision for x and y values. More the
// interval, more the number of significant digits
#define INTER 20
using namespace std;

int main()
{
	int interval, i;
	double ra_x, ra_y, origin, pi;
	int circle_points = 0, square_points = 0;

	// Initializing rand()
	srand(time(NULL));

	// Total Random numbers generated = possible x
	// values * possible y values
	for (i = 0; i < (INTER * INTER); i++) {

		// Randomly generated x and y values
		ra_x = double(rand() % (INTER + 1)) / INTER;
		ra_y = double(rand() % (INTER + 1)) / INTER;

		// Distance between (x, y) from the origin
		origin = ra_x * ra_x + ra_y * ra_y;

		// Checking if (x, y) lies inside the define
		// circle with R=1
		if (origin <= 1)
			circle_points++;

		// Total number of points generated
		square_points++;

		// estimated pi after this iteration
		pi = double(4 * circle_points) / square_points;

		// For visual understanding (Optional)
		cout << "Value of pi after "<<i<<"iteration "<< pi << endl<<endl ;

		// Pausing estimation for first 10 values (Optional)
		if (i < 10)
		{
			cout<<"Press Enter for next iteration  "<<endl<<endl;
			getchar();
	    }
	}

	// Final Estimated Value
	cout << "\nFinal value of pi after "<<INTER*INTER<<" interval :" << pi;

	return 0;
}
