#include <ros/ros.h>
#include <opencv_apps/CircleArrayStamped.h>
#include <sensor_msgs/CameraInfo.h>
#include <geometry_msgs/Twist.h>

class STL_Test
{
private:
	ros::NodeHandle nh_;
	ros::Subscriber sub_;
	ros::Subscriber sub_info_;
	ros::Publisher pub_;

	// ROS Parameters
	int scale_l;
	int scale_a;

	// Normal Variables
	int width;
	int height;

public:
	STL_Test()
	{
		width = 0;
		height = 0;

		nh_.param<int>("/scale_linear", scale_l, 100);
		nh_.param<int>("/scale_angular", scale_a, 100);

		sub_ = nh_.subscribe("/hough_circles/circles", 1, &STL_Test::callback, this);
		sub_info_ = nh_.subscribe("/usb_cam_node/camera_info", 1, &STL_Test::callback_info, this);
		pub_ = nh_.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 1);
	}

	~STL_Test()
	{
	}

	void callback(const opencv_apps::CircleArrayStamped::Ptr &msg)
	{
		if(width==0 || height == 0)
		{
			ROS_INFO("No Camera Info");
			return;
		}

		if(msg->circles.size() == 1)
		{
			float x = msg->circles[0].center.x;
			float y = msg->circles[0].center.y;

			geometry_msgs::Twist t;

			t.linear.x = (y-height/2)/scale_l * -1;
			t.angular.z = (x-width/2)/scale_a;

			pub_.publish(t);
		}

		return;
	}

	void callback_info(const sensor_msgs::CameraInfo::Ptr &msg)
	{
		width = msg->width;
		height = msg->height;

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
