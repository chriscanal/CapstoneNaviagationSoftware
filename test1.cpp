/*This funciton takes the point2 cloud from the
Duo M and correctly updates the octomap */
#include <octomap/octomap.h>

using namespace std;
#include <stdlib.h>     /* srand, rand */

void createRandomPointCloud(octomap::Pointcloud & cloud9, int width, int hieght)
{
        float x = 1.0;
        float y = 1.0;
        float z = 1.0;
        for (int i = 0 ; i < hieght ; i++)
        {
                for (int j = 0 ; j < width ; j++)
		{
			cloud9.push_back( x, y, z);
        	        x += 1.0;
                }
		y += 1.0;
        }
}

double getMiddleAverage(int totalW, int totalH, double percentSize)
{
	//using 1/10 of the field of view at the center
	//in order to calculate the distance change
	//from last scan to now. Assumes the vector
	//of points is streaming in from left to right
	//and then from top to bottom, so it will have the
	//entire first row first in order.
	int right = (totalW*percentSize);
	int left = (total);
	for (int i = 0 ; i < hieght ; i++)
        	{       
                	for (int j = 0 ; j < width ; j++)
                	{       
                       		cloud9.push_back( x, y, z);
                        	x += 1.0;
                	} 
                	y += 1.0;
        }
	
	
}
	

int main(){
        octomap::OcTree chrisTree (0.1);
        chrisTree.setOccupancyThres(0.5);
        cout << "This shit is working" << endl;

        //Size of pointCloud = 640 x 480
        octomap::Pointcloud sensorData1;
        createRandomPointCloud(sensorData1, 640, 480);
	
	//display point data in terminal
	octomap::point3d nPoint;
	for (int i = 0 ; i < 2500; i++)
	{
		nPoint = sensorData1.getPoint(i);	
		cout << "x = " << nPoint.x() << "; y = " << nPoint.y() << "; z = " << nPoint.z() << ";\n"; 
	}
	//Pose6D(float x, float y, float z, double roll, double pitch, double yaw)
	octomath::Pose6D startPose;        
        octomath::Quaternion rotation1;
	octomath::Vector3 translation1;
	
	rotation1 = startPose.rot();
	translation1 = startPose.trans();
	cout << "rotation = " << rotation1 << "; translation = " << translation1 << ";\n";
	return 0;
	
}
