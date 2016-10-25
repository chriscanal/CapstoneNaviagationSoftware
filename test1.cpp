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

double getMiddleAverage(octomap::Pointcloud & sensorData, int totalW, int totalH, double percentSize)
{
	//using 1/10 of the field of view at the center
	//in order to calculate the distance change
	//from last scan to now. Assumes the vector
	//of points is streaming in from left to right
	//and then from top to bottom, so it will have the
	//entire first row first in order.
	octomap::point3d nPoint;
	int right = (totalW*(percentSize/2)+(totalW/2));
	int left = (totalW/2)-(totalW*(percentSize/2));
	int top = (totalH*(percentSize/2)+(totalH/2));
        int bottom = (totalH/2)-(totalH*(percentSize/2));
	double count = 0.0;
	double totalDepth = 0.0;
	for (int i = left ; i <= right ; i++)
        {	
		for (int j = bottom ; j <= top ; j++)
		{
			nPoint = sensorData.getPoint((i+1)*(j+1)-1);
			count += 1.0;
			totalDepth += nPoint.z();
		}
        }
	return totalDepth/count;
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
	cout << "Middle Pixels Average = " << getMiddleAverage(sensorData1, 640, 480, 0.1) << "\n";
	return 0;
	
}
