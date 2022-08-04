/*
https://www.guyuehome.com/36509
*/

#include <ros/ros.h>
#include <visualization_msgs/Marker.h>
 
int main( int argc, char** argv )
{
    ros::init(argc, argv, "basic_shapes");
    ros::NodeHandle n;
    ros::Rate r(5);
    ros::Publisher marker_pub = n.advertise<visualization_msgs::Marker>("visualization_marker", 1);

    uint32_t shape = visualization_msgs::Marker::CUBE;

    visualization_msgs::Marker marker;

    marker.header.frame_id = "my_frame";
    marker.header.stamp = ros::Time::now();

    marker.ns = "basic_shapes";
    marker.id = 0;

    marker.type = shape;

    marker.action = visualization_msgs::Marker::ADD;

    marker.pose.position.x = 0;
    marker.pose.position.y = 0;
    marker.pose.position.z = 0;
    marker.pose.orientation.x = 0.0;
    marker.pose.orientation.y = 0.0;
    marker.pose.orientation.z = 0.0;
    marker.pose.orientation.w = 1.0;

    marker.scale.x = 1.0;
    marker.scale.y = 1.0;
    marker.scale.z = 1.0;

    marker.color.r = 0.0f;
    marker.color.g = 1.0f;
    marker.color.b = 0.0f;
    marker.color.a = 1.0;

    marker.lifetime = ros::Duration();
    while (ros::ok())
    {
        marker.color.g += 0.1;
        if (marker.color.g > 1.0) marker.color.g = 0.0;

        marker.pose.orientation.x += 0.1;
        if (marker.pose.orientation.x > 3.0) marker.pose.orientation.x = -3.0;

        while (marker_pub.getNumSubscribers() < 1)
        {
        if (!ros::ok())
        {
            return 0;
        }
        ROS_WARN_ONCE("Please create a subscriber to the marker");
        sleep(1);
        }
        marker_pub.publish(marker);

    r.sleep();
    }
}