/*                    Written by Chris Canal
This funciton takes the point2 cloud from the
Duo M and correctly updates the octomap */
#include <octomap/octomap.h>

using namespace std;


int main(){
	octomap::OcTree chrisTree (0.1);
	chrisTree.setOccupancyThres(0.5);
        cout << "This shit is working" << endl;
	
	//Size of point2cloud = 640 x 480
	octomap::Pointcloud sensorData;
	float x = 1;
	float y = 2;
	float z = 3;
	sensorData.push_back( x, y, z);
	return 0;

}
