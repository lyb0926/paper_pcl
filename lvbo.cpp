#include <iostream>  
#include <pcl/io/pcd_io.h>  
#include <pcl/point_types.h>  
#include <pcl/filters/voxel_grid.h>  


int main(int argc, char** argv)
{

	pcl::PCLPointCloud2::Ptr cloud(new pcl::PCLPointCloud2());
	pcl::PCLPointCloud2::Ptr cloud_filtered(new pcl::PCLPointCloud2());

	//点云对象的读取  
	pcl::PCDReader reader;

	reader.read("C:/Users/lyb/Desktop/新建文件夹/zaosheng.pcd", *cloud);    //读取点云到cloud中  

	std::cerr << "PointCloud before filtering: " << cloud->width * cloud->height
		<< " data points (" << pcl::getFieldsList(*cloud) << ").";

	
	pcl::VoxelGrid<pcl::PCLPointCloud2> sor;  //创建滤波对象  
	sor.setInputCloud(cloud);            //设置需要过滤的点云给滤波对象  
	sor.setLeafSize(0.05f, 0.07f, 0.05f);  //设置滤波时创建的体素体积为1cm的立方体  
	sor.filter(*cloud_filtered);           //执行滤波处理，存储输出  

	std::cerr << "PointCloud after filtering: " << cloud_filtered->width * cloud_filtered->height
		<< " data points (" << pcl::getFieldsList(*cloud_filtered) << ").";

	pcl::PCDWriter writer;
	writer.write("C:/Users/lyb/Desktop/新建文件夹/lvbo.pcd", *cloud_filtered, Eigen::Vector4f::Zero(), Eigen::Quaternionf::Identity(), false);
	return (0);
}