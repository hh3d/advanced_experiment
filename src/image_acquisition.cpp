#include <ros/ros.h>
#include <sensor_msgs/Image.h>

class STL_Test
{
private:
	ros::NodeHandle nh_;
	ros::Subscriber sub_;
	ros::Publisher pub_;

public:
	STL_Test()
	{
		sub_ = nh_.subscribe("/cv_camera_node/image_raw", 1, &STL_Test::callback, this);
	}

	~STL_Test()
	{
	}

	void callback(const sensor_msgs::ImageConstPtr &msg)
	{
		ROS_INFO("Get image!");

		return;
	}
};

int main (int argc, char** argv)
{
	ros::init (argc, argv, "STL_Test");

	STL_Test st;

	ros::Rate spin_rate(10);

	while (ros::ok())
	{
		ros::spinOnce();
		spin_rate.sleep();
	}

	return 0;
}