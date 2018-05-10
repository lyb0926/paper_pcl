#include <iostream>  
#include <pcl/io/pcd_io.h>  
#include <pcl/point_types.h>  
#include <pcl/filters/voxel_grid.h>  


int main(int argc, char** argv)
{

	pcl::PCLPointCloud2::Ptr cloud(new pcl::PCLPointCloud2());
	pcl::PCLPointCloud2::Ptr cloud_filtered(new pcl::PCLPointCloud2());

	//���ƶ���Ķ�ȡ  
	pcl::PCDReader reader;

	reader.read("C:/Users/lyb/Desktop/�½��ļ���/zaosheng.pcd", *cloud);    //��ȡ���Ƶ�cloud��  

	std::cerr << "PointCloud before filtering: " << cloud->width * cloud->height
		<< " data points (" << pcl::getFieldsList(*cloud) << ").";

	
	pcl::VoxelGrid<pcl::PCLPointCloud2> sor;  //�����˲�����  
	sor.setInputCloud(cloud);            //������Ҫ���˵ĵ��Ƹ��˲�����  
	sor.setLeafSize(0.05f, 0.07f, 0.05f);  //�����˲�ʱ�������������Ϊ1cm��������  
	sor.filter(*cloud_filtered);           //ִ���˲������洢���  

	std::cerr << "PointCloud after filtering: " << cloud_filtered->width * cloud_filtered->height
		<< " data points (" << pcl::getFieldsList(*cloud_filtered) << ").";

	pcl::PCDWriter writer;
	writer.write("C:/Users/lyb/Desktop/�½��ļ���/lvbo.pcd", *cloud_filtered, Eigen::Vector4f::Zero(), Eigen::Quaternionf::Identity(), false);
	return (0);
}